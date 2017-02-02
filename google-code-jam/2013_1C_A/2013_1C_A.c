#include <stdio.h>

int main(void) {

	FILE *fin = fopen("A-small-practice.in", "r");
	FILE *fout = fopen("output.txt", "w");
	
	int cases;
	fscanf(fin, "%d\n", &cases);

	int c;
	for (c=0; c<cases; c++) {
		char name[100];
		fscanf(fin, "%s%*[^0-9]", name);
		int n;
		fscanf(fin, "%d \n", &n);

		// 
	}

	return 0;
}
