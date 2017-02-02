#include <stdio.h>
#include <stdbool.h>
#include <math.h> // Need to compile with -lm on Ubuntu

int findLen(double i) {
	int len = 1;

	while (i > 9) {
		len++;
		i /= 10;
	}
	return len;
}
	
bool powIsLen(int i, int p) {
	double result = pow(i,p);
	int len = findLen(result);
	if (p == len) 
		return true;
	else 
		return false;
}

int main(void) {

	int i;
	int p = 1;
	int count = 0;
	for (i=1; i<100; i++) {
		p = 1;
		while (powIsLen(i,p)) {
			printf("%d, %d, Count: %d\n", i, p, count);
			count++;
			p++;
		}	
	}
	count--; // Be careful, the count increments an extra one time!
	printf("The count is %d.\n", count);
	
	if (powIsLen(7,5)) {
		printf("7power5 yes!\n");	
	}
	return 0;
}
