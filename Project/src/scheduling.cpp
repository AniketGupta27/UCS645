#include <omp.h>
#include "utils.h"

void schedulingMultiply(double** A, double** B, double** C, int n, int type) {

    if(type == 0) {
        #pragma omp parallel for schedule(static)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    C[i][j] += A[i][k] * B[k][j];
    }

    else if(type == 1) {
        #pragma omp parallel for schedule(dynamic)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    C[i][j] += A[i][k] * B[k][j];
    }

    else {
        #pragma omp parallel for schedule(guided)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    C[i][j] += A[i][k] * B[k][j];
    }
}