#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
#define MIN 0

int main()
{
    int i, aux, m, k = 1, x, cont = 0;
    int vetor[MAX];
    bool troca = true;
    for (i = MIN; i < MAX; i++)
    {
        printf("Digite: elemento %d \n", i);
        scanf("%d", &vetor[i]);
    }
    for (i = MIN; i < MAX; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    while (troca == true)
    {
        troca = false;
        for (i = MIN; i < MAX - 1; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                k = i;
                troca = true;
            }
        }
    }
    for (i = MIN; i < MAX; i++)
    printf("%d ", vetor[i]);
    for (i = MIN; i < MAX; i++)
    {
        if (vetor[i] == vetor [i + 1])
            cont ++;
    }
    printf("\nO numero de elementos distintos e: %d", MAX - cont);

}
