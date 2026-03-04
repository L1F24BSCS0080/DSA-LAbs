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
		if (num2 == 0 || num2 == 0.0) return -1;
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
	calculator<int> c1(10,5);
	calculator<float> c2(12.0,4.5);
	calculator<double> c3(122.123, 4.53);
	c1.showall();
	c2.showall();
	c3.showall();
}