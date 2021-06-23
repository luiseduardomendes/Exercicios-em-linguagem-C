/*O programa a seguir apresenta uma resolucao para o seguinte exercicio:

exercício 8.5 Uma revenda de automóveis armazena os dados relativos aos carros disponíveis 
para venda em uma matriz multidimensional. As dimensões dessa matriz e os índices utiliza-
dos em cada dimensão são:

 1. código de identificação do carro, com índice inteiro, de 1 a 50;
 2. modelo do carro, com índice tipo enumeração (modA, modB, modC, modD, modE);
 3. cor, índice tipo enumeração (branco, prata, vermelho, azul, verde, preto);
 4. ano de fabricação, índice tipo inteiro (2009, 2010, 2011);
 5. combustível, índice tipo enumeração (gasolina, álcool, flex).
 
O conteúdo da matriz é o preço de cada um dos automóveis identificado pelos itens que 
constituem as dimensões. Escreva um programa que inicie preenchendo, a partir de leituras 
do teclado, todos os dados dessa matriz. Em seguida, o programa deve responder a uma série 
de consultas, lendo os dados que identificam cada automóvel e informando o seu preço. Crie 
um controle para identificar quando o programa deve terminar de responder a consultas. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min 0
#define maxid 50 
#define maxano 3 // (2011 - 2009) + 1


int main()
{

    enum mod {modA, modB, modC, modD, modE};
    enum cor {branco, prata, vermelho, azul, verde, preto};
    enum com {gasolina, alcool, flex};
    char modelos_disp[] = {'a', 'b', 'c', 'd', 'e', 'A', 'B', 'C', 'D', 'E'};
    int mat[modE][maxid][preto][maxano][flex];
    char modelo, cores[20], combustivel[20], consulta;
    int cod_cons = 0, cor_cons = 0, ano_cons = 0, com_cons = 0, mod_cons = 0;
    int i;      // codigo de identificacao
    enum mod k; // modelo do carro
    enum cor j; // cor
    int l;      // ano de fabricacao
    enum com m; // combustivel
    for (i = min; i <= maxid; i ++)
    {
        for (k = modA; k <= modE; k ++)
        {
            for (j = branco; j <= preto; j ++)
            {
                for (l = min; l < maxano; l ++)
                {
                    for (m = gasolina; m <= flex; m ++)
                    {
                        printf("Codigo de Identificacao _ : %d\n", i + 1);
                        switch (k)
                        {
                            case modA : modelo = 'A';
                                break;
                            case modB : modelo = 'B';
                                break;
                            case modC : modelo = 'C';
                                break;
                            case modD : modelo = 'D';
                                break;
                            case modE : modelo = 'E';
                                break;
                        }
                        printf("Modelo do Carro _________ : %c\n", modelo);
                        switch (j)
                        {
                            case branco : strcpy(cores, "branco");
                                break;
                            case prata : strcpy(cores, "prata");
                                break;
                            case vermelho : strcpy(cores, "vermelho");
                                break;
                            case azul : strcpy(cores, "azul");
                                break;
                            case verde : strcpy(cores, "verde");
                                break;
                            case preto : strcpy(cores, "preto");
                                break;
                        }
                        printf("Cor _____________________ : %s\n", cores);
                        printf("Ano de Fabricacao _______ : %d \n", l+2009);
                        switch (m)
                        {
                            case gasolina : strcpy(combustivel, "gasolina");
                                break;
                            case alcool : strcpy(combustivel, "alcool");
                                break;
                            case flex : strcpy(combustivel, "flex");
                        }
                        printf("Combustivel Utilizado ___ : %s \n", combustivel);
                        printf("\ninsira o preco: R$");
                        scanf("%d", &mat[i][k][j][l][m]);

                    }
                }
            }
        }
    }
    do
    {
        printf("\nDeseja realizar uma consulta? insira [s] para sim ou [n] para nao: ");
        scanf("%c", &consulta);
        if (consulta != 's' && consulta != 'n' && consulta != 'S' && consulta != 'N')
            printf("\nInsira uma resposta valida\n");
    }
    while (consulta != 's' && consulta != 'n' && consulta != 'S' && consulta != 'N');
    do
    {
        cod_cons = 0;
        mod_cons = 0;
        cor_cons = 0;
        ano_cons = 0;
        com_cons = 0;
        do
        {
            printf("\nInsira o codigo de identificacao desejado [1 ate 50]: ");
            scanf("%d", &cod_cons);
            if (cod_cons < 1 || cod_cons > 50)
                printf("\nInsira um valor valido\n");
        }
        while (cod_cons < 1 || cod_cons > 50);
        do
        {
            printf("\nInsira o Modelo do carro [A ate E]: \n[1] Modelo A\n[2] Modelo B\n[3] Modelo C\n[4] Modelo D\n[5] Modelo E\nSua opcao: ");
            scanf("%d", &mod_cons);
            if (mod_cons < 1 || mod_cons > 5)
                printf("\nInsira um valor valido\n");
        }
        while (mod_cons < 1 || mod_cons > 5);
        do
        {
            printf("\nInsira a cor do carro: \n[1] branco\n[2] prata\n[3] vermelho\n[4] azul\n[5] verde\n[6] preto\nSua opcao: ");
            scanf("%d", &cor_cons);
            if (cor_cons < 1 || cor_cons > 6)
                printf("\nInsira um valor valido\n");
        }
        while (cor_cons < 1 || cor_cons > 6);
        cor_cons --;
        do
        {
            printf("\nInsira o ano de fabricacao [2009 ate 2011]: ");
            scanf("%d", ano_cons);
            if (ano_cons < 2009 || ano_cons > 2011)
                printf("\nInsira um valor valido\n");
        }
        while (ano_cons < 2009 || ano_cons > 2011);
        ano_cons -= 2009;
        do
        {
            printf("Insira o tipo de combustivel: \n[1] gasolina\n[2] alcool\n[3] flex\nSua opcao: ");
            scanf("%d", com_cons);
            if (com_cons < 1 || com_cons > 3)
                printf("\nInsira um valor valido\n");
        }
        while (com_cons < 1 || com_cons > 3);
        com_cons --;
        do
        {
            printf("\nDeseja realizar uma nova consulta? insira [s] para sim ou [n] para nao: ");
            scanf("%c", &consulta);
            if ((consulta != 's') && (consulta != 'n') && (consulta != 'S') && (consulta != 'N'))
                printf("\nInsira uma resposta valida\n");
        }
        while ((consulta != 's') && (consulta != 'n') && (consulta != 'S') && (consulta != 'N'));
    }
    while (consulta == 'S' || consulta == 's');
    printf("Programa finalizado!");
}
