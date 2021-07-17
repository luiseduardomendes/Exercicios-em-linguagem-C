#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define MIN 0
#define MOV 5

int main()
{
    int i, k;
    float soma = 0, media = 0;
    float vet[MAX] = {0};
    for(i = MIN; i < MAX; i++)
    {
        printf("Escreva os valores da media movel: \n");
        scanf("%f", &vet[i]);
        if (i < MOV)
        {
            for (k = i; k >= MIN; k --)
                soma = soma + vet[k];
            media = soma / (i + 1);
            printf("A media movel ate o momento e %.2f \n", media);
        }
        if (i >= MOV)
        {
            for (k = i - MOV + 1; k <= i; k ++)
                soma = soma + vet[k];
            media = soma / MOV;
            printf("A media movel do momento e %.2f \n", media);
        }
        media = 0;
        soma = 0;
    }
}
