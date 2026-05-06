#include<iostream>
using namespace std;
#include <string>
using namespace std;

string reverseString(string s) {
    // Base case: empty or single character
    // -- write here --
   if(s.size()==1) return s;
    // Recursive case: reverse the rest, then add first char at end
    // -- write here --
   return reverseString(s.substr(1)) + s[0];
}

int main() {
    cout << reverseString("hello") << endl;  // Expected: olleh
    cout << reverseString("racecar") << endl;  // Expected: racecar
    return 0;
}

