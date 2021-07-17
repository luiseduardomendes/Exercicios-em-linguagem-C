#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 5

int tam = max;

bool pertinencia(int vetor[], int num);
void remove_repeticao(int vetor[]);

int main()
{

    int num, i = 0;
    int conj_e[max] = {0};
    printf("Digite os elementos do conjunto E\n");
    while (i < max){
        do{
            printf("Insira um valor: ");
            scanf("%d", &conj_e[i]);
            if ((conj_e[i] < 0) || (conj_e[i] > 20))
                printf("Numero invalido\n");
            else
                i ++;
        } while((num < 0) || (num > 20));
    }
    remove_repeticao(conj_e);
    for (i = 0; i < 4; i ++){
        printf("\nDigite um valor para testar se pertence ao conjunto E: ");
        scanf("%d", &num);
        if (pertinencia(conj_e, num))
            printf("\nO elemento %d pertence ao conjunto E", num);
        else
            printf("\nO elemento %d nao pertence ao conjunto E", num);
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

