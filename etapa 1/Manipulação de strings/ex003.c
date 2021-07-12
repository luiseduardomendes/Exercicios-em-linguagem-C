#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void scan(char frase[81], int Palavras[500][40]);
void main()
{
    char frase[81];
    int Palavras[500][40];
    scan(frase, Palavras);
    return 0;
}
void scan(char frase[81], int Palavras[500][40])
{
    int i, j, linha = 0, coluna = 0;
    do
    {
        printf("Digite uma frase: \n");
        gets(frase);
        if (strlen(frase) - 1 != " \0")
            strcat(frase, " \0");
        for (i = 0; i < 81; i ++){
            if (frase[i] == ' '){
                Palavras[linha][coluna] = i;
                coluna ++;
            }
            if (frase[i] == '\0'){
                linha ++;
            }
        }
    }
    while (frase [0] != '0');
    for (i = 0; i < 5; i ++){
        for (j = 0; j < 10; j ++)
            printf("%d ", Palavras[i][j]);
        printf("\n");
    }
}
