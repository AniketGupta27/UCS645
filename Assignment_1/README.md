# UCS645 – LAB1 (OpenMP Experiments)

Student: Aniket Gupta 

Roll NO: 102317169

---

## EXPERIMENTAL QUESTIONS & RESULT

---

## Q1. DAXPY Loop

**Operation:**  
X[i] = a × X[i] + Y[i], where X and Y are vectors of size 2^16.

### Output

OMP_NUM_THREADS = 1  
Time taken: 0.000262 seconds  

OMP_NUM_THREADS = 2  
Time taken: 0.000298 seconds  

OMP_NUM_THREADS = 4  
Time taken: 0.003944 seconds  

OMP_NUM_THREADS = 8  
Time taken: 0.000964 seconds  

### Observation

Execution time stays low when using a small number of threads.

When the number of threads exceeds the available CPU cores, performance becomes inconsistent.

This fluctuation is caused by thread management overhead and context switching.

The highest efficiency is achieved with low to moderate numbers of threads.

---

## Q2. Matrix Multiplication (1D vs 2D Threading)

**Matrix Size:** 500 × 500  

### Output – 1D Threading

OMP_NUM_THREADS = 1  
Time taken (1D): 0.715027 seconds  

OMP_NUM_THREADS = 2  
Time taken (1D): 0.708881 seconds  

OMP_NUM_THREADS = 4  
Time taken (1D): 0.294908 seconds  

OMP_NUM_THREADS = 8  
Time taken (1D): 0.358535 seconds  

---

### Output – 2D Threading

OMP_NUM_THREADS = 1  
Time taken (2D): 0.505215 seconds  

OMP_NUM_THREADS = 2  
Time taken (2D): 0.410227 seconds  

OMP_NUM_THREADS = 4  
Time taken (2D): 0.302412 seconds  

OMP_NUM_THREADS = 8  
Time taken (2D): 0.370897 seconds  

### Observation

2D threading usually offers better load balancing than 1D threading.

Performance increases as the number of threads grows, up to an optimal limit.

After this limit, synchronization overhead increases.

This overhead reduces the performance gains from additional threads.

---

## Q3. Calculation of π Using Numerical Integration

### Output

OMP_NUM_THREADS = 1  
Calculated PI = 3.141593  
Time taken: 0.381978 seconds  

OMP_NUM_THREADS = 2  
Calculated PI = 3.141593  
Time taken: 0.197506 seconds  

OMP_NUM_THREADS = 4  
Calculated PI = 3.141593  
Time taken: 0.146089 seconds  

OMP_NUM_THREADS = 8  
Calculated PI = 3.141593  
Time taken: 0.156900 seconds  

### Observation

The computed value of π remains consistent and accurate for all numbers of threads.

Execution time decreases as the number of threads increases, up to an optimal level.

After this point, adding more threads causes overhead.

This overhead slightly increases the overall execution time.

---

## Conclusion

OpenMP improves performance for computationally intensive tasks by enabling parallel execution.

The performance gain is limited by the number of physical CPU cores available.

Using more threads than the number of physical cores introduces overhead.

This overhead reduces overall efficiency and performance.


