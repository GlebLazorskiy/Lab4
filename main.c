#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
#define M 6

void arrayprint (int ** A);

void maindiagonalsum (int ** A);

void arrayfree (int ** A);

int main()
{
    srand(time(NULL));

    int ** A = (int **) malloc(N * sizeof(int *));
    
    for (int i = 0; i < N; i++) {
            A[i] = (int *) calloc(M, sizeof(int));
    }

    int x;
    int n = (N / M);
    int k = N * M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            x = n + rand() % k;
            A[i][j] = x;
        }
    }

    arrayprint (A);

    maindiagonalsum (A);

    arrayfree (A);

    return 0;
}

void arrayprint (int ** A)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }
}

void maindiagonalsum (int ** A)
{
    int S = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == j) {
                S = S + A[i][j];
            }
        }
    }

    printf("S = %d", S);
}

void arrayfree (int ** A)
{
    for (int i = 0; i < N; i++)
        free(A[i]);
    free(A);
}