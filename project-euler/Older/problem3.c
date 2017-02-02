#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(double num) {
	double i;
	for (i = 2; i < num/2; i++ ) {
		if (fmod(num,i) == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	double f, number = 600851475143;

	for (f = 2; f < number/2; f++) {
		if ( fmod(number,f) == 0 ) {
			printf("%.2f is %.0f/%.0f.\n", number/f, number, f);
			if (isPrime(number/f)) {
				printf("The answer is %.2f.\n", number/f);
				break;
			}
		}
	}
	return 0;
}
	
	
