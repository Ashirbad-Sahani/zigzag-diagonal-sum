# Zigzag Diagonal Sum – Qualification Round Submission

## 🧠 Problem Statement

Given an NxN matrix of positive integers, traverse it in a **zigzag diagonal fashion**.  
At each step:

- **Add** the value if it is **not a prime number**.
- **Subtract** the value if it **is a prime number**.

Return the final computed sum.

---

## 🔍 Approach

- Use `i + j = d` to iterate diagonals.
- Alternate traversal direction:
  - Even `d`: ↗ up-right (bottom to top)
  - Odd `d`: ↙ down-left (top to bottom)
- Use **pointers only** to access the matrix (as per constraints).
- Implement a **custom prime-checking** function (no library functions used).
- Maintain a running total based on whether the current element is prime.

---

## 💡 Example

### Input:
```c
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
Zigzag Path:
1 → 2 → 4 → 5 → 3 → 6 → 8 → 7 → 9

Primes in Path:
2, 3, 5, 7

Computed Sum:
1 -2 +4 -5 -3 +6 +8 -7 +9 = 11
