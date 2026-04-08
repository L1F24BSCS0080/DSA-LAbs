#include<iostream>
#include "LinkeList.h"
#include<stack>
using namespace std;

Node<int>* reverseknodes(Node<int>* head,int k) {
	Node<int>* prevhead = head;
	Node<int>* cur = head;
	Node<int>* prev = nullptr;

	int i = 0;
	while (cur != nullptr && i < k) {
		Node<int>* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		i++;
	}
	prevhead->next = cur;


	return prev;

}

int main() {
	LinkedList<int> l1;
	l1.insertFront(3);
	l1.insertFront(8);
	l1.insertFront(15);
	l1.insertFront(1);
	l1.insertFront(8);
	l1.insertFront(3);
	cout << "enter k: ";
	int k = 0;
	cin >> k;


	l1.display();
	if (k > l1.size()) {
		cout << "cannot reverse k is greater then list size " << endl;
		return 0;
	}

	Node<int>* head = l1.getHead();
	head=reverseknodes(head, k);
	l1.head = head;
	cout<<"reversed"<<endl;
	l1.display();
}

/*Sometimes you only want to reverse a prefix of a linked list and leave the rest unchanged. Reverse the first k nodes in-place using the three-pointer technique, then reconnect the reversed segment to the remaining nodes. The original head becomes the tail of the reversed segment.

•	Declare a LinkedList<int> and insert: {1, 2, 3, 4, 5, 6, 7}. Display the original list.
•	Ask the user to enter k (the number of nodes to reverse from the front). Use k = 3 for the sample run.
•	Write a function Node<int>* reverseK(Node<int>* head, int k) that: reverses the first k nodes using prev/curr/next pointers, then attaches the old head (now the tail of the reversed segment) to node k+1.
•	Update the list head to the value returned by reverseK().
•	Display the updated list. Verify that nodes after position k are unchanged.
•	Test with k = 1 (no visible change), k = 7 (full reversal), and k = 4.
*/