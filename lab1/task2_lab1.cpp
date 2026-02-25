#include <iostream>
using namespace std;
int binarysearch(int arr[], int sz, int target) {
	int low = 0;
	int high = sz - 1;
	int mid = 0;
	while (low < high) {
		mid = (low + high) / 2;
		if (arr[mid] == target) return mid;
		else if (arr[mid] < target) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}
int main() {
	int arr[5] = { 1,2,3,4,5 };
	int target = 9;
	cout << binarysearch(arr, 5, 3);
}