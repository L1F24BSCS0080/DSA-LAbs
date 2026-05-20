#pragma once
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

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

    void insertRecursive(T value, BNode<T>*& curr) {
        if (curr == nullptr) {
            curr = new BNode<T>(value);
            return;
        }

        if (value < curr->data)
            insertRecursive(value, curr->left);

        else if (value > curr->data)
            insertRecursive(value, curr->right);
    }

    void invertRecursive(BNode<T>* cur) {
        if (cur == nullptr)
            return;

        BNode<T>* temp = cur->left;
        cur->left = cur->right;
        cur->right = temp;

        invertRecursive(cur->left);
        invertRecursive(cur->right);
    }

    bool validateBST(BNode<T>* cur) {
        if (cur == nullptr)
            return true;

        if (cur->left != nullptr) {
            BNode<T>* temp = cur->left;
            while (temp->right != nullptr)
                temp = temp->right;

            if (temp->data >= cur->data)
                return false;
        }

        if (cur->right != nullptr) {
            BNode<T>* temp = cur->right;
            while (temp->left != nullptr)
                temp = temp->left;

            if (temp->data <= cur->data)
                return false;
        }

        return validateBST(cur->left) && validateBST(cur->right);
    }

public:

    BST() {
        root = nullptr;
    }

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

            if (value < cur->data)
                cur = cur->left;

            else if (value > cur->data)
                cur = cur->right;

            else {
                delete newnode;
                return;
            }
        }

        if (value < parent->data)
            parent->left = newnode;
        else
            parent->right = newnode;
    }

    void insertRecursive(T value) {
        insertRecursive(value, root);
    }

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

    void BFT() {
        if (root == nullptr)
            return;

        queue<BNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            BNode<T>* front = q.front();
            q.pop();

            cout << front->data << " ";

            if (front->left != nullptr)
                q.push(front->left);

            if (front->right != nullptr)
                q.push(front->right);
        }
    }

    void inorder_iterative() {
        if (root == nullptr)
            return;

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
        if (root == nullptr)
            return;

        stack<BNode<T>*> s;
        s.push(root);

        while (!s.empty()) {
            BNode<T>* cur = s.top();
            s.pop();

            cout << cur->data << " ";

            if (cur->right != nullptr)
                s.push(cur->right);

            if (cur->left != nullptr)
                s.push(cur->left);
        }
    }

    void postorder_iterative() {
        if (root == nullptr)
            return;

        stack<BNode<T>*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            BNode<T>* cur = s1.top();
            s1.pop();

            s2.push(cur);

            if (cur->left != nullptr)
                s1.push(cur->left);

            if (cur->right != nullptr)
                s1.push(cur->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }

    bool search_iter(T val) {
        BNode<T>* cur = root;

        while (cur != nullptr) {
            if (val == cur->data)
                return true;

            else if (val < cur->data)
                cur = cur->left;

            else
                cur = cur->right;
        }

        return false;
    }

    bool search_rec(BNode<T>* curr, T val) {
        if (curr == nullptr)
            return false;

        if (curr->data == val)
            return true;

        if (val < curr->data)
            return search_rec(curr->left, val);

        return search_rec(curr->right, val);
    }

    BNode<T>* getRoot() {
        return root;
    }

    int counttotal() {
        if (root == nullptr)
            return 0;

        int count = 0;
        queue<BNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            BNode<T>* front = q.front();
            q.pop();
            count++;

            if (front->left != nullptr)
                q.push(front->left);

            if (front->right != nullptr)
                q.push(front->right);
        }

        return count;
    }

    int countleafs(BNode<T>* cur) {
        if (cur == nullptr)
            return 0;

        if (cur->left == nullptr && cur->right == nullptr)
            return 1;

        return countleafs(cur->left) + countleafs(cur->right);
    }

    int height(BNode<T>* cur) {
        if (cur == nullptr)
            return -1;

        int leftH = height(cur->left);
        int rightH = height(cur->right);

        if (leftH > rightH)
            return 1 + leftH;
        else
            return 1 + rightH;
    }

    T min() {
        if (root == nullptr)
            return -1;

        BNode<T>* cur = root;

        while (cur->left != nullptr)
            cur = cur->left;

        return cur->data;
    }

    T max() {
        if (root == nullptr)
            return -1;

        BNode<T>* cur = root;

        while (cur->right != nullptr)
            cur = cur->right;

        return cur->data;
    }

    void invert() {
        invertRecursive(root);
    }

    bool validateBST() {
        return validateBST(root);
    }
};

int main() {
    BST<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder: ";
    tree.inorder(tree.getRoot());
    cout << endl;

    cout << "Preorder: ";
    tree.preorder(tree.getRoot());
    cout << endl;

    cout << "Postorder: ";
    tree.postorder(tree.getRoot());
    cout << endl;

    cout << "BFT: ";
    tree.BFT();
    cout << endl;

    cout << "Iterative Inorder: ";
    tree.inorder_iterative();
    cout << endl;

    cout << "Iterative Preorder: ";
    tree.preorder_iterative();
    cout << endl;

    cout << "Iterative Postorder: ";
    tree.postorder_iterative();
    cout << endl;

    cout << "Search 40: " << tree.search_iter(40) << endl;
    cout << "Search 100: " << tree.search_iter(100) << endl;

    cout << "Total Nodes: " << tree.counttotal() << endl;
    cout << "Leaf Nodes: " << tree.countleafs(tree.getRoot()) << endl;
    cout << "Height: " << tree.height(tree.getRoot()) << endl;
    cout << "Min: " << tree.min() << endl;
    cout << "Max: " << tree.max() << endl;

    cout << "BST Valid Before Invert: ";
    if (tree.validateBST())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    tree.invert();

    cout << "Inorder After Invert: ";
    tree.inorder(tree.getRoot());
    cout << endl;

    cout << "BST Valid After Invert: ";
    if (tree.validateBST())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
