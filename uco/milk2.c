/*
ID: unload11
LANG: C
PROG: milk2
*/

#include <stdio.h>
#include <stdbool.h>
		 
struct timerange {
	int start;
	int end;
	struct timerange *next; // Pointer to the next timerange
} ;
typedef struct timerange TIMERANGE;

int main(void) {
	FILE *fin = fopen("milk2.in", "r");
	FILE *fout = fopen("milk2.out", "w");
	
	int N;
	int start;
	int end;
	int i;

	// Get the number of farmers
	fscanf(fin, "%d \n", &N);
	printf("%d\n", N);

	// List of timeranges
	TIMERANGE range[N];
	for (i=0; i<N; i++) {
		range[i].start = -1;
		range[i].end = -1;
	}

	// Get the time ranges
	for (i=0; i<N; i++) {
		fscanf(fin, "%d %d \n", &start, &end);
		range[i].start = start;
		range[i].end = end;
	}	

	// Sort the ranges
	int x, y;
	for (x=0; x<N; x++) {
		for (y=0; y<N-1; y++) {
			if (range[y].start > range[y+1].start) {
				// swap
				TIMERANGE temp = range[y+1];
				range[y+1] = range[y];
				range[y] = temp;
			}
		}	
	}

	// Now let's get into linked lists
	TIMERANGE *root = &range[0]; 	
	for (i=0; i<N-1; i++) {
		// Linking up the array 
		range[i].next = &range[i+1];
	}
	range[N-1].next = NULL; // Tail element has no next element

	TIMERANGE *current;
	
	// Merge overlapping timeranges
	current = root; // Reset pointer
	while (current->next != NULL) { // Loop to second last element
		printf("Current: %d, %d\n", current->start, current->end);
		// While the End intersects following timeranges, keep on merging with all of them!
		while ( (current->end) >= (current->next->start) ) {
			// If we've reached the end of the list
			if (current->next == NULL) 
				break;

			if ( (current->end) < (current->next->end) ) {
				current->end = current->next->end; // reassign the larger end to the merged range
			} else ; // do nothing, current-end is the end of the merged range

			// Merge the ranges
			if (current->next->next == NULL) // If reached the 2nd last element on the list
				break;
			current->next = current->next->next;

		}		

		// Move along to the next range 
		current = current->next;	
	}

	printf("Made it here.\n");
	// Find the longest idle time
	current = root;
	int maxIdle = 0; 
	while (current->next != NULL) {
		if ( (current->next->start - current->end) > maxIdle) {
			maxIdle = current->next->start - current->end; 
		}
		current = current->next;
	}
	printf("The maximum idle time is %d.\n", maxIdle);

	// Find the longest milking time
	current = root;
	int maxMilk = current->end - current->start;
	while (current != NULL) {
		if ( (current->end - current->start) > maxMilk) {
			maxMilk = current->end - current->start;
		}
		current = current->next;
	}
	printf("The maximum milking time is %d.\n", maxMilk);

	// Print to output
	fprintf(fout, "%d %d\n", maxMilk, maxIdle);

	return 0;
}

