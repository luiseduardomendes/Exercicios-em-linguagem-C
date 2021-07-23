#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arquivo, *arq_novo;
char frase[101];

int main()
{
    arquivo = fopen("E:\\teste C\\ex052.txt", "a+");
    arq_novo = fopen("E:\\teste C\\ex052.aux.txt", "w");
    rewind(arquivo);
    for(int i = 0; i < 3; i ++){
        fgets(frase, 101, arquivo);
        if (!feof(arquivo)){
            fputs(frase, arq_novo);
        }
    }
    fputs("Escreva uma frase\n", stdout);
    fgets(frase, 101, stdin);
    fputs(frase, arq_novo);

    while (!feof(arquivo)){
        fgets(frase, 101, arquivo);
        fputs(frase, arq_novo);
    }

    fclose(arquivo);
    fclose(arq_novo);

    return 0;
}
