#include<iostream>
#include"Stack.h"
using namespace std;
void sortstack(Stack<int> &st) {
    Stack<int> temp(100);
    temp.push(st.pop());
    while (!st.isEmpty()) {
        int current = st.pop();
        while (!temp.isEmpty()&&current < temp.peek()) {
            st.push(temp.pop());
        }
        temp.push(current);
    }
    while (!temp.isEmpty()) {
        st.push(temp.pop());
    }

}
int main()
{
    Stack<int> st(5);
    st.push(3);
    st.push(4);
    st.push(1);
    st.push(9);
    st.push(0);
    sortstack(st);
    while (!st.isEmpty()) {
        cout << st.pop() << endl;
    }
    return 0;
}