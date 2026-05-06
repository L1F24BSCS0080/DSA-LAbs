#include<iostream>
using namespace std;
void printRow(int row, int col) {
    // Base case: if col > row, print newline and return
    // -- write here --
    if (col > row) {
        cout << "\n";
        return;
    }
        // Print current col, then recurse for next col
        // -- write here --
        cout << col;
    printRow(row,col+1);
}

void printPattern(int n, int row) {
    // Base case: if row > n, return
    // -- write here --
    if (row > n) return;
    // Print row, then recurse for next row
    // -- write here --
    printRow(row,1);
    printPattern(n, row+1);
}

int main() {
    printPattern(5, 1);
    return 0;
}
//1
//1 2
//1 2 3
//1 2 3 4
//1 2 3 4 5
