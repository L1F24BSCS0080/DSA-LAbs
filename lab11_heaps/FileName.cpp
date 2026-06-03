#include "maxheap.h"
int main() {
	heap h1(15);
	int sz = 0;
	cout << "enter herap size ";
	cin >> sz;
	for (int i = 0; i < sz; i++) {
		h1.insertmin(i);
	}
	h1.display();
	cout << endl;
	cout << h1.getmaxmin();
	cout << endl;
	h1.delminheap();
	cout << endl;

	h1.display();
	cout << endl;
	cout << h1.getmaxmin();
	cout << endl;

	heap h2(15);
	int arr[5] = { 4,1,2,5,6 };
	h2.loadUnsortedArray(arr, 5);

	h2.heapSortInPlace();
	cout << endl;
	h2.display();
}