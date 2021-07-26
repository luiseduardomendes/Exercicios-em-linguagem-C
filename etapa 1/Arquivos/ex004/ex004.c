#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arquivo;

int main()
{
    char caract, frase[101];
    arquivo = fopen("texto_ex054.txt", "r+");
    if (ferror(arquivo))
        printf("Erro ao abrir o arquivo\n");
    while (!(feof(arquivo))){
        caract = getc(arquivo);
        switch (caract){
            case 'A' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('Z', arquivo);
                break;
            case 'E' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('Y', arquivo);
                break;
            case 'I' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('X', arquivo);
                break;
            case 'O' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('W', arquivo);
                break;
            case 'U' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('V', arquivo);
                break;
            case 'V' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('U', arquivo);
                break;
            case 'W' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('O', arquivo);
                break;
            case 'X' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('I', arquivo);
                break;
            case 'Y' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('E', arquivo);
                break;
            case 'Z' :
                fseek(arquivo, -1*sizeof(caract), SEEK_CUR);
                putc('A', arquivo);
                break;
        }
    }
    fclose(arquivo);
    return 0;



    rewind(arquivo);
    while (!(feof(arquivo))){
        fputs(frase, arquivo);
        printf("%s", frase);
    }
    fclose(arquivo);
    return 0;
}
