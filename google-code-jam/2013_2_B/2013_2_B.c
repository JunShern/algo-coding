#include <stdio.h>
#include <math.h>

int bestPrize(int N) {
	int i;
	int bp = 0;
	for (i=0; i<N; i++) {
		bp += pow(2, i);
	}
	return bp;
}
		
void binary(int N, char* bString) {
	int i=0;
	// Fill bString with a backward binary representation
	while (N) {
		if (N & 1) { // as long as the bitwise AND does not give '0000'
			bString[i] = '1';
		}
		else {
			bString[i] = '0';
		}
		N >>= 1;
		i++;
	}

	// Mirror the binary string to get the correct binary
	int k = 0;
	int len = i;
	for (k=0; k<len/2; k++) { // Swap 
		char temp = bString[k];
		bString[k] = bString[len-k-1];
		bString[len-k-1] = temp;
	}

	bString[len] = '\0';
}

int countWins(int n) {
	int wins = 0;
	int N = n;
	while (N) {
		if (N & 1) wins++;
		N >>= 1;
	}
	char bString[100];
	binary(n, bString);
//	printf("%s has %d wins.\n", bString, wins);	
	return wins;
}

int easiestPrize(int bp, int wp) {
	int ep = bp;
	int wins = countWins(ep);
	int i;
	for (i=1; i<=bp-wp; i++) {
		if (countWins(bp-i) < wins) {
			ep = bp-i;
		}
	}
	return ep;
}

int main(void) {

	// PART ONE - Calculating the minimum wins needed to get a prize
	int N = 3;
	int P = 3;

	int bp = bestPrize(N);
	int wp = bp - P + 1;
	int ep = easiestPrize(bp, wp); // find the easiest prize between the range bp and wp

	char bp0b[100];
	binary(bp, bp0b);
	char wp0b[100]; 
	binary(wp, wp0b);
	char ep0b[100];
	binary(ep, ep0b);
	printf("Best: %s, Worst: %s, Easiest: %s\n", bp0b, wp0b, ep0b);

	int minWins = countWins(ep);
	printf("To win a prize, a minimum of %d wins is required.\n", minWins);

	// PART TWO - Finding the larget-numbered team that is guaranteed to win a prize


	// PART THREE - Finding the largest-numbered team that could win a prize		
	int z;
	z = (pow(2,N) - 1) - (2*minWins - 1);
	printf("The largest-numbered team that could win a prize is %d.\n", z);
 
	return 0;
}
