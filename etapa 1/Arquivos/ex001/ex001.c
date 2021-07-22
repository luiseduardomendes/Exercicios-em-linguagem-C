#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* arquivo;

int main()
{
    char linha[51], nome[51], letra;

    arquivo = fopen("dados.dat", "rb+");
    printf("Arquivo encontrado...\n\n");

    printf("Insira uma frase:\n");
    fgets(nome, sizeof(nome), stdin);

    do{
        letra = fgetc(arquivo);
        if (letra = '\0')
            fputc ('\n', arquivo);
    } while (feof(arquivo) == 0);

    fputs(nome, arquivo);
    if (ferror(arquivo)){
        printf("Erro ao inserir\n");
    }
    for (int i = 0; i < 9; i ++){
        printf("Insira uma frase:\n");
        fgets(nome, sizeof(nome), stdin);
        fputs(nome, arquivo);
        if (ferror(arquivo)){
            printf("Erro ao inserir\n");
        }
    }

    rewind(arquivo);
    printf("\nTextos digitados e armazenados:\n\n");
    while (feof(arquivo) == 0){
        fgets(linha, 51, arquivo);
        if (feof(arquivo))
            break;
        else
            printf("%s", linha);
    }

    fclose(arquivo);
    return 0;
}
