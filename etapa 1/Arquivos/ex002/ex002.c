#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* arquivo;
char linha[101];
char letra;
int i;

void primeira_palavra();
void ultima_palavra();

int main()
{


    arquivo = fopen("E:\\teste C\\ex051.txt", "ab+");
    if (arquivo != NULL){
        printf("Arquivo encontrado...\n\n");
    }
    else{
        printf("Arquivo nao encontrado, criando novo...\n\n");
        arquivo = fopen("E:\\teste C\\ex051.txt", "wb");
    }
    fputs("Digite um texto: \n", stdout);
    fgets(linha, 101, stdin);
    while (linha[0] != '0'){
        fputs(linha, arquivo);
        printf("Digite outro texto: \n");
        fgets(linha, 101, stdin);
    }

    rewind(arquivo);

    printf("\nprimeiras palavras das linhas pares: \n");

    primeira_palavra();

    printf("\nultimas palavras de cada linha: \n");

    rewind(arquivo);

    ultima_palavra();

    fclose(arquivo);

    return 0;
}

void primeira_palavra()
{
    while (!feof(arquivo)){
        fgets(linha, 101, arquivo);
        letra = 'a';
        while (letra != ' '){
            letra = fgetc(arquivo);
            if (((letra >= 'a') && (letra >= 'z')) || ((letra >= 'A') && (letra >= 'Z')))
            {
                printf("%c", letra);
            }
            if (letra == ' '){
                printf("\n");
                fgets(linha, 101, arquivo);
            }
            if (letra == EOF){
                break;
            }
        }
    }
}

void ultima_palavra()
{
    while (!feof(arquivo)){
        fgets(linha, 101, arquivo);
        i = strlen(linha);
        while (linha[i] != ' ')
            i --;
        for(int j = i + 1; j < strlen(linha); j ++)
            printf("%c", linha[j]);
    }
}
