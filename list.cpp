#include <iostream>
#include <list>

int main() {
    // Creating a list of integers
    std::list<int> myList;

    // Adding elements to the list
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // Printing elements in the list
    std::cout << "Elements in the list: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Removing an element from the list
    myList.pop_front();  // Removes the first element

    // Printing the updated list
    std::cout << "Elements in the list after pop_front: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
