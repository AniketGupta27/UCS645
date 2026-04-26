#include <iostream>
#include <omp.h>
#include "utils.h"

using namespace std;

void initializeMatrix(double** mat, int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mat[i][j] = rand() % 10;
}

void zeroMatrix(double** mat, int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mat[i][j] = 0;
}

double getTime() {
    return omp_get_wtime();
}