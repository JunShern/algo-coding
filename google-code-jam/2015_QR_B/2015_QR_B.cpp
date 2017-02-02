#include <iostream>
#include <vector>
using namespace std;


int sum(const vector<int>& plates) {
	int s = 0;
	for (int i=0; i<plates.size(); i++) {
		s += plates[i];
	}
	return s;
}

int highest(const vector<int>& plates) {
	int h = 0;
	for (int i=0; i<plates.size(); i++) {
		if (plates[i] > h) h = plates[i];
	}
	return h;
}

void eat(vector<int>& plates) {
	for (int i=0; i<plates.size(); i++) {
		if (plates[i]!=0) plates[i] -= 1;
	}
}

void split(vector<int>& plates) {
	// Figure out which stack to split - the highest one
	int stack = highest(plates);
	// Find that particular stack, and split it!
	for (int i=0; i<plates.size(); i++) {
		if (plates[i]==stack) {
			// Split it
			plates.push_back(stack/2);
			plates[i] -= stack/2;
			return;
		}
	}
}

void printAll(const vector< vector<int> >& platelist) {
	for (int i=0; i<platelist.size(); i++) {
		cout << "[ " ;
		for (int j=0; j<platelist[i].size(); j++) {
			cout << platelist[i][j] << " ";
		}
		cout << "]\t";
	}
	cout << endl;
}

int findAnswer(vector< vector<int> >& platelist) {
	
	int minutes = 0;
	while (true) {
		cout << "Minute " << minutes << ": ";
		printAll(platelist);

		minutes += 1;

		vector< vector<int> > newlist;
		for (int i=0; i<platelist.size(); i++) {
			// Eat one
			vector<int> eaten_plate;
			eaten_plate = platelist[i];
			eat(eaten_plate);
			if (sum(eaten_plate) == 0) return minutes;
			// Split one
			vector<int> split_plate;
			split_plate = platelist[i];
			split(split_plate);
			//if (sum(split_plate) == 0) return minutes;
			// Place new plates into newlist 
			newlist.push_back(eaten_plate); 
			newlist.push_back(split_plate);
		}
		// Update platelist
		platelist = newlist;
	}

	cout << "Error finding answer!" << endl;
	return 0;
}


int main() {
	int T;
	cin >> T;
	for (int t=0; t<T; t++) {
		int D;
		cin >> D;
		vector<int> plates;
		// Read in the plates
		for (int d=0; d<D; d++) {
			int tmp;
			cin >> tmp;
			plates.push_back(tmp);
		}

		// Make the list of plates
		vector< vector<int> > platelist;
		platelist.push_back(plates);

		// Find the answer and output
		cout << "Case #" << t+1 << ": " << findAnswer(platelist) << endl;
	}

	return 0;
}
