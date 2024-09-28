/*
The differences between vectors and arrays in C++ are significant, especially in terms of flexibility, functionality, and memory management. Here’s a detailed comparison:

### 1. **Size**
- **Array**:
  - The size of an array must be known at compile time and cannot be changed after declaration.
  - Example: `int arr[5];` defines an array of size 5.

- **Vector**:
  - A vector can dynamically resize itself during runtime, allowing you to add or remove elements as needed.
  - Example: `vector<int> v; v.push_back(10);` increases the size of the vector.

### 2. **Memory Management**
- **Array**:
  - Allocated on the stack (if it's a local array) or in a static memory area.
  - Memory for arrays is allocated contiguously, and the size is fixed.

- **Vector**:
  - Allocated on the heap, which allows for dynamic memory management.
  - It manages its own memory and can grow or shrink as elements are added or removed.

### 3. **Functionality**
- **Array**:
  - Provides basic functionality to store elements.
  - Lacks built-in methods for insertion, deletion, and resizing.

- **Vector**:
  - Offers a wide range of member functions (like `push_back()`, `pop_back()`, `insert()`, `erase()`, `resize()`, etc.) that make it easier to manage data.
  - Supports automatic memory management, meaning you don’t have to manually allocate or deallocate memory.

### 4. **Performance**
- **Array**:
  - Accessing elements in an array is usually faster because there's no overhead of dynamic memory allocation.
  - Memory is allocated all at once, so there's less fragmentation.

- **Vector**:
  - Accessing elements is also fast (constant time), but operations that modify the size (like `push_back()`) may involve copying elements to a new memory location if the current capacity is exceeded, which can be slower.
  - However, vectors tend to be more efficient in terms of memory usage over time due to their dynamic nature.

### 5. **Initialization**
- **Array**:
  - Requires you to specify the size upfront and can be initialized using curly braces.
  - Example: `int arr[3] = {1, 2, 3};`

- **Vector**:
  - Can be initialized with an initial size and value or with a list of values.
  - Example: `vector<int> v(3, 0);` initializes a vector of size 3 with all values set to 0.

### 6. **Bound Checking**
- **Array**:
  - Does not provide any bounds checking; accessing out-of-bounds elements leads to undefined behavior.

- **Vector**:
  - The `at()` member function provides bounds checking, throwing an `out_of_range` exception if the index is invalid.
  - Example: `v.at(5);` will throw an exception if `v` has fewer than 6 elements.

### 7. **Compatibility**
- **Array**:
  - More compatible with C-style APIs, which often expect raw arrays.

- **Vector**:
  - Part of the C++ Standard Template Library (STL), making it more suitable for modern C++ programming.

### Summary
In general, you would choose **arrays** when you know the size of the data structure at compile time and need minimal overhead. On the other hand, **vectors** are preferred for their flexibility and ease of use when the size of the data structure may change or when you need additional functionality for managing the elements.
*/