#include <iostream>

using namespace std;

int main() {
	int a=1, b=2;
	int sum = 2;
	
	while (a+b < 4000000) {
		b = a+b;
		a = b-a;
		if (b%2 == 0) {
			sum += b;
		}
	}
	
	cout << "Sum: " << sum << endl;


	return 0;
}
