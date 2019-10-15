#include <stdlib.h>
#include <cblas/cblas.h>
#include <openblas/cblas.h>
#include <bliss/bliss_C.h>
#include "matOperations.h"

void alocaMatrizDouble(int N, double** pointer) {
    *pointer = calloc(N*N, sizeof(double));
}

void gerNumAleatorios(int N, double* pointer) {
    int i;

    for(i=0 ; i<N ; i++) {
        pointer[i] = (double) (random() % 256);
    }
}

double getMax(int N, double* pointer) {
    int i = cblas_idamax(N, pointer, 1);

    return pointer[i];
}

void normalizar(int N, double* pointer, double scal) {
    cblas_dscal(N, scal, pointer, 1);
}

void doGEMM(int N, double alpha, double beta, double* A, double* B, double* C) {
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, alpha, A, N, B, N, beta, C, N);

    return;
}