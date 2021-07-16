#include <stdio.h>
#include <stdlib.h.>

int main()
{
    int i, num, pos;
    enum nrs {UM = 1, DOIS, TRES, QUATRO, CINCO};
    int vet1[CINCO], vet2[CINCO];
    for (i = UM; i <= CINCO; i ++) // Preenche vet1 por leitura
    {
        printf("Elemento %d: ", i);
        scanf("%d", &vet1[i]);
    }
    for (i = UM; i <= CINCO; i ++) // copia os elementos de vet1 para vet2
        vet2[i] = vet1[i];
    printf("\nVetor 1\n");
    for (i = UM; i <= CINCO; i ++) // Escreve os elementos de vet1
        printf("%d ", vet1[i]);
    printf("\nVetor 2\n");
    for (i = UM; i <= CINCO; i ++) // Escreve os elementos de vet2
        printf("%d ", vet2[i]);
    printf("\n");
    printf("\nDigite um valor que deseja buscar no vetor: ");
    scanf("%d", &num);
    for (i = UM; i <= CINCO; i ++) // Procura o valor digitado pelo usuario em vet2
    {
        if (vet2[i] == num)
            pos = i;
    }
    printf("\nO valor %d se encontra na posicao %d do vetor 2\n", num, pos);
}