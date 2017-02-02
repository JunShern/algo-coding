#define NCARDS 52
#define NSUITS 4

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

char values[] = "23456789TJQKA";
char suits[] = "cdhs";

int rank_card(char value, char suit) {
	
	for (int i=0; i<(NCARDS/NSUITS); i++) {
		if (values[i] == value) {
			for (int j=0; j<NSUITS; j++) {
				if (suits[j] == suit) {
					return (i*NSUITS + j);
				}
			}
		}
	}
}

int suit(int card) {
	return suits[card % NSUITS];
}

char value(int card) {
	return values[card/NSUITS];
}

int main() {
	queue<int> deck1;
	queue<int> deck2; 

	char value, suit; 

	string line;
	while (getline(cin,line)) {

		cout << "Reading first deck : " << endl;
		// First deck
		stringstream ss(line);
		string tmp;
		while (ss >> tmp) {
			value = tmp[0]; 
			cout << value;
			suit = tmp[1]; 
			cout << suit;
		}

		cout << "Reading second deck : " << endl;
		// Second deck
		getline(cin, line);
		ss(line);
		while (ss >> tmp) {
			value = tmp[0]; 
			cout << value;
			suit = tmp[1]; 
			cout << suit;
		}
	}


	return 0;
}
