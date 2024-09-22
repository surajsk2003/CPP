#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v;   // A vector of integers
    v.push_back(10); // Adds 10 to the end of the vector
    v.push_back(20); // Adds 20 to the end of the vector
    int x = v[0];    // Accesses the first element (10)
    int y = v.at(1); // Accesses the second element (20) with bounds checking

    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }

    // Using range-based for loop
    for (int element : v)
    {
        std::cout << element << " ";
    }
}