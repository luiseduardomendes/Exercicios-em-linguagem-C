#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* arquivo;

int main()
{

    char linha[51], nome[51], letra;


    arquivo = fopen("dados.dat", "rb+");
    printf("Novo arquivo criado\n");


    printf("Insira uma frase:\n");
    fgets(nome, sizeof(nome), stdin);
    printf("\n\n");

    do{
        letra = fgetc(arquivo);
        if (letra = '\0')
            fputc ('\n', arquivo);
    } while (feof(arquivo) == 0);

    fputs(nome, arquivo);
    if (ferror(arquivo)){
        printf("Erro ao inserir\n");
    }
    rewind(arquivo);
    while (feof(arquivo) == 0){
        fgets(linha, 51, arquivo);
        printf("%s", linha);
    }

    fclose(arquivo);
    return 0;
}
