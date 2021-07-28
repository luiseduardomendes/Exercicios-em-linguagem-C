#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE *arquivo, *arquivo_novo;
void cria_arquivo();
void organiza();
void printa();

struct registro{
    int cod;
    char nome[41];
    float preco;
    int quant;
    int cod_fornec;
}buffer;

int main()
{
    //cria_arquivo();
    organiza();
    printa();
    return 0;
}
void cria_arquivo()
{
    char resp;
    arquivo = fopen("pecas.dat", "wb");
    do{
        printf("Insira o codigo da peca[1 ate 1500]: ");
        do{
            scanf("%d", &buffer.cod);
            if ((buffer.cod < 1) || (buffer.cod > 1500)){
                printf("Valor invalido, insira outro entre 1 e 1500: ");
            }
        } while ((buffer.cod < 1) || (buffer.cod > 1500));
        printf("Nome da peca: ");
        fflush(stdin);
        gets(buffer.nome);
        printf("Preco da peca: R$");
        scanf("%f", &buffer.preco);
        printf("Quantidade em estoque: ");
        fflush(stdin);
        scanf("%d", &buffer.quant);
        printf("Codigo do fornecedor: ");
        fflush(stdin);
        scanf("%d", &buffer.cod_fornec);
        fwrite(&buffer, sizeof(struct registro), 1, arquivo);
        printf("Deseja inserir outro? [S/N]: ");
        fflush(stdin);
        scanf("%c", &resp);
        resp = toupper(resp);
        printf("\n");
    }while (resp == 'S');
    fclose(arquivo);
}
void organiza()
{
    arquivo_novo = fopen("pecas2.dat", "wb");
    arquivo = fopen("pecas.dat", "rb");
    for(int i = 1; i <= 1500; i ++){
        rewind(arquivo);
        do{
            fread(&buffer, sizeof(struct registro), 1, arquivo);
            if (feof(arquivo))
                break;
            if (i == buffer.cod){
                fflush(stdin);
                fwrite(&buffer, sizeof(struct registro), 1, arquivo_novo);
                break;
            }
        } while(1);
    }
    fclose(arquivo);
    fclose(arquivo_novo);
}
void printa()
{
    arquivo_novo = fopen("pecas2.dat", "rb");
    do{
        fread(&buffer, sizeof(struct registro), 1, arquivo_novo);
        if (feof(arquivo_novo))
            break;
        printf("Codigo: %d\n", buffer.cod);
        printf("Nome: %s\n", buffer.nome);
        printf("Preco: R$%.2f\n", buffer.preco);
        printf("Quantidade em estoque: %d\n", buffer.quant);
        printf("Codigo do fornecedor: %d\n\n", buffer.cod_fornec);
    } while(1);
    fclose(arquivo_novo);
}
