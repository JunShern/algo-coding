#include <stdio.h>

#define arrSize 10 // 2D array, each this size so > 10^9

int T; // number of test cases
int N; // number of stations
int M; // number of pairs

int x(index) {
	return (index-index%arrSize)/arrSize;
}
int y(index) {
	return index%arrSize;
}

int sumUpTo(int n) {
	return ((n-1)*n)/2;
}

int cumuPrice(int dist) {
	return (dist*N) - sumUpTo(dist);
}

int sumArray(int array[], int N) {
	int i, sum=0;
	for (i=0; i<N; i++) {
		sum += array[i];
	}	
	return sum;
}

void printStations(int N, int enter[], int exit[]) {
	int i;
	for (i=0; i<N; i++) {
		printf("%d\t", enter[i]);
	}
	printf(" = %d\n", sumArray(enter, N) );
	for (i=0; i<N; i++) {
		printf("%d\t", exit[i]);
	}
	printf(" = %d\n", sumArray(exit, N) );
}	

int main(void) {

	FILE *fin = fopen("A-small-practice.in", "r");
	
	fscanf(fin, "%d\n", &T);
//	printf("%d cases.\n", T);
	int c, i, in, out, people;
	for (c=0; c<T; c++) {
		printf("Case #%d: ", c+1);
		fscanf(fin, "%d %d\n", &N, &M);
//		printf("Stations, N = %d, Pairs, M = %d\n", N, M);
//		getchar();	
		int legalRev = 0;
		int totalPeople = 0;	

		// Make arrays for the number of entrees and exitees at each station
		int enter[100] = {0};
		int exit[100] = {0};
		
		for (i=0; i<M; i++) {
			fscanf(fin, "%d %d %d\n", &in, &out, &people);
			enter[in] += people;
			exit[out] += people;	
			totalPeople += people;
			// Calculate "legal" revenue
			legalRev += people * cumuPrice(out-in);				
		}

		// Print to check
//		printStations(N, enter, exit);

		
		int swapRev = 0;
		i = 0;
//		printf("Total people = %d\n", totalPeople);
		while (i<totalPeople) {
//			printf("Current count = %d // %d\n", i, totalPeople);
			int firstEn = 0, secondEn, lastEn = N-1;
			int firstEx = 0, lastEx = N-1, secondLastEx, closestEx;

			// Set indices at the right positions
			while (enter[lastEn] == 0) lastEn--;	
			
			// Settle lastEn with the closest exits possible
			closestEx = lastEn;
			int nSettle; // Number of people we can settle in each iteration 
			while (enter[lastEn] != 0) {
				while (exit[closestEx] == 0) closestEx++; // Move the (closestEx) index to the closest non-zero exit
				if (enter[lastEn] > exit[closestEx]) { 
					nSettle = exit[closestEx]; 
				} else {
					nSettle = enter[lastEn];
				}
				enter[lastEn] -= nSettle;
				exit[closestEx] -= nSettle;
				swapRev += nSettle * cumuPrice(closestEx - lastEn);
/*
				printf("nSettle = %d\n", nSettle);
				printf("distance = %d\n", closestEx - lastEn);
				printf("cumuPrice = %d\n", cumuPrice(closestEx - lastEn));
				printf("Swap revenue += %d = %d\n", nSettle * cumuPrice(closestEx - lastEn), swapRev);
*/
				// Check
/*				printStations(N, enter, exit);
				getchar();
*/
				i += nSettle;
			}

		}
/*
		printf("Legal revenue = %d\n", legalRev);

		printf("Swap revenue = %d\n", swapRev);

		printf("City financial loss = %d\n", legalRev - swapRev);
*/
		printf("%d\n", legalRev - swapRev);

	}

	return 0;
}
