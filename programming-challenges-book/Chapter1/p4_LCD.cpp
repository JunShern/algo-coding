#include <iostream>
#include <cmath>

using namespace std;

int length(int num) {
	// Count the number of digits
	int n_digits = 0;
	if (num == 0) return 1; // Special case 0
	while (num >= 1) {
		num = num / 10; 
		n_digits++;
	}
	return n_digits;
}

int index(int num, int ind) {
	// Test for index validity
	if (ind >= length(num)) {
		cout << "Array out of bounds" << endl;
	}
	int reduced = num/pow(10, length(num)-ind-1);
	return reduced % 10;
}	

string make_linetype(int linetype, int s) {
/* 
	linetype:
	0 "    "
	1 " -- "
	2 "|   "
	3 "   |"
	4 "|  |"
*/
	string str;
	if (linetype == 0) {
		str = ' ' + string(s, ' ') + ' ';
	} else if (linetype == 1) {
		str = ' ' + string(s, '-') + ' ';
	} else if (linetype == 2) {
		str = '|' + string(s, ' ') + ' ';
	} else if (linetype == 3) {
		str = ' ' + string(s, ' ') + '|';
	} else if (linetype == 4) {
		str = '|' + string(s, ' ') + '|';
	} 

	return str;
}

int check_linetype(int number, int line, int s) {
	if (line == 0) {
		if (number==1 || number==4) {
			return 0;
		} else {
			return 1;
		}
	} else if (line < s+1) {
		if (number==5 || number==6) {
			return 2;
		} else if (number==1 || number==2 || number==3 || number==7) {
			return 3;
		} else {
			return 4;
		}
	} else if (line == s+1) {
		if (number==1 || number==7 || number==0) {
			return 0;
		} else {
			return 1;	
		}
	} else if (line < 2*s+2) {
		if (number==2) {
			return 2;
		} else if (number==6 || number==8 || number==0) {
			return 4;
		} else {
			return 3;
		}
	} else if (line == 2*s+2) {
		if (number==1 || number==4 || number==7) {
			return 0;
		} else {
			return 1;
		}	
	}

}
		

int main() {

	int s, num;
	cin >> s >> num;
	while (s!=0) {
		// Print row by row
		for (int line = 0; line < 2*s + 3; line++) {
			// Print number by number
			for (int j = 0; j < length(num); j++) {
				int digit = index(num, j);	
				int linetype = check_linetype(digit, line, s);
				cout << make_linetype(linetype, s);
				if (j != length(num)-1) cout << " ";
			}
			cout << endl; // Go to next line
		}
		cin >> s >> num;
		cout << endl;
	}	
	
	return 0;
}
