/*
ID: unload11
LANG: C
PROG: palsquare
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char string[]) {
	char reverse[10];
	int len = 0;
	while (string[len] != '\0') {
		len++;
	}
	int i;	
	for (i=0; i<len; i++) {
		reverse[i] = string[len-i-1];
		//printf("%c\n", string[len-i-1]);
	}
	reverse[i] = '\0';
	//printf("String is %s, reverse is %s.\n", string, reverse);
	if (strcmp(string, reverse) == 0) {
		return true;
	} else {
		return false;
	}
}
		
void convertBase(int num, int base, char numString[]) {
	char digits[20] = {'0','1','2','3','4','5','6','7','8','9',
			'A','B','C','D','E','F','G','H','I','J'};
	int index = 0;
	int i = 0;
	int convertedNum[10];
	// Convert
	while (num != 0) {
		convertedNum[index] = num % base;
		num = num/base;
		index++;
	}

	// Print result (reverse order)
	--index; 
	//printf("\n\nConverted Number:\n");
	for (; index>=0; index--) {
		//printf("%c", digits[convertedNum[index]]);
		numString[i] = digits[convertedNum[index]];
		i++;
	}
	numString[i] = '\0';
	//printf("\n");
}
	

int main(void) {
	FILE *fin = fopen("palsquare.in", "r");
	FILE *fout = fopen("palsquare.out", "w");
	int n = 1;
	
	int base;
	fscanf(fin, "%d", &base);

	for (n=1; n<=300; n++) {
		char numString[10];
		convertBase(n*n, base, numString);
		if (isPalindrome(numString)) {
			fprintf(fout, "%d %s\n", n, numString);
			printf("%d %s\n", n, numString);
		}
	}

	// Closing
	fclose(fin);
	fclose(fout);
	return 0;
}

