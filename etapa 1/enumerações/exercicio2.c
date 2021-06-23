/*O programa a seguir responde ao seguinte exercicio do livro Algoritmos e programacao com exemplos em C e Pascal

exercício 8.2 Defina dois vetores v1 e v2, cada um com 5 elementos inteiros, sendo os elementos de ambos indexados
pelo tipo Nrs, cujos valores são (UM, DOIS, TRES, QUATRO, CINCO). Construa um programa que:

a preencha o vetor v1 por leitura;
b copie os elementos de v1 para v2;
c imprima os conteúdos de v1 e de v2;
d leia um valor e percorra v2, procurando o valor lido – se encontrar, informe em que posição de v2 o valor foi encontrado.*/

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