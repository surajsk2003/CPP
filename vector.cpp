/*
Here are the important things to remember when working with C++ vectors and iterators based on the code you've been writing:

### 1. **Initialization of Vectors:**
   - You can initialize an empty vector and add elements using `push_back()` or `emplace_back()`:
     ```cpp
     vector<int> v;
     v.push_back(1);
     v.emplace_back(2);  // Similar to push_back but more efficient for complex objects
     ```

### 2. **Vector of Pairs:**
   - You can use `vector<pair<int, int>>` to store pairs of integers, and access the pair elements using `.first` and `.second`.
     ```cpp
     vector<pair<int, int>> vec;
     vec.push_back({1, 2});
     cout << vec[0].first << " " << vec[0].second << endl;
     ```

### 3. **Iterators:**
   - Iterators allow you to traverse a vector element by element. You can get an iterator to the first element with `.begin()` and the end with `.end()`.
     ```cpp
     vector<int>::iterator it = v.begin();  // Points to first element
     cout << *it << endl;  // Dereference iterator to access the value
     ```

### 4. **Range-Based for Loop:**
   - You can iterate through vectors using a range-based for loop for simplicity:
     ```cpp
     for (const auto& value : v) {
         cout << value << endl;
     }
     ```

### 5. **Dereferencing Iterators:**
   - Always dereference iterators using `*` to access the value it points to.
     ```cpp
     vector<int> v;
     v.push_back(10);
     vector<int>::iterator it = v.begin();
     cout << *it << endl;  // Dereference to access the value
     ```

### 6. **Avoid Incrementing Iterators Beyond `end()`:**
   - Never increment an iterator past `v.end()`. `end()` is one past the last element, and dereferencing it is invalid.
     ```cpp
     it = v.end() - 1;  // Points to the last element
     cout << *it << endl;  // Safe
     ```

### 7. **Erasing Elements:**
   - Erasing elements from a vector shifts the subsequent elements. Be careful when using `.erase()`:
     ```cpp
     v.erase(v.begin());  // Removes the first element
     v.erase(v.begin() + 1, v.begin() + 3);  // Removes a range of elements
     ```

### 8. **Inserting Elements:**
   - You can insert elements into a specific position in a vector:
     ```cpp
     v.insert(v.begin() + 1, 50);  // Insert 50 at the second position
     ```

### 9. **Memory Considerations:**
   - Inserting or deleting elements in a vector can involve copying and reallocating elements, so be mindful of performance if you're working with large data sets.

### 10. **Use `emplace_back` for Efficiency:**
   - `emplace_back()` is more efficient than `push_back()` for complex data types (like objects) because it constructs the object in place without making a copy.

### 11. **Array of Vectors:**
   - You can declare an array of vectors, but remember to manage each vector separately.
     ```cpp
     vector<int> arr[5];  // An array of 5 vectors
     ```

### 12. **Vector Size vs. Capacity:**
   - The `size()` function tells you how many elements are in the vector, while `capacity()` tells you how much space is allocated. If the vector exceeds its capacity, it reallocates.
     ```cpp
     cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;
     ```

By keeping these points in mind, you will be better equipped to handle vectors and iterators efficiently in C++.
*/

/*
In C++, `v.end()` returns an iterator that points **one past the last element** of the vector `v`. This means that if you have a vector with elements, the iterator returned by `v.end()` does not point to a valid element; it's a sentinel value indicating the end of the vector.

### Example Explanation

Consider the following vector:

```cpp
vector<int> v = {10, 20, 30};
```

- The valid indices for this vector are:
  - `v[0]` → 10
  - `v[1]` → 20
  - `v[2]` → 30
- When you call `v.end()`, it will point to an iterator that is **one past** the last element (i.e., `v[3]`, which is not a valid index).

### Important Notes

1. **Dereferencing `v.end()` is Undefined Behavior**: Attempting to dereference the iterator returned by `v.end()` (e.g., `*(v.end())`) is undefined behavior because it does not point to a valid element.

2. **Used for Loop Control**: `v.end()` is often used in loops to determine when to stop iterating through the vector:
   ```cpp
   for (auto it = v.begin(); it != v.end(); ++it) {
       cout << *it << endl;  // Safe to dereference since it is between begin() and end()
   }
   ```

3. **Comparing with Other Iterators**: You can use `v.end()` to compare with other iterators to check if you have reached the end of the vector.

In summary, `v.end()` is a crucial part of C++ STL (Standard Template Library) iterators, providing a way to manage iteration over the elements of a vector safely.
*/