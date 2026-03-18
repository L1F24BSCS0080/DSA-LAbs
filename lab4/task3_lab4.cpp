#include<iostream>
#include"Stack.h"
using namespace std;
void int_to_binary(int num) {
    Stack<int> st(100);
    while (num > 0) {
        st.push(num % 2);
        num /= 2;
    }
    while (!st.isEmpty()) {
        cout << st.pop();
    }
}
int main()
{
    cout << "enter number\n";
    int exp;
    cin >> exp;
    cout << exp << endl;
    int_to_binary(exp);
    return 0;
}