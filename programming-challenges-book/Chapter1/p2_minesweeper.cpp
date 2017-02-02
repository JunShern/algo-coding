#include <iostream>

using namespace std;

//int bomb(char *field, char width, int i, int j) {
//	// Make it an asterisk
//	field[i + j*width] = '*';
//}

int main(void) {

	int n, m;
	int field_num = 0;
	while (cin >> n >> m) {
		// Check for end flag
//		cout << "n: " << n << " m: " << m << endl;
		if (n == m && n == 0) {
			break;
		} 

		// Presentation formatting
		if (field_num != 0) cout << endl;

		field_num++;
		
		// First make an n x m field all initialized to 0
		char field[n][m];
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				field[i][j] = '0';
			}
		}

		// Read in the field inputs
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				char symbol;
				cin >> symbol;
				// If a mine is detected
				if (symbol == '*') {
					// Change to Mine symbol
					field[i][j] = '*';
					// Increment surroundings
					for (int a=i-1; a<=i+1; a++) {
						for (int b=j-1; b<=j+1; b++) {	
							// Skip out of bound cases
							if (a<0 || b<0 || a>n-1 || b>m-1) continue;
							// Increment if not a Mine as well
							if (field[a][b] != '*') field[a][b]++;
						}
					}	
				}
			}
		}

		// Print output field
		cout << "Field #" << field_num << ":" << endl;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cout << field[i][j];
			}
			cout << endl;
		}	
	}
		


	return 0;
}

