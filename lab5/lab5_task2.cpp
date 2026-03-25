#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;
bool isoperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
}
int getprec(char ch) {
	if (ch == '+' || ch == '-') return 1;
	if (ch == '*' || ch == '/') return 2;
}
void infixtoprefix(string exp) {
	reverse(exp.begin(), exp.end());

	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == '(') {
			exp[i] = ')';
		}
		else if (exp[i] == ')') {
			exp[i] = '(';
		}
	}
	string res = "";
	Stack<char> st(exp.size());
	for (char ch : exp) {
		if (ch == '(') { st.push(ch); }
		else if (isoperator(ch)) {
			int prec = getprec(ch);
			while (!st.isEmpty() && st.peek() != '(' && getprec(st.peek()) > prec) {
				char top = st.peek();
				res += top;
				st.pop();
			}
			st.push(ch);
		}
		else if (ch == ')') {
			while (!st.isEmpty() && st.peek() != '(' ) {
				char top = st.peek();
				res += top;
				st.pop();
			}
			if (!st.isEmpty() && st.peek() == '(') st.pop();    //    '('  removed  
		}
		else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
			res += ch;
		}
	}
	while (!st.isEmpty()) {
		res += st.peek();
		st.pop();
	}
	reverse(res.begin(), res.end());
	cout<<"\nresult: " << res << endl;
}
int main() {
	infixtoprefix("A+B*C");
}