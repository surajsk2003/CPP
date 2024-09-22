#include <iostream>
using namespace std;

int main()
{
    string repeat;
    do
    {
        int n;
        cout << "Enter the value of n: "; // Input the value of n from the user.
        cin >> n;
        int sum;
        sum = 0;

        for (int counter = 1; counter <= n; counter++)
        {
            sum = sum + counter;
        }
        cout << "The sum of first " << n << " natural numbers is: " << sum << endl;
        cout << "Do you want to continue? (yes/no): "; // Ask the user if they want to continue.
        cin >> repeat;
    } while (repeat == "y" || repeat == "Y");
    return 0;
}