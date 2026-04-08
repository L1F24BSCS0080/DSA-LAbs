#include<iostream>
#include "LinkeList.h"

using namespace std;

void countEvenOdd(Node<int>* head, int& even, int& odd) {
	Node<int>* temp = head;
	while (temp != nullptr) {

		if (temp->data % 2 == 0) even++;
		else odd++;
		temp = temp->next;
	}

}
int main() {
	LinkedList<int> l1;
	l1.insertFront(3);
	l1.insertFront(8);
	l1.insertFront(15);
	l1.insertFront(22);
	l1.insertFront(7);
	l1.insertFront(14);
	l1.insertFront(9);
	l1.insertFront(6);
	l1.display();

	int even = 0;
	int odd = 0;
	
	countEvenOdd(l1.getHead(), even, odd);
	cout << "even: " << even << ", odd : " << odd << endl;

	LinkedList<int> l2;
	cout << "\nEnter list 2 numbers : ";
	for (int i = 0; i < 6; i++) {
		int n = 0;
		cin >> n;
		l2.insertFront(n);
	}
	l2.display();
	even = 0;
	odd = 0;
	countEvenOdd(l2.getHead(), even, odd);
	cout << "even: " << even << ", odd : " << odd << endl;
}
/*

1.	Declare a LinkedList<int> and insert: {3, 8, 15, 22, 7, 14, 9, 6}.
2.	Display the list.
3.	Write a function void countEvenOdd(Node<int>* head, int& even, int& odd) that fills the two reference parameters.
4.	Print the even count and the odd count.
5.	Ask the user to enter 6 integers, build a new list, and display even/odd counts again.
*/