#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

FILE *arquivo, *arquivo_teste;

void cadastra_bolsista();
int menu();
int menu_bolsa();
void lista_cad();
void altera_dados();

struct registro{
    int codigo;
    char nome[31];
    int bolsa;
    char email[51];
}buffer, leitura[25];

int j;

int main()
{
    int opc;
    do{

        opc = menu();
        switch (opc){
        case 1 :
            arquivo = fopen("bolsistas.cad", "wb");
            fclose(arquivo);
            for (j = 0; j < 5; j ++){
                cadastra_bolsista();
            }
            break;
        case 2 :
            lista_cad();
            break;
        case 3 :
            arquivo = fopen("bolsistas.cad", "ab");
            cadastra_bolsista();
            break;
        case 4 :
            altera_dados();
            break;
        case 5 :
            printf("Programa encerrado\n");
            break;
        }
        fflush(stdin);
    } while (opc != 5);
    return 0;
}

int menu_bolsa()
{
    int bolsa;
    do{
        printf("[1] Trabalho\n");
        printf("[2] Iniciacao\n");
        printf("[3] Pesquisa\n");
        printf("Sua opcao: ");
        scanf("%d", &bolsa);
        if (!((bolsa <= 3) && (bolsa >= 1)))
            printf("Numero invalido\n");
    } while (!((bolsa <= 3) && (bolsa >= 1)));
    return bolsa;

}
int menu()
{
    int opc;
    do{

        printf("O que deseja fazer?\n\n");
        printf("[1] Cadastrar os primeiros 5 bolsistas\n");
        printf("[2] Listar os bolsistas\n");
        printf("[3] Cadastrar novos bolsistas\n");
        printf("[4] Alterar dados de um bolsista\n");
        printf("[5] Sair\n");
        printf("\nSua opcao: ");
        scanf("%d", &opc);
        if ((opc < 1) || (opc > 5))
            printf("Numero invalido\n");
    } while ((opc < 1) || (opc > 5));
}
void lista_cad()
{
    arquivo = fopen("bolsistas.cad", "rb");
    while (1){
        fread(&buffer, sizeof(struct registro), 1, arquivo);
        if (feof(arquivo))
            break;
        printf("Codigo: %d\nNome: %s\n", buffer.codigo, buffer.nome);
        switch (buffer.bolsa){
            case 1 :
                printf("Bolsa: Trabalho\n");
                break;
            case 2 :
                printf("Bolsa: Iniciacao\n");
                break;
            case 3 :
                printf("Bolsa: Pesquisa\n");
                break;
        }
        printf("Email: %s\n\n", buffer.email);
    }
    fclose(arquivo);
}

void cadastra_bolsista()
{
    int cod, total_lido;
    char resp, nome[31];
    bool repetido;

    do{
        repetido = false;
        do{
            printf("Insira o codigo do bolsista: ");
            fflush(stdin);
            scanf("%d", &cod);
            if ((cod < 1) || (cod > 25))
                printf("Codigo invalido\nInsira um codigo entre 1 e 25\n");
        } while ((cod < 1) || (cod > 25));
        arquivo_teste = fopen("bolsistas.cad", "rb");
        do{
            fread(&buffer, sizeof(struct registro), 1, arquivo_teste);
            if (feof(arquivo_teste))
                break;
            if(cod == buffer.codigo){
                repetido = true;
                printf("Codigo inserido ja utilizado\n");
                
                break;
            }
        } while(!feof(arquivo_teste));
        close(arquivo_teste);
    } while(repetido);
    buffer.codigo = cod;
    printf("Insira o nome do bolsista: ");
    fflush(stdin);
    gets(nome);
    strcpy(buffer.nome, nome);

    printf("Insira o tipo de bolsa do aluno: \n");
    buffer.bolsa = menu_bolsa();
    fflush(stdin);

    printf("Insira o email do bolsista: ");
    gets(buffer.email);
    fflush(stdin);

    arquivo = fopen("bolsistas.cad", "ab");
    fwrite(&buffer, sizeof(struct registro), 1, arquivo);

    fclose(arquivo);
}
void altera_dados()
{
    int cod;
    bool repete;
    char nome[31];
    do{
        repete = false;
        printf("Insira um codigo: \n");
        scanf("%d", &cod);
        arquivo = fopen("bolsistas.cad", "rb+");
        while(true){
            fread(&buffer, sizeof(struct registro), 1, arquivo);
            if (feof(arquivo))
                break;
            if (buffer.codigo == cod){
                repete = true;
                break;
            }
        }
        if (repete){
            printf("Dados anteriores: \n");
            printf("Codigo: %d\nNome: %s\n", buffer.codigo, buffer.nome);
            switch (buffer.bolsa){
                case 1 :
                    printf("Bolsa: Trabalho\n");
                    break;
                case 2 :
                    printf("Bolsa: Iniciacao\n");
                    break;
                case 3 :
                    printf("Bolsa: Pesquisa\n");
                    break;
            }
            printf("Email: %s\n\n", buffer.email);
        }
        else
            printf("Codigo nao existente\n");

    }while(!repete);
    buffer.codigo = cod;
    printf("Insira o nome do bolsista: ");
    fflush(stdin);
    gets(nome);
    strcpy(buffer.nome, nome);

    printf("Insira o tipo de bolsa do aluno: \n");
    buffer.bolsa = menu_bolsa();
    fflush(stdin);

    printf("Insira o email do bolsista: ");
    gets(buffer.email);
    fflush(stdin);

    fseek(arquivo, -1 * sizeof(struct registro), SEEK_CUR);
    fwrite(&buffer, sizeof(struct registro), 1, arquivo);
    fclose(arquivo);
}