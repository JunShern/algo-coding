#include <stdio.h>	

int main(void) {	
	int i;
	// Part One - Create A Database by Frequency Analysis
	FILE *data = fopen("data.txt", "r");
	int alphaCount[26];
	while (fscanf(data, "%c", 


	int cmap[150];
	for (i=97; i<123; i++) {
		cmap[i] = 'b';
	}
	cmap[' '] = ' ';
	cmap['\n'] = '\n';

	// Part Two - Translate
	int T;
	scanf("%d\n", &T);

	char c;
	for (i=0; i<T; i++) {
		while (scanf("%c", &c)) {
			printf("%c", cmap[c]);
			if (c == '\n') break;
		}
	}
	
	return 0;
}
