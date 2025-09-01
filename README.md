# 📌Hashira-Polynomial-Solver

## 📖 Problem Statement

We were given a set of roots in **JSON format**. Each root has:

* An **index (x)**
* A **base** (e.g., binary, decimal, base-4, etc.)
* A **value** (the root value in that base system).

Using at least **k roots** (where `k = m + 1`, and `m` is the degree of the polynomial), the task is to reconstruct the **polynomial coefficients**.

---

## 🎯 Key Features

✔️ Reads input from JSON test case.
✔️ Handles values given in different bases (binary, decimal, base-4, etc.).
✔️ Converts all values to **decimal** internally.
✔️ Uses a **Vandermonde Matrix + Gaussian Elimination** to solve the system of equations.
✔️ Outputs the polynomial coefficients in order (lowest degree → highest degree).

---

## 📂 Sample Input (JSON)

```json
{
  "keys": {
    "n": 4,
    "k": 3
  },
  "1": {
    "base": "10",
    "value": "4"
  },
  "2": {
    "base": "2",
    "value": "111"
  },
  "3": {
    "base": "10",
    "value": "12"
  },
  "6": {
    "base": "4",
    "value": "213"
  }
}
```

---

## ✅ Sample Output

```
Polynomial coefficients (lowest degree to highest):
5 -2 1
```

This means the polynomial is:

$$
P(x) = 5 - 2x + x^2
$$

---

## ⚡ How It Works

1. Parse the JSON file and extract `(x, y)` pairs.
2. Convert all `y` values from their respective bases to **decimal**.
3. Construct a **Vandermonde matrix** using the x-values.
4. Solve the system with **Gaussian elimination**.
5. Print the polynomial coefficients.

---

## 🛠️ Tech Stack

* **Language**: C++
* **Algorithm**: Gaussian elimination, Vandermonde matrix
* **Environment**: Tested in VS Code with `g++`

---

## 🚀 How to Run

### 1. Compile

```bash
g++ solution.cpp -o solution
```

### 2. Run with JSON Input

```bash
./solution < input.json
```

---


## 📌 Author

👨‍💻 **Rohan Arora**
📚 4th Year Computer Science Engineering Student
💡 Passionate about **DSA, Algorithms, and Real-world Applications**


