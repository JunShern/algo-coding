#include <stdio.h>

int main(void) {
	int i, j, k, T;
	scanf("%d\n", &T);

	for (i=0; i<T; i++) {
		int r, c, mines;
		scanf("%d %d %d\n", &r, &c, &mines);
		int smallSide;
		if (r < c) {
			smallSide = r;
		} else {
			smallSide = c;
		}	
		
		if (mines == 0) {
			printf("Possible\n");
		} else if ( (r*c)-mines == 1 ) {
			printf("Definitely possible.\n");
		} else if (smallSide == 1) {
			printf("Possible.\n");
		} else if ( (r*c)-mines == 2 ) {
			printf("Impossible.\n");
		} else if (r == 2 || c == 2) {
			if (mines%2==0) {
				printf("Possible.\n");
			}
		} else if ( ((r*c)-mines)%2==0 || (r*c)-mines==9 ) {
			printf("Possible\n");
		}
	}
		
	return 0;
}
