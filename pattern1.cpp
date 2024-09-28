#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Pattern class to handle pattern printing
class Pattern
{
public:
    // Function to take input for number of rows and columns
    void input(int &rows, int &columns) {
        cout << "Enter the number of rows and columns: ";
        cin >> rows >> columns; // Store user input into rows and columns
    }

    // Function to print a normal rectangle pattern of stars
    void printPattern1(int rows, int columns) {
        for (int i = 0; i < rows; i++) { // Loop through each row
            for (int j = 0; j < columns; j++) { // Loop through each column
                cout << "* "; // Print the star followed by a space
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print a right triangle pattern of stars
    void printPattern2(int rows, int columns) {
        for (int i = 1; i <= rows; i++) { // Loop through rows
            for (int j = 1; j <= i; j++) { // Print increasing number of stars for each row
                cout << "* "; // Print the star followed by a space
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print an inverted triangle pattern of stars
    void printPattern3(int rows, int columns) {
        for (int i = 1; i <= rows; i++) { // Loop through rows
            for (int j = rows - i; j > 0; j--) { // Print decreasing spaces for each row
                cout << " "; // Print space before stars
            }
            for (int j = 1; j <= i; j++) { // Print increasing number of stars for each row
                cout << "* "; // Print the star followed by a space
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print an inverted rectangle pattern of stars
    void printPattern4(int rows, int columns) {
        for (int i = 1; i <= rows; i++) { // Loop through rows
            for (int j = 1; j <= columns; j++) { // Loop through columns
                // Print '*' for the borders of the rectangle
                if (i == 1 || i == rows || j == 1 || j == columns) {
                    cout << "* "; // Print the star followed by a space
                } else {
                    cout << "  "; // Print spaces for the inner portion
                }
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print a numeric rectangle pattern
    void printPattern5(int rows, int columns) {
        for (int i = 1; i <= rows; i++) { // Loop through rows
            for (int j = 1; j <= columns; j++) { // Loop through columns
                cout << i << " "; // Print the row number followed by a space
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print a numeric triangle pattern
    void printPattern6(int rows, int columns) {
        for (int i = 1; i <= rows; i++) { // Loop through rows
            for (int j = 1; j <= i; j++) { // Loop through columns
                cout << j << " "; // Print numbers from 1 to i
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print a numeric pattern where each row consists of the row number
    void printPattern7(int rows, int columns) {
        for (int i = 1; i <= rows; i++) { // Loop through rows
            for (int j = 0; j < i; j++) { // Loop for current row number
                cout << i; // Print the current row number
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print an inverted triangle pattern of stars
    void printPattern8(int rows, int columns) {
        for (int i = 1; i <= rows; i++) { // Loop through rows
            for (int j = 0; j <= rows - i; j++) { // Print stars decreasing with each row
                cout << "* "; // Print the star followed by a space
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print a pattern with stars in rhombus shape
    void printPattern9(int rows, int columns) {
        for (int i = 1; i <= rows; i++) { // Loop through rows
            for (int j = 1; j <= rows - i; j++) { // Print leading spaces
                cout << " "; // Print leading spaces
            }
            for (int j = 1; j <= rows; j++) { // Print fixed number of stars
                cout << "* "; // Print the star followed by a space
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print an inverted rhombus pattern of stars
    void printPattern10(int rows, int columns) {
        for (int i = 1; i <= rows; i++) { // Loop through rows
            for (int j = 0; j < i; j++) { // Print spaces before stars
                cout << " "; // Print the space before stars
            }
            for (int j = rows; j >= i; j--) { // Print decreasing stars
                cout << "* "; // Print the star followed by a space
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print a double inverted triangle pattern
    void printPattern11(int rows, int columns) {
        // Upper part of the pattern
        for (int i = 1; i <= rows; i++) { // Loop for upper triangle
            for (int j = 1; j <= rows - i; j++) { // Print leading spaces
                cout << " "; // Print leading spaces
            }
            for (int j = 1; j <= i; j++) { // Print stars
                cout << "* "; // Print the star followed by a space
            }
            cout << endl; // Move to the next line after printing a row
        }
        
        // Lower part of the pattern
        for (int i = 1; i <= rows; i++) { // Loop for lower triangle
            for (int j = 0; j < i; j++) { // Print leading spaces
                cout << " "; // Print leading spaces
            }
            for (int j = rows - 1; j >= i; j--) { // Print stars
                cout << "* "; // Print the star followed by a space
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print a star pattern that creates a diamond shape
    void printPattern12(int rows, int columns) {
        for (int i = 0; i < rows; i++) { // Loop through upper part of diamond
            for (int j = 0; j < i; j++) { // Print leading stars
                cout << "* "; // Print the star followed by a space
            }
            cout << endl; // Move to the next line after printing a row
        }
        for (int i = 0; i < rows; i++) { // Loop through lower part of diamond
            for (int j = rows - 1; j >= i; j--) { // Print leading stars
                cout << "* "; // Print the star followed by a space
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    // Function to print a pattern of alternating 1s and 0s
    void printPattern13(int rows, int columns) {
        // Loop to print the rows
        for (int i = 1; i <= rows; i++) {
            // Print alternating 1s and 0s based on the row index
            for (int j = 1; j <= i; j++) {
                if (i % 2 == 0) {
                    cout << ((j % 2 == 0) ? "1 " : "0 "); // Even row: 1 at even index, 0 at odd index
                } else {
                    cout << ((j % 2 == 0) ? "0 " : "1 "); // Odd row: 0 at even index, 1 at odd index
                }
            }
            cout << endl; // Move to the next line after printing a row
        }
    }

    void printPattern14(int row, int columns){
        for (int i = 1; i <=row; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout<<j ;
            }
            for (int k = i+1 ; k<= 2*row -i ; k++)
            {
                cout<<" ";
            }
            for (int l =  i;l >=1; l--)
            {
                cout<<l ;
            }
            cout<<endl;
            
        }
    }
    void printPattern15(int row, int columns) {
        int num = 1; // Starting number
        for (int i = 1; i <= row; ++i) { // Loop for each row
            for (int j = 1; j <= i; ++j) { // Loop to print numbers in each row
                std::cout << num << " "; // Print the current number
                num++; // Increment the number
            }
                std::cout << std::endl; // Move to the next line after each row
        }

    // Print the pattern in reverse order
    }


};
int main()
{
    Pattern pattern;   // Create an instance of the Pattern class
    int rows, columns; // Declare variables for rows and columns

    pattern.input(rows, columns); // Get user input for rows and columns

    cout << "Normal rectangle pattern:" << endl;
    pattern.printPattern1(rows, columns); // Print the rectangular pattern

    cout << "Right triangle pattern:" << endl;
    pattern.printPattern2(rows, columns); // Print the right-angled triangle pattern

    cout << "Inverted triangle pattern:" << endl;
    pattern.printPattern3(rows, columns); // Print the inverted right-angled triangle pattern

    cout << "Inverted rectangle pattern:" << endl;
    pattern.printPattern4(rows, columns); // Print the inverted rectangular pattern

    cout << "Numeric rectangle pattern:" << endl;
    pattern.printPattern5(rows, columns); // Print the numeric rectangle pattern

    cout << "Integer triangular pattern:" << endl;
    pattern.printPattern6(rows, columns); // Print the integer triangle pattern

    cout << "Numeric triangular pattern:" << endl;
    pattern.printPattern7(rows, columns); // Print the numeric triangle pattern

    cout << "Inverted triangle pattern:" << endl;
    pattern.printPattern8(rows, columns); // Print the inverted star pattern

    cout << "Rhombus pattern:" << endl;
    pattern.printPattern9(rows, columns); // Print the rhombus pattern

    cout << "Inverted triangle pattern:" << endl;
    pattern.printPattern10(rows, columns); // Print the inverted rhombus pattern

    cout << "Inverted star pattern:" << endl;
    pattern.printPattern11(rows, columns); // Print the inverted star pattern

    cout << "Star pattern:" << endl;
    pattern.printPattern12(rows, columns); // Print the star pattern

    cout << "Isosceles triangle pattern:" << endl;
    pattern.printPattern13(rows, columns); // Print the isosceles triangle pattern

    cout << "Pyramid pattern:" << endl;
    pattern.printPattern14(rows, columns); // Print the pyramid pattern

    cout << "Fountain pattern:" << endl;
    pattern.printPattern15(rows, columns); // Print the fountain pattern

    return 0;
}