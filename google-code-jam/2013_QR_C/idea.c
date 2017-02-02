#include <stdio.h>
#include <string.h>

int isPalindrome(long long int num) {
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

	long long int baby = 0;
	int count = 0;
	long long int maxParent = 100000000000000;

	for (baby = 0; baby*baby < maxParent; baby++) {
		long long int parent = baby*baby;	
		if ( isPalindrome(baby) == 1 ) {
			if ( isPalindrome(parent) == 1 ) {
				count++;
				printf("Parent: %lld, Baby: %lld.\n", parent, baby);
			}
		} 
	}
/*
	getchar();
	while (1) {
		printf("Please input baby: ");
		scanf("%lld", &baby);
		long long int parent = baby*baby;
		printf("Parent = %lld\n", parent);
		if ( isPalindrome(parent) == 1) {
			printf("YES!\n");
		} else {
			printf("Nope...\n");
		}
	}
*/
	return 0;
}

