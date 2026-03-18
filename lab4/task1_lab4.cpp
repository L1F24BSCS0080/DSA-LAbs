#include<iostream>
#include"Stack.h"
using namespace std;
bool isValid(string s) {
    Stack<char> st(s.size());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else if (!isalnum(s[i])) {
            if (st.isEmpty()) return false;
            else if (s[i] == ')' && st.peek() == '(') {
                st.pop();
            }
            else  if (s[i] == '}' && st.peek() == '{') {
                st.pop();
            }
            else if (s[i] == ']' && st.peek() == '[') {

                st.pop();

            }
            else return false;
      }
    }
    return st.isEmpty();
}
int main()
{
    cout << "enter expression\n";
    string exp;
    cin >> exp;
    cout << exp << endl;
    if (isValid(exp)) cout << "valid string\n";
    else cout << "not valid\n";
	return 0;
}