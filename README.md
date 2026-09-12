# Strassen’s Matrix Multiplication 🧮

C++ program to multiply matrices using **Strassen’s Algorithm**.

---

## 📖 Description
- Divide matrices into submatrices
- Perform 7 multiplications instead of 8
- Combine results to form product matrix
- Time Complexity: O(n^log7) ≈ O(n^2.81)

### 🔍 Why Better than Normal Multiplication?
- Traditional multiplication: O(n^3)
- Strassen’s reduces complexity, faster for large matrices
- Useful in computational mathematics and graphics

---

## ▶️ Compilation & Run
```bash
g++ strassen.cpp -o strassen
./strassen
