#include <stdio.h>
#include <math.h>

#define arrSize 1000 // 2D array, each this size so > 10^9

double T; // number of test cases
double N; // number of stations
double M; // number of pairs

int x(float index) {
	return (index-fmod(index,arrSize))/arrSize;
}
int y(float index) {
	return fmod(index,arrSize);
}

double sumUpTo(double n) {
	return ((n-1)*n)/2;
}

double cumuPrice(double dist) {
	return (dist*N) - sumUpTo(dist);
}

double sumArray(double array[arrSize][arrSize], double N) {
	int i, sum=0;
	for (i=0; i<N; i++) {
		sum += array[x(i)][y(i)];
	}	
	return sum;
}

void printStations(double N, double enter[arrSize][arrSize], double exit[arrSize][arrSize]) {
	int i;
	for (i=0; i<N; i++) {
		printf("%.0f\t", enter[x(i)][y(i)]);
	}
	printf(" = %.0f\n", sumArray(enter, N) );
	for (i=0; i<N; i++) {
		printf("%.0f\t", exit[x(i)][y(i)]);
	}
	printf(" = %.0f\n", sumArray(exit, N) );
}	

int main(void) {

	FILE *fin = fopen("A-small-practice.in", "r");
	
	fscanf(fin, "%lf\n", &T);
//	printf("%f cases.\n", T);
	double c, i, in, out, people;
	for (c=0; c<T; c++) {
		printf("Case #%.0f: ", c+1);
		fscanf(fin, "%lf %lf\n", &N, &M);
//		printf("Stations, N = %.0f, Pairs, M = %.0f\n", N, M);
//		getchar();	
		double legalRev = 0;
		double totalPeople = 0;	

		// Make arrays for the number of entrees and exitees at each station
		double enter[arrSize][arrSize] = {{0}};
		double exit[arrSize][arrSize] = {{0}};
		
		for (i=0; i<M; i++) {
			fscanf(fin, "%lf %lf %lf \n", &in, &out, &people);
//			printf("%.0f %.0f %.0f\n", in, out, people);
			enter[x(in-1)][y(in-1)] += people;
			exit[x(out-1)][y(out-1)] += people;	
			totalPeople += people;
			// Calculate "legal" revenue
			legalRev += people * cumuPrice(out-in);				
		}

		// Print to check
//		printStations(N, enter, exit);

		
		double swapRev = 0;
		i = 0;
//		printf("Total people = %.0f\n", totalPeople);
		while (i<totalPeople) {
//			printf("Current count = %.0f // %.0f\n", i, totalPeople);
			double firstEn = 0, secondEn, lastEn = N-1;
			double firstEx = 0, lastEx = N-1, secondLastEx, closestEx;

			// Set indices at the right positions
			while (enter[x(lastEn)][y(lastEn)] == 0) lastEn--;	
			
			// Settle lastEn with the closest exits possible
			closestEx = lastEn;
			double nSettle; // Number of people we can settle in each iteration 
			while (enter[x(lastEn)][y(lastEn)] != 0) {
				while (exit[x(closestEx)][y(closestEx)] == 0) closestEx++; // Move the (closestEx) index to the closest non-zero exit
				if (enter[x(lastEn)][y(lastEn)] > exit[x(closestEx)][y(closestEx)]) { 
					nSettle = exit[x(closestEx)][y(closestEx)]; 
				} else {
					nSettle = enter[x(lastEn)][y(lastEn)];
				}
				enter[x(lastEn)][y(lastEn)] -= nSettle;
				exit[x(closestEx)][y(closestEx)] -= nSettle;
				swapRev += nSettle * cumuPrice(closestEx - lastEn);
//				printf("nSettle = %.0f\n", nSettle);
//				printf("distance = %.0f\n", closestEx - lastEn);
//				printf("cumuPrice = %.0f\n", cumuPrice(closestEx - lastEn));
//				printf("Swap revenue += %.0f = %.0f\n", nSettle * cumuPrice(closestEx - lastEn), swapRev);

				// Check
//				printStations(N, enter, exit);
//				getchar();

				i += nSettle;
			}

		}

/*		printf("Legal revenue = %.0f\n", legalRev);

		printf("Swap revenue = %.0f\n", swapRev);

		printf("City financial loss = %.0f\n", legalRev - swapRev);
*/
		printf("%.0f\n", legalRev - swapRev);

	}

	return 0;
}
