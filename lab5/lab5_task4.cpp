#include <iostream>
#include<stack>
using namespace std;
int getprec(char ch)
{
    if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    return 0;
}
int evaluatePostfix(string s) {
    stack<int> st;

    for (int i = s.length()-1; i >=0; i--) {

        if (isdigit(s[i])) {
            st.push((s[i] - '0'));
        }

        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if (s[i] == '+') st.push(val1 + val2);
            else if (s[i] == '-') st.push(val1 - val2);
            else if (s[i] == '*') st.push(val1 * val2);
            else if (s[i] == '/') st.push(val1 / val2);
        }
    }

    return st.top();
}
int main() {

    cout << evaluatePostfix("+9*23");


    return 0;
}