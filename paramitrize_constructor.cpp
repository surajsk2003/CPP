/*This code demonstrates the concept of parameterized constructors in two separate examples: one with a Complex class representing complex numbers and another with a Point class representing coordinates on a 2D plane.

First Example: Complex Class

	•	Purpose: It models a complex number of the form a + bi, where a and b are integers.
	•	Constructor: The constructor Complex(int, int) initializes the private members a and b using the values passed during object creation.

Code Explanation:*/

#include<iostream>
using namespace std;

class Complex {
    int a, b;  // Private members

public:
    Complex(int, int); // Constructor declaration

    void printNumber() {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

// Constructor definition
Complex :: Complex(int x, int y) {
    a = x;
    b = y;
}

int main() {
    // Implicit call
    Complex a(4, 6);
    a.printNumber();  // Output: "Your number is 4 + 6i"

    // Explicit call
    Complex b = Complex(5, 7);
    b.printNumber();  // Output: "Your number is 5 + 7i"

    return 0;
}

/*1.	Implicit call: Complex a(4, 6); directly initializes a and b using the constructor.
	2.	Explicit call: Complex b = Complex(5, 7); explicitly calls the constructor to create an object.
	3.	Output: Displays complex numbers in the form a + bi.

Second Example: Point Class

	•	Purpose: It models a point (x, y) in a 2D space.
	•	Constructor: The constructor Point(int, int) initializes the coordinates x and y.

Code Explanation:*/

#include<iostream>
using namespace std;

class Point {
    int x, y;  // Private members

public:
    Point(int a, int b) {  // Constructor
        x = a;
        y = b;
    }

    void displayPoint() {
        cout << "The point is (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p(1, 1);  // Create point (1,1)
    p.displayPoint();  // Output: "The point is (1, 1)"

    Point q(4, 6);  // Create point (4,6)
    q.displayPoint();  // Output: "The point is (4, 6)"

    return 0;
}
/*.	Point class: Represents a 2D point.
	2.	Constructor: Initializes the x and y coordinates.
	3.	Output: Displays the point coordinates.

Both examples illustrate how to use parameterized constructors to initialize object members.*/