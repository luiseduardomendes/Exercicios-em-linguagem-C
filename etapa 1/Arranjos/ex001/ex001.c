#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 5

bool pertinencia(int vetor[], int num);
void remove_repeticao(int vetor[]);
int tam = max;
void main()
{
    int vetor[tam];
    int i, num;
    for (i = 0; i < tam; i ++){
        printf("Digite os elementos do conjunto: \n");
        scanf("%i", &vetor[i]);
    }
    remove_repeticao(vetor);
    printf("Digite um elemento que deseja verificar a pertinencia: \n");
    scanf("%i", &num);
    if (pertinencia(vetor, num))
        printf("\nO valor %i esta no conjunto digitado\n");
    else
        printf("\nO valor %i nao esta no conjunto digitado\n");
    for (i = 0; i < tam; i ++){
        printf("%d ", vetor[i]);
    }
    for (i = tam - 1; i < max; i ++){
        vetor[i] = 0;
    }
}
bool pertinencia(int vetor[], int num)
{
    int i;
    bool resposta = false;
    for (i = 0; i < tam; i ++){
        if (vetor[i] == num)
            resposta = true;
    }
    return resposta;
}

void remove_repeticao(int vetor[])
{
    int i, j, k;
    for ( i = 0; i < tam - 1; i ++){
        for (j = i + 1; j < tam;){
            if (vetor[i] == vetor[j]){
                for (k = j; k < tam - 1; k ++){
                    vetor[k] = vetor[k + 1];
                }
                tam --;
            }
            else{
                j ++;
            }
        }
    }
}
