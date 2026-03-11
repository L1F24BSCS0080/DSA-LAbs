
#include <iostream>
using namespace std;

template<class T>
class Array {
public:
    int maxsize;
    int currsize;
    T* arr;

    Array(int sz) {
        maxsize = sz;
        currsize = 0;
        arr = new T[maxsize];
    }

    void insertval(T val) {
        if (this->isfull()) {
            cout << "array is already full" << endl;
            return;
        }
        this->arr[this->currsize] = val;
        this->currsize++;
    }
    int search(T val) {
        int index = -3;
        for (int i = 0; i < this->currsize; i++) {
            if (this->arr[i] == val) {
                index = i;
                break;
            }
        }
        if (index == -3) {
            cout << "value is not present\n";
            return -1;
        }
        else return index;
    }
    void removeval(T val) {
        if (this->isempty()) {
            cout << "Array is empty" << endl;
            return;
        }
        int index = -3;
        for (int i = 0; i < this->currsize; i++) {
            if (this->arr[i] == val) {
                index = i;
                break;
            }
        }
        if (index == -3) {
            cout << "value is not present\n";
            return;
        }
        for (int i = index; i < this->currsize - 1; i++) {
            this->arr[i] = this->arr[i + 1];
        }
        this->currsize--;
        cout << "value removed\n";
    }
    void display() {
        for (int i = 0; i < this->currsize; i++) {
            cout << i << "." << this->arr[i] << endl;
        }
    }
    bool isempty() {
        return (this->currsize == 0);
    }
    bool isfull() {
        return (this->currsize == this->maxsize);
    }

    virtual ~Array() {
        delete[] arr;
    }
};