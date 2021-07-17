#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MIN 0
#define MAX 5
#define MAX_U 2 * MAX

int main()
{
    int cont = 0, i, k, aux;
    int veti[MAX] = {0}, vety[MAX], vetx[MAX], vetu[MAX_U] = {0};
    bool troca = true;


    printf("Digite os %d elementos do vetor x: \n", MAX);
    for(i = MIN; i < MAX; i++)
        scanf("%d", &vetx[i]);
    printf("Agora digite os %d elementos do vetor y \n", MAX);
    for(i = MIN; i < MAX; i++)
        scanf("%d", &vety[i]);
    while (troca == true)//COLOCA OS NUMEROS DO ARRANJO VETX EM ORDEM
    {
        troca = false;
        for (i = MIN; i < MAX - 1; i++)
        {
            if (vetx[i] > vetx[i + 1])
            {
                aux = vetx[i];
                vetx[i] = vetx[i + 1];
                vetx[i + 1] = aux;
                troca = true;
            }
        }
    }
    troca = true;
    while (troca == true)//COLOCA OS NUMEROS DO ARRANJO VETY EM ORDEM
    {
        troca = false;
        for (i = MIN; i < MAX - 1; i++)
        {
            if (vety[i] > vety[i + 1])
            {
                aux = vety[i];
                vety[i] = vety[i + 1];
                vety[i + 1] = aux;
                troca = true;
            }
        }
    }
    troca = true;
    printf("\n");
    for (i = MIN; i < MAX; i ++)//MOSTRA OS NUMEROS DE VETX EM ORDEM
    {
        printf("%d ", vetx[i]);
    }
        printf("\n");
    for (i = MIN; i < MAX; i ++)//MOSTRA OS NUMEROS DE VETY EM ORDEM
    {
        printf("%d ", vety[i]);
    }
    for (i = MIN; ((i < MAX) && (vetx[i+1] != 0)); i ++)//EXCLUI OS NUMEROS IGUAIS EM VETX
    {
        if (vetx[i] == vetx[i + 1])
        {
            for (k = i + 1; k < MAX; k++)
                vetx[k] = vetx[k + 1];
            i;
        }
    }
    for (i = MIN; (i < MAX) && (vety[i] != 0); i ++)//EXCLUI OS NUMEROS IGUAIS EM VETY
    {
        if (vety[i] == vety[i + 1])
        {
            for (k = i + 1; k < MAX; k++)
                vety[k] = vety[k + 1];
            i--;
        }
    }
    printf("\n");
    for (i = MIN; i < MAX; i ++)//MOSTRA O CONJUNTO SEM OS NUMEROS IGUAIS
    {
        printf("%d ", vetx[i]);
    }
    printf("\n");
    for (i = MIN; i < MAX; i ++)//MOSTRA O CONJUNTO SEM OS NUMEROS IGUAIS
    {
        printf("%d ", vety[i]);
    }
    for (i = MIN; i < MAX; i++)//CALCULA O CONJUNTO INTERSECCAO
    {
        for (k = MIN; k < MAX; k++)
        {
            if ((vetx[i] == vety[k]) && (vetx[i] != 0) && (vety[k] != 0))
            {
                veti[cont] = vetx[i];
                cont ++;
            }
        }
    }
    cont = 0;
    printf("\nCONJUNTO INTERSECCAO: ");
    for (i = MIN; i < MAX; i ++)//MOSTRA O CONJUNTO INTERSECCAO
    {
        printf("%d ", veti[i]);
    }
    cont = 1;
    for (i = MIN; (vetx[i] != 0) && i < MAX; i ++)//CALCULA O CONJUNTO UNIAO
    {
        vetu[i] = vetx[i];
        cont++;
    }
    for (i = MIN; i < MAX_U; i++)
        vetu[cont + i - 1] = vety[i];
    troca = true;
    aux = 0;
    while (troca == true)//COLOCA OS NUMEROS DO ARRANJO VETU EM ORDEM
    {
        troca = false;
        for (i = MIN; (i < (MAX_U) - 1) && (vetu[i + 1] != 0); i++)
        {
            if (vetu[i] > vetu[i + 1])
            {
                aux = vetu[i];
                vetu[i] = vetu[i + 1];
                vetu[i + 1] = aux;
                troca = true;
            }
        }
    }
    for (i = MIN; i < (MAX_U) - 1; i ++)//EXCLUI OS NUMEROS IGUAIS
    {
        if ((vetu[i] == vetu[i + 1]) && (vetu[i] != 0))
        {
            for (k = i + 1; k < (MAX_U)-1; k++)
                vetu[k] = vetu[k + 1];
            i--;
        }
    }
    printf("\nCONJUNTO UNIAO: ");
    for (i = MIN; i < MAX_U; i++)
        printf("%d ", vetu[i]);
    return 0;
}
