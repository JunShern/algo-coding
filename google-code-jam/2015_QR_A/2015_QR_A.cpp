#include <iostream>

using namespace std;


int countDigits(int num) {
	int width = 1;
	while ( (num/=10) > 0) width++;
	return width;
}


int main() {

	int T;
	cin >> T;
	for (int t=0; t<T; t++) {
		int S_max;
		cin >> S_max;

//		char space;
//		cin >> space; // Discard space

//		cout << "Case " << t << endl;
		// Read string and accumulate sum
		int sum = 0, answer = 0;
		for (int s=0; s<S_max+1; s++) {
			char digit_c;
			cin >> digit_c;
			int digit = digit_c - 48; // Convert char to int
			
//			cout << "Digit=" << digit << ", s=" << s << ", sum=" << sum << endl;
			// Logic
			if (sum >= s) {
				sum += digit;
			} else {
				int diff = s-sum;
				sum += digit + diff;
				answer += diff;
			}
		}

		// Output
		cout << "Case #" << t+1 << ": " << answer << endl;
	}

	return 0;
}
