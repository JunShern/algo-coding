/*
ID: unload11
LANG: C
PROG: friday
*/

#include <stdio.h>

int isLeap(int year);
int daysInMonth(int month, int year);

int main(void) {
	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");

	int days = 0; 
	int date = 0;
	int month = 1;
	int year = 1900;
	
	int mondays=0, tuesdays=0, wednesdays=0; 
	int thursdays=0, fridays=0, saturdays=0, sundays=0;

	int numYears;
	fscanf(fin, "%d", &numYears);
	
	int maxDays=0;
	int endYear = year + numYears;

	while (year < endYear) {
		days++;
		date++;

		// increment the day name count
		switch (days%7) {
			case 1: 
				if (date==13) {
					mondays++;
				} break;
			case 2: 
				if (date==13) {
					tuesdays++;
				} break;
			case 3: 
				if (date==13) {
					wednesdays++;
				} break;
			case 4: 
				if (date==13) {
					thursdays++;
				} break;
			case 5:
				if (date==13) {
					fridays++;
				} break;
			case 6: 
				if (date==13) {
					saturdays++;
				} break;
			case 0:
				if (date==13) {
					sundays++;
				} break;
		}
/*
		if (date==13) {
		switch (days%7) {
			case 1: mondays++;
			case 2: tuesdays++;
			case 3: wednesdays++;
			case 4: thursdays++;
			case 5: fridays++;
			case 6:	saturdays++;
			case 0: sundays++;
		}
*/

		// check if month changes
		maxDays = daysInMonth(month, year);
		if (date>maxDays) {
			month++;
			date = 1;
		}
		
		// check if year changes
		if (month>12) {
			year++;
			month = 1;
		}
		//printf("Date: %d/%d/%d, %d \n", date, month, year, days%7);
	}

	fprintf(fout, "%d %d %d %d %d %d %d\n", saturdays, sundays, mondays, tuesdays, wednesdays, thursdays, fridays);

	return 0;
}

int isLeap(int year) {
	if (year%400 == 0) {
		return 1;
	}
	else if (year%100 == 0) {
		return 0;
	}
	else if (year%4 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int daysInMonth(int month, int year) {
	int maxDays;
	switch (month) {
		case 1: return 31;

		case 2: 
			if (isLeap(year)==1) {
				return 29; 
			}
			else {
				return 28;
			}
			break;

		case 3: return 31;
		case 4: return 30; 
		case 5: return 31;
		case 6: return 30;
		case 7: return 31;
		case 8: return 31;
		case 9: return 30;
		case 10: return 31;
		case 11: return 30;
		case 12: return 31;
	}
	
}
	 
