#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* arquivo;

int main()
{
    char  nome[51];

    arquivo = fopen("texto_ex051.txt", "rb+");
    if (arquivo == NULL){
        printf("Arquivo nao encontrado\nNovo arquivo criado\n");
        arquivo = fopen("texto_ex051.txt", "wb+");
    }
    else
        printf("Arquivo encontrado...\n\n");

    fputs("Insira uma frase:\n", stdout);
    fgets(nome, 51, stdin);

    //while(strcmp(nome, "0") != 0){
        fputs(nome, arquivo);
        fputs("Insira outra frase:\n", stdout);
        fgets(nome, 51, stdin);
    //}

    fclose(arquivo);

    arquivo = fopen("texto_ex051.txt", "rb");


    printf("\nTextos digitados e armazenados:\n\n");

    while (fgets(nome, 51, arquivo) != NULL){
        fgets(nome, 51, arquivo);
        printf("%s", nome);
        printf("Hello world\n");
    }

    fclose(arquivo);
    return 0;
}
