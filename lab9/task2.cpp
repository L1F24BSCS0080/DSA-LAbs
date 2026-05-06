#include<iostream>
using namespace std;
int sumOfDigits(int n) {
    // Base case: if n is 0, return 0
    // -- write here --
    if (n == 0) return 0;
    // Recursive case: last digit + sum of remaining digits
    // -- write here --
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    cout << sumOfDigits(1234) << endl;  // Expected: 10
    cout << sumOfDigits(567) << endl;  // Expected: 18
    return 0;
}
