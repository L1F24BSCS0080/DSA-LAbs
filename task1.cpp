#include"bst.h"
int main() {
	BST <int> bst;
	bst.insert(10);
	bst.insert(5);
	bst.insert(15);
	bst.insert(1);
	bst.insert(7);
	bst.insert(12);
	bst.insert(17);
	bst.BFT();
	cout << endl;

}