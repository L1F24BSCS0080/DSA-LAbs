#include<iostream>
#include "CQueue.h"
using namespace std;

void printHistory(CQueue<string>& q)
{
    string temp[10];
    int i = 0;

    while (!q.isEmpty())
    {
        temp[i] = q.Dequeue();
        cout << temp[i] << " ";
        i++;
    }

    for (int j = 0; j < i; j++)
        q.Enqueue(temp[j]);
}

int main()
{
    string searches[8] = { "arrays","queues","stacks","trees","graphs","sorting","hashing","recursion" };

    CQueue<string> q(3);

    for (int i = 0; i < 8; i++)
    {
        cout << "\nSearch: " << searches[i] << " -> ";

        if (q.isFull())
            q.Dequeue();

        q.Enqueue(searches[i]);

        cout << "History: ";
        printHistory(q);
    }

    cout << "\n\nFinal last 3 searches: ";
    printHistory(q);

    cout << "\n\nEnter 5 searches:\n";

    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;

        if (q.isFull())
            q.Dequeue();

        q.Enqueue(s);
    }

    cout << "Updated history: ";
    printHistory(q);
}