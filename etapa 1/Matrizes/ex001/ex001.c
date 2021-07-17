#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX1 5 //NUMERO DE LINHAS
#define MAX2 10 //NUMERO DE COLUNAS
#define MIN 0

int main()
{
    bool encontrado = false;
    int i, k, aux, prod = 1, negat = 0, num;
    int maiores[MAX1][3];
    int mat[MAX1][MAX2];
    float media[MAX2] = {0};
    float soma[MAX2] = {0};
    printf("Preencha a matriz %dx%d \n", MAX1, MAX2);
    for (i = MIN; i < MAX1; i ++) // LE OS VALORES DA MATRIZ
    {
        for (k = MIN; k < MAX2; k ++)
        {
            printf("Linha %d, coluna %d \n", i + 1, k + 1);
            scanf("%d", &mat[i][k]);
        }
    }
    printf("\nMatriz digitada: \n");
    for (i = MIN; i < MAX1; i ++) // MOSTRA OS VALORES DA MATRIZ
    {
        for (k = MIN; k < MAX2; k ++)
        {
            printf("%d ", mat[i][k]);
        }
        printf("\n");
    }
    for (i = MIN; i < MAX1; i ++) // ORGANIZA AS LINHAS DA MATRIZ EM ORDEM CRESCENTE
    {
        maiores[i][0] = mat[i][0];
        maiores[i][1] = i;
        maiores[i][2] = 0;
        for (k = MIN + 1; k < MAX2; k++)
        {
            if (mat[i][k] > maiores[i][0])
            {
                maiores[i][0] = mat[i][k];
                maiores[i][1] = i;
                maiores[i][2] = k;
            }
        }
    }
    printf("\nMaior / linha / coluna\n");
    for (i = MIN; i < MAX1; i ++) // MOSTRA OS MAIORES VALORES DE CADA LINHA
    {
        printf("%d ", maiores[i][0]);
        printf("%d ", maiores[i][1] + 1);
        printf("%d ", maiores[i][2] + 1);
        printf("\n");
    }
    for (k = MIN; k < MAX2; k ++) // CALCULA A MEDIA DAS COLUNAS
    {
        for (i = MIN; i < MAX1; i++)
            soma[k] += mat[i][k];
        media[k] = soma[k] / MAX1;
    }
    printf("\nMedia das colunas \n");
    for (i = MIN; i < MAX2; i ++) // MOSTRA A MEDIA DAS COLUNAS
        printf("coluna %d = %.2f \n", i + 1, media[i]);
    printf("\n");
    for (i = MIN; i < MAX1; i ++) // CALCULA O PRODUTO DOS VALORES NAO NULOS
    {
        for (k = MIN; k < MAX2; k ++)
        {
            if (mat[i][k] != 0)
                prod *= mat[i][k];
        }
    }
    printf("Produto entre os valores nao nulos: %d\n", prod);
    for (i = MIN; i < MAX1; i ++) // CALCULA QUANTOS ELEMENTOS NAO SAO NEGATIVOS
    {
        for (k = MIN; k < MAX2; k ++)
        {
            if (mat[i][k] < 0)
                negat ++;
        }
    }
    printf("\nO numero de elementos negativos eh %d\n", negat);
    printf("\nDigite um valor que deseja buscar\n");
    scanf("%d", &num);
    for (i = MIN; i < MAX1; i ++) // BUSCA UM VALOR DIGITADO PELO USUARIO
    {
        for (k = MIN; k < MAX2; k++)
        {
            if (mat[i][k] == num)
            {
                printf("O numero procurado se encontra na linha %d e coluna %d\n", i+1, k+1);
                encontrado = true;
            }
        }
    }
    if (encontrado == false)
        printf("Valor nao encontrado \n");
}
