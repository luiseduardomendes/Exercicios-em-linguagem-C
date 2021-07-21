#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* arquivo;

int main()
{

    char linha[51], nome[51];
    char* pnome = nome;


    //strcpy(linha, "qualquer texto aleatorio\n");

    //printf("%s\n", linha);

    if (fopen("dados.dat", "rb+") == NULL){
        arquivo = fopen("dados.dat", "wb+");
        printf("Arquivo nao encontrado, novo arquivo criado\n");
    }
    else{
        arquivo = fopen("dados.dat", "rb+");
        printf("Arquivo encontrado, continuando execucao...\n");
    }




    /*if (feof(arquivo) == 0){
        printf("Final do arquivo nao atingido\n");
    }
    else{
        printf("Final do arquivo atingido\n");
    }*/

    fgets(nome, sizeof(nome), stdin); //funcao scanf
    if (nome[strlen(nome) - 1] == '\n'){
        nome[strlen(nome) - 1] = '\0';
    }
    while (feof(arquivo) == 0)
        fgets(linha, 51, arquivo);
    fputs(nome, arquivo);
    printf("%s\n", nome);


    if (fclose(arquivo) == EOF){
        printf("Erro no encerramento do programa");
    }
    else{
        fclose(arquivo);
    }

    if (fopen("dados.dat", "rb+") == NULL){
        arquivo = fopen("dados.dat", "wb+");
        printf("Arquivo nao encontrado, novo arquivo criado\n");
    }
    else{
        arquivo = fopen("dados.dat", "rb+");
        printf("Arquivo encontrado, continuando execucao...\n");
    }

    while (feof(arquivo) == 0){
        fgets(linha, 51, arquivo);
        printf("%s", linha);

    }

    fclose(arquivo);

}
