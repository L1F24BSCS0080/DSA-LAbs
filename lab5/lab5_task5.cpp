#include<iostream>
#include "Stack.h"
using namespace std;
int main() {
    cout << "-----WELCOME TO BROWSER------\n";
    string command, url;
    Stack<string> backward(20);
    Stack<string> forward(20);
    string currentpage;
    while (true) {
        cin >> command;
        if (command == "VISIT") {
            cout << "\nPage : ";
            cin >> url; 
            while (!forward.isEmpty()) {
                forward.pop();
            }
            if (currentpage != "") {
                backward.push(currentpage);
            }
            currentpage = url;
            cout << "current page : " << currentpage << endl;
        }


        else if (command == "BACK") { 
            if (backward.isEmpty()) {
                cout << "Nothing to go back to.\n";
                continue;
            }
            forward.push(currentpage);
            currentpage = backward.peek();
            backward.pop();
            cout << "Current: " << currentpage << endl;
        }
        else if (command == "FORWARD") { 
            if (forward.isEmpty()) {
                cout << "Nothing to go forward to.\n";
                continue;
            }
            backward.push(currentpage);
            currentpage = forward.peek();
            forward.pop();
            cout << "Current: " << currentpage << endl;
        }
        else if (command == "EXIT") {
            break; 
        }
    }

}