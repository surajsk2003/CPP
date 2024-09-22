#include<iostream>
#include<cmath>
using namespace std;

int fibonacci_sequence( int n){
    {if (n<=2) 
        return 1;
    }
    return fibonacci_sequence(n-1) + fibonacci_sequence(n-2);
}

int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"Fibonacci sequence: ";
    for(int i=1; i<=n; i++){
        cout<<fibonacci_sequence(i) <<" ";
    }
    return 0;
}