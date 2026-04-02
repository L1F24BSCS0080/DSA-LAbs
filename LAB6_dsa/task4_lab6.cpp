#include<iostream>
#include "Queue.h"
using namespace std;

int main()
{
    int arr[5] = { 101, 102, 103, 102, 104 };

    Queue<int> mainQ(10);
    Queue<int> helperQ(10);

    for (int i = 0; i < 5; i++)
    {
        int roll = arr[i];
        bool found = false;

        while (!mainQ.isEmpty())
        {
            int val = mainQ.Dequeue();

            if (val == roll)
                found = true;

            helperQ.Enqueue(val);
        }

        while (!helperQ.isEmpty())
            mainQ.Enqueue(helperQ.Dequeue());

        if (found)
        {
            cout << "DUPLICATE FOUND: " << roll << endl;
        }
        else
        {
            mainQ.Enqueue(roll);
        }
    }

    cout << "\nUnique roll numbers: ";

    while (!mainQ.isEmpty())
        cout << mainQ.Dequeue() << " ";
}