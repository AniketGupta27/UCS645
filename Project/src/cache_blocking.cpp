#include "utils.h"
#include <algorithm>

using namespace std;

void cacheBlockingMultiply(double** A, double** B, double** C, int n, int blockSize) {
    for(int ii = 0; ii < n; ii += blockSize)
    for(int jj = 0; jj < n; jj += blockSize)
    for(int kk = 0; kk < n; kk += blockSize)
        for(int i = ii; i < min(ii + blockSize, n); i++)
            for(int j = jj; j < min(jj + blockSize, n); j++)
                for(int k = kk; k < min(kk + blockSize, n); k++)
                    C[i][j] += A[i][k] * B[k][j];
}