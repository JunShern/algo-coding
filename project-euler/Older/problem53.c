#include <stdio.h>

double factorial(double n) {
	if (n==0) {
		return 1;
	}
	return n*factorial(n-1);
}

double choose(double n, double r) {
	double ans;
	ans = factorial(n) / ( factorial(r)*factorial(n-r));
	return ans;
}

double valuesAboveMil(int n) {
	int count = 0;
	int d = 1;
	// Even numbers here please!
	if (n%2==0) { 
		// Base case: None above a million
		if (choose(n,n/2)<1000000) 
			return count;	
		else count += 1;
		// Non-base cases
		while (1) {
			if (choose(n, (n/2)-d)>1000000) 
				count += 2; 
			else return count;
			d++;
		} 
	}
	// Odd numbers here!
	else {
		// Base case:
		if (choose(n, (n-1)/2) < 1000000)
			return count;
		else count += 2;
		// Non-base cases
		while (1) {
			if (choose(n, ((n-1)/2)-d) > 1000000) 
				count += 2;
			else return count;
			d++;
		}
	}
}
				
int main(void) {
	int i;
	int count = 0;
	for (i=1; i<=100; i++) {
		printf("n = %d\n", i);
		count += valuesAboveMil(i);
	}	
	printf("Count: %d\n", count);
	return 0;
}
