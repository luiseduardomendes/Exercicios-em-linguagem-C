#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

FILE *arquivo, *arquivo_teste, *arquivo_novo;

void cadastra_bolsista();
int menu();
int menu_bolsa();
void lista_cad();
void altera_dados();
void insert_mes_ano();
void lista_mes_ano();
void atualiza_dados();

struct registro{
    int codigo;
    char nome[31];
    int bolsa;
    char email[51];
}buffer, leitura[25];
struct registro2{
    int codigo;
    char nome[31];
    int bolsa;
    char email[51];
    int mes_venc;
    int ano_venc;
}buffer2;

int j;

int main()
{
    int opc;
    char resp;
    do{

        opc = menu();
        switch (opc){
        case 1 :
            printf("Esta acao apaga todos os dados para regravar os 5 primeiros\n");
            printf("Deseja realmente apagar todos os dados? [S/N]: ");
            fflush(stdin);
            scanf("%c", &resp);
            resp = toupper(resp);
            if (resp == 'S'){
                arquivo = fopen("bolsistas.cad", "wb");
                fclose(arquivo);
                arquivo_novo = fopen("bolsistas2.cad", "wb");
                fclose(arquivo_novo);
                for (j = 0; j < 5; j ++){
                    system("cls");
                    printf("Cadastro: %d\n", 1 + j);
                    cadastra_bolsista();
                }
            }
            break;
        case 2 :
            lista_cad();
            break;
        case 3 :
            arquivo = fopen("bolsistas.cad", "ab");
            system("cls");
            cadastra_bolsista();
            break;
        case 4 :
            altera_dados();
            break;
        case 5 :
            arquivo_novo = fopen("bolsistas2.cad", "rb");
            if (!feof(arquivo)){
                printf("O arquivo ja esta preenchido\n");
                printf("Deseja atualizar todos os dados? [S/N]: ");
                fflush(stdin);
                scanf("%c", &resp);
                resp = toupper(resp);
                if (resp == 'S'){
                    insert_mes_ano();
                    break;
                }
                else
                    break;
            }
            else
                insert_mes_ano();
            break;
        case 6 :
            lista_mes_ano();
            break;
        case 7 :
            printf("Programa encerrado\n");
            break;
        }
        fflush(stdin);
    } while (opc != 7);
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
    system("cls");
    do{

        printf("O que deseja fazer?\n\n");
        printf("[1] Cadastrar os primeiros 5 bolsistas\n");
        printf("[2] Listar os bolsistas\n");
        printf("[3] Cadastrar novos bolsistas\n");
        printf("[4] Alterar dados de um bolsista\n");
        printf("[5] Inserir mes e ano de validade da bolsa\n");
        printf("[6] Mostrar os bolsistas com a respectiva validade da bolsa\n");
        printf("[7] Sair\n");
        printf("\nSua opcao: ");
        scanf("%d", &opc);
        if ((opc < 1) || (opc > 7)){
            printf("Numero invalido\n");
            system("pause");
            system("cls");
        }
    } while ((opc < 1) || (opc > 7));
}
void lista_cad()
{
    system("cls");
    arquivo = fopen("bolsistas.cad", "rb");
    while (1){
        fread(&buffer, sizeof(struct registro), 1, arquivo);
        if (feof(arquivo))
            break;
        printf("Codigo:..............%d\nNome:................%s\n",
               buffer.codigo, buffer.nome);
        switch (buffer.bolsa){
            case 1 :
                printf("Bolsa:...............Trabalho\n");
                break;
            case 2 :
                printf("Bolsa:...............Iniciacao\n");
                break;
            case 3 :
                printf("Bolsa:...............Pesquisa\n");
                break;
        }
        printf("Email:...............%s\n\n", buffer.email);
    }
    fclose(arquivo);
    system("pause");
}
void cadastra_bolsista()
{
    int cod, total_lido;
    char resp, nome[31];
    bool repetido;

    do{
        repetido = false;
        do{
            printf("Insira o codigo do bolsista [entre 1 e 25]: ");
            fflush(stdin);
            scanf("%d", &cod);
            if ((cod < 1) || (cod > 25))
                printf("Codigo invalido\nInsira um codigo entre 1 e 25\n");
        } while ((cod < 1) || (cod > 25));
        arquivo_teste = fopen("bolsistas.cad", "rb+");
        do{
            fread(&buffer, sizeof(struct registro), 1, arquivo_teste);
            if (feof(arquivo_teste))
                break;
            if(cod == buffer.codigo){
                repetido = true;
                printf("Codigo inserido ja utilizado\n");
                printf("Deseja atualiza-lo? [S/N]: ");
                fflush(stdin);
                scanf("%c", &resp);
                resp = toupper(resp);
                if (resp == 'S'){
                    atualiza_dados();
                    repetido = false;
                }
                break;
            }
        } while(!feof(arquivo_teste));
        close(arquivo_teste);
    } while(repetido);
    if (resp != 'S'){
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
}
void altera_dados()
{
    system("cls");
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
void insert_mes_ano()
{
    system("cls");
    arquivo_novo = fopen("bolsistas2.cad", "wb");
    arquivo = fopen("bolsistas.cad", "rb");
    for(int i = 0; i < 25; i ++){
        rewind(arquivo);
        do{
            fread(&buffer2, sizeof(struct registro ), 1, arquivo);
            if (feof(arquivo))
                break;
            if ((i + 1) == buffer2.codigo){
                printf("Escreva o mes e o ano de vencimento da bolsa do aluno: \n");
                printf("codigo: %d\nnome: %s\n",
                        buffer2.codigo, buffer2.nome);
                printf("Mes: ");
                scanf("%d", &buffer2.mes_venc);
                printf("Ano: ");
                scanf("%d", &buffer2.ano_venc);
                fflush(stdin);
                fwrite(&buffer2, sizeof(struct registro2), 1, arquivo_novo);
            }
        }while(1);
    }
    fclose(arquivo);
    fclose(arquivo_novo);
}
void lista_mes_ano()
{
    system("cls");
    arquivo_novo = fopen("bolsistas2.cad", "rb");
    while (1){
        fread(&buffer2, sizeof(struct registro2), 1, arquivo_novo);
        if (feof(arquivo_novo))
            break;
        printf("Codigo:..............%d\nNome:................%s\n",
               buffer2.codigo, buffer2.nome);
        switch (buffer2.bolsa){
            case 1 :
                printf("Bolsa:...............Trabalho\n");
                break;
            case 2 :
                printf("Bolsa:...............Iniciacao\n");
                break;
            case 3 :
                printf("Bolsa:...............Pesquisa\n");
                break;
        }
        printf("Email:...............%s\n", buffer2.email);
        printf("Validade da bolsa:...%d/%d\n\n", buffer2.mes_venc, buffer2.ano_venc);
    }
    fclose(arquivo_novo);
    system("pause");
}
void atualiza_dados()
{
    char nome[31];
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

    fseek(arquivo_teste, -1 * sizeof(struct registro), SEEK_CUR);
    fwrite(&buffer, sizeof(struct registro), 1, arquivo_teste);
    fclose(arquivo_teste);

}
