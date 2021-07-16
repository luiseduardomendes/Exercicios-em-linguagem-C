/* O programa a seguir apresenta uma resolucao para o seguinte exercicio:

exercício 9.10) Faça um programa que calcule a média móvel. O programa deverá
executar um laço de leitura de valores inteiros e positivos; a introdução de um
valor negativo servirá como indicador de término do programa. Para cada valor
fornecido deverá ser impressa a média calculada. A média móvel é efetuada sobre
um número especificado de pontos. Quando se introduz um novo dado, descarta-se
o valor mais antigo, dando-se lugar à nova introdução. Este esquema de substi-
tuição faz da média móvel um instrumento valioso na análise de tendências.
Quanto menor o número de dados, mais sensível será com relação à média. Consi-
dere, para a solução deste problema, cinco pontos (valores) e assuma que pelo
menos cinco pontos válidos serão fornecidos.
Use obrigatoriamente subprogramas para:

a) armazenar os valores no vetor de valores;
b) calcular as médias sucessivas.

No programa principal, a cada valor introduzido (após os quatro primeiros) de-
verá ser apresentada a média calculada e os valores considerados no seu cálculo.
*/

#include <stdio.h>
#include <stdlib.h>
#define max 100

float Media(float vet[]);
void Scan(float vet[]);
void Scanfirst(float vet[]);
int i, cont = 0;
int main()
{
    float vet[max];
    printf("--------Calculadora de media movel---------\n");
    printf("insira os primeiros 5 numeros para comecar:\n");
    printf("insira um numero negativo para encerrar o programa\n");
    Scanfirst(vet);
    Scan(vet);
    return 0;
}
void Scanfirst(float vet[])
{
    for(i = 0; i < 5; i ++){
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vet[i]);
        if (vet[i] < 0){
            printf("insira um numero valido\n");
            i--;
        }
        else
            cont++;
    }
    printf("A media movel dos primeiros 5 valores eh %.2f\n", Media(vet));
}
void Scan(float vet[])
{
    do{
        printf("Elemento %d: ", cont + 1);
        scanf("%f", &vet[cont]);
        if (vet[cont] >= 0){
            cont ++;
            printf("A media movel dos ultimos 5 valores eh %.2f\n", Media(vet));
        }
        else
            printf("Programa Encerrado\n");
    }
    while (vet[cont] >= 0);
}
float Media(float vet[])
{
    float soma = 0, mediamovel;
    for (i = (cont - 5); i < cont; i ++){
        soma += vet[i];
        printf("%.2f ", vet[i]);
        if (i < cont - 1)
            printf("+ ");
    }
    printf("\n");
    mediamovel = soma / 5;
    return(mediamovel);
}
