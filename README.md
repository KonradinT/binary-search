# Binary Search Implementation (Exercism)

This project implements a Binary Search algorithm as part of an **Exercism** exercise. This version represents the **second iteration** of the solution, incorporating feedback from the Exercism mentoring process to move from functional code to a more refined implementation.

## Refactor Highlights (Iteration 2)
The mentoring process focused on replacing "special-case" branching with unified logic.

* **Simplified Search Space:** Adopted `len = mid` when the target is smaller than the middle element. This treats the index as the new element count, removing the need for manual decrements or `mid == 0` special cases.
* **Unified Logic:** Eliminated the `if (len == 1 && *ptr == number)` check. Since `len / 2` equals `0` when one element remains, the standard loop logic naturally evaluates the final candidate.
* **Self-Documenting Code:** Removed procedural comments in favor of expressive naming (e.g., `value_at_mid`), letting the logic explain itself.

## Technical Decisions & Theory 

### Memory & Performance
* **Pointer Arithmetic:** Calculated offsets directly to maintain $O(1)$ space complexity.
* **Complexity:** $O(\log n)$ time complexity by halving the search space in each iteration.

### *Effective C++* (Scott Meyers) Integration
* **Item 20 (Pass-by-Reference):** The `std::vector` is passed by `const reference` to avoid $O(n)$ copy overhead. The `int` target is passed by `value` to avoid the overhead of pointer indirection for a small primitive type.
* **Item 3 (Const Correctness):** Local variables and pointers are marked `const` to prevent accidental state changes and document the read-only intent of the search.

## Build and Test
```bash
mkdir build && cd build
cmake ..
make
