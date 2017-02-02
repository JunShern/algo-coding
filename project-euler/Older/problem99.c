#include <stdio.h>
#include <math.h>

int main(void) {
	FILE* fin = fopen("base_exp.txt", "r");
	
	int i;
	float b;
	float e;
	float maxVal = 0;
	int line = 0;
	int maxLine;
	for (i=0; i<1000; i++) {
		line++;
		fscanf(fin, "%f, %f\n", &b, &e);
		if (e*log(b) > maxVal) {
			maxVal = e*log(b);
			maxLine = line;
		}
	}
	printf("Line with highest value is %d.\n", maxLine);	
	return 0;
}

