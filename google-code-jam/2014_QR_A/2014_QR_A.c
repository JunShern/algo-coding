#include <stdio.h>

int main(void) {
	int i, T;
	scanf("%d\n", &T);

	for (i=0; i<T; i++) {
		int a1, a2;
		// First answer
		scanf("%d\n", &a1);
		int k, j;
		int row1[4];
		for (k=0; k<4; k++) {
			int ind;
			if (k == a1-1) {
				for (ind = 0; ind < 4; ind++) {
					scanf("%d ", &row1[ind]);
				}
			} else {
				for (ind = 0; ind < 4; ind++) {
					scanf("%*d "); // Scan and ignore
				}
			}	
		}

		// Second answer
		scanf("%d\n", &a2);
		int row2[4];
		for (k=0; k<4; k++) {
			int ind;
			if (k == a2-1) {
				for (ind = 0; ind < 4; ind++) {
					scanf("%d ", &row2[ind]);
				}
			} else {
				for (ind = 0; ind < 4; ind++) {
					scanf("%*d "); // Scan and ignore
				}
			}	
		}
		
		/*			
		printf("First row: ");
		for (k=0; k<4; k++) {
			printf("%d ", row1[k]);
		} printf("\n");
		printf("Second row: ");
		for (k=0; k<4; k++) {
			printf("%d ", row2[k]);
		} printf("\n");
		*/

		// Find numbers in common for row1 and row2
		printf("Case #%d: ", i+1);
		int common = 0;
		int ans;
		for (j=0; j<4; j++) {
			if (common > 1) break;
			for (k=0; k<4; k++) {
				if (row1[j] == row2[k]) {
					ans = row1[j];
					common += 1;
					if (common > 1) {
						printf("Bad magician!\n");
						break;
					}
				}
			}
		}
		if (common == 0) {
			printf("Volunteer cheated!\n");
		} else if (common == 1) {
			printf("%d\n", ans);
		} 
	}
		
	return 0;
}
