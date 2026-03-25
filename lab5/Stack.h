#include <iostream>
using namespace std;

template<class T>
class Stack
{
    T* arr;
    int size;
    int top;  

public:

    Stack(int ssize)
    {
        size = ssize;
        arr = new T[size];   
        top = -1; 
    }

    bool isEmpty()
    {
        return (top == -1);

    }

    bool isFull()
    {
        return (top == size - 1);

    }

    void push(T value)
    {
        if (!isFull())
            arr[++top] = value;
        else
            cout << "Stack is Full";
    }

    T pop()
    {
        T temp = arr[top];
        top--;
        return temp;

    }

    T peek()
    {
      
        return arr[top];
    }
 

};

