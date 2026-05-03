# 🔍 C++ Binary Search Implementation 

## 📖 Overview 

This project implements a **Binary Search** algorithm as part of an **Exercism** exercise.
The goal was to achieve logarithmic time complexity. 

## 🛠️ Build and Requirements

This project uses **CMake** and requires a C++17 compliant compiler (tested with G++ 16.1.1).

```bash
mkdir build && cd build
cmake ..
make
```

## 🎯 Design Philosophy 

Implemented using pointer arithmetic with a focus on memory efficiency.

### _Effective C++_ Principles (Scott Meyers)

I applied the following core guidelines from Scott Meyers' _Effective C++_ to optimize efficiency and maintainability. 
 
#### Item 20: Prefer pass-by-reference-to-const to pass-by-value

* **Vector parameter** (`const std::vector<int>& data`): 
    * **Efficiency**: Passed-by-reference to achieve $O(1)$ during the function call.
Passing by value would mean a deep copy, resulting in $O(n)$ time complexity and doubling memory usage.
    * **Safety**: `const` to provide a read-only contract, ensuring the original data remains untouched.

* **Target parameter** (`int number`): 
    * **Performance**: Intentionally passed-by-value. Since an `int` (typically 4 bytes) is smaller than a pointer (8 bytes on 64-bit systems),
passing by value avoids the overhead of indirection and is more memory efficient. 

#### Item 3: Use const whenever possible

* internal pointers and local variables (like `value_at_mid`) are `const` to document intent and prevent accidental logic errors.

## ⚙️ Complexity Analysis

* **Time Complexity**: $O(\log n)$
* **Space Complexity**: $O(1)$. The search operates in-place, requiring no additional allocations.
