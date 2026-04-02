#include<iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue<int> q(10);

    int arr[5] = { 10, 20, 30, 40, 50 };

    cout << "Original array : ";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    for (int i = 0; i < 5; i++)
        q.Enqueue(arr[i]);

    for (int i = 4; i >= 0; i--)
        arr[i] = q.Dequeue();

    cout << "\nReversed array : ";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    cout << "\n\nEnter 5 numbers:\n";

    for (int i = 0; i < 5; i++)
        cin >> arr[i];

    for (int i = 0; i < 5; i++)
        q.Enqueue(arr[i]);

    for (int i = 4; i >= 0; i--)
        arr[i] = q.Dequeue();

    cout << "Reversed array : ";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}