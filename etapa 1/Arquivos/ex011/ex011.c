#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

FILE *arq_cad, *arq_test;

enum op {deposito = 1, saque};
enum tipo {fechada = 0, simples, especial};

int menu();
int menu_cliente(int codigo);
int menu_funcionario();
void op_saque(int codigo);
void op_deposito(int codigo);
void op_movimento(int codigo);
void op_todos_movimto(int codigo);
void login();
void cadastrar();
void atualiza();
enum tipo menu_conta();

struct movimento{
    int data_mov[3];
    enum op movimto;
};

struct cadastro{
    int conta;
    char nome[41];
    int data_abertura[3];
    enum tipo tipo_conta;
    int data_vencimento[3];
    char senha[17];
}buffer;

int main()
{
    arq_cad = fopen("cadastros.cad", "ab");
    for (int i = 1; i <= 500; i ++ ){
        buffer.conta = i;
        strcpy(buffer.nome, " ");
        strcpy(buffer.senha, "admin");
        fwrite(&buffer, sizeof(struct cadastro), 1, arq_cad);


    }
    fclose(arq_cad);

    int resp;
    do{
        resp = menu();
    } while (resp != 0);

    return 0;
}

int menu()
{
    int resp;
    system("cls");
    do{
        printf("[1] Acesso ao cliente\n");
        printf("[2] Acesso ao funcionario\n");
        printf("[0] Encerrar programa\n");
        fflush(stdin);
        scanf("%d", &resp);
        if ((resp < 0) || (resp > 2)){
            printf("\nInsira um valor valido: ");
        }
    } while ((resp < 0) || (resp > 2));
    switch (resp){
        case 1 : login();
        break;
        case 2 : menu_funcionario();
        break;
    }
    return (resp);
}

int menu_cliente(int codigo)
{
    int resp;
    system("cls");
    printf("[1] Saque\n");
    printf("[2] Deposito\n");
    printf("[3] movimentacoes\n");
    printf("[0] Sair\n");
    do{
        fflush(stdin);
        scanf("%d", &resp);
        if ((resp < 0) || (resp > 3)){
            printf("Insira um valor valido: ");
        }
    } while ((resp < 0) || (resp > 3));
    switch (resp){
        case 1 : //op_saque(codigo);
        break;
        case 2 : //op_deposito(codigo);
        break;
        case 3 : //op_moviment(codigo);
        break;
        case 4 : //op_todos_mov(codigo);
        break;
    }
    return resp;
}

int menu_funcionario()
{
    system("cls");
    int resp;
    printf("[1] Realizar um cadastro\n");
    printf("[2] Atualizar dados do cliente\n");
    printf("[0] Sair\n");
    do{
        fflush(stdin);
        scanf("%d", &resp);
        if ((resp < 0) || (resp > 2)){
            printf("Insira um valor valido: ");
        }
    } while ((resp < 0) || (resp > 2));
    switch (resp){
        case 1 : cadastrar();
        break;
        case 2 : //atualiza();
        break;
    }
    return resp;
}
void login()
{
    int codigo;
    char senha[17];
    bool acesso;
    arq_cad = fopen("cadastros.cad", "rb");
    printf("Insira o seu codigo para continuar: ");

    do{
        do{
            fflush(stdin);
            scanf("%d", &codigo);
            if((codigo < 1) || (codigo > 500)){
                printf("Conta invalida\nO numero da conta deve estar ");
                printf("entre 1 e 500\nInsira outro: ");
            }
        } while ((codigo < 1) || (codigo > 500));

        fseek(arq_cad, (codigo - 1)*sizeof(struct cadastro), SEEK_SET);
        fread(&buffer, sizeof(struct cadastro), 1, arq_cad);
        if (strcmp(buffer.nome, " ") == 0){
            printf("Conta nao encontrada\nInsira outra: ");
        }
    }while(strcmp(buffer.nome, " ") == 0);
    for(int i = 4; i >= 0; i --){
        acesso = false;
        printf("Insira a senha: ");
        fflush(stdin);
        gets(senha);
        if (strcmp(senha, buffer.senha) != 0){
            printf("Senha invalida\n");
            printf("%d tentativas restantes\n", i);
        }
        else{
            acesso = true;
            break;
        }
        if (i == 0){
            printf("Voce excedeu o limite de tentativas\n");
            system("pause");
            break;
        }
    }
    if (acesso){
        menu_cliente(codigo - 1);
    }
}
void cadastrar()
{
    int cod, total_lido;
    char resp, nome[41];
    bool repetido;

    do{
        repetido = false;
        do{
            printf("Insira o codigo da conta [entre 1 e 500]: ");
            fflush(stdin);
            scanf("%d", &cod);
            if ((cod < 1) || (cod > 500))
                printf("Codigo invalido\nInsira um codigo entre 1 e 500\n");
        } while ((cod < 1) || (cod > 500));
        arq_test = fopen("cadastros.cad", "rb");
        repetido = false;
        fseek(arq_cad, (cod - 1)*sizeof(struct cadastro),SEEK_SET);
        fread(&buffer, sizeof(struct cadastro), 1, arq_test);
        if (feof(arq_test))
            break;
        if(strcmp(buffer.nome, " ") != 0){
            repetido = true;
            printf("Codigo inserido ja utilizado\n");
            break;
        }
        close(arq_test);
    } while(repetido);

    buffer.conta = cod;
    printf("Insira o nome do titular da conta: ");
    fflush(stdin);
    gets(buffer.nome);

    printf("Insira o tipo da conta: \n");
    buffer.tipo_conta = menu_conta();
    fflush(stdin);

    printf("Insira a senha da conta: ");
    gets(buffer.senha);
    fflush(stdin);

    arq_cad = fopen("cadastros.cad", "wb");
    fseek(arq_cad, (cod - 1)*sizeof(struct cadastro), SEEK_SET);
    fwrite(&buffer, sizeof(struct cadastro), 1, arq_cad);
    fclose(arq_cad);
}
enum tipo menu_conta()
{
    enum tipo tipo_conta;
    system("cls");
    do{
        printf("Insira o tipo da conta: \n");
        printf("[1] Simples\n");
        printf("[2] Especial\n");
        fflush(stdin);
        scanf("%d", &tipo_conta);
        if ((tipo_conta != simples) &&
             (tipo_conta != especial))
            printf("Numero invalido\n");

    } while ((tipo_conta != simples) &&
             (tipo_conta != especial));
    return (tipo_conta);
}
