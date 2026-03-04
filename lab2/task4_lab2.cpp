
#include <iostream>
using namespace std;
template <class T>
class calculator {
	T num1;
	T num2;
public:
	calculator(T a, T b) :num1(a), num2(b) {}
	T add() {
		return num1 + num2;
	}
	T sub() {
		return num1 - num2;
	}
	T mul() {
		return num1 * num2;
	}
	T div() {
	
		return num1 / num2;
	}
	void showall() {
		cout << "calculator\n";
		cout << "sum: " << add() << endl;
		cout << "sub: " << sub() << endl;
		cout << "mul: " << mul() << endl;
		cout << "div: " << div() << endl;
	}
};
int main() {
	calculator<int> c1(10, 5);
	calculator<float> c2(12.0, 4.5);
	calculator<string> c3("122.12", "4.53");
	/*
	* here we created class instance and object instance with string datatype
	* but issue is calculatore operations are not possible with string 
	* we cannot subtract,multyiply,divide stringsa in c++
	* KEY POINT:
	* if we keep onlyu addition function in class then it will work with string easily
	* it will concatenate strings
	* 
	*/

	c1.showall();
	c2.showall();
	c3.showall();
}