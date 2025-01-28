#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <time.h>




using std::cout;
using std::endl;
using std::string;
using std::sort;
using std::vector;


class Card {
	
	private:

	string label;
	string suit;
	int value, altValue, sortValue;

	
	public:
	

	Card() {
	};

	Card(string add_suit, string add_label,int add_value, int add_altValue, int add_sortValue) : suit(add_suit), label(add_label), value(add_value), altValue(add_altValue), sortValue(add_sortValue) {}

	void DisplayCard() const {
		
		cout << "  " << label << " of " << suit << endl;

	}

	int getValue() const {
		return value;
	}

	int getsortValue() const {
		return sortValue;
	}

	string getSuit() const {
		return suit;
	}

};


class Deck {
	
	private:
		vector<Card> current_deck;

	public:
		Deck() {
		};
		Deck (bool newDeck) {
			vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
			vector<string> labels = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
			vector<int> value = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
			vector<int> altValue = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
			vector<int> sortValue = {14, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

			for (auto e: suits) {
				for(int i = 0; i < 13; i++) {
					Card newCard(e, labels.at(i), value.at(i), altValue.at(i), sortValue.at(i));
					current_deck.push_back(newCard);

				}
			}
		}

		Deck(vector<Card> add_deck) {
			current_deck = add_deck;
		}
		
		void addCard(const Card& newCard) {
			current_deck.push_back(newCard);
		}
		
		int cardCount() const {
			return current_deck.size();

		}

		Card dealCard() {
			if (current_deck.empty()) {
				return Card();
			}
			Card dealtCard = current_deck.back();
			current_deck.pop_back();
			return dealtCard;
		}
		


		Deck splitDeck(int number_of_cards) {

			vector<Card> new_deck;


			if (number_of_cards > current_deck.size()) {
				number_of_cards = current_deck.size();

			}

			for (int i = 0; i < number_of_cards; i++) { 
				new_deck.push_back(current_deck.back());
				current_deck.pop_back();

			}

			return new_deck;
		}

		void DisplayDeck() const { 
			for(const auto &card : current_deck) {
				card.DisplayCard();
			}
		}
		
		Deck Sort() {
			auto compare = [](const Card& card1, const Card& card2) {
				if (card1.getSuit() != card2.getSuit()) {
				static const string suitOrder = "HeartsDiamondsClubsSpades";
				
				return suitOrder.find(card1.getSuit()) < suitOrder.find(card2.getSuit());
				}

				if (card1.getValue() == 1) {
					return true;
				}else if (card2.getValue() == 1) {
					return false;
					}
				return card1.getsortValue() < card2.getsortValue();

			};
			
			sort(current_deck.begin(), current_deck.end(), compare);

		return current_deck;
		}
		

		Deck RiffleShuffle(Deck sub2) {
			Deck shuffled_deck;
			int size1 = current_deck.size();
			int size2 = sub2.current_deck.size();

			int max_size = std::max(size1, size2);
			
			for(int i = 0; i < max_size; i++) {
				if (i < size1) {
					shuffled_deck.current_deck.push_back(current_deck[i]);
				}
				if (i < size2) {
					shuffled_deck.current_deck.push_back(sub2.current_deck[i]);
				}
			}
				return shuffled_deck;
			}
		Deck RandomShuffle (Deck sub2) {
			srand(time(NULL));
			Deck shuffled_deck;
			int size1 = current_deck.size();
			int size2 = sub2.current_deck.size();
			
			int index1 = 0;
			int index2 = 0;	


			int max_size = std::max(size1, size2);


			while (index1 < size1 && index2 < size2) {

			int num = rand()% 2;

			if (num == 0) {
				shuffled_deck.current_deck.push_back(current_deck[index1]);
				index1++;
			}
			else {
				shuffled_deck.current_deck.push_back(sub2.current_deck[index2]);
				index2++;
			}
			}
			while(index1 < size1) {
				shuffled_deck.current_deck.push_back(current_deck[index1]);
				index1++;
			}
		        while(index2 < size2) {
				shuffled_deck.current_deck.push_back(sub2.current_deck[index2]);
				index2++;
				}
			
			return shuffled_deck;
		}



};

int main() {
	Deck deck(true);
	cout << "Original Deck:" << endl;
	deck.DisplayDeck();
	Deck original_deck = deck;

	
	Deck subdeck1 = deck.splitDeck(26);
	cout << "Split Deck: " << endl;
	subdeck1.DisplayDeck();
	
	Deck subdeck2 = deck;
	cout << "Remaining Deck: " << endl;
	subdeck2.DisplayDeck();
	
	deck = subdeck1.RiffleShuffle(subdeck2);
	cout << "Shuffled Deck: " << endl;
	deck.DisplayDeck();

	for (int i = 0; i < 11; i++) {	
	Deck subdeck1 = deck.splitDeck(26);
	Deck subdeck2 = deck;
	deck = subdeck1.RiffleShuffle(subdeck2);
	}
 	cout << "11 more shuffles for a total of 12 = "  << endl;
		
	deck.DisplayDeck();

	cout << "This deck is the same as the first one after 12 total shuffles" << endl;
	
	cout << "Now I will RANDOMLY shuffle 12 times to see if we get the same result: " << endl;
	for (int i = 0; i < 12; i++) {	
	Deck subdeck1 = deck.splitDeck(26);
	Deck subdeck2 = deck;
	deck = subdeck1.RandomShuffle(subdeck2);
	}
	deck.DisplayDeck();

	cout << "This deck with the random shuffle is not the same as the original deck." << endl;

	deck = deck.Sort();
	
	cout << "This is the same deck once it has been sorted by suit and card value like the original:" << endl;

	deck.DisplayDeck();

	return 0;

}
