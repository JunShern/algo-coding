#include <iostream>

using namespace std;

int main(void) {

	int n_students;
	cin >> n_students;
	while (n_students != 0) {
		// Read in expenses
		float expenses[n_students], total = 0;
		for (int i=0; i<n_students; i++) {
			cin >> expenses[i];
			total += expenses[i];
		}

		// Calculate mean cost
		float mean = total / n_students;
		
		// Calculate money exchanged
		float exchange = 0;
		for (int i=0; i<n_students; i++) {
			// Use absolute instead!
			if (mean > expenses[i]) {
				exchange += mean - expenses[i];
			} else {
				exchange += expenses[i] - mean;
			}
		}
		float answer = exchange/2;
		cout << "$" << answer << endl;
		
		cin >> n_students;
	}

	return 0;
}
