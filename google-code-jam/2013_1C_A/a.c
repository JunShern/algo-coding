#include<stdio.h>
#include<string.h>

int isvowel(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

char str[1000001];
int d[1000001];
int q[1000001];
int strLen,nValue;

int main() {
	
	FILE *fout = fopen("output.txt", "w");

	int cases,c=0,i,sp;
	long long ret;
	int k;
	for(scanf("%d",&cases); cases--;) {
		// Reset [d] and [q]
		for (k=0; k<strLen; k++) {
			d[k] = 0;
			q[k] = 0;
		}

		scanf("%s %d",str,&nValue); // (s) is string, (nValue) is nValue
		printf("str: %s, nValue: %d\n", str, nValue);
		strLen = strlen(str); // strLen is length of current string
		d[strLen]=sp=0;


		printf("%s\n", str);
		for(i=strLen-1;i>=0;i--) { // Loop index (i) from back of string, down to zero
			if (isvowel(str[i])) 
				d[i]=0; // If the char at (i) is a vowel, set (d[i]) to zero
			else 
				d[i]=d[i+1]+1; // If the char at (i) ISN'T a vowel, (d[i]) is the previous value plus one
			if (d[i]>=nValue) 
				q[sp++]=i; // If the value at d[i] > nValue, append (i) to the list q

			// Print out array [d] for understanding
			for (k=0; k<strLen; k++) {
				printf("%d", d[k]);
			}
			printf("\n");

			// Print out array [q] for understanding
			for (k=0; k<strLen; k++) {
				printf("%d", q[k]);
			}
			printf("\n");
		}
		printf("sp: %d\n\n", sp); // sp holds a count of the number of times nValue has been reached

		ret = 0;
		for(i=0; i<strLen && sp; i++) { // Iterate through (strLen) times
			int mn=q[sp-1]+nValue;
			printf("mn\t= q[sp-1] + nValue\n\t= q[%d-1] + %d\n\t= %d + %d\n\t= %d\n", sp, nValue, q[sp-1], nValue, mn);
			ret+=strLen-mn+1;
			printf("ret\t+= strLen - mn + 1\n\t+= %d - %d + 1\n\t= %lld\n", ret, strLen, mn, ret);
			if (q[sp-1]==i) 
				sp--;
				printf("q[sp-1] == i (%d), so sp-- (%d)\n", i, sp);
		}
		fprintf(fout, "Case #%d: %lld\n", ++c, ret);
		printf("Case #%d: %lld\n", ++c, ret);
		printf("\n");
	}
	return 0;
}
