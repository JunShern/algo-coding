#include <stdio.h>
#include <string.h>

int isPalin(int num) {
	// Convert num to string
	char string[100000];
	sprintf(string, "%d", num);

	// Find length of String
	int len = strlen(string);
	if (len == 1) {
		return 1;
	}

	// Make two strings to hold the halves
	int size;
	if (len % 2 == 0) { // Even numbers
		size = len/2;
	} else { 
		size = (len-1)/2; // Odd numbers
	}
	char str1[size+1], str2[size+1]; // plus one for null character
	
	// Copy halves into two strings
	if (len % 2 == 0) { // Even
		memcpy(str1, string, size);
		str1[size] = '\0';
		memcpy(str2, string+size, size);
		str2[size] = '\0';
	} else { // Odd
		memcpy(str1, string, size);
		str1[size] = '\0';
		memcpy(str2, string+size+1, size); // Plus one, ignore middle char for odd numbers
		str2[size] = '\0';
	}

	// Reverse str2
	int i, len2 = strlen(str2);
	for (i=0; i<len2/2; i++) {
		char temp = str2[i];
		str2[i] = str2[len2-1-i];
		str2[len2-1-i] = temp;
	}
	
//	printf("str1 : %s, Str2 : %s.\n", str1, str2);
	// Convert str1 and str2 to numbers
	char *ptr;
	int num1 = strtol(str1, ptr, 10);
	int num2 = strtol(str2, ptr, 10);

//	printf("num1 = %d, num2 = %d.\n", num2, num2);
	// Check if they are equal
	if (num1 - num2 == 0) {
		return 1;
	} else {
		return 0;
	}
}
	
int main(void) {

	int cases;
	scanf("%d \n", &cases);
	
	int boundA, boundB;
	int c;

	for (c=0; c<cases; c++) {
		int count = 0;
		scanf("%d %d \n", &boundA, &boundB);
//		printf("Bounds: %d - %d \n", boundA, boundB);

		int baby = 0;
		while ( (baby*baby) < boundA ) baby++;

		int parent = baby*baby;	
		while ( (parent) <= boundB ) {
			if ( isPalin(baby) == 1 ) {
				if ( isPalin(parent) == 1 ) {
					count++;
				}
			} 
			// Prepare for next iteration
			baby++;
			parent = baby*baby;
		}	

		printf("Case #%d: %d\n", c+1, count);
	}		
	return 0;
}

