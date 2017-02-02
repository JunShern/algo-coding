#include <stdio.h>
#include <string.h>

int isPalin(long long int num) {
	long long int reverse = 0, temp = num;
	
	while (temp != 0) {
		reverse *= 10;
		reverse += temp%10;
		temp /= 10;
	}

	if (reverse == num) {
		return 1;
	} else {
		return 0;
	}
}

	
int main(void) {

	int cases;
	scanf("%d \n", &cases);
	
	long long int boundA, boundB;
	int c;

	for (c=0; c<cases; c++) {
		int count = 0;
		scanf("%lld %lld \n", &boundA, &boundB);
//		printf("Bounds: %d - %d \n", boundA, boundB);

		long long int baby = 0;
		while ( (baby*baby) < boundA ) baby++;

		long long int parent = baby*baby;	
		while ( (parent) <= boundB ) {
			if ( isPalin(baby) == 1 ) {
				if ( isPalin(parent) == 1 ) {
					count++;
//					printf("Parent: %lld, Baby: %lld.\n", parent, baby);
				}
			} 
			// Prepare for next iteration
			baby++;
			parent = baby*baby;
		}	

		printf("Case #%d: %d\n", c+1, count);
		fflush(stdout);
	}		
	return 0;
}

