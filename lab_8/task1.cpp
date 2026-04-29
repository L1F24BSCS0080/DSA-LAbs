#include<iostream>
using namespace std;


template <class T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <class T>
class CircularLinkedList {
private:
    Node<T>* tail;   // tail->next == head
public:
    CircularLinkedList() {
        tail = nullptr;
    }
    void insertEnd(T val) {
        Node<T>* newnode = new Node<T>(val);

        if (tail == nullptr) {
            tail = newnode;
            tail->next = tail;
        }
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
    Node<T>* getHead() {
        if (tail == nullptr) {
            return nullptr;
        }
        return tail->next;
    }
    int size() {
        if (tail == nullptr) {
            return 0;
        }
        int sz = 0;
        Node<T>* cur = tail->next;
        while (cur != tail) {
            sz++;
            cur = cur->next;
        }
        return sz + 1;
    }
    void display() {
        if (size() == 0) {
            cout << "empty list";
            return;
        }
        Node<T>* cur = tail->next;
        for (int i = 0; i < size(); i++) {
            cout << cur->data << "---";
            cur = cur->next;
        }
    }
};

Node<int>* findHour(Node<int>* head, int hour) {
    Node<int>* curr = head;
    while (curr->data != hour)
        curr = curr->next;
    return curr;
}
void tickHand(Node<int>*& hand, int ticks) {
    for (int i = 0; i < ticks; i++) {
        cout << hand->data << "->";
        hand = hand->next;
    }
    cout << hand->data << endl;
    cout << "\nHand is at " << hand->data << endl << endl;
}

int main() {
    CircularLinkedList<int> list;
    for (int i = 1; i < 13; i++) {
        list.insertEnd(i);
    }
    Node<int>* curr =  findHour(list.getHead(), 4);
    tickHand(curr, 6);
    tickHand(curr, 4);

    int sth, ticks;
    cout << "\n Enter starting hours ";
    cin >> sth;
    cout << "\n Enter ticks " ;
    cin >> ticks;
    curr = findHour(list.getHead(), sth);
    tickHand(curr, ticks);
}