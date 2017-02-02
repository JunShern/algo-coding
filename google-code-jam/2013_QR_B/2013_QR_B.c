#include <stdio.h>

int crossCheck(int c, int i, int j, int n, int m, int lawn[n][m]) {
	int height = lawn[i][j];
	int x;
	//  Check horizontal row
	int possible = 1;
	for (x=0; x<m; x++) {
		if ( lawn[i][x] > height ) {
			possible = 0;
		}
	}
	if (possible == 1) {
		return 1;
	}
		
	//  Check vertical column
	possible = 1;
	for (x=0; x<n; x++) {
		if ( lawn[x][j] > height ) {
			possible = 0;
		}
	}
	if (possible == 1) {
		return 1;
	}
		
	return 0;
}

int main(void) {

	FILE *fin = fopen("B-large-practice.in", "r");
	FILE *fout  = fopen("output.txt", "w");

	int cases;
	fscanf(fin, "%d\n", &cases);
	
	int c;
	for (c=0; c<cases; c++) {
		
		// Get dimensions of the lawn
		int n, m;
		fscanf(fin, "%d\n", &n);
		fscanf(fin, "%d\n", &m);
		printf("n : %d, m : %d\n", n, m);
		
		// Read into a two-dimensional array
		int lawn[n][m];
		int i, j;
		for (i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				fscanf(fin, "%d\n", &lawn[i][j]);
			}
		}

		// Print array to check
		for (i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				printf("%d", lawn[i][j]);
			}
			printf("\n");
		}
		
		printf("Case #%d: ", c+1);
		fprintf(fout, "Case #%d: ", c+1);

		// Find the smallest height
		int possible = 1;
		for (i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				if (crossCheck(c,i,j,n,m,lawn)==0) {
					possible = 0;
				}
			}
		}
		if (possible == 1) {
			printf("YES\n");
			fprintf(fout, "YES\n");
		} else { 
			printf("NO\n");
			fprintf(fout, "NO\n");
		}

		// Debug
		printf("\n");
		
	}
	return 0;
}
