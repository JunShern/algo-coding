#include <iostream>
using namespace std;

int isDark(int num) {
	int array[] = {2,4,6,8,9,11,13,15,18,20,22,24,25,27,29,31,34,36,38,40,41,43,45,47,50,52,54,56,57,59,61,63};
	for (int i=0; i<32; i++) {
		if (num == array[i]) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int bishop, target, diff;
	cin >> bishop >> target;
	
	if (bishop == target) {
		cout << 0 << endl;
	} else if (bishop > target) {
		diff = bishop - target;
	} else if (target > bishop) {
		diff = target - bishop;
	}

	if (diff%9==0  || diff%7==0) {
		cout << 1 << endl;
	} else if (isDark(bishop) - isDark(target) == 0) {
		cout << 2 << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}
