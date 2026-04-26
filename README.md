# UCS645 Parallel and Distributed Computing

## Project Repository and Overview

This repository contains my project work for the **UCS645: Parallel and Distributed Computing** course. The project focuses on optimizing matrix multiplication using parallel computing techniques and performance optimization strategies.

---

## 📌 Project Title

**Optimized Parallel Matrix Multiplication using OpenMP with Cache Blocking and Dynamic Scheduling**

---

## ⚙️ Implementation Details

* Sequential matrix multiplication implemented as baseline
* Parallel implementation using OpenMP threads
* Cache blocking used for memory optimization
* Scheduling strategies compared:

  * Static
  * Dynamic
  * Guided

---

## 📊 Results

| Method         | Time (s) | Speedup |
| -------------- | -------- | ------- |
| Sequential     | 0.904    | 1.00    |
| Parallel       | 0.235    | 3.85    |
| Static         | 0.279    | 3.24    |
| Dynamic        | 0.124    | 7.29    |
| Guided         | 0.112    | 8.07    |
| Cache Blocking | 0.945    | 0.96    |

---

## 🧠 Learning Outcomes

* Understanding of OpenMP and parallel programming
* Thread scheduling and load balancing
* Performance optimization using cache techniques
* Analysis of execution time and speedup

---

## ▶️ How to Run

### Compile:

```
g++ -fopenmp src/*.cpp -o matrix
```

### Run:

```
./matrix
```

---

## Submitted By:

**Aniket Gupta**

Roll No: 102317169

Subgroup: 3Q21

---

## 🎯 Conclusion

This project demonstrates how parallel computing significantly improves performance for computationally intensive tasks like matrix multiplication. It highlights the importance of efficient scheduling and memory usage.

---

## Acknowledgment

Guided by **Dr. Saif Nalband**

Thapar Institute of Engineering and Technology
