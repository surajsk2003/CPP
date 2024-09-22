#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};  // C++11 initializer list

    // Iterating using an iterator
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";  // Output: 10 20 30 40 50
    }

    return 0;
}

/*Ensure the Command is Correct:
It seems like your command is sometimes getting malformed. Just execute the following two commands separately to avoid any input errors:*/

/*

clang++ -std=c++11 prac3.cpp -o prac3
./prac3
*/