#include <iostream>
#include <vector>

using namespace std;

struct wire {
	int a;
	int b;
};

int main() {
	int T;
	cin >> T;

	// Loop through each test case
	for (int i=0; i<T; i++) {
		int N;
		cin >> N;
		int getA[10001] = {0};
		int getB[10001] = {0};
		// Read in each wire
		for (int j=0; j<N; j++) {
			int a, b;
			cin >> a >> b;
			getB[a] = b;
			getA[b] = a;
		}

		// Copy array into vector for easier processing
		vector<wire> wires;
		for (int j=0; j<10001; j++) {
			if (getB[j] != 0) {
				wire tmp;
				tmp.a = j;
				tmp.b = getB[j];
				wires.push_back(tmp);
//				cout << tmp.a << " " << tmp.b << endl;
			}
		}
		
		// Now start the real work
//		cout << "Checking.. " << endl;
		int intersects = 0;
		for (int j=0; j<wires.size(); j++) {
			int A = wires[j].a;
			int B = wires[j].b;
//			cout << "Wires below B(" << B << ") whose A="<< A << ":  " << endl;

			for (int k=0; k<B; k++) {
				if (getA[k] != 0) {
//					cout << "b=" << k << ", a=" << getA[k] << endl;
					if (getA[k] > A) {
						intersects++;
					}
				}
			}
		}
		cout << "Case #" << i+1 << ": " << intersects << endl;

	}

	return 0;
}
