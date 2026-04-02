#include<iostream>
#include "Queue.h"
using namespace std;

template <class T>
class Stack
{
private:
    int top;
    int size;
    T* arr;

public:
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new T[size];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(T val)
    {
        if (top == size - 1)
            return;

        top++;
        arr[top] = val;
    }

    T pop()
    {
        if (isEmpty())
            return T();

        T val = arr[top];
        top--;
        return val;
    }
};

int main()
{
    Stack<char> s(20);
    Queue<char> q(20);

    char word[50];

    cout << "Enter word: ";
    cin >> word;

    int len = 0;
    while (word[len] != '\0')
        len++;

    for (int i = 0; i < len; i++)
    {
        s.push(word[i]);
        q.Enqueue(word[i]);
    }

    bool isPalindrome = true;

    cout << "\nStack pops : ";
    for (int i = 0; i < len; i++)
    {
        char a = s.pop();
        cout << a << " ";
    }

    cout << "\nQueue deq  : ";
    for (int i = 0; i < len; i++)
    {
        char b = q.Dequeue();
        cout << b << " ";
    }

    for (int i = 0; i < len; i++)
    {
        char a = word[i];
        char b = word[len - i - 1];

        if (a != b)
            isPalindrome = false;
    }

    cout << "\n\nResult: ";
    if (isPalindrome)
        cout << "PALINDROME";
    else
        cout << "NOT A PALINDROME";
}