#include <iostream>
using namespace std;

// Forward declaration of class Y
class Y;

class X{
    int data;
    public:
        // Method to set the value of X's private member 'data'
        void setValue(int value){
            data = value;
        }
    // 'add' function is a friend of class X, so it can access private members
    friend void add(X, Y);    
};

// Full definition of class Y
class Y{
    int num;
    public:
        // Method to set the value of Y's private member 'num'
        void setValue(int value){
            num = value;
        }
    // 'add' function is a friend of class Y, so it can access private members
    friend void add(X, Y);    
};

// Function to add the private members of classes X and Y
void add(X o1, Y o2){
    cout << "Summing data of X and Y objects gives me " << o1.data + o2.num << endl;
}

class c2;

class c1{
    int val1;
    // 'exchange' function is a friend of class c1, so it can access private members
    friend void exchange(c1 & , c2 &);
    public:
        // Method to set the value of c1's private member 'val1'
        void indata(int a){
            val1 = a;
        }
        // Method to display the value of 'val1'
        void display(void){
            cout << val1 << endl;
        }
};

class c2{
    int val2;
    // 'exchange' function is a friend of class c2, so it can access private members
    friend void exchange(c1 &, c2 &);
    public:
        // Method to set the value of c2's private member 'val2'
        void indata(int a){
            val2 = a;
        }
        // Method to display the value of 'val2'
        void display(void){
            cout << val2 << endl;
        }
};

// Function to swap the values of private members 'val1' and 'val2' of c1 and c2
void exchange(c1 &x, c2 &y){
    int tmp = x.val1;   // Temporary variable to hold the value of c1's 'val1'
    x.val1 = y.val2;    // Assign c2's 'val2' to c1's 'val1'
    y.val2 = tmp;       // Assign the value of 'val1' stored in 'tmp' to c2's 'val2'
}

int main(){
    // First part: Creating objects of X and Y and adding their values
    X a1;
    a1.setValue(3);     // Set value for object a1 of class X

    Y b1;
    b1.setValue(15);    // Set value for object b1 of class Y

    add(a1, b1);        // Call the friend function to add values of a1 and b1

    // Second part: Creating objects of c1 and c2 and exchanging their values
    c1 oc1;
    c2 oc2;

    oc1.indata(34);     // Set value for object oc1 of class c1
    oc2.indata(67);     // Set value for object oc2 of class c2
    exchange(oc1, oc2); // Call the friend function to swap values of oc1 and oc2

    // Displaying the exchanged values
    cout << "The value of c1 after exchanging becomes: ";
    oc1.display();      // Display value of oc1 after swapping
    cout << "The value of c2 after exchanging becomes: ";
    oc2.display();      // Display value of oc2 after swapping

    return 0;
}
