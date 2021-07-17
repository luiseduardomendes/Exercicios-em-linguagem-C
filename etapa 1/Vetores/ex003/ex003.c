#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MIN 0
#define MAX 10

int main()
{
    bool troca = true;
    int vet[MAX];
    int pos[MAX];
    int semdup[MAX];
    int MAX2 = 0, aux, i, k, MAX3 = MAX;
    printf("Digite os valores de um vetor: \n");
    for (i = MIN; i < MAX; i++)
        scanf("%d", &vet[i]);
    for (i = MIN; i < MAX; i++)
        printf("%d ", vet[i]);
    for (i = MIN; i < MAX; i++)
    {
        if (vet[i] > 0)
        {
            pos[MAX2] = vet[i];
            MAX2++;
        }
    }
    printf("\nVetor apenas com numeros positivos: \n");
    for (i = MIN; i < MAX2; i++)
        printf("%d ", pos[i]);
    while (troca == true)
    {
        troca = false;
        for (i = MIN; i < (MAX2 - 1); i++)
        {
            if (pos[i] > pos [i + 1])
            {
                aux = pos[i];
                pos[i] = pos[i + 1];
                pos[i + 1] = aux;
                troca = true;
            }
        }
    }
    printf("\nVetor com os numeros ordenados\n");
    MAX3 = 0;
    for (i = MIN; i < MAX2; i++)
        printf("%d ", pos[i]);
    for (i = MIN; i < MAX2; i++)
        semdup[i] = pos[i];
    for (i = MIN; i < MAX2 - MAX3 - 1; i++)
    {
        if (semdup[i] == semdup[i + 1])
        {
            for (k = i + 1; k < MAX2 - 1; k++)
                semdup[k] = semdup[k + 1];
            MAX3++;
            i--;
        }
    }
    printf("\nNumeros sem repeticao\n");
    for (i = MIN; i < MAX2 - MAX3; i++)
        printf("%d ", semdup[i]);
}
