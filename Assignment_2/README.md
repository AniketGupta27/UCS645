# LAB 2 – OpenMP Parallel Programming Report

**Course:** UCS645 – Parallel & Distributed Computing  
**Lab Number:** 2  
**Programming Model:** OpenMP (Shared Memory)  
**Language:** C  
**Platform:** Ubuntu (WSL)  

---

## 1. Introduction

Parallel computing is a powerful approach used to enhance the performance of computationally intensive applications by distributing tasks across multiple processor cores. OpenMP offers a shared-memory programming model that enables parallelization through multithreading with only minimal modifications to the original sequential code.

In this lab, three different problems were implemented and parallelized using OpenMP. The aim of the experiment is to evaluate execution time and examine the scalability of each algorithm by analyzing performance metrics such as speedup and efficiency.

---

## 2. Experimental Setup

The experiments were performed using the following configuration:

- Programming Language: C  
- Compiler: GCC  
- Compilation Flags: `-O3 -fopenmp`  
- Operating System: Ubuntu (WSL)  
- Editor: Visual Studio Code  
- Threads Tested: 1, 2, 4, 8  

Execution time was measured using the OpenMP function `omp_get_wtime()`.

---

## 3. Performance Metrics

The following metrics were used to evaluate parallel performance:

**Speedup**

Speedup = T1 / Tp

**Efficiency**

Efficiency = Speedup / p

Where:  
- T1 = execution time using 1 thread  
- Tp = execution time using p threads  
- p = number of threads  

---

## 4. Program Descriptions and Results

---

## Q1 – Molecular Dynamics (Lennard-Jones Potential)

### Problem Description

This program computes the interaction potential between particles using the Lennard-Jones model. Each particle interacts with every other particle, resulting in high computational complexity. This makes the problem suitable for parallelization using OpenMP.

Nested loops were parallelized, and a reduction clause was used to safely accumulate the total potential energy.

---

### Performance Results

| Threads | Time (s) | Speedup | Efficiency |
|-------:|---------:|--------:|-----------:|
| 1 | 0.069563 | 1.000 | 1.000 |
| 2 | 0.044709 | 1.556 | 0.778 |
| 4 | 0.033514 | 2.076 | 0.519 |
| 8 | 0.035515 | 1.958 | 0.245 |

### Speedup Graph

### Speedup Graph
![Q1 Speedup Graph](q1.jpeg)



### Analysis

Speedup increases as the number of threads increases up to 4 threads, showing effective parallelization.

After 4 threads, the speedup slightly decreases.

The decrease is due to synchronization overhead and reduction operations.

This behavior indicates diminishing returns at higher thread counts.

The observation is consistent with Amdahl’s Law.
---

## Q2 – Bioinformatics (Smith–Waterman Algorithm)

### Problem Description

The Smith–Waterman algorithm performs local DNA sequence alignment using dynamic programming. Each cell in the scoring matrix depends on previously computed cells, creating strong data dependencies. Wavefront (diagonal) parallelization was used to handle these dependencies.

---

### Performance Results

| Threads | Time (s) | Speedup | Efficiency | Alignment Score |
|-------:|---------:|--------:|-----------:|----------------:|
| 1 | 0.000818 | 1.000 | 1.000 | 10 |
| 2 | 0.000190 | 4.305 | 2.152 | 10 |
| 4 | 0.013800 | 0.059 | 0.015 | 10 |
| 8 | 0.003777 | 0.217 | 0.027 | 10 |

### Speedup Graph
![Q2 Speedup Graph](q2.jpeg)



### Analysis

The graph indicates poor scalability for the Smith–Waterman algorithm.

Speedup improves at lower thread counts.

Speedup decreases significantly at higher thread counts.

The drop is caused by strong data dependencies in the algorithm.

Additional slowdown occurs due to synchronization overhead between diagonals.

---

## Q3 – Scientific Computing (Heat Diffusion Simulation)

### Problem Description

This program simulates heat diffusion over a two-dimensional grid using the finite difference method. Each grid cell update depends only on neighboring values from the previous iteration, allowing spatial loops to be parallelized efficiently.

---

### Performance Results

| Threads | Time (s) | Speedup | Efficiency |
|-------:|---------:|--------:|-----------:|
| 1      | 0.048565 | 1.000 | 1.000 |
| 2 | 0.025268 | 1.922 | 0.961 |
| 4 | 0.147601 | 0.329 | 0.082 |
| 8 | 0.259488 | 0.187 | 0.023 |

### Speedup Graph
![Q3 Speedup Graph](q3.jpeg)


### Analysis

The heat diffusion simulation shows good performance improvement at lower thread counts.

The improvement is due to independent grid computations.

At higher thread counts, performance begins to degrade.

The degradation is caused by memory contention.

Additional slowdown occurs due to parallel overhead.
---

## 5. Comparison of Algorithms

| Algorithm | Scalability | Reason |
|---------|------------|-------|
| Molecular Dynamics | Moderate | Synchronization and reduction overhead |
| Smith–Waterman | Poor | Strong data dependencies |
| Heat Diffusion | Moderate | Independent computations with memory overhead |

---

## 6. Discussion

The results show that scalability in parallel programs is highly dependent on the algorithm’s structure.

Algorithms with independent computations achieve better scalability and performance gains.

Algorithms with strong data dependencies exhibit limited improvement as thread count increases.

These findings align with the principles of Amdahl’s Law.

---

## 7. Conclusion

This lab highlights both the advantages and limitations of OpenMP in shared-memory parallel programming.

The heat diffusion algorithm demonstrated the best scalability among the three problems.

The molecular dynamics implementation showed moderate performance improvement.

The Smith–Waterman algorithm exhibited poor scalability due to strong data dependencies.

Successful parallelization requires minimizing synchronization overhead.

It also depends on maintaining balanced workload distribution across threads.
---
