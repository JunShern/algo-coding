#include <iostream>
#include <vector>

using namespace std;

int product(int a, int b) {
//	cout << a << " x " << b << endl;
	// Dealing with signs
	if (a < 0 && b < 0) return product(-a, -b); // - and - make +
	if (a < 0) return -product(-a, b); // - and + make -
	if (b < 0) return -product(a, -b); // + and - make -
	// Dealing with simple cases
	if (a == 1) return b;
	if (b == 1) return a;
	if (a == b) return -1;
	// Standard multiplication
	if (a=='i' && b=='j') return (int)'k';
	if (a=='i' && b=='k') return -(int)'j';
	if (a=='j' && b=='i') return -(int)'k';
	if (a=='j' && b=='k') return (int)'i';
	if (a=='k' && b=='i') return (int)'j';
	if (a=='k' && b=='j') return -(int)'i';

//	cout << "Error in product! " << a << ", " << b << endl;
	return 0;
}

int pow(int a, int x) {
	if (x == 1) return a;
	if (a == 1) return 1;
	
	if (x % 4 == 1) {
		return a;
	} else if (x % 4 == 2) {
		return -1;
	} else if (x % 4 == 3) {
		return -a;
	} else if (x % 4 == 0) {
		return 1;
	} else {
//		cout << "Error in pow" << endl;
		return 0;
	}
}

void printVect(const vector<int>& str) {
	for (int i=0; i<str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;
}

bool is_ijk(const vector<int>& longstr) {
//	cout << "Checking if it's \'ijk\'!" << endl;
//	printVect(longstr);	
	int prod, i=0;
	// Keep going until you have 'i'
	prod = 1;
	while (prod != 'i') {
		int next = longstr[i];
		prod = product(prod, next);
		// Move pointer
		i++;
		if (i >= longstr.size()) return false;
	}
//	cout << "Got 'i'!" << endl;
	// Keep going until you have 'j'
	prod = 1;
	while (prod != 'j') {
		int next = longstr[i];
		prod = product(prod, next);
		// Move pointer
		i++;
		if (i >= longstr.size()) return false;
	}
//	cout << "Got 'j'!" << endl;
	// Keep going until the end
	prod = 1;
	while (i < longstr.size()) {
		int next = longstr[i];
		prod = product(prod, next);
		// Move pointer
		i++;
	}
	// Evaluate what we have left
//	cout << "Finishing with... " << prod << endl;
	if (prod == 'k') return true;
	else return false;
}

int main() {
	int T;
	cin >> T;

	for (int t=0; t<T; t++) {
		int L, X;
		cin >> L >> X;
		
		int prod_L = 1;
		char tmp;
		vector<int> string;
		// Read in length L
		for (int l=0; l<L; l++) {
			cin >> tmp;
			int tmp_int = tmp;
			string.push_back(tmp_int);
//			cout << prod_L << " x " << tmp_int << " = ";
			prod_L = product(prod_L, tmp_int);
//			cout << prod_L << endl;
		}

		// Compute prod_L^X
		int prod_total = pow(prod_L, X);
//		cout << "prod_L = " << prod_L << ", X = " << X << endl;
//		cout << "prod_total = " << prod_total << endl;

		// Output and extra computation
		cout << "Case #" << t+1 << ": ";

		if (prod_total != -1) { 
			cout << "NO" << endl; // Not ijk

		} else { 
			// Make the full long string
			vector<int> longstr;
			int ind = 0;
			for (int x=0; x<X; x++) {
				for (int l=0; l<L; l++) {
					longstr.push_back(string[ind%string.size()]);
					ind++;
				}
			}
			// Check if longstr is ijk
			if ( is_ijk(longstr) ) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
//		cout << endl;
	}


	return 0;
}
