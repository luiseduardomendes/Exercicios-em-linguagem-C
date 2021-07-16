#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 4
#define MAX2 10
#define MIN 0

int main()
{
    enum nrs {UM = 1, DOIS, TRES, QUATRO, CINCO};
    enum vogs {A, E, I, O, U}; // enumeracao auxiliar
    int i, k, j, num_vog = 0, num_cons = 0, aux; // variaveis auxiliares
    char mat[MAX][CINCO]; // matriz inserida pelo usuario
    char vogais[MAX2] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}; // todas as vogais
    char vogais_ordem[5] = {'a', 'e', 'i', 'o', 'u'}; // ordem de incidencia
    int vogal_inc[5] = {0}; //incidencia de cada vogal
    bool v = false, troca = true;
    printf("Insira os elementos de uma matriz %dx%d: \n", MAX, CINCO);
    for (i = MIN; i < MAX; i ++) // Le os elementos digitados pelo usuario
    {
        for (k = UM - 1; k < CINCO; k ++)
        {
            printf("Linha %d, Coluna %d: ", i + 1, k + 1);
            gets(&mat[i][k]);
        }
    }
    printf("\nMatriz digitada: \n\n");
    for (i = MIN; i < MAX; i ++) // Escreve a matriz inserida pelo usuario
    {
        for (k = UM - 1; k < CINCO; k ++)
            printf("%c ", mat[i][k]);
        printf("\n");
    }
//    for (i = A; i <= U; i ++)
//        vogal_inc[i] = 0;
    for (i = MIN; i < MAX; i ++) // Conta a quantidade de vogais e consoantes
    {
        for (k = UM - 1; k < CINCO; k ++)
        {
            for (j = MIN; (j < MAX2) || (mat[i][k] != vogais[j]); j ++)
            {
                if (mat[i][k] == vogais[j])
                {
                    num_vog ++;
                    v = true;
                    switch (mat[i][k]) // Conta a incidencia de cada vogal
                    {
                        case 'A' : vogal_inc[A] ++;
                            break;
                        case 'a' : vogal_inc[A] ++;
                            break;
                        case 'E' : vogal_inc[E] ++;
                            break;
                        case 'e' : vogal_inc[E] ++;
                            break;
                        case 'I' : vogal_inc[I] ++;
                            break;
                        case 'i' : vogal_inc[I] ++;
                            break;
                        case 'O' : vogal_inc[O] ++;
                            break;
                        case 'o' : vogal_inc[O] ++;
                            break;
                        case 'U' : vogal_inc[U] ++;
                            break;
                        case 'u' : vogal_inc[U] ++;
                            break;
                    }
                }
            }
            if (v == false)
                num_cons ++;
            v = false;
        }
    }
    printf("\nO numero de vogais eh %d e o de consoantes eh %d\n", num_vog, num_cons);
    while (troca == true) // Coloca em ordem de incidencia
    {
        troca = false;
        for (i = A; i < U; i ++)
        {
            if (vogal_inc[i] < vogal_inc[i + 1])
            {
                aux = vogal_inc[i];
                vogal_inc[i] = vogal_inc[i + 1];
                vogal_inc[i + 1] = aux;
                aux = vogais_ordem[i];
                vogais_ordem[i] = vogais_ordem[i + 1];
                vogais_ordem[i + 1] = aux;
                troca = true;
            }
        }
    }
    printf("\nA vogal que mais se repete eh: %c", vogais_ordem[0]);
}
