#include<iostream>
#include"Stack.h"
using namespace std;
bool ispalendromic(string s) {
    Stack<char> st(s.size());
    for (int i = 0; i < s.size(); i++) {
        st.push(s[i]);
    }
    string rev;
    while (!st.isEmpty()) {
        rev += st.pop();
    }
    cout << "reverse is: " << rev << endl;
    if (rev == s) return true;
    else return false;
}
int main()
{
    cout << "enter word\n";
    string exp;
    cin >> exp;
    cout << exp << endl;
    if (ispalendromic(exp)) cout << "plaendromic string\n";
    else cout << "not plaendromic\n";
    return 0;
}