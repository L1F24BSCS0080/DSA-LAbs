#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <class T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList();
    void insertEnd(T val);
    void insertFront(T val);
    void insertBefore(T val, int node_no);
    void removeFront();
    void removeAny(int node_no);
    bool search(T val);
    void display();
    bool isEmpty();
    Node<T>* getHead();
    int size();
    bool searchList(Node<T>* head, int target);
   void deleteList(Node<T>* head);
};

// ─────────────────────────────────────────────
// Constructor
// ─────────────────────────────────────────────
template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

// ─────────────────────────────────────────────
// isEmpty : returns true if list has no nodes
// ─────────────────────────────────────────────
template <class T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

// ─────────────────────────────────────────────
// getHead : returns the head pointer
// ─────────────────────────────────────────────
template <class T>
Node<T>* LinkedList<T>::getHead() {
    return head;
}

// ─────────────────────────────────────────────
// size : counts and returns total nodes
// ─────────────────────────────────────────────
template <class T>
int LinkedList<T>::size() {
    int count = 0;
    Node<T>* curr = head;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;
}

// ─────────────────────────────────────────────
// display : prints all node values
// e.g.  10 -> 20 -> 30 -> NULL
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::display() {
    Node<T>* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

// ─────────────────────────────────────────────
// insertFront : creates new node and places it
//               before the current head
//
//   NEW -> [old head] -> ... -> NULL
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::insertFront(T val) {
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;   // point new node to old head
    head = newNode;         // update head to new node
}

// ─────────────────────────────────────────────
// insertEnd : walks to the last node and links
//             the new node after it
//
//   head -> ... -> [old last] -> NEW -> NULL
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::insertEnd(T val) {
    Node<T>* newNode = new Node<T>(val);

    if (isEmpty()) {            // empty list: new node becomes head
        head = newNode;
        return;
    }

    Node<T>* curr = head;
    while (curr->next != nullptr)   // walk to last node
        curr = curr->next;

    curr->next = newNode;           // link new node at the end
}

// ─────────────────────────────────────────────
// insertBefore : inserts a new node BEFORE the
//                node at position node_no
//                (1-based index)
//
//   Example  node_no = 3:
//   head -> 1 -> 2 -> NEW -> [old 3] -> 4 -> NULL
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::insertBefore(T val, int node_no) {
    if (node_no < 1 || node_no > size() + 1) {
        cout << "Invalid position." << endl;
        return;
    }

    if (node_no == 1) {         // inserting before head is just insertFront
        insertFront(val);
        return;
    }

    Node<T>* newNode = new Node<T>(val);
    Node<T>* curr = head;

    // walk to the node just BEFORE the target position
    for (int i = 1; i < node_no - 1; i++)
        curr = curr->next;

    newNode->next = curr->next; // new node points to the target node
    curr->next = newNode;       // previous node points to new node
}

// ─────────────────────────────────────────────
// removeFront : unlinks and deletes the head
//               node, advancing head forward
//
//   [head] -> 2 -> 3 -> NULL
//    DELETE      new head = 2
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::removeFront() {
    if (isEmpty()) {
        cout << "List is empty. Nothing to remove." << endl;
        return;
    }

    Node<T>* temp = head;   // save current head
    head = head->next;      // move head forward
    delete temp;            // free old head
}

// ─────────────────────────────────────────────
// removeAny : removes the node at position
//             node_no (1-based index)
//
//   Example  node_no = 3:
//   head -> 1 -> 2 -> [DELETE] -> 4 -> NULL
//                 ^               ^
//                 prev->next  =  curr->next
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::removeAny(int node_no) {
    if (isEmpty()) {
        cout << "List is empty. Nothing to remove." << endl;
        return;
    }

    if (node_no < 1 || node_no > size()) {
        cout << "Invalid position." << endl;
        return;
    }

    if (node_no == 1) {     // removing head is just removeFront
        removeFront();
        return;
    }

    Node<T>* prev = head;

    // walk prev to the node just BEFORE the target
    for (int i = 1; i < node_no - 1; i++)
        prev = prev->next;

    Node<T>* target = prev->next;   // node to delete
    prev->next = target->next;      // bypass the target
    delete target;                  // free memory
}

// ─────────────────────────────────────────────
// search : traverses the list looking for val
//          returns true if found, false if not
// ─────────────────────────────────────────────
template <class T>
bool LinkedList<T>::search(T val) {
    Node<T>* curr = head;
    while (curr != nullptr) {
        if (curr->data == val)
            return true;
        curr = curr->next;
    }
    return false;
}
template <class T>
bool LinkedList<T>::searchList(Node<T>* head, int target) {
    // Base case 1: reached end of list, not found
    // -- write here --
    if (head == NULL) return false;
    // Base case 2: current node matches target
    // -- write here --
    if (head->data == target) return true;

    // Recursive case: search the rest of the list
    // -- write here --
    return searchList(head->next, target);
}
template <class T>
void LinkedList<T>::deleteList(Node<T>* head) {
    // Base case: if head is nullptr, nothing to delete
    // -- write here --
    if (head == NULL) return ;
    // Recursive case: delete the rest of the list first
    // -- write here --
    deleteList(head->next);
    // Now delete the current node and set head to nullptr
    // -- write here --
    delete head;
    head = NULL;
}

int main() {
    // Build list: 10 -> 20 -> 30 -> 40 -> 50
    LinkedList<int> List;
    List.insertEnd(10);
  /*  List.insertEnd(20);
    List.insertEnd(30);
    List.insertEnd(40);
    List.insertEnd(50);
    List.insertEnd(60);*/
    // search List
    List.display();
    Node<int>* head = List.getHead();
    List.deleteList(head);
    cout << "\nafter deleting\n";
 
    List = LinkedList<int>();
    List.display();
    return 0;
}
