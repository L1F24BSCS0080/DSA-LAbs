#pragma once
#include<iostream>
using namespace std;

template <class T>
class CQueue
{
private:
    int size;
    int front;
    int rear;
    T* arr;

public:
    CQueue(int s)
    {
        size = s;
        front = -1;
        rear = -1;
        arr = new T[size];
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void Enqueue(T val)
    {
        if (isFull())
            return;

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        arr[rear] = val;
    }

    T Dequeue()
    {
        if (isEmpty())
            return T();

        T value = arr[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }

        return value;
    }

    T getFront()
    {
        if (isEmpty())
            return T();

        return arr[front];
    }
};