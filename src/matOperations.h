/**
 * Aloca memória para uma matriz de tamanho NxN em um vetor de double
 * N: Dimensão da matriz
 * pointer: ponteiro da matriz
 */
void alocaMatrizDouble(int N, double** pointer);

/**
 * Gera uma sequência de números aleatórios em um vetor de caracteres
 * N: Tamanho do vetor
 * pointer: ponteiro para o vetor
 */
void gerNumAleatorios(int N, double* pointer);

/**
 * Retorna o maior valor do vetor
 */
double getMax(int N, double* pointer);

/**
 * Normaliza um vetor de caracteres e o armazena um vetor de double
 * N: Tamanho dos vetores
 * C: Ponteiro para vetor não-normalizado
 * D: Ponteiro do vetor normalizado
 * max: Valor máximo do vetor C
 */
void normalizar(int N, double* scal, double max);

/**
 * GEMM
 * TODO: Adicionar documentação depois
 */
void doGEMM(int N, double alpha, double beta, double* A, double* B, double* C);
