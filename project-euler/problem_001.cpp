#include <iostream>

using namespace std;

int main() {
	int sum=0;
	int y=0, i=0;
	while (y < 1000) {
		sum += y;
		i++;
		y = 3 * i;
	}
	y = 0;
	i = 0;
	while (y < 1000) {
		sum += y;
		i++;
		y = 5 * i;
	}
	y = 0;
	i = 0;
	while (y < 1000) {
		sum -= y;
		i++;
		y = 15 * i;
	}
	
	cout << "Sum: " << sum << endl;

	return 0;
}
