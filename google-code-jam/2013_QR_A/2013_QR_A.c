#include <stdio.h>

int check(char (symbols)[4][4]) {
	// 1 - X won
	// 2 - O won
	// 3 - Draw
	// 4 - Game has not completed

	// Check for wins in all possible lines
	// Horizontal lines
	int i, j;
	for (i=0; i<4; i++) {
		int countX = 0, countO = 0, countT = 0;
		for (j=0; j<4; j++) {
			switch (symbols[i][j]) {
				case 'X' :
					countX += 1;
					break;
				case 'O' :
					countO += 1;
					break;
				case 'T' :
					countT += 1;
					break;
				default :
					break;
			}
		}
		if ( countX + countT == 4 ) {
			return 1;	
		} else if ( countO + countT == 4 ) {
			return 2;
		}
	}
	// Vertical lines 
	for (j=0; j<4; j++) {
		int countX = 0, countO = 0, countT = 0;
		for (i=0; i<4; i++) {
			switch (symbols[i][j]) {
				case 'X' :
					countX += 1;
					break;
				case 'O' :
					countO += 1;
					break;
				case 'T' :
					countT += 1;
					break;
				default :
					break;
			}
		}
		if ( countX + countT == 4 ) {
			return 1;	
		} else if ( countO + countT == 4 ) {
			return 2;
		}
	}
	// Upper left to lower right diagonal
	int countX = 0, countO = 0, countT = 0;
	for (i=0; i<4; i++) {
		switch (symbols[i][i]) {
			case 'X' :
				countX += 1;
				break;
			case 'O' :
				countO += 1;
				break;
			case 'T' :
				countT += 1;
				break;
			default :
				break;
		}
		if ( countX + countT == 4 ) {
			return 1;	
		} else if ( countO + countT == 4 ) {
			return 2;
		}
	}
	// Lower left to upper right diagonal
	countX = 0, countO = 0, countT = 0;
	for (i=0; i<4; i++) {
		switch (symbols[i][3-i]) {
			case 'X' :
				countX += 1;
				break;
			case 'O' :
				countO += 1;
				break;
			case 'T' :
				countT += 1;
				break;
			default :
				break;
		}
		if ( countX + countT == 4 ) {
			return 1;	
		} else if ( countO + countT == 4 ) {
			return 2;
		}
	}

	// Check for '.' - if yes, game incomplete
	for (i=0; i<4; i++) {
		for (j=0; j<4; j++) {
			if (symbols[i][j] == '.') {
				return 4;
			}	
		}
	}
	// Otherwise, draw
	return 3;
}

int main(void) {
	FILE *fin = fopen("A-large-practice.in", "r");
	FILE *fout = fopen("output.txt", "w");
	
	int cases = 0;
	fscanf(fin, "%d\n", &cases);
	
	int c;
	for (c=0; c<cases; c++) {
		char symbols[4][4]; 

		// Pack each line into an array of chars
		int i, j;
		for (i=0; i<4; i++) {
			for (j=0; j<4; j++) {
				fscanf(fin, "%c\n", &symbols[i][j]);
			}
		}

		// Print array to check
		for (i=0; i<4; i++) {
			for (j=0; j<4; j++) {
				printf("%c", symbols[i][j]);
			}
			printf("\n");
		}

		fprintf(fout, "Case #%d: ", c+1);
		printf("Case #%d: ", c+1);

		int result = check(symbols);
	
		switch (result) {
			case 1 : 
				fprintf(fout, "X won\n");
				printf("X won\n");
				break;	
			case 2 :
				fprintf(fout, "O won\n");
				printf("O won\n");
				break;
			case 3 :
				fprintf(fout, "Draw\n");
				printf("Draw\n");
				break;
			case 4 :
				fprintf(fout, "Game has not completed\n");
				printf("Game has not completed\n");
				break;
		}
		printf("\n");
	}
	
	return 0;
}
	
