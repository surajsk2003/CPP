#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    // Initializing vector 'v' and adding elements
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.emplace_back(4);

    // Printing elements of vector 'v'
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " " << endl;
    }

    // Initializing vector of pairs 'vec' and adding pairs
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.push_back({3, 4});
    vec.emplace_back(5, 6);

    // Using a range-based for loop to print pairs
    for (const auto& p : vec) {
        cout << p.first << " " << p.second << endl;  // Access and print each pair
    }

    // Initializing a vector of pair of int and pair of int, int
    vector<pair<int, pair<int, int>>> ve;
    ve.push_back({1, {2, 3}});

    // Accessing and printing nested pairs
    for (const auto& p : ve){
        cout << p.first << " " << p.second.second << endl;
    }

    // Array of pairs
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].second << endl;  // Access and print element of array

    // Initializing vector 'v3' with 5 elements, each with a value of 100
    vector<int> v3(5, 100);

    // Declaring an iterator to iterate through vector 'v3'
    auto it = v3.begin();
    it++;  // Moving the iterator to the second element
    cout << *(it) << endl;  // Printing the second element (100)

    // Correct use of iterator: Do not increment past end()
    it = v3.end() - 1;  // Pointing to the last element
    cout << *(it) << endl;  // Printing the last element (100)

    // Iterating through vector 'v3' and printing elements
    for (auto it = v3.begin(); it != v3.end(); it++) {
        cout << *(it) << endl;  // Print each element of 'v3'
    }

    // Declaring an array of vectors (each element is a vector<int>)
    vector<int> v4;

    // Iterating through vector 'v' and storing elements in the vector 'v4'
    for (auto it  = v.begin(); it != v.end(); it++) {
        v4.push_back(*it);  // Store elements in 'v4'
        cout << (*it) << endl; // Print
    }

    // Example of erasing elements from vector 'v4'
    if (!v4.empty()) {
        v4.erase(v4.begin());  // Erase the first element of 'v4'
        // Adjusting for new size after erasure
        if (v4.size() > 3) {
            v4.erase(v4.begin() + 1, v4.begin() + 4);  // Erase a range of elements from 'v4'
        }
    }

    // Printing remaining elements of 'v4'
    for (const auto& value : v4) {
        cout << value << endl;  // Print each element of 'v4'
    }

    return 0;
}