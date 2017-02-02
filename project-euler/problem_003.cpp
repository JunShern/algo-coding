#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(double n) {
	for (double i=2; i<n/2; i++) {
		if (fmod(n,i) == 0) {
			return false;
		}
	} 
	return true;
}

int main() {

	double num = 600851475143;
	double upper = num;
	double largest = 0;
	for (double i=2; i<upper; i++) {
		if (fmod(num,i) == 0) {
			if (isPrime(i)) {
				cout << i << " is Prime!" << endl;
				if (i > largest) largest = i;
			}
			if (isPrime(num/i)) {
				cout << num/i << " is Prime!" << endl;
				if (num/i > largest) largest = num/i;
			}
			upper = num/i;
		}
	}
	cout << "Largest is " << largest << endl;

	return 0;
}
