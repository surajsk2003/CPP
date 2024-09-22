/*
#include <iostream>
#include <cmath>
using namespace std;


bool Is_prime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }

    return true;
}

int main() {
    int input;
    cout << "Enter the number: " << endl;
    cin >> input;

    if (Is_prime(input)) {
        cout << input << " is a prime number." << endl;
    } else {
        cout << input << " is not a prime number." << endl;
    }

    return 0;
}
*/

#include <iostream>
#include <cmath>
using namespace std;

bool Is_prime(int num) {
    if (num <= 1) 
        return false; // Handle 0 and 1 together
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string repeat;
    do {
        int number;
        cout << "Enter the number: " << endl;
        cin >> number;

        if (Is_prime(number)) {
            cout << number << " is a prime number." << endl;
        } else {
            cout << number << " is not a prime number." << endl;
        }

        cout << "Do you want to check another number? [y/n]: " << endl;
        cin >> repeat;

    } while (repeat == "y" || repeat == "Y");

    return 0;
}
