/*
ID: unload11
LANG: C
PROG: transform
*/

#include <stdio.h>
#include <stdbool.h>

void printPattern(int sidelen, char pattern[sidelen][sidelen]) {
	int i, k;
	for (i=0; i<sidelen; i++) {
		for (k=0; k<sidelen; k++) 
			printf("%c", pattern[i][k]);
		printf("\n");
	}
}

void t1(int sidelen, char pattern[sidelen][sidelen]) {
// 90 degree rotation CW
	char temp[sidelen][sidelen];
	int i, k;
	// Make a copy of the pattern into temp
	for (i=0; i<sidelen; i++) {
		for (k=0; k<sidelen; k++)
			temp[i][k] = pattern[i][k];
	}
	// Transform
	for (i=0; i<sidelen; i++) {
		for (k=0; k<sidelen; k++)
			pattern[i][k] = temp[sidelen-1-k][i];
	}
}
	
void t4(int sidelen, char pattern[sidelen][sidelen]) {
// Reflection
	char temp[sidelen][sidelen];
	int i, k;
	// Make a copy of the pattern into temp
	for (i=0; i<sidelen; i++) {
		for (k=0; k<sidelen; k++)
			temp[i][k] = pattern[i][k];
	}
	// Transform
	for (i=0; i<sidelen; i++) {
		for (k=0; k<sidelen; k++) 
			pattern[i][k] = temp[i][sidelen-1-k];
	}
}		
		
bool compare(int sidelen, char pattern1[sidelen][sidelen], char pattern2[sidelen][sidelen]) {
// Return true if identical, otherwise false
	int i, k;
	for (i=0; i<sidelen; i++) {
		for (k=0; k<sidelen; k++) 
			if ( pattern1[i][k] != pattern2[i][k]) return false;
	}
	return true;
}

int main(void) {
	FILE *fin = fopen("transform.in", "r");
	FILE *fout = fopen("transform.out", "w");

	int sidelen;
	int i;

	// Get dimensions of square, sidelen
	fscanf(fin, "%d\n", &sidelen);
	
	// Get original layout
	char pattern1[sidelen][sidelen]; 
	for (i=0; i<sidelen; i++) {
		fscanf(fin, "%s\n", pattern1[i]);
	}
		
	// Get transformed layout
	char pattern2[sidelen][sidelen];
	for (i=0; i<sidelen; i++) {
		fscanf(fin, "%s\n", pattern2[i]);
	}
	
	printf("We begin with: \n");	
	printPattern(sidelen, pattern1);
	printPattern(sidelen, pattern2);

	// Test each of the transformations
	t1(sidelen, pattern1); // Rotate 90
	if (compare(sidelen, pattern1, pattern2)) {
		printf("Transformation #1, 90 degrees CW! DONE!\n");
		fprintf(fout, "1\n");
		return 0;
	}	
	t1(sidelen, pattern1); // Rotate another 90 (total 180)	
	if (compare(sidelen, pattern1, pattern2)) {
		printf("Transformation #2, 180 degrees CW! DONE!\n");
		fprintf(fout, "2\n");
		return 0;
	}	
	t1(sidelen, pattern1); // Rotate another 90 (total 270)	
	if (compare(sidelen, pattern1, pattern2)) {
		printf("Transformation #3, 270 degrees CW! DONE!\n");
		fprintf(fout, "3\n");
		return 0;
	}	
	t1(sidelen, pattern1); // Rotate another 90, return to original
	t4(sidelen, pattern1); // Reflect horizontally
	if (compare(sidelen, pattern1, pattern2)) {
		printf("Transformation #4, horizontal reflection! DONE!\n");
		fprintf(fout, "4\n");
		return 0;
	}	
	t1(sidelen, pattern1); // Rotate 90
	if (compare(sidelen, pattern1, pattern2)) {
		printf("Transformation #5, horizontal reflection then 90 degrees CW! DONE!\n");
		fprintf(fout, "5\n");
		return 0;
	}	
	t1(sidelen, pattern1); // Rotate another 90 (total 180)	
	if (compare(sidelen, pattern1, pattern2)) {
		printf("Transformation #5, horizontal reflection then 180 degrees CW! DONE!\n");
		fprintf(fout, "5\n");
		return 0;
	}	
	t1(sidelen, pattern1); // Rotate another 90 (total 270)	
	if (compare(sidelen, pattern1, pattern2)) {
		printf("Transformation #5, horizontal reflection then 270 degrees CW! DONE!\n");
		fprintf(fout, "5\n");
		return 0;
	}	
	t1(sidelen, pattern1); // Rotate another 90, return to original
	t4(sidelen, pattern1); // Reflect horizontally
	if (compare(sidelen, pattern1, pattern2)) {
		printf("Transformation #6, no change! DONE!\n");
		fprintf(fout, "6\n");
		return 0;
	} 	
	
	printf("Looks like nothing worked. #7, invalid transformation!\n");
	fprintf(fout, "7\n");
	return 0;
}

