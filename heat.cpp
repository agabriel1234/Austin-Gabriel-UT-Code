#include <iostream>
#include <cmath>

using std::endl;
using std::cout;


int main() {
	
	//solving for u (temperature)
	double u[100][20][20];

	//initialization parameters
	int plate_length = 20;
	int max_time = 100;

	double alpha = 2.0;
	double delta_x = 1.0;
	
	double delta_t = (delta_x*delta_x)/(4.0 * alpha);
	double gamma = (alpha*delta_t)/(delta_x*delta_x);

	//initial values
	double u_initial = 0.0;
	double u_top = 0.0;
	double u_left = 100.00;
	double u_bottom = 0.0;
	double u_right = 100.00;

	//initial values of u
	for(int k = 0; k < max_time; k++) { 
		
		cout << "Time: " << k << endl;

		for(int i = 0; i < plate_length; i+= delta_x) {
			for (int j = 0; j < plate_length; j+= delta_x) {
				u[k][i][j] = u_initial;

				if( i == plate_length - 1) 
					u[k][i][j] = u_top;

				if (j == 0 && i != plate_length-1) 
					u[k][i][j] = u_left;

				if (i == 0) 
					u[k][i][j] = u_bottom;
					
				if (j == plate_length - 1 && i != plate_length-1) 
					u[k][i][j] = u_right;
				
					cout << " " << u[k][i][j];

				
				cout << endl;
				
				
				
			}
		}
	}

	for (int k = 0; k < max_time-1; k++) {
		cout << "Time: " << k << endl;
		
		for (int i = 1; i < plate_length; i+= delta_x) {

			for ( int j = 1; j < plate_length; j+=delta_x) { 
			

				u[k+1][i][j] = 
					gamma*(u[k][i+1][j] + u[k][i-1][j]
					+ u[k][i][j+1] + u[k][i][j-1]
					- 4*u[k][i][j]) + u[k][i][j];
					cout << " " << u[k][i][j];
			}
			cout << endl;
		}
	}

}


