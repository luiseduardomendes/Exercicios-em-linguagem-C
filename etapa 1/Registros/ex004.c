#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool pertinencia(int vetor[]);
void remove_repeticao(int vetor[]);
void main()
{
    int tam = 10;
    int vetor[tam];
    int i, num;
    for (i = 0; i < tam; i ++){
        printf("Digite os elementos do conjunto: \n");
        scanf("%i", &vetor[i]);
    }
    printf("Digite um elemento que deseja verificar a pertinencia: \n");
    scanf("%i", num);
    remove_repeticao(vetor);
    for (i = 0; i < tam; i ++){
        printf("%d ", vetor[i]);
    }
}
bool pertinencia(int vetor[])
{

}

void remove_repeticao(int vetor[])
{
    int i, j, k, tam = 100;
    for ( i = 0; i < tam - 1; i ++){
        for (j = i + 1; j < tam;){
            if (vetor[i] == vetor[j]){
                for (k = j; k < tam; k ++){
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