#include <iostream>
#include <algorithm>  // For lower_bound() function
#include <vector>     // For storing the array
#include <string> // For
using namespace std;

int main() {
    int X;
    cout << "Enter the number to search for: ";  // Get the number to search for from the user
    cin >> X;
    int a[] = {1, 4, 4, 4, 4, 9, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);  // Calculate the size of the array
    int ind = lower_bound(a, a + n, X) - a;  // Get the lower bound index

    // Check if the found index actually contains X
    if (ind < n && a[ind] == X) {
        cout << a[ind] << endl;
    } else {
        cout << "-1" << endl;  // X is not found in the array
    }

    return 0;
}