#include<iostream>
#include "LinkeList.h"

using namespace std;


int main() {
	LinkedList<int> l1;
	l1.insertFront(3);
	l1.insertFront(8);
	l1.insertFront(15);
	l1.insertFront(22);



	l1.display();
	Node<int>* slow = l1.getHead();
	Node<int>* fast = l1.getHead();


	while (fast != nullptr && fast->next != nullptr) {

		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "middle node: ";
	cout<<slow->data;
}

/*
•	Declare a LinkedList<int> and insert: {10, 20, 30, 40, 50}.
•	Traverse the list and push each node's data onto a Stack<int> of size 50, counting nodes as you go.
•	The middle index is count / 2 (0-based). Pop elements from the stack (count - middle index) times; the last popped value is the middle.
•	Alternatively, traverse the list again and stop at position count / 2 to read the middle directly.
•	Print the middle node value. Test with both an odd-length list (5 nodes) and an even-length list (6 nodes, take the second of the two middle nodes).
*/