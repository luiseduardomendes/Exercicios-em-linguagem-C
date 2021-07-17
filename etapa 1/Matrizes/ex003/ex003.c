#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define MIN 0

int main()
{
    int i, k;
    int mat[MAX][MAX];
    int maior, maior_linha, menor, menor_linha;
    printf("Digite os elementos de uma matriz %dx%d\n", MAX, MAX);
    for (i = MIN; i < MAX; i ++) // LE OS ELEMENTOS DA MATRIX
    {
        for (k = MIN; k < MAX; k ++)
        {
            printf("\nLinha %d, coluna %d \n", i + 1, k + 1);
            scanf("%d", &mat[i][k]);
        }
    }
    printf("\nMatriz digitada\n");
    for (i = MIN; i < MAX; i ++) // MOSTRA A MATRIZ DIGITADA
    {
        for (k = MIN; k < MAX; k ++)
            printf("%d ", mat[i][k]);
        printf("\n");
    }
    maior = mat [MIN][MIN];
    for (i = MIN; i < MAX; i ++) // DETERMINA O MAIOR VALOR DIGITADO E A LINHA NA QUAL SE ENCONTRA
    {
        for (k = MIN; k < MAX; k ++)
        {
            if (mat[i][k] > maior)
            {
                maior = mat[i][k];
                maior_linha = i;
            }
        }
    }
    menor = mat[maior_linha][MIN];
    for (k = MIN; k < MAX; k ++) // DETERMINA O MENOR VALOR NA LINHA QUE SE ENCONTRA O MAIOR VALOR
    {
        if (mat[maior_linha][k] < menor)
        {
            menor = mat[maior_linha][k];
            menor_linha = k;
        }
    }
    printf("\nO elemento minimax da matriz digitada eh %d e ele se encontra na coluna %d",menor, menor_linha + 1);
}
