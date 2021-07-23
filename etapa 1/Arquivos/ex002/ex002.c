#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* arquivo;

int main()
{
    char linha[101];
    if (fopen("texto_ex051.txt", "w") != NULL){
        printf("Arquivo encontrado...\n\n");
        arquivo = fopen("texto_ex051.txt", "w");
    }
    else{
        printf("Arquivo nao encontrado, criando novo...\n\n");
        arquivo = fopen("texto_ex051.txt", "wb+");
    }
    fputs("Digite um texto: \n", stdout);
    fgets(linha, 101, stdin);
    while (linha[0] != '0'){
        fputs(linha, arquivo);
        printf("Digite outro texto: \n");
        fgets(linha, 101, stdin);
    }

    fclose(arquivo);
    return 0;
}
