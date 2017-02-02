#include <stdio.h>
#define MAX 1000000

void sieve(double array[]) {
	int i;
	for (i=2; i<MAX; i++) { 
		if (array[i] != 0) { // If it hasn't already been Sieved
			int j = 2;	
			// Sieve out all multiples of (i)
			while (i * j < MAX) {
				array[i*j] = 0;
				j++;
			}
		}
	}
}
	
int main(void) {
	double numbers[MAX], primes[10001];
	int i, j = 0;
	// Populate the array	
	for (i=0; i<MAX; i++) {
		numbers[i] = i;
	}
	// Sieve the array
	sieve(numbers);
	// Put non-zero elements of sieved (numbers) into (primes)
	for (i=2; i<MAX; i++) {
		if (numbers[i] != 0) {
			printf("Prime number %d: %.0f\n", j, numbers[i]);
			primes[j] = numbers[i];
			if (j==10000) {
				break;
			}
			j++;
		}
	}
	
	printf("The 10001st prime is %f.\n", primes[10000]);
	return 0;	
}
