#include <iostream>
#include <vector>

/*int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50, 60 , 70, 80, 100};

    for (const auto& value : vec) {
        std::cout << value << " ";
    }

    return 0;
}*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    // Adding elements
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // Accessing elements
    std::cout << "First element: " << vec[0] << std::endl;

    // Iterating over elements
    std::cout << "Elements in vector: ";
    for (const auto& value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Removing the last element
    vec.pop_back();

    // Checking size and capacity
    std::cout << "Size after pop_back: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    return 0;
}

/*

clang++ -std=c++11 prac3.cpp -o prac3
./prac3
*/