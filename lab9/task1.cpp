#include<iostream>
using namespace std;
int countDigits(int n) {
    // Base case: if n is 0, no digits remain
    // -- write here --
    if (n == 0) return 0;
    // Recursive case: strip one digit and count the rest
    // -- write here --
    return 1 + countDigits(n / 10);
}

int main() {
    cout << countDigits(12345) << endl;  // Expected: 5
    cout << countDigits(9) << endl;  // Expected: 1
    return 0;
}
