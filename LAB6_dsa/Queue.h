#pragma once
#include<iostream>
using namespace std;

template <class T>
class Queue
{
private:
    int size;
    int front;
    int rear;
    T* arr;

public:
    Queue(int s)
    {
        size = s;
        front = -1;
        rear = -1;
        arr = new T[size];
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    void Enqueue(T val)
    {
        if (isFull())
            return;

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = val;
    }

    T Dequeue()
    {
        if (isEmpty())
            return T();

        T value = arr[front];
        front++;

        return value;
    }

    T getFront()
    {
        if (isEmpty())
            return T();

        return arr[front];
    }

    T getRear()
    {
        if (isEmpty())
            return T();

        return arr[rear];
    }
};