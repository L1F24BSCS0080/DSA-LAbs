#include<iostream>
using namespace std;


template <class T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;
    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

template <class T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    DoublyLinkedList() {
        head = tail = NULL;
    }
    void insertEnd(T val) {
        Node<T>* newnode = new Node<T>(val);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    void displayForward()
    {
        Node<T>* cur = head;
        while (cur != nullptr) {
            cout << cur->data ;
            if(cur->next!=nullptr) cout << "-";
            cur = cur->next;
        }
    }// head -> ... -> tail

    void displayBackward() {
        Node<T>* cur = tail;
        while (cur != nullptr) {
            cout << cur->data;
            if (cur->prev != nullptr) cout << "-";
            cur = cur->prev;
        }
    }
    Node<T>* getHead() {
        return head;
    }
    Node<T>* getTail() {
        return tail;
    }
    int size() {
        Node<T>* cur = tail;
        int sz = 0;
        while (cur != nullptr) {
            sz++;
            cur = cur->prev;
        }
        return sz;
    }

};
void nextImage(DoublyLinkedList<string> list,Node<string>*& cur) {
    if (cur == list.getTail()) {
        cout << "already at last image";
        cout << endl;
        return;
    }
    cur = cur->next;
    cout << "next-> viewing " << cur->data << endl;

}
void prevImage(DoublyLinkedList<string> list, Node<string>*& cur) {
    if (cur == list.getHead()) {
        cout << "already at first image";
        cout << endl;
        return;
    }
    cur = cur->prev;
    cout << "prev-> viewing " << cur->data << endl;

}
int main() {
    DoublyLinkedList<string> list;
//Gallery: Sunset.jpg < ->Mountain.jpg < ->Beach.jpg < ->Forest.jpg < ->City.jpg
    list.insertEnd("sunset.jpg");
    list.insertEnd("Mountain.jpg");
    list.insertEnd("Beach.jpg");
    list.insertEnd("Forest.jpg");
    list.insertEnd("City.jpg");
    Node<string>* curr = list.getHead();

    nextImage(list, curr);
    nextImage(list, curr);
    nextImage(list, curr);
    nextImage(list, curr);
    nextImage(list, curr);
    nextImage(list, curr);
    cout << endl<<"-------------------"<<endl;
    prevImage(list, curr);
    prevImage(list, curr);
    prevImage(list, curr);
    prevImage(list, curr);
    prevImage(list, curr);
    prevImage(list, curr);
}