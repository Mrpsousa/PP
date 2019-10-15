#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "matOperations.h"

void oper_matrizes(int N) {
    // Matrizes A, B e C em tons de cinza (Valores de 0 a 255)
    double *A = NULL, *B = NULL, *C = NULL;

    // double *AA = NULL, *BB = NULL, *CC = NULL; Não usado por enquanto
    
    // Números máximos das matrizes
    double maxA, maxB, maxC;
    maxA = maxB = maxC = 0;


    // Aloca as matrizes em seus respectivos vetores
    alocaMatrizDouble(N, &A);
    alocaMatrizDouble(N, &B);
    alocaMatrizDouble(N, &C);
    //alocaMatrizDouble(N, &AA);
    //alocaMatrizDouble(N, &BB);
    //alocaMatrizDouble(N, &CC);

    // Gera a sequência aleatória de números
    gerNumAleatorios(N*N, A);
    gerNumAleatorios(N*N, B);
    gerNumAleatorios(N*N, C);

    // Normalização //
    // Encontrar Amax, Bmax, Cmax
    maxA = getMax(N*N, A);
    maxB = getMax(N*N, B);
    maxC = getMax(N*N, C);

    // Normalizando os vetores A, B e C
    normalizar(N*N, A, 1/maxA);
    normalizar(N*N, B, 1/maxB);
    normalizar(N*N, C, 1/maxC);

    // GEMM
    doGEMM(N, 10, 2, A, B, C);

    // Máximo do vetor normalizado
    double novoMax = getMax(N*N, C);

    // Desnormalização
    normalizar(N*N, C, maxC/novoMax);

    // Rebanho de free //
    free(A);
    free(B);
    free(C);

    return;
}

double media_tempo(double* vetor) {
    int i;
    double soma=0;
    for(i=0 ; i<10 ; i++) {
        soma += vetor[i];
    }
    return soma/10;
}

int main(int argc, char *argv[]) {
    int i, j;
    double start[10], end[10], tempo[10];
    FILE* saida;
    
    saida = fopen("resultados.m", "w");
    
    fprintf(saida, "%s", "matr = [\n");

    for(i=1024 ; i<=4096 ; i+=256) {
        for(j=0 ; j<10 ; j++) {
            start[j] = omp_get_wtime();
            oper_matrizes(i);
            end[j] = omp_get_wtime();
            tempo[j] = end[j] - start[j];
        }
        fprintf(saida, "%i %f\n", i, media_tempo(tempo));
    }
    fprintf(saida, "%s", "];");
    fclose(saida);

    return 1;
}