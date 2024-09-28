#include <iostream>
#include <vector>

using namespace std;

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------" << endl; // Print grid separator
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "|"; // Print column separator
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed in a given position
bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    // Check the row
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Check the column
    for (int x = 0; x < 9; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Check the 3x3 grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Backtracking function to solve the Sudoku
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // Check for an empty cell
            if (board[row][col] == 0) {
                // Try numbers from 1 to 9
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num; // Place the number

                        // Recur to see if it leads to a solution
                        if (solveSudoku(board)) {
                            return true;
                        }

                        // If it doesn't lead to a solution, reset the cell
                        board[row][col] = 0;
                    }
                }
                return false; // No number can be placed, trigger backtracking
            }
        }
    }
    return true; // Sudoku solved
}

int main() {
    // Example Sudoku puzzle (0 represents empty cells)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Sudoku Puzzle:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "Solved Sudoku:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}