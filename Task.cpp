#include <iostream>
using namespace std;

const int N = 9;

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0 && row != 0) {
            cout << "------+-------+------" << endl;
        }
        for (int col = 0; col < N; col++) {
            if (col % 3 == 0 && col != 0) {
                cout << "| ";
            }
            if (grid[row][col] == 0) {
                cout << ". ";
            }
            else {
                cout << grid[row][col] << " ";
            }
        }
        cout << endl;
    }
}
bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num || grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num)
            return false;
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool isEmpty = true;
    // Find an empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
            break;
    }
    // If no empty cell is found, puzzle is solved
    if (isEmpty)
        return true;
    // Try placing numbers 1 to 9 in the cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // Place the number if it's safe
            grid[row][col] = num;
            // Recursively try to solve the rest of the puzzle
            if (solveSudoku(grid))
                return true;
            // If placing num in (row, col) doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }
    // If no number can be placed, backtrack
    return false;
}

int main() {
    // Example
    int grid[N][N] = { {5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9} };
    // Before 
    printGrid(grid);
    cout << "\n---------------------------------------\n\n";
    // After
    if (solveSudoku(grid))
        printGrid(grid);
    else
        cout << "No solution exists";

    return 0;
}
