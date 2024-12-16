#include <iostream>
using namespace std;

// Function to print a single row
void printRow(int spaces, int stars) {
    for (int i = 0; i < spaces; i++) cout << " ";
    for (int i = 0; i < stars; i++) cout << "*";
    cout << endl;
}

// Recursive function to print the upper triangle
void printUpperTriangle(int currentRow, int totalRows) {
    if (currentRow > totalRows) return; // Base case

    int spaces = totalRows - currentRow;
    int stars = 2 * currentRow - 1;

    printRow(spaces, stars);

    printUpperTriangle(currentRow + 1, totalRows); // Recursive call
}

// Recursive function to print the lower triangle
void printLowerTriangle(int currentRow, int totalRows) {
    if (currentRow < 1) return; // Base case

    int spaces = totalRows - currentRow;
    int stars = 2 * currentRow - 1;

    printRow(spaces, stars);

    printLowerTriangle(currentRow - 1, totalRows); // Recursive call
}

int main() {
    int n = 9; // Total number of rows
    int mid = n / 2 + 1; // Middle row (5th for 9 rows)

    printUpperTriangle(1, mid); // Print the upper triangle
    printLowerTriangle(mid - 1, mid); // Print the lower triangle

    return 0;
}
