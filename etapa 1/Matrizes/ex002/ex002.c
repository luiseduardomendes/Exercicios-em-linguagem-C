#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define MIN 0

int main()
{
    int i, k, pares = 0;
    int vetp[(MAX*MAX)/2];
    int vetd[MAX];
    int mat[MAX][MAX];
    printf("Digite os elementos de uma matriz %dx%d\n", MAX, MAX);
    for (i = MIN; i < MAX; i ++) // LE A MATRIZ DIGITADA PELO USUARIO
    {
        for (k = MIN; k < MAX; k ++)
        {
            printf("linha %d, coluna %d\n", i + 1, k + 1);
            scanf("%d", &mat[i][k]);
        }
    }
    for (i = MIN + 1; i < MAX; i += 2) // ESCREVE O VETOR P COMO SENDO OS ELEMENTOS DAS LINHAS PARES
    {
        for (k = MIN; k < MAX; k ++)
        {
            vetp[pares] = mat[i][k];
            pares ++;
        }
    }
    for (i = MIN; i < MAX; i ++) // VETOR D PASSA A SER O VALOR DA DIAGONAL PRINCIPAL
        vetd[i] = mat[i][i];
    for (i = MIN; i < MAX; i ++) // SOMA-SE O VALOR DA DIAGONAL PRINCIPAL AO DA SECUNDARIA
        vetd[i] += mat[i][(MAX - i) - 1];
    printf("\nA matriz digitada eh: \n");
    for (i = MIN; i < MAX; i ++) // ESCREVE A MATRIZ
    {
        for(k = MIN; k < MAX; k ++)
            printf("%d ", mat[i][k]);
        printf("\n");
    }
    printf("\nOs elementos das linhas pares sao: \n");
    for (i = MIN; i < (MAX*MAX)/2; i ++)
        printf("%d ", vetp[i]);
    printf("\n");
    printf("\nA diagonal principal, somada aos elementos da mesma linha da diagonal secundaria eh: \n");
    for (i = MIN; i < MAX; i ++)
        printf("%d ", vetd[i]);
}
