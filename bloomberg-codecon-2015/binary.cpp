#include <iostream>
#include <vector>
using namespace std;

int bin_search(int num, const vector<int>& array) {
// Return the index of 'num' if found in array
// Else return -1
	int size = array.size();
	int low = 0, high = size-1;
	while (low <= high) {
		cout << "Searching between " << low << " and " << high << endl;
		int mid = low + (high-low)/2;
		if (array[mid] == num) {
			return mid;
		} else if (num < array[mid]) {
			high = mid-1; 
		} else if (num > array[mid]) {
			low = mid+1;
		} 
	}
	return -1;
}

int main() {
	// Magical vector declaration using arrays
	int arr[] = {1,4,6,8,9,11,21,32,43,52,66,87};
	vector<int> array(arr, arr + sizeof(arr)/sizeof(arr[0]) );
	
	for (int i=0; i<array.size(); i++) {
		cout << array[i] << endl;
	}

	// Binary search
	int num;
	cout << "Search for?" << endl;
	while (cin >> num) {
		cout << "Found at index " << bin_search(num, array) << endl;
		cout << "Search for?" << endl;
	}

	return 0;
}
