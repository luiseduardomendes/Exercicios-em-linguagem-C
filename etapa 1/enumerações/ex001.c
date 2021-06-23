/*O programa a seguir apresenta uma resolucao para o seguinte exercicio:

exercício 8.1 Defina o tipo enumeração Nrs, cujos valores são (UM, DOIS, TRES, QUATRO, 
CINCO). Defina uma variável simples com esse tipo. Construa um programa que preencha 
essa variável com um dos valores permitidos, a partir de informação fornecida por leitura. 
Em seguida, o programa deve imprimir o conteúdo da variável, testando seu valor interno. 
Teste esse programa fornecendo todas as possíveis opções de preenchimento da variável com 
tipo Nrs.*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    enum nrs {UM = 1, DOIS, TRES, QUATRO, CINCO};
    enum nrs num, i;
    printf("Digite um valor de 1 a 5: \n");
    scanf("%d", &num);
    printf("%d\n", UM);
    for (i = UM; i <= CINCO; i++)
    {
        switch (i)
        {
            case UM : printf("O valor digitado por extenso eh um\n");
                break;
            case DOIS : printf("O valor digitado por extenso eh dois\n");
                break;
            case TRES : printf("O valor digitado por extenso eh tres\n");
                break;
            case QUATRO : printf("O valor digitado por extenso eh quatro\n");
                break;
            case CINCO : printf("O valor digitado por extenso eh cinco\n");
                break;
        }
    }
}
