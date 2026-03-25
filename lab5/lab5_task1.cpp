#include<iostream>
#include"Stack.h"
using namespace std;

int getprec(char ch)
{
    if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    return 0;
}

void infixtopostfix(string exp)
{
    Stack<char> st(exp.size());
    string res = "";

    for (char ch : exp)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            res.push_back(ch);
        }
        else
        {
            if (ch == '(') st.push(ch);
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                int prec = getprec(ch);
                while (!st.isEmpty() && st.peek() != '(' && getprec(st.peek()) >= prec)
                {
                    res.push_back(st.pop());
                }
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (!st.isEmpty() && st.peek() != '(')
                {
                    res.push_back(st.pop());
                }
                if (!st.isEmpty() && st.peek() == '(') st.pop();
            }
        }
    }
    while (!st.isEmpty()) res.push_back(st.pop());

    cout << res << endl;
}

int main()
{
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    infixtopostfix(exp);

    return 0;
}