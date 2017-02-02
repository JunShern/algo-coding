#include <stdio.h>
#include <stdbool.h>
#define DLENGTH	1000000 

void expandSpiral(int diagonals[], int *sideLen, int *lastIndex) {
	int i;
	int layers = (*sideLen+1)/2;
	int inc = *sideLen + 1;
	
	for (i=0; i<4; i++) { // add four corners
		*lastIndex += 1;
		diagonals[*lastIndex] = diagonals[*lastIndex-1] + inc;
	}
	
	*sideLen += 2;
	
	return;
}
				
bool isPrime(int number) {
	if (number<=1) return false; // zero and one not prime
	int i;
	for (i=2; i*i<=number; i++) {
		if (number % i == 0) return false;
	}
	return true;
}

int main(void) {
	int diagonals[DLENGTH]; 
	int i; 
	int k;
	int sideLen = 1;
	int lastIndex = 0; // 1 is already counted in
	int primeCount = 0;
	float pp;

	// Fill up the array with default values 
	for (i=0; i<DLENGTH; i++) {
		diagonals[i] = -1;
	}

	// Start with 1
	diagonals[0] = 1;

	// Expand it three times to start with the given spiral
	while (true) {
		expandSpiral(diagonals, &sideLen, &lastIndex);
		// Check the four new corners for primeness
		for (k=0; k<4; k++) {
			if (isPrime(diagonals[lastIndex-k])) 
				primeCount++;
		}
		// Calculate % of primes
		pp = (float) primeCount/(lastIndex+1);
		printf("%d: %d, %d\n", sideLen, primeCount, (lastIndex+1));
		printf("%f\n", pp);

		if (pp<0.1) {
			printf("Side Length = %d\n", sideLen);
			break;
		}
	}
/*
	// Print out all the diagonals so far
	for (i=0; i<=lastIndex; i++) {
		printf("%d\n", diagonals[i]);
	}	
*/
	return 0;
}	
