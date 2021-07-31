#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

enum op {dep = 1, saque};
enum tipo {simples = 1, especial, fechada};

menu();
menu_cliente();
menu_funcionario();
op_saque();
op_deposito();
op_movimento();
op_todos_movimto();
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
};

int main()
{
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
        printf("[0] Encerrar programa");
        fflush(stdin);
        scanf("%d", &resp);
        if ((resp < 0) || (resp > 2)){
            printf("\nInsira um valor valido: ");
        }
    } while ((resp < 0) || (resp > 2));
    switch (resp){
        case 1 : menu_cliente();
        break;
        case 2 : menu_funcionario();
        break;
    }
    return (resp);
}

int menu_cliente()
{
    int resp;
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
        case 1 : op_saque();
        break;
        case 2 : op_deposito();
        break;
        case 3 : op_moviment();
        break;
        case 4 : op_todos_mov();
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
        case 2 : atualiza();
        break;
    }
    return resp;
}
