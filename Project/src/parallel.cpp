#include <omp.h>
#include "utils.h"

void parallelMultiply(double** A, double** B, double** C, int n) {
    #pragma omp parallel for
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}