#include <iostream>

using namespace std;

int main(void) {

	int i, j;
	
	while (cin >> i >> j) {
		cout << i << " " << j << " ";
	
		int highcount = 1;

		// Make sure that i < j
		if (j < i) {
			int temp = i;
			i = j;
			j = temp;
		}
			
		for (int n=i; n<=j; n++) {
//			cout << n << endl;
			int count = 1;
			unsigned int num = n; // Careful here! int isn't large enough to hold all the values of num we need, but an unsigned int gives us an extra bit to work with.
			while (num != 1) {
				if (num % 2 == 0) {
					num = num/2;
				} else {
					num = num*3 + 1;
				}
//				cout << num << " ";
				count++;
			}	
			if (count > highcount) highcount = count;

//			cout << "Count : " << count << endl;
		}
		// Longest cycle length
		cout << highcount << endl;
	}


	
	return 0;
}
