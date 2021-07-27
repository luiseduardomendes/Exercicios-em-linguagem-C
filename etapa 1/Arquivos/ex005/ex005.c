#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arquivo, *arq_novo;

struct registro{
    int chave, data[3];
    char info[31];
    float valor;
}buffer, teste;

struct registro1{
    int chave, data[3];
    char info[31];
}buffer1, fonte;

int main()
{
    int total_lido, total_escrito;
    float num;
    arquivo = fopen("fonte.dat", "rb");
    arq_novo = fopen("fontenovo.dat", "wb");
    if ((arquivo == NULL) || (arq_novo == NULL)){
        printf("Falha ao abrir arquivo\n");
        exit(1);
    }

    total_lido = fread(&buffer1, sizeof(struct registro1), 1, arquivo);
    if (total_lido != 1){
        printf("Falha ao ler arquivo\n");
        exit(1);
    }
    fclose(arquivo);

    buffer.chave = buffer1.chave;
    strcpy(buffer.info, buffer1.info);
    buffer.data[0] = buffer1.data[0];
    buffer.data[1] = buffer1.data[1];
    buffer.data[2] = buffer1.data[2];

    printf("Escreva um valor real\n");
    scanf("%f", &num);
    buffer.valor = num;

    total_escrito = fwrite(&buffer, sizeof(struct registro), 1, arq_novo);
    if (total_escrito != 1){
        printf("Falha ao escrever arquivo\n");
        exit(1);
    }

    fclose(arq_novo);
    arq_novo = fopen("fontenovo.dat", "rb");

    fread(&teste, sizeof(struct registro), 1, arq_novo);
    fclose(arq_novo);
    printf("chave: %d\ninformacao: %s\ndata: %d/%d/%d\nvalor: %.2f\n",
           teste.chave, teste.info, teste.data[0], teste.data[1],
           teste.data[2], teste.valor);
    return 0;
}
