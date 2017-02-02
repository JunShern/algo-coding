#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t=0; t<T; t++) {
		int X, R, C;
		cin >> X >> R >> C;
		cout << "Case #" << t+1 << ": ";
		// 1-ominoes
		if (X == 1) {
			cout << "GABRIEL" << endl;
		// 2-ominoes
		} else if (X == 2) {
			if (R*C % 2 == 0) { // Even
				cout << "GABRIEL" << endl;
			} else { // Odd
				cout << "RICHARD" << endl;
			}
		// 3-ominoes
		} else if (X == 3) {
			if ((R==3 && C==3) || (R*C==6) || (R*C==12)) {
				cout << "GABRIEL" << endl;
			} else {
				cout << "RICHARD" << endl;
			}
		// 4-ominoes
		} else if (X == 4) {
			if (R*C==12 || R*C==16) {
				cout << "GABRIEL" << endl;
			} else {
				cout << "RICHARD" << endl;
			}
		}
	}
	return 0;
}
