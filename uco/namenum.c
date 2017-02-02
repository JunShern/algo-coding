/*
ID: unload11
LANG: C
PROG: namenum
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkCompatibility(FILE *fout, char serial[], char name[]) {
	char nameNum[13];
	int i = 0;
	while (name[i] != '\0') {
		char c = name[i];
		if (c == 'A' || c == 'B' || c == 'C') {
			nameNum[i] = '2';
		} else if (c == 'D' || c == 'E' || c == 'F') {
			nameNum[i] = '3';
		} else if (c == 'G' || c == 'H' || c == 'I') {
			nameNum[i] = '4';
		} else if (c == 'J' || c == 'K' || c == 'L') {
			nameNum[i] = '5';
		} else if (c == 'M' || c == 'N' || c == 'O') {
			nameNum[i] = '6';
		} else if (c == 'P' || c == 'R' || c == 'S') {
			nameNum[i] = '7';
		} else if (c == 'T' || c == 'U' || c == 'V') {
			nameNum[i] = '8';
		} else if (c == 'W' || c == 'X' || c == 'Y') {
			nameNum[i] = '9';
		} else {
			printf("Invalid character %c!\n", c);
		}
		i++;
	}
	nameNum[i] = '\0';
	printf("nameNum is %s, serial is %s.\n", nameNum, serial);
	if (strcmp(nameNum, serial) == 0) {
		printf("Compatible!\n");
		getchar();
		fprintf(fout, "%s\n", name);
		return true;
	} else {
		printf("Not compatible!\n");
		return false;
	}
}

int main(void) {
	// Open files
	FILE *fin = fopen("namenum.in", "r");
	FILE *dict = fopen("dict.txt", "r");
	FILE *fout = fopen("namenum.out", "w");

	if (fin == NULL) {
		printf("Input file error!\n");
		return 0;
	}

	// Program start
	char serial[13];
	fscanf(fin, "%s", serial);	
	printf("The serial number %s can generate these names:\n", serial);
	
	char name[13];
	bool found = false;
	while (fscanf(dict, "%s\n", name) != EOF) {
		printf("Checking compatibility of %s with %s.\n", name, serial);
		if (checkCompatibility(fout, serial, name) == true) {
			found = true;
		}
	}
	if (!(found)) {
		printf("None are compatible. :(\n");
		fprintf(fout, "NONE\n");
	}
	//  Closing
	fclose(fin);
	fclose(fout);
	fclose(dict);
	return 0;
}

