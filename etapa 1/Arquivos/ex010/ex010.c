#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

FILE *arquivo_principal, *arquivo_homens;
FILE *arquivo_mulheres, *arquivo_outros;
FILE *arquivo_leitura, *arquivo_novo;

void cria_arquivo();
void divide_arquivos();
int menu_principal();
void mostra_arquivos();
void remove_cadastro();

struct registro{
    char nome[41];
    char sexo;
    float altura;
    float peso_i;
    float peso_f;
    int data[3];
}buffer;

int main()
{
    char resp;
    int opc;

    printf("Deseja cadastrar novos clientes? [S/N]: ");
    do{
        fflush(stdin);
        scanf("%c", &resp);
        resp = toupper(resp);
        if (resp == 'S'){
            cria_arquivo();
        }
        if ((resp != 'S') && (resp != 'N')){
            printf("Resposta invalida\nInsira outra [S/N]: ");
        }
    } while ((resp != 'S') && (resp != 'N'));



    opc = menu_principal();

    while(opc != 0){
        if (opc < 5)
            mostra_arquivos();
        if ((opc > 4) || (opc == 6))
            divide_arquivos();
        opc = menu_principal();
    }

    return 0;
}

void cria_arquivo()
{
    system("cls");
    char resp;
    arquivo_principal = fopen("cadastro.cad", "ab");
    do{
        printf("Nome do cliente: ");
        fflush(stdin);
        gets(buffer.nome);

        printf("Sexo [M/F/O (Outro)]: ");
        do{
            fflush(stdin);
            scanf("%c", &buffer.sexo);
            buffer.sexo = toupper(buffer.sexo);
            if ((buffer.sexo != 'M') && (buffer.sexo != 'F')
                && (buffer.sexo != 'O')){
                printf("Insira um sexo valido [M/F/O (Outro)]: ");
            }
        } while ((buffer.sexo != 'M') && (buffer.sexo != 'F')
                && (buffer.sexo != 'O'));

        printf("Altura: ");
        fflush(stdin);
        scanf("%f", &buffer.altura);

        printf("Peso inicial: ");
        fflush(stdin);
        scanf("%f", &buffer.peso_i);

        printf("Peso atual: ");
        fflush(stdin);
        scanf("%f", &buffer.peso_f);

        printf("Data de nascimento: \n");
        printf("dia: ");
        do{
            fflush(stdin);
            scanf("%d", &buffer.data[0]);
            if ((buffer.data[0] < 1) || (buffer.data[0] > 31)){
                printf("Valor invalido, \ninsira um dia valido: ");
            }
        } while ((buffer.data[0] < 1) || (buffer.data[0] > 31));

        printf("mes: ");
        do{
            fflush(stdin);
            scanf("%d", &buffer.data[1]);
            if ((buffer.data[1] < 1) || (buffer.data[1] > 12)){
                printf("Valor invalido, \ninsira um mes valido: ");
            }
        } while ((buffer.data[1] < 1) || (buffer.data[1] > 12));

        printf("ano: ");
        do{
            fflush(stdin);
            scanf("%d", &buffer.data[2]);
            if ((buffer.data[2] < 1900) || (buffer.data[2] > 2021)){
                printf("Valor invalido, \ninsira um ano valido: ");
            }
        } while ((buffer.data[2] < 1900) || (buffer.data[2] > 2021));


        fwrite(&buffer, sizeof(struct registro), 1, arquivo_principal);
        fclose(arquivo_principal);

        printf("Deseja realizar outro cadastro? [S/N]: ");
        fflush(stdin);
        scanf("%c", &resp);
        resp = toupper(resp);
        printf("\n");
    }while (resp == 'S');
    fclose(arquivo_principal);
}

void divide_arquivos()
{
    arquivo_principal = fopen("cadastro.cad", "rb");
    arquivo_homens = fopen("cadastro.homens.cad", "wb");
    arquivo_mulheres = fopen("cadastro.mulheres.cad", "wb");
    arquivo_outros = fopen("cadastro.outros.cad", "wb");

    while(true){
        fread(&buffer, sizeof(struct registro), 1, arquivo_principal);
        if(feof(arquivo_principal))
            break;
        switch (buffer.sexo){
            case 'M' :
                fwrite(&buffer, sizeof(struct registro), 1, arquivo_homens);
                break;
            case 'F' :
                fwrite(&buffer, sizeof(struct registro), 1, arquivo_mulheres);
                break;
            case 'O' :
                fwrite(&buffer, sizeof(struct registro), 1, arquivo_outros);
                break;
        }
    }

    fclose(arquivo_principal);
    fclose(arquivo_homens);
    fclose(arquivo_mulheres);
    fclose(arquivo_outros);
}

int menu_principal()
{
    int opc;
    do{
        system("cls");
        printf("Qual arquivo deseja visualizar?\n");
        printf("[1] Clientes totais\n");
        printf("[2] Clientes homens\n");
        printf("[3] Clientes mulheres\n");
        printf("[4] Clientes de outra sexualidade\n");
        printf("[5] Cadastrar novo cliente\n");
        printf("[6] Remover dados de um cliente\n");
        printf("[0] Encerrar programa\n");
        printf("Sua opcao: ");
        fflush(stdin);
        scanf("%d", &opc);
        if((opc < 0) || (opc > 6))
            printf("Valor invalido\nInsira outro: ");
        switch (opc){
            case 1 : arquivo_leitura = fopen("cadastro.cad", "rb");
                break;
            case 2 : arquivo_leitura = fopen("cadastro.homens.cad", "rb");
                break;
            case 3 : arquivo_leitura = fopen("cadastro.mulheres.cad", "rb");
                break;
            case 4 : arquivo_leitura = fopen("cadastro.outros.cad", "rb");
                break;
            case 5 : cria_arquivo();
                break;
            case 6 : remove_cadastro();
                break;
        }
    }while((opc < 0) || (opc > 6));
    return opc;
}

void mostra_arquivos()
{
    system("cls");
    while(true){
        fread(&buffer, sizeof(struct registro), 1, arquivo_leitura);
        if (feof(arquivo_leitura))
            break;
        printf("Nome:...............: %s\n", buffer.nome);
        printf("Sexo:...............: ");
        switch(buffer.sexo){
            case 'M' : printf("Masculino\n");
                break;
            case 'F' : printf("Feminino\n");
                break;
            case 'O' : printf("Outro\n");
                break;
        }
        printf("Altura:.............: %.2f\n", buffer.altura);
        printf("Peso inicial........: %.2f\n", buffer.peso_i);
        printf("Peso atual..........: %.2f\n", buffer.peso_f);
        printf("Data de nascimento..: %d/%d/%d\n\n", buffer.data[0],
               buffer.data[1], buffer.data[2]);
    }
    fclose(arquivo_leitura);
    system("pause");
}

void remove_cadastro()
{
    system("cls");
    bool encontrado;
    char resp, opc;
    arquivo_principal = fopen("cadastro.cad", "rb");
    char nome[41];

    do{
        printf("Digite o nome do cliente a ser removido: ");
        encontrado = false;
        fflush(stdin);
        gets(nome);
        rewind(arquivo_principal);
        while (true){
            fread(&buffer, sizeof(struct registro), 1, arquivo_principal);
            if (feof(arquivo_principal))
                break;
            if (strcmp(nome, buffer.nome) == 0){
                encontrado = true;
                system("cls");
                printf("Dados do cliente: \n\n");
                printf("Nome:...............: %s\n", buffer.nome);
                printf("Sexo:...............: ");
                switch(buffer.sexo){
                    case 'M' : printf("Masculino\n");
                        break;
                    case 'F' : printf("Feminino\n");
                        break;
                    case 'O' : printf("Outro\n");
                        break;
                }
                printf("Altura:.............: %.2f\n", buffer.altura);
                printf("Peso inicial........: %.2f\n", buffer.peso_i);
                printf("Peso atual..........: %.2f\n", buffer.peso_f);
                printf("Data de nascimento..: %d/%d/%d\n\n", buffer.data[0],
                        buffer.data[1], buffer.data[2]);

                fclose(arquivo_principal);
                printf("Deseja realmente excluir esses dados? [S/N]: ");
                fflush(stdin);
                scanf("%c", &opc);
                opc = toupper(opc);
                if (opc == 'S'){
                    arquivo_principal = fopen("cadastro.cad", "rb");
                    arquivo_novo = fopen("cadastro.novo.cad", "wb");
                    while(true){
                        fread(&buffer, sizeof(struct registro), 1, arquivo_principal);
                        if(feof(arquivo_principal)){
                            break;
                        }
                        if(strcmp(buffer.nome, nome) != 0){
                            fwrite(&buffer, sizeof(struct registro), 1, arquivo_novo);
                        }
                    }
                    fclose(arquivo_principal);
                    fclose(arquivo_novo);
                    remove("cadastro.cad");
                    rename("cadastro.novo.cad", "cadastro.cad");
                }
                break;
            }
        }
        if (!encontrado){
            printf("Cliente nao encontrado\n");
            printf("deseja ver a lista de clientes? [S/N]: ");
            fflush(stdin);
            scanf("%c", &resp);
            resp = toupper(resp);
            if (resp == 'S'){
                arquivo_leitura = fopen("cadastro.cad", "rb");
                mostra_arquivos();
            }
        }
    } while(!encontrado);
}
