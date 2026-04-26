#include <iostream>
#include "utils.h"

using namespace std;

// Function declarations
void sequentialMultiply(double**, double**, double**, int);
void parallelMultiply(double**, double**, double**, int);
void cacheBlockingMultiply(double**, double**, double**, int, int);
void schedulingMultiply(double**, double**, double**, int, int);

double** createMatrix(int n) {
    double** mat = new double*[n];
    for(int i = 0; i < n; i++)
        mat[i] = new double[n];
    return mat;
}

int main() {

    int n = 500; // change later for experiments
    int blockSize = 32;

    double** A = createMatrix(n);
    double** B = createMatrix(n);
    double** C = createMatrix(n);

    initializeMatrix(A, n);
    initializeMatrix(B, n);

    // Sequential
    zeroMatrix(C, n);
    double start = getTime();
    sequentialMultiply(A, B, C, n);
    double end = getTime();
    cout << "Sequential Time: " << end - start << endl;

    // Parallel
    zeroMatrix(C, n);
    start = getTime();
    parallelMultiply(A, B, C, n);
    end = getTime();
    cout << "Parallel Time: " << end - start << endl;

    // Cache Blocking
    zeroMatrix(C, n);
    start = getTime();
    cacheBlockingMultiply(A, B, C, n, blockSize);
    end = getTime();
    cout << "Cache Blocking Time: " << end - start << endl;

    // Scheduling
    for(int i = 0; i < 3; i++) {
        zeroMatrix(C, n);
        start = getTime();
        schedulingMultiply(A, B, C, n, i);
        end = getTime();

        if(i == 0) cout << "Static: ";
        else if(i == 1) cout << "Dynamic: ";
        else cout << "Guided: ";

        cout << end - start << endl;
    }

    return 0;
}