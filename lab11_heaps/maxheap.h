#pragma once
#include<iostream>
using namespace std;
class heap {
public:
	int sz;
	int n;
	int* arr;
	heap(int sz) {
		this->sz = sz+1;
		arr = new int[this->sz];
		n = 0;
	}
	void display() {
		for (int i = 1; i <= n; i++) {
			cout << arr[i] << " ";
		 }
	}
	//task1
	void insertmax(int val) {
		arr[0] = -1;
		n++;
		if (n == sz) {
			cout << "heap is full";
			return;
		}
		arr[n] = val;
		int i = n;
		int parent = i / 2;
		do {
			if (parent <= 0) break;
			if (arr[parent] < arr[i]) {
				swap(arr[parent], arr[i]);
				i = parent;
				parent = i / 2;
			}

		} while (arr[parent] < arr[i]);
	 }
	//task2
	void insertmin(int val) {
		arr[0] = -1;
		n++;
		if (n == sz) {
			cout << "heap is full";
			return;
		}
		arr[n] = val;
		int i = n;
		int parent = i / 2;
		do {
			if (parent <= 0) break;
			if (arr[parent] > arr[i]) {
				swap(arr[parent], arr[i]);
				i = parent;
				parent = i / 2;
			}

		} while (arr[parent] > arr[i]);
	}
	//task3
	void delmaxheap() {
		if (n == 0) {
			cout << "heap is empty\n";
			return;
		}
		arr[1] = arr[n--];
		int i = 1;
		while (i * 2 <= n) {
			int left = i * 2;
			int right=left+1;
			int largest = i;
			if (arr[left] > arr[largest]) {
				largest = left;
			}
			if (right <= n&&arr[right] > arr[largest]) {
				largest = right;
			}
			if (largest == i) break;
			swap(arr[i], arr[largest]);
			i = largest;
		}
	}
	void delminheap() {
		if (n == 0) {
			cout << "heap is empty\n";
			return;
		}
		arr[1] = arr[n--];
		int i = 1;
		while (i * 2 <= n) {
			int left = i * 2;
			int right = left + 1;
			int largest = i;
			if (arr[left] < arr[largest]) {
				largest = left;
			}
			if (right <= n && arr[right] < arr[largest]) {
				largest = right;
			}
			if (largest == i) break;
			swap(arr[i], arr[largest]);
			i = largest;
		}
	}
	int getmaxmin() {
		if (n == 0) {
			cout << "empty heap";
			return -1;
		}
		return arr[1];
	}
	void heapSortInPlace() {
		if (n <= 1) return;

		for (int start = n / 2; start >= 1; start--) {
			int i = start;
			while (i * 2 <= n) {
				int left = i * 2;
				int right = left + 1;
				int largest = i;

				if (arr[left] > arr[largest]) {
					largest = left;
				}
				if (right <= n && arr[right] > arr[largest]) {
					largest = right;
				}
				if (largest == i) break;

				swap(arr[i], arr[largest]);
				i = largest;
			}
		}

		cout << "Phase 1 Output (Max-Heap Built):\n";
		display();

		for (int activeSize = n; activeSize > 1; activeSize--) {
			swap(arr[1], arr[activeSize]);

			int remainingHeap = activeSize - 1;
			int i = 1;

			while (i * 2 <= remainingHeap) {
				int left = i * 2;
				int right = left + 1;
				int largest = i;

				if (arr[left] > arr[largest]) {
					largest = left;
				}
				if (right <= remainingHeap && arr[right] > arr[largest]) {
					largest = right;
				}
				if (largest == i) break;

				swap(arr[i], arr[largest]);
				i = largest;
			}
		}

		cout << "\nPhase 2 Output (Final Sorted Array):\n";
		display();
	}
	void loadUnsortedArray(int unsortedArr[], int size) {
    if (size >= sz) {
        cout << "Array size exceeds heap capacity\n";
        return;
    }

    n = size;
    arr[0] = -1;

   
    for (int i = 0; i < size; i++) {
        arr[i + 1] = unsortedArr[i];
    }
    }
};
