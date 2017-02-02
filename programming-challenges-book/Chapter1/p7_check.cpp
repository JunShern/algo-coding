#include <iostream>
#include <vector>

using namespace std;

void printboard(const vector<char>& board) {
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			cout << board[i*8 + j];
		}
		cout << endl;
	}
}

bool pawn(char colour, int pos, int king_pos) {
	if (colour =='w') {
		if ( (pos-7==king_pos) || (pos-9==king_pos) ) {
			return true;
		}
	} else if (colour == 'b') {
		if ( (pos+7==king_pos) || (pos+9==king_pos) ) {
			return true;
		}
	}

	return false;
}

bool knight(int pos, int king_pos) {
	int reach[] = {-17, -15, -10, -6, 6, 10, 15, 17};
	for (int i=0; i<8; i++) {
		if (pos+reach[i] == king_pos) {
			return true;
		}
	}
	return false;
}

bool bishop(int pos, int king_pos) {
	for (int i=-8; i<=8; i++) {
		if (pos + i*8 + i == king_pos) {
			return true;
		} else if (pos + i*8 - i == king_pos) {
			return true;
		}
	}
	return false;
}

bool rook(int pos, int king_pos) {
	for (int i=-8; i<=8; i++) {
		// Check row movement
		if (pos+i == king_pos) {
			return true;
		// Check column movement
		} else if (pos + i*8 == king_pos) {
			return true;
		}
	}
	return false;
}

bool queen(int pos, int king_pos) {
	// Queen movement is the sum of bishop and rook movement
	return ( bishop(pos, king_pos) || rook(pos, king_pos) );
}

bool king(int pos, int king_pos) {
	// Problem does not describe king-beside-king situation;
	// assume kings are always not in range of each other
	return false;
}

int checking(char c, int pos, int black_pos, int white_pos) {
	char colour;
	int king_pos;
	if (c >= 97) { // Lowercase
		colour = 'b';
		king_pos = white_pos;
	} else { // Uppercase
		colour = 'w';
		king_pos = black_pos;
	}
	
	c = tolower(c);
	bool check = false;
	if (c == 'p') {
		check = pawn(colour, pos, king_pos);
	} else if (c == 'n') {
		check = knight(pos, king_pos);
	} else if (c == 'b') {
		check = bishop(pos, king_pos);
	} else if (c == 'r') {
		check = rook(pos, king_pos);
	} else if (c == 'q') {
		check = queen(pos, king_pos);
	} else if (c == 'k') {
		check = king(pos, king_pos);
		// Weird case if two kings side by side?
	} 

	if (check) {
		if (colour == 'w') {
			return 1; // Black king being checked
		} else if (colour == 'b') {
			return 2; // White king being checked
		}
	} else {
		return 0; // No check
	}
}
		

int main() {

	int gameNum = 1;

	while (1) {
		// Load in board data, save king positions
		vector<char> board;
		int black_pos=-1, white_pos=-1;
		for (int i=0; i<64; i++) {
			char tmp;
			cin >> tmp;
			board.push_back(tmp);

			if (tmp == 'k') {
				black_pos = i;
			} else if (tmp == 'K') {
				white_pos = i;
			}
		}
		
		// End program if no kings on board / empty board
		if (black_pos + white_pos == -2) return 0; 

		// Check each piece, see if they are checking
		int checked = 0;
		for (int i=0; i<64; i++) {
			char c = board[i];
			int pos = i;
			checked += checking(c, pos, black_pos, white_pos);
			if (checked) break; // One check is enough
		}

		// Output
		cout << "Game #" << gameNum << ": ";
		if (checked == 0) {
			cout << "no king is in check." << endl;
		} else if (checked == 1) {
			cout << "black king is in check." << endl;
		} else if (checked == 2) {
			cout << "white king is in check." << endl;
		}
		
//		printboard(board);
		gameNum++;
	}
	
	return 0;
}

