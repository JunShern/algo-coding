#include <stdio.h>
#include <math.h>
#include <assert.h>

double twicePellTriangles(double n) {
	double ans = ( pow(1+sqrt(2),2*n+1) + pow(1-sqrt(2),2*n+1) - 2*pow(-1,n) ) / 8; 
	return ans;
}

double lenDigits(double i) {
	double d = 0;
	while (i >= 1) {
		d++;
		i /= 10;
	}
	return d;
}

void reduce(double *num, double *denom) {
	// We assume num > denom for all cases, let me know if I'm wrong!
	assert(*num >= *denom);

	// Find the HCF using Euclid's Algorithm
	double hcf;
	double i = *num;
	double j = *denom;
	double temp;
	while ( fmod(i,j) != 0 ) { // fmod is modulus for doubles
		printf("i: %.0f, j: %.0f; temp: %.0f, fmod(i,j): %.0f\n", i, j, temp, fmod(i,j));
		if (fmod(i,j)==0) break;
		temp = i;
		i = j;
		j = fmod(temp,j);
	}
	hcf = j;
	printf("The HCF of %.0f and %.0f is %.0f.\n", *num, *denom, hcf);

	// Reduce the values by dividing by HCF
	*num /= hcf;
	*denom /= hcf;

	return;
}

void add(double *num1, double *denom1, double *num2, double *denom2) {
	printf("%.0f/%.0f + %.0f/%.0f ", *num1, *denom1, *num2, *denom2);
	// Change to same denominator
	*num1 *= *denom2;
	*num2 *= *denom1;
	*denom1 *= *denom2;
	*denom2 = *denom1;
	// Add
	*num1 += *num2;
	// Reduce
	reduce(num1, denom1);
	printf("= %.0f/%.0f \n", *num1, *denom1); 
}

void subtract(double *num1, double *denom1, double *num2, double *denom2) {
	printf("%.0f/%.0f + %.0f/%.0f ", *num1, *denom1, *num2, *denom2);
	// Change to same denominator
	*num1 *= *denom2;
	*num2 *= *denom1;
	*denom1 *= *denom2;
	*denom2 = *denom1;
	// Subtract
	*num1 -= *num2;
	// Reduce
	reduce(num1, denom1);
	printf("= %.0f/%.0f \n", *num1, *denom1); 
}

int main(void) {
	int count = 0;
	int i;
	double num = 3;
	double denom = 2;
	double pellNum = 1;
	double pellDenom;
	
	
	for (i=1; i<3; i++) {
		printf("Fraction: %.0f/%.0f \n", num, denom);
		// Test fraction pair
		if ( lenDigits(num) > lenDigits(denom) ) 
			count++;
		
		// Set up next fraction pair
		pellNum = 1;
		pellDenom = twicePellTriangles(i+1);

		// Change to same denominator
		num *= pellDenom;
		pellNum *= denom;
		denom *= pellDenom;	
		pellDenom = denom;
			
		if (i%2==1) { // Odd expansion number, subtract
			subtract(&num, &denom, &pellNum, &pellDenom);
		}
		else { // Even expansion number, add
			add(&num, &denom, &pellNum, &pellDenom);
		}	
			
	}

	return 0;
}
