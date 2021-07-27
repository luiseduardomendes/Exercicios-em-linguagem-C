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

struct registro{
    int codigo;
    char nome[31];
    int bolsa;
    char email[51];
}buffer, teste;

int i;

int main()
{
    int j;
    int opc;

    do{
        opc = menu();
        switch (opc){
        case 1 :
            arquivo = fopen("bolsistas.cad", "wb");
            cadastra_bolsista();
            printf("Primeiro aluno cadastrado\n");
            for (j = 0; j < 4; j ++){
                arquivo = fopen("bolsistas.cad", "ab");
                cadastra_bolsista();
                printf("Encerrado\n");
            }
            break;
        case 2 :
            lista_cad();
        case 3 :
            arquivo = fopen("bolsistas.cad", "ab");
            cadastra_bolsista();
            i++;
            break;
        }
    } while (opc != 4);
    return 0;
}

void cadastra_bolsista()
{
    int cod, cod_test;
    char email[51], nome[31], att;
    bool repetido = false;

    do{
        repetido = false;
        do{
            printf("Insira o codigo: ");
            scanf("%d", &cod);
            if ((cod < 1) || (cod > 25))
                printf("Codigo invalido\n");
        } while ((cod < 1) || (cod > 25));
        arquivo_teste = fopen("bolsistas.cad", "rb");
        if (arquivo_teste == NULL)
            printf("Falha ao abrir o arquivo\n");
        while (true){
            fread(&buffer, sizeof(struct registro), 1, arquivo_teste);
            if (buffer.codigo == cod){
                printf("Codigo ja inserido\ndeseja atualizar? [s/n]");
                scanf("%c", &att);
                att = toupper(att);
                repetido = true;
                if (att == 'S')
                    repetido = false;
            }
            if (feof(arquivo_teste))
                break;
        }
        fclose(arquivo_teste);
    } while(repetido);
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

    fwrite(&buffer, sizeof(struct registro), 1, arquivo);

    fclose(arquivo);
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

        printf("O que deseja fazer?\n");
        printf("[1] Cadastrar os primeiros 5 bolsistas\n");
        printf("[2] Listar os bolsistas\n");
        printf("[3] Cadastrar novos bolsistas\n");
        printf("[4] Sair\n");
        printf("Sua opcao: ");
        scanf("%d", &opc);
        if ((opc < 1) || (opc > 4))
            printf("Numero invalido\n");
    } while ((opc < 1) || (opc > 4));
}
void lista_cad()
{
    arquivo = fopen("E:\\teste C\\bolsistas.cad", "rb");
    while (1){
        fread(&buffer, sizeof(struct registro), 1, arquivo);
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
        printf("Email: %s\n", buffer.email);
        if (feof(arquivo))
            break;
    }
    fclose(arquivo);
}

