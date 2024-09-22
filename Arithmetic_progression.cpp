
// #include<iostream>
// #include<cmath>
// #include<vector>
// #include<list>
// using namespace std;

// // find the arithmetic progression of the series


// int main()
// {   int a; 
//     int d;
//     int n, sum = 0, a_n;

//     cout << "Enter the number of terms: ";
//     cin >> n;  

//     cout << "Enter the first term: ";
//     cin >> a;

//     cout << "Enter the common difference: ";
//     cin >> d;

//     // calculate the nth term
//     a_n = a + (n - 1) * d;

//     // calculate the sum of the series
//     for (int i = a; i <= a_n; i += d) {
//         sum += i;
//     }

//     cout << "Sum of the series: " << sum << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <cmath>

using namespace std;

// Function to calculate the sum of the series
int calculateSum(const vector<int>& series) {
    int sum = 0;
    for (int number : series) {
        sum += number;
    }
    return sum;
}

// Function to get the last number of the series
int getLastNumber(const vector<int>& series) {
    if (!series.empty()) {
        return series.back();
    }
    return 0; // Or some error value indicating the series is empty
}

int main() {
    cout << "Enter integers for the arithmetic series (enter a non-integer to stop):" << endl;
    int input;
    vector<int> series;  // Using vector for indexing

    while (true) {
        cin >> input;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Input is not an integer. Exiting loop." << endl;
            break; // Exit the loop if the input is not an integer
        }

        series.push_back(input);
    }

    // Ensure at least 3 elements are entered to check arithmetic sequence
    if (series.size() >= 3) {
        int diff = series[1] - series[0];
        bool isArithmetic = true;

        for (size_t i = 2; i < series.size(); ++i) {
            if (series[i] - series[i - 1] != diff) {
                isArithmetic = false;
                break;
            }
        }

        if (isArithmetic) {
            cout << "The entered series is an arithmetic series with a common difference of " << diff << "." << endl;
        } else {
            cout << "The entered series is not an arithmetic series." << endl;
        }
    } else if (series.empty()) {
        cout << "No valid integers entered." << endl;
    } else {
        cout << "Not enough elements to determine if it's an arithmetic series." << endl;
    }

    // Prompt user for additional information
    cout << "Do you want to know the 'sum' or the 'last_number' of the series?" << endl;
    string choice;
    cin >> choice;

    if (choice == "sum") {
        cout << "Sum of the series: " << calculateSum(series) << endl;
    } else if (choice == "last_number") {
        cout << "Last number of the series: " << getLastNumber(series) << endl;
    } else {
        cout << "Invalid input. Please enter either 'sum' or 'last_number'." << endl;
    }

    return 0;
}

