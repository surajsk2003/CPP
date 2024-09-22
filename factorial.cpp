#include<iostream>
#include<cmath>
using namespace std;
int factorial(int number){
    {
        if(number <= 1)
            return 1;
    }
    return number * factorial(number - 1);
}

int main()
    {
        int number;
        cout << "Enter a number: " <<endl;
        cin >> number;
        int result = factorial(number);
        cout << "Factorial of " << number << " is: " << result << endl;
        return 0;
    }
