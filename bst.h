#pragma once
#include<iostream>
#include<queue>
#include<stack>
using namespace std;


//Task 1:
//•	Write a BST Node class BNode as a template class with data portion, left and right child along with a constructor to initialize the given attributes.
//•	Write a template BST Class with the root pointer only.Add a public constructor to initialize root with the NULLPTR.

template<class T>
class BNode {
public:
    T data;
    BNode<T>* left;
    BNode<T>* right;

    BNode(T d) {
        data = d;
        left = right = nullptr;
    }
};

template<class T>
class BST {
private:
    BNode<T>* root;


public:

    BST() {
        root = nullptr;
    }

    //Task 2:
    //•	Write iterative insert function in the BST class as void insert(T value);

    void insert(T value) {

        BNode<T>* newnode = new BNode<T>(value);

        if (root == nullptr) {
            root = newnode;
            return;
        }

        BNode<T>* cur = root;
        BNode<T>* parent = nullptr;

        while (cur != nullptr) {

            parent = cur;

            if (value < cur->data) {
                cur = cur->left;
            }
            else if (value > cur->data) {
                cur = cur->right;
            }
            else
                return;

        }

        if (value < parent->data) {
            parent->left = newnode;
        }
        else {
            parent->right = newnode;
        }
    }

    //Task 3:
    //•	Try writing the recursive insert function in the BST class .

    void insertRecursive(T value, BNode<T>*& curr) {

        if (curr == nullptr) {
            curr = new BNode<T>(value);
            return;
        }

        if (value < curr->data) {
            insertRecursive(value, curr->left);
        }
        else if (value > curr->data) {
            insertRecursive(value, curr->right);
        }
    }

    //Task 4:
    //•	Write recursive inorder traversal in BST class using the function void inorder(BNode<T>* curr);
    //•	Write recursive preorder traversal in BST class using the function void preorder(BNode<T>* curr);
    //•	Write recursive postorder traversal in BST class using the function void postorder(BNode<T>* curr);

    void inorder(BNode<T>* cur) {

        if (cur != nullptr) {
            inorder(cur->left);
            cout << cur->data << " ";
            inorder(cur->right);
        }
    }

    void preorder(BNode<T>* cur) {

        if (cur != nullptr) {
            cout << cur->data << " ";
            preorder(cur->left);
            preorder(cur->right);
        }
    }

    void postorder(BNode<T>* cur) {

        if (cur != nullptr) {
            postorder(cur->left);
            postorder(cur->right);
            cout << cur->data << " ";
        }
    }

    //Task 5:
    //•	 Write iterative Breadth first traversal using queue as discussed in the class.


    void BFT() {

        if (root == nullptr) {
            return;
        }

        queue<BNode<T>*> q;
        q.push(root);

        while (!q.empty()) {

            BNode<T>* front = q.front();
            q.pop();

            cout << front->data << " ";

            if (front->left != nullptr) {
                q.push(front->left);
            }

            if (front->right != nullptr) {
                q.push(front->right);
            }
        }
    }

    //Task 6:
    //•	Write iterative inorder traversal in BST class using Stack as discussed in the class.
    //    •	Write iterative preorder traversal in BST class using Stack as discussed in the class.


    void inorder_iterative() {

        if (root == nullptr) {
            return;
        }

        stack<BNode<T>*> s;
        BNode<T>* cur = root;

        while (cur != nullptr || !s.empty()) {

            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();

            cout << cur->data << " ";

            cur = cur->right;
        }
    }

    void preorder_iterative() {

        if (root == nullptr) {
            return;
        }

        stack<BNode<T>*> s;
        s.push(root);

        while (!s.empty()) {

            BNode<T>* cur = s.top();
            s.pop();

            cout << cur->data << " ";

            if (cur->right != nullptr) {
                s.push(cur->right);
            }

            if (cur->left != nullptr) {
                s.push(cur->left);
            }
        }
    }

    /* Task 7:
     •	Write iterative postorder traversal in BST class using two stacks.
     Push root into stack 1, pop into stack 2 while pushing left then right to stack 1, then print stack 2 contents.Here stack 2 collects results in reverse.*/

    void postorder_iterative() {

        if (root == nullptr) {
            return;
        }
        stack<BNode<T>*> s1;
        stack<BNode<T>*> s2;

        s1.push(root);

        while (!s1.empty()) {
            BNode<T>* cur = s1.top();
            s1.pop();

            s2.push(cur);


            if (cur->left != nullptr) {
                s1.push(cur->left);
            }


            if (cur->right != nullptr) {
                s1.push(cur->right);
            }
        }


        while (!s2.empty()) {

            cout << s2.top()->data << " ";
            s2.pop();
        }
    }
    //Task 8:
    //•	Write iterative search function in BST, returning bool.  bool search_iter(T val);
    //•	Write recursive search function in BST returning bool.  bool search_rec(BNode<T>* curr, T val);

    bool search_iter(T val) {

        BNode<T>* cur = root;

        while (cur != nullptr) {

            if (val == cur->data) {
                return true;
            }

            else if (val < cur->data) {
                cur = cur->left;
            }

            else {
                cur = cur->right;
            }
        }

        return false;
    }


    bool search_rec(BNode<T>* curr, T val) {

        if (curr == nullptr) {
            return false;
        }
        if (curr->data == val) {
            return true;
        }
        if (val < curr->data) {
            return search_rec(curr->left, val);
        }
        return search_rec(curr->right, val);
    }


    BNode<T>* getRoot() {
        return root;
    }
    //lab 11
    //task1
    int counttotal() {
        int count = 0;
        if (root == nullptr) {
            return;
        }

        queue<BNode<T>*> q;
        q.push(root);

        while (!q.empty()) {

            BNode<T>* front = q.front();
            q.pop();
            count++;
            cout << front->data << " ";

            if (front->left != nullptr) {
                q.push(front->left);
            }

            if (front->right != nullptr) {
                q.push(front->right);
            }
        }
        return count;

    }
    //task2 
    int countleafs(BNode<int>* cur) {
        if (cur == NULL) return 0;
        if (cur->left == nullptr && cur->right== nullptr) return 1;
        return countleafs(cur->left) + countleafs(cur->right);
    }
    //task3
    int height(BNode<int>* cur) {
        if (cur == nullptr) return -1;
        if (cur->left == nullptr && cur->right == nullptr) return 0;
        return 1 + max(height(cur->left), height(cur->right));
    }
    //task4 a
    int min() {
        BNode<int>* cur = root;
        while (cur->left != nullptr) {
            cur = cur->left;
        }
        return cur->data;
    }
    //task4 b
    int max() {
        BNode<int>* cur = root;
        while (cur->right != nullptr) {
            cur = cur->right;
        }
        return cur->data;
    }
    //task5 
    void swapit(BNode<int>* &n1, BNode<int>* &n2) {
        if (n1 == NULL && n2 == NULL) {
            return;
        }
        swap(n1, n2);
        if(n1!=NULL)  swapit(n1->left, n1->right);
        if(n2!=NULL)  swapit(n2->left, n2->right);
    }
    void invert() {
        BNode<int>* cur = root;
        swapit(cur->left, cur->right);
    }
    //task6

};
