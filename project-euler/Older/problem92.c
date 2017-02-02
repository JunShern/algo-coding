#include <stdio.h>

int nextNum(double n) {
	char digits[5];
	sprintf(digits, "%f", n);
	
	double ans = 0;
	double d;
	int i;
	for (i=0;digits[i]!='\0';i++) {
		d = digits[i] - '0';	
		ans += d*d;
	} 
	printf("Type of ans: %s", typeof(ans));
	return ans;
}

int main(void) {
	printf("After 44 comes %f\n", nextNum(44));
}
		
