/* O programa a seguir apresenta uma resolucao para o seguinte exercicio:

exercício 11.4) Defina um tipo registro composto por dois campos inteiros: nu-
merador e denominador. Esse registro será utilizado para representar uma fra-
ção. Escreva um programa que preencha por leitura os dados relativos a duas
frações (variáveis declaradas com o tipo antes definido). Em seguida, por meio 
de funções, informe:

a) soma das duas frações fornecidas;
b) primeira fração menos a segunda;
c) multiplicação das duas frações;
d) divisão da primeira fração pela segunda.*/

#include <stdio.h>
#include <stdlib.h>

struct frac{
    float numerador;
    float denominador;
};
struct frac leitura_fracao(struct frac fracao);
double valor_fracoes(struct frac fracao);

int main()
{
    float num1, num2, soma, produto, divisao;
    struct frac fracao1;
    struct frac fracao2;
    fracao1 = leitura_fracao(fracao1);
    fracao2 = leitura_fracao(fracao2);
    num1 = valor_fracoes(fracao1);
    num2 = valor_fracoes(fracao2);
    soma = num1 + num2;
    produto = num1 * num2;
    divisao = num1 / num2;
    printf("A soma das fracoes digitadas eh: %.2f\n", soma);
    printf("O produto entre as fracoes eh: %.2f\n", produto);
    printf("A divisao entre as fracoes eh: %.2f\n", divisao);
    return 0;
}
struct frac leitura_fracao(struct frac fracao)
{
    printf("Digite o numerador: ");
    scanf("%d", &fracao.numerador);
    printf("Digite o denominador: ");
    scanf("%d", &fracao.denominador);
    return (fracao);
}
double valor_fracoes(struct frac fracao)
{
    double retorna = fracao.numerador / fracao.denominador;
    return (retorna);
}
