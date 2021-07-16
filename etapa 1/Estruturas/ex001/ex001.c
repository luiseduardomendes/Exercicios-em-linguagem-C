/* O programa a seguir apresenta uma resolucao para o seguinte exercicio:

a variável do tipo registro que tenha dois campos, sendo o primeiro um vetor 
de três elementos inteiros e o segundo um valor inteiro. Faça um programa que:

a) preencha por leitura os valores do primeiro campo (o vetor);
b) imprima os valores contidos nesse campo;
c) some os valores contidos no primeiro campo e preencha o segundo campo com o 
resultado da soma;
d) imprima o valor contido no segundo campo. */

#include <stdio.h>
#include <stdlib.h>

int i;
struct registro{
        int vetor[3];
        int num_int;
    }g_reg;

void leitura_dados();
void imprimir_valores();
void soma_vetor_nums();
void imprimir_soma();

int main()
{
    leitura_dados();
    imprimir_valores();
    soma_vetor_nums();
    imprimir_soma();
    return 0;
}

void leitura_dados()
{
    for (i = 0; i < 3; i ++){
        printf("\nDigite o elemento %d do vetor: ", i + 1);
        scanf("%d", &g_reg.vetor[i]);
    }
}

void imprimir_valores()
{
    for (i = 0; i < 3; i ++)
        printf("%d " , g_reg.vetor[i]);
}

void soma_vetor_nums()
{
    g_reg.num_int = 0;
    for (i = 0; i < 3; i ++){
        g_reg.num_int += g_reg.vetor[i];
    }
}

void imprimir_soma()
{
    printf("\n\nO valor da soma dos elementos eh %d\n", g_reg.num_int);
}
