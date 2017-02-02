#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int GCD(int a, int b) {
	int c = 1; // Arbitrary non-zero value
	assert(a >= b);
	//printf("The GCD of %d and %d is ", a, b);
	while (c!=0) {
		c = a % b;
		if (c==0) break;
		a = b;
		b = c;
	}
	return b;
}

bool relPrime(int a, int b) {
	if (GCD(a, b) == 1) {
		return true;
	} else return false;
}

int totient(int n) {
	int i;
	int tot = 0;
	for (i=1; i<n; i++) {
		if (relPrime(n, i)) {
			tot++;
		}
	}
	return tot;
}

float ntot(int n) {
	return (float) n/totient(n);
}

int main(void) {
	int i;
	int maxN = 1;
	float maxVal = 0;
	for (i=30030; i<1000000; i+=30030) {
		float nt = ntot(i);
		printf("%d: %f\n", i, nt);
		if (nt>maxVal) {
			maxVal = nt;
			maxN = i;
		}
	}
	printf("MaxN = %d, MaxVal = %f\n", maxN, maxVal);
}
	
