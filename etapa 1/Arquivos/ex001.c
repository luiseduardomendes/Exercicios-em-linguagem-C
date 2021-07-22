#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* arquivo;

int main()
{

    char linha[51], nome[51];
    char* pnome = nome;
    if (fopen("dados.dat", "rb+") == NULL){
        arquivo = fopen("dados.dat", "wb+");
        printf("Arquivo nao encontrado, novo arquivo criado\n");
    }
    else{
        arquivo = fopen("dados.dat", "rb+");
        printf("Arquivo encontrado, continuando execucao...\n");
    }

    printf("Insira uma frase:\n");
    fgets(nome, strlen(nome), stdin);
    if(ferror(arquivo)){
        printf("Erro\n");
    }

    /*do{
        if(fread(&nome, sizeof(nome), 1, arquivo) == 1){
            fgets(linha, 0, arquivo);
        }
    } while (feof(arquivo) == 0);*/

    fputs(nome, arquivo);
    if(ferror(arquivo)){
        printf("Erro\n");
    }
    else{
        printf("Sem erro\n");
    }

    fclose(arquivo);

    fopen("dados.dat", "rb+");

    do{
        if(fread(&nome, sizeof(nome), 1, arquivo) == 1){
            fgets(linha, 50, arquivo);
            if(ferror(arquivo)){
                printf("Erro\n");
            }
            else{
                printf("Sem erro\n");
            }
            printf("\n%s", linha);


        }
    } while (feof(arquivo) == 0);




    fclose(arquivo);
    return 0;
}
