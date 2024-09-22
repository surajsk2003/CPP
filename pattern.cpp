#include <iostream>
using namespace std;
int main()
{
    cout << "How many rows and columns of '*' do you want for this pattern?" << endl;
    int row, column;
    cin >> row >> column; // Correct the order to input rows first, then columns

    if (row == column) // Case when rows and columns are equal
    {
        for (int i = 0; i < row; i++)
        {
            // Print spaces for triangle alignment
            for (int j = 0; j < column - i - 1; j++)
            {
                cout << " ";
            }
            // Print stars
            for (int j = 0; j <= i; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
    else if (row > column) // Case when rows are greater than columns
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    else if (row < column) // Case when columns are greater than rows
    {
        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }

    return 0;
}
