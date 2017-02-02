/*
ID: unload11
LANG: C
PROG: namenum
*/

#include <stdio.h>

int main(void) {
	FILE *fin = fopen("namenum.in", "r");
	FILE *fout = fopen("namenum.out", "w");

	fclose(fin);
	fclose(fout);
	return 0;
}

