/*
ID: unload11
LANG: C
PROG: beads
*/

#include <stdio.h>
#include <string.h>

int collectAt(const char oriNecklace[], int N, int index);
void seekIndices(char necklace[], int N, int *indices);

int main(void) {
	FILE *fin = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");

	int N;
	fscanf(fin, "%d \n", &N);
	
	char necklace[N+1];
	fscanf(fin, "%s", necklace);

	int ind = 0;
	int collected;
	int highestCollected;

	// Get the indices of interest
	int indices[N+1]; // arbitrary size N is definitely more than large enough
	seekIndices(necklace, N, indices);

	// If all the letters are the same
	if (indices[0] == -1) {
		indices[0] = 0;
		indices[1] = -1;
		
		highestCollected = N;
	}
/*
	int i;
	while (indices[i]!=-1) {
		printf("%d\n", indices[i]);
		i++;
	}
*/
	// Find the highest collection of all indices

	while ((indices[ind] != -1) && (indices[1] != -1)) {
		printf("\nWe are now looking at index %d.\n", indices[ind]);
		collected = collectAt(necklace, N, indices[ind]);
		if (collected > highestCollected) {
			highestCollected = collected;
		}
		ind++;
	}

	printf("%d\n", highestCollected);
	fprintf(fout, "%d\n", highestCollected);

	return 0;
}

void seekIndices(char necklace[], int N, int *indices) {
	int i = 0;
	int ind = 0;
	char currentColour;
	char previousColour = necklace[N-1];
	for (i=0; i<N; i++) {
		currentColour = necklace[i];
		if (currentColour != previousColour) {
			indices[ind] = i;
			ind++;
		}
		previousColour = currentColour;
	}
	
	indices[ind] = -1; // flag to indicate end of usable indices
}

int collectAt(const char oriNecklace[], int N, int index) {
	char necklace[N+1];
	strcpy(necklace, oriNecklace); 
	int i = index;
	int k;
	if (index==0) {
		k = N-1; //-1; // extra -1 for EOL
	} else {
		k = index - 1;
	}

	int nc1 = 0;
	int nc2 = 0;

	// For special cases STARTING with 'w', change 'w' to the nearest non-'w' colour
	if (necklace[i]=='w') {
		int iTemp = i;
		while (necklace[iTemp]=='w') {
			// increment the index
			if (iTemp==N-1/*-1*/) {
				iTemp = 0;
			} else {
				iTemp++;
			}
		}
		necklace[i] = necklace[iTemp];
	} else if (necklace[k]=='w') {
		int kTemp = k;
		while (necklace[kTemp]=='w') {
			// increment the index
			if (kTemp==0) {
				kTemp = N-1/*-1*/;
			} else {
				kTemp--;
			}
		}
		necklace[k] = necklace[kTemp];
	} 

	char colour1 = necklace[i];
	char colour2 = necklace[k]; 

	printf("Index %d is %c, index %d is %c.", i, colour1, k, colour2);

	while ( (necklace[i] == colour1) || (necklace[i] == 'w') ) {
		if (necklace[i] == 'w') {
			necklace[i] = colour1;
		}
		nc1 += 1;

		// increment the index
		if (i==N-1/*-1*/) {
			i = 0;
		} else {
			i++;
		}
	}
	printf("Found %d %c beads!\n", nc1, colour1);

	while ( (necklace[k] == colour2) || (necklace[k] == 'w') ) {
		if (necklace[k] == 'w') {
			necklace[k] = colour2;
		}
		nc2 += 1;
		
		// increment the index
		if (k==0) {
			k = N-1/*-1*/;
		} else {
			k--;
		} 
	}

	printf("Found %d %c beads!\n", nc2, colour2);

	int answer = nc1 + nc2;
	printf("Collecting from %s at index %d, we get %d.\n", oriNecklace, index, answer);

	return (answer);
}
		
