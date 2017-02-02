/*
ID: unload11
LANG: C
PROG: gift1
*/

#include <stdio.h>
#include <string.h>

struct person {
	char name[14];
	int index;

	int givesOut;
	int numRecipients;
	int recipients[10];
	int giftPerHead;
	int remainder;

	int money;

	int netAmount;
};

typedef struct person PERSON;

PERSON person_default = { "defaultName", -1, 0, 0, {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, 0, 0, 0, 0} ;

int indexOf(PERSON people[], int NP, char name[]) {
	int i;
	int k;
	int same = 1;
	for (i=0; i<NP; i++) {
		same = 1;	
		if ( strcmp(people[i].name, name) == 0) { // strcmp compares two strings, returning 0 if they are the same
			return people[i].index;
		}
	}
	printf("The name %s is not in our database.\n", name);
	return -1;
}

int main(void) {
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");
	
	// Number of people
	int NP;
	fscanf(fin, "%d \n", &NP);
	printf("Number of people: %d\n", NP);
	
	// Declare and initialize the people
	PERSON people[NP];
	int i;
	for (i=0; i<NP; i++) {
		people[i] = person_default;
	}

	// Names of people; Assign their index numbers
	for (i=0; i<NP; i++) {	
		people[i].index = i;
		fscanf(fin, "%s \n", people[i].name);
		printf("%d\t%s\n", people[i].index, people[i].name);
	}

	// Update the data for each person
	char currentName[14];
	int ind;
	while (!feof(fin)) {
		// Name of the Giver
		fscanf(fin, "%s \n", currentName);
		ind = indexOf(people, NP, currentName); // given currentName, locate the relevant struct 

		// How much the Giver gives out and Who he gives it to
		fscanf(fin, "%d %d \n", &people[ind].givesOut, &people[ind].numRecipients);
		if ( (people[ind].numRecipients) == 0 ) {
			people[ind].giftPerHead = 0;
		} else {
			// Find the remainder and  giftPerHead for each person
			people[ind].remainder = (people[ind].givesOut%people[ind].numRecipients) ;
			people[ind].giftPerHead = (people[ind].givesOut - people[ind].remainder) / people[ind].numRecipients;
		}

		// Allocate money to the Recipients of this Giver 
		for (i=0; i<people[ind].numRecipients; i++) {
			char newName[14];
			fscanf(fin, "%s \n", newName);
			int indRecp = indexOf(people, NP, newName);
			people[ind].money -= people[ind].giftPerHead;
			people[indRecp].money += people[ind].giftPerHead;
		}
	}
	
	/* LET'S SEE HOW FAR WE'VE COME 
	for (i=0; i<NP; i++) { 
		printf("%s will give out %d to %d person(s), giving out %d per head. He/she has a net amount of %d.\n\n", 
		people[i].name, people[i].givesOut, people[i].numRecipients, people[i].giftPerHead, people[i].money );
	}
	*/

	for (i=0; i<NP; i++) {
		fprintf(fout, "%s %d\n", people[i].name, people[i].money);
	}
	
	return 0;
}
