#include <iostream>
#include <vector>

using namespace std;

struct line {
	vector<string> card;
};

int main() {

	line lines[5];

	sting tmp;
	while (cin >> tmp) {
		lines[linenum%4].card.push_back(tmp);
		linenum++;

	return 0;
}
