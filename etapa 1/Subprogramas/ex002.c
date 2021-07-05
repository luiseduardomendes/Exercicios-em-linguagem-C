/* O programa a seguir apresenta uma resolucao para o seguinte exercicio:

exercício 9.7 Escreva um programa que, dado o raio de uma esfera, calcule o
seu volume. O programa deverá realizar um laço de leitura de valores para raio,
fornecendo para cada um o volume da esfera correspondente. O final do programa
será sinalizado pela introdução de um valor negativo ou nulo para o raio. O
cálculo dos volumes deverá ser realizado por uma função. Observação: essa fun-
ção deverá utilizar uma função POTENCIA para calcular a potência do raio neces-
sária no cálculo do volume */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    float VolumeCirc (float raio);
    float raio, volume;
    do {
        printf("Digite o valor do raio de uma circuferencia: \n");
        scanf("%f", &raio);
        volume = VolumeCirc(raio);
        if (raio > 0){
            printf("\nO volume da circunferencia de raio %.2f eh: %.2f\n", raio, volume);
        }
    }
    while (raio > 0);
    printf("\nPrograma encerrado\n");
    return 0;
}
float VolumeCirc (float raio)
{
    float Potencia(float raio);
    float volume, pot;
    pot = Potencia(raio);
    volume = (4 * atan(1) * 4 * pot) / 3;
    return volume;
}
float Potencia(float num)
{
    num *= num * num;
    return num;
}
