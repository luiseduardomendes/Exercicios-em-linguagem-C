#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arquivo;

int main()
{
    char caract, frase[101];
    arquivo = fopen("texto_ex053.txt", "r+");
    if (ferror(arquivo))
        printf("Erro ao abrir o arquivo\n");
    while (!(feof(arquivo))){
        caract = getc(arquivo);
        switch (caract){
            case 'A' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('Z', arquivo);
                fflush(arquivo);
                break;
            case 'E' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('Y', arquivo);
                fflush(arquivo);
                break;
            case 'I' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('X', arquivo);
                fflush(arquivo);
                break;
            case 'O' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('W', arquivo);
                fflush(arquivo);
                break;
            case 'U' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('V', arquivo);
                fflush(arquivo);
                break;
            case 'V' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('U', arquivo);
                fflush(arquivo);
                break;
            case 'W' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('O', arquivo);
                fflush(arquivo);
                break;
            case 'X' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('I', arquivo);
                fflush(arquivo);
                break;
            case 'Y' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('E', arquivo);
                fflush(arquivo);
                break;
            case 'Z' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('A', arquivo);
                fflush(arquivo);
                break;
        }
    }

    rewind(arquivo);
    while (!(feof(arquivo))){
        fgets(frase, 101, arquivo);
        printf("%s", frase);
    }
    fclose(arquivo);
    return 0;
}
