#include<iostream>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    // Base case: if start >= end, it is a palindrome
    // -- write here --
    if (start >= end) return true;

    // If outer characters don't match, not a palindrome
    // -- write here --
    if (s[start] != s[end]) return false;
    // Recursive case: check inner substring
    // -- write here --
    return isPalindrome(s, start + 1, end - 1);
}

int main() {
    string s1 = "madam";
    cout << isPalindrome(s1, 0, s1.length() - 1) << endl;  // Expected: 1 (true)
    string s2 = "hello";
    cout << isPalindrome(s2, 0, s2.length() - 1) << endl;  // Expected: 0 (false)
    return 0;
}

