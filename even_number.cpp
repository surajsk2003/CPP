#include <iostream>
#include <string>
using namespace std;


int main() {
    int n;
    cout << "Enter a number: ";  // asking user to input a number.
    cin >> n;

    if (n%2 == 0)
    {    cout << n << "is the a even number" << endl;}
    else {
        cout << n << "is not the a even number" << endl;
    }
    return 0;

     
}

