#include <iostream>
#include <cmath>
using namespace std;

class Point {
    int a, b;          // Coordinates of the point
    double p2;         // Distance from the origin
public:
    // Constructor to initialize the point and calculate the distance from the origin
    Point(int x, int y) {
        a = x;
        b = y;
        p2 = sqrt(x * x + y * y);  // Calculate the distance
    }

    // Function to display the point and the distance from the origin
    void displayPoint() {
        cout << "Point (" << a << ", " << b << ")" << endl;
        cout << "Distance from origin to point (" << a << ", " << b << ") is " << p2 << endl;
    }
};

int main() {
    cout << "Enter the coordinates:" << endl;
    int m, n;
    cin >> m >> n;

    // Create a Point object with the input coordinates
    Point p(m, n);

    // Display the point and the distance
    p.displayPoint();
    
    return 0;
}