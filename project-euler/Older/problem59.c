#include <stdio.h>

int lenCipher;	

void XOR(int cipher[], int key[], char translation[]) {
	int kInd = 0; // counter for key
	int i = 0;
	for (i=0; i<lenCipher; i++) { 
		// Apply XOR 
		translation[i] = cipher[i] ^ key[kInd];
		// Loop key counter
		if (++kInd > 2) kInd = 0;
	}
	translation[i] = '\0'; // Terminate string
	return;
}

int numberOf(char trigram[], char text[]) {
	int i = 0;	
	// Count number of trigrams
	int tri = 0;
	while ( (text[i+2] != '\0') ) { // Plus 2 because need three characters to form a trigram
		if (text[i]!=trigram[0]) { // Skip ahead until first letter found
			i++;
			continue;
		}
		if ( (text[i+1]==trigram[1]) && (text[i+2]==trigram[2]) ) { // Compare other two letters
			tri++;
		}
		i++;
	}
	//printf("Number of %s: %d\n", trigram, tri);
	return tri;
}

int isEnglish(char text[], int threshold) {
	int i = 0;
	// Count number of "the"
	int the = numberOf("the", text);
	// Count number of "and"
	int and = numberOf("and", text);
	// Count number of "are"
	int tha = numberOf("tha", text);
	// Count number of "was"
	int ent = numberOf("ent", text);
	// Count number of "you"
	int ing = numberOf("ing", text);

	if (the+and+tha+ent+ing > threshold) {
		printf("It's English!\n");
		return 1; 
	} else {
		//printf("It's not English...\n");
		return 0; 
	}
}

int findSum(char text[]) {
	int i = 0;
	int sum = 0;
	while (text[i] != '\0') {
		sum += text[i];
		i++;
	}
	return sum;
}	
	
int main(void) {
	FILE *fin = fopen("cipher1.txt", "r");
	// Scan file into the num array cipher[]
	int cipher[2000];	
	int i = 0;
	while ( fscanf(fin,"%d ,",&cipher[i]) != EOF ) {
		i += 1;
	} 
	printf("\n");
	lenCipher = i;
//	printf("The length of the cipher is %d.\n", lenCipher);

	// Iterate through all possible keys, stop at translations that seem to be English
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int j, k;	
	for (i=0; i<26; i++) {
		for (j=0; j<26; j++) {
			for (k=0; k<26; k++) {
				int key[3] = {alphabet[i], alphabet[j], alphabet[k]};
				char translation[2000];
				XOR(cipher, key, translation);	
				if (isEnglish(translation, 20)) {
					printf("%d %d %d\n", key[0], key[1], key[2]);
					printf("%s\n", translation);
					printf("The sum is %d.\n", findSum(translation));					
				}
			}
		}
	}

	fclose(fin);
	return 0;
}

