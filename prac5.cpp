#include <iostream>

int main() {
    int n; // Number of rows
    std::cout << "Enter the number of rows: ";
    std::cin >> n;

    int num = 1; // Starting number
    for (int i = 1; i <= n; ++i) { // Loop for each row
        for (int j = 1; j <= i; ++j) { // Loop to print numbers in each row
            std::cout << num << " "; // Print the current number
            num++; // Increment the number
        }
        std::cout << std::endl; // Move to the next line after each row
    }

    return 0;
}