#include<iostream>
using namespace std; 
int binarySearch(int arr[], int left, int right, int target) {
    // Base case: if left > right, target not found
    // -- write here --
    if (left > right) return - 1;
    int mid = (left + right) / 2;

    // If middle element is the target
    // -- write here --
    if (arr[mid] == target) return mid;
    // If target is smaller, search left half
    // -- write here --
    if (target < arr[mid]) {
        return  binarySearch(arr, left, mid - 1, target);
    }
   
    // If target is larger, search right half
    // -- write here --
    if (target > arr[mid]) { 
        return  binarySearch(arr, mid + 1, right, target);
    }
   
}

int main() {
    int arr[] = { 1, 3, 5, 7, 9, 11, 13 };
    int n = 7;
    cout << binarySearch(arr, 0, n - 1, 7) << endl;  // Expected: 3
    cout << binarySearch(arr, 0, n - 1, 1) << endl;  // Expected: 0
    cout << binarySearch(arr, 0, n - 1, 13) << endl;  // Expected: 6
    cout << binarySearch(arr, 0, n - 1, 4) << endl;  // Expected: -1
    return 0;
}
