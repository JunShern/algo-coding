#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int parse(string command, int ind, int *num) {
	while (command[ind] != ' ') {
		int digit = command[ind] - '0';
		*num *= 10;
		*num = *num + digit;
		ind++;
	}
	return ind;
}
	
void newImage(char image[][250], int M, int N) {
	for (int j=0; j<N; j++) {
		for (int i=0; i<M; i++) {
			image[i][j] = 'O';
		}
	}
}

void pixel(char image[][250], int x, int y, char C) {
	image[x][y] = C;
}

void vertical(char image[][250], int x, int y1, int y2, char C) {
	for (int j=y1; j<=y2; j++) {
		image[x][j] = C;
	}
}

void horizontal(char image[][250], int x1, int x2, int y, char C) {
	for (int i=x1; i<=x2; i++) {
		image[i][y] = C;
	}
}

void print(char image[][250], int M, int N) {
	for (int j=0; j<N; j++) {
		for (int i=0; i<M; i++) {
			cout << image[i][j];
		}
		cout << endl;
	}
}

void rect(char image[][250], int x1, int x2, int y1, int y2, char C) {
	for (int i=x1; i<=x2; i++) {
		for (int j=y1; j<=y2; j++) {
			image[i][j] = C;
		}
	}
}

void fill(char image[][250], int x, int y, char C, char ori_C) {
//	cout << "Filling [" << x << ", " << y << "] now." << endl;
	image[x][y] = C;
	for (int i=x-1; i<=x+1; i++) {
		for (int j=y-1; j<=y+1; j++) {
			// Ignore diagonals - up/down/left/right only
			if (abs(x-i) + abs(y-j) > 1) continue;
			
//			cout << "Considering [" << i << ", " << j << "]." << endl;
			// Boundary test
			if (i<0 || j<0 || image[i][j]=='x') {
//				cout << "Out of bounds." << endl;
				continue;
			}
			// Colour test
			if (image[i][j]==C || image[i][j]!=ori_C) {
//				cout << "Do not colour." << endl;
				continue;
			}
			// Recursively fill
			fill(image, i, j, C, ori_C);
		}
	}
}	
	

int main(void) {

	string command;
	int M = 0;
	int N = 0;
	
	// Create default empty image
	char image[250][250];
	for (int i=0; i<250; i++) {
		for (int j=0; j<250; j++) {
			image[i][j] = 'x'; // Null char
		}
	}

	// Read in commands
	getline(cin, command);

	while (command[0] != 'X') {
		// Append ' ' to end of command for easier parsing
		command = command + ' ';

		// New image
		if (command[0] == 'I') {
			// Parse parameters
			M = 0;
			int i = 2;
			i = parse(command, i, &M);
			N = 0;
			i = parse(command, i+1, &N);
			// Execute 'New'
			newImage(image, M, N);
		} else if (command[0] == 'C') {
			// Execute 'Clear'
			newImage(image, M, N); // Same as 'New'
		} else if (command[0] == 'L') {
			// Parse parameters
			int x = 0, y = 0;
			int i = 2;
			i = parse(command, i, &x);
			i = parse(command, i+1, &y);
			char C = command[i+1];
			// Execute 'Pixel'
			pixel(image, x-1, y-1, C);
		} else if (command[0] == 'V') {
			// Parse parameters
			int x = 0, y1 = 0, y2 = 0;
			int i = 2;
			i = parse(command, i, &x);
			i = parse(command, i+1, &y1);
			i = parse(command, i+1, &y2);
			char C = command[i+1];
			// Execute 'Vertical'
			vertical(image, x-1, y1-1, y2-1, C);
		} else if (command[0] == 'H') {
			// Parse parameters
			int x1 = 0, x2 = 0, y = 0;
			int i = 2;
			i = parse(command, i, &x1);
			i = parse(command, i+1, &x2);
			i = parse(command, i+1, &y);
			char C = command[i+1];
			// Execute 'Horizontal'
			horizontal(image, x1-1, x2-1, y-1, C);
		} else if (command[0] == 'K') {
			// Parse parameters
			int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
			int i = 2;
			i = parse(command, i, &x1);
			i = parse(command, i+1, &y1);
			i = parse(command, i+1, &x2);
			i = parse(command, i+1, &y2);
			char C = command[i+1];
			// Execute 'Rect'
			rect(image, x1-1, x2-1, y1-1, y2-1, C);
		} else if (command[0] == 'F') {
			// Parse parameters
			int x = 0, y = 0;
			int i = 2;
			i = parse(command, i, &x);
			i = parse(command, i+1, &y);
			char C = command[i+1];
			char ori_C = image[x-1][y-1];
			// Execute 'Fill'
			fill(image, x-1, y-1, C, ori_C);
		} else if (command[0] == 'S') {
			// Parse parameters
			string name = command.substr(2); // From 2 to end
			// Execute name and 'Print'
			cout << name << endl;
			print(image, M, N);
		}

		// Read next line
		getline(cin, command);
	}

	return 0;
}
