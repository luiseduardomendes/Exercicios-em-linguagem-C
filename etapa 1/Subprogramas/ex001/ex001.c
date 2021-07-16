/* O programa a seguir apresenta uma resolucao para o seguinte exercicio:

exercício 9.2 Faça um programa que leia quatro matrizes inteiras, 5 × 5 (A, B, C e D), com
pelo menos dois subprogramas: um que carrega valores em uma matriz, a ser usado para a
leitura das quatro matrizes, e um segundo que recebe duas matrizes 5 × 5 e calcula a matriz
soma. Aplique esse último subprograma para obter A + B, C + D e A + C. */


#include <stdio.h>
#include <stdlib.h>
#define MIN 0
#define MAX 2

void FuncPrint(int mat[MAX][MAX])
{
    int i, k;
    for (i = MIN; i < MAX; i ++) {
        for (k = MIN; k < MAX; k ++) {
            printf("%d ", mat[i][k]);
        }
        printf("\n");
    }
}

int* Matriz(int mat[MAX][MAX])
{
    int i, k;
    for (i = MIN; i < MAX; i ++) {
        for (k = MIN; k < MAX; k ++) {
            printf("Linha %d, coluna %d: ", i+1, k+1);
            scanf("%d", &mat[i][k]);
        }
    }
    return (&mat[MAX][MAX]);
}
void SomaMatrizes (int matA[MAX][MAX], int matB[MAX][MAX], int somado[MAX][MAX])
{
    int i, k;
    int soma[MAX][MAX];
    for (i = MIN; i < MAX; i ++) {
        for (k = MIN; k < MAX; k ++) {
            soma[i][k] = matA[i][k] + matB[i][k];
            somado[i][k] = soma[i][k];
        }
    }
}

int main ()
{
    int mat1[MAX][MAX], mat2[MAX][MAX], mat3[MAX][MAX], mat4[MAX][MAX];
    int aeb[MAX][MAX], ced[MAX][MAX], aec[MAX][MAX];

    printf("Matriz 1: \n");
    Matriz(mat1);
    printf("\nMatriz 2: \n");
    Matriz(mat2);
    printf("\nMatriz 3: \n");
    Matriz(mat3);
    printf("\nMatriz 4: \n");
    Matriz(mat4);

    printf("\nMatriz 1: \n");
    FuncPrint(mat1);
    printf("\nMatriz 2: \n");
    FuncPrint(mat2);
    printf("\nMatriz 3: \n");
    FuncPrint(mat3);
    printf("\nMatriz 4: \n");
    FuncPrint(mat4);

    printf("\nA soma das matrizes 1 e 2 eh: \n");
    SomaMatrizes (mat1, mat2, aeb);
    FuncPrint(aeb);
    printf("\nA soma das matrizes 3 e 4 eh: \n");
    SomaMatrizes (mat3, mat4, ced);
    FuncPrint(ced);
    printf("\nA soma das matrizes 1 e 3 eh: \n");
    SomaMatrizes (mat1, mat3, aec);
    FuncPrint(aec);
    return 0;
}
