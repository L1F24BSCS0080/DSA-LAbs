#include <iostream>
using namespace std;
int linearsearch(int arr[],int sz, int target) {
	int i = 0;
	while (i < sz) {
		if (arr[i] == target) return i;
		i++;
	}
	return -1;
}
int main() {
	int arr[5] = {3,4,9,1,2};
	int target = 9;
	cout << linearsearch(arr, 5, 9);
}