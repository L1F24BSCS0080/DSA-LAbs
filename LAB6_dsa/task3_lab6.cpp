#include<iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue<string> q(10);
    string cmd;

    while (true)
    {
        cout << "\nEnter command (ADD / PRINT / EXIT): ";
        cin >> cmd;

        if (cmd == "ADD")
        {
            string doc;
            cout << "Enter document name: ";
            cin >> doc;

            if (q.isFull())
                cout << "Queue is full. Cannot add.";
            else
                q.Enqueue(doc);
        }
        else if (cmd == "PRINT")
        {
            if (q.isEmpty())
                cout << "No documents in queue.";
            else
                cout << "Printing: " << q.Dequeue();
        }
        else if (cmd == "EXIT")
        {
            break;
        }
    }
}