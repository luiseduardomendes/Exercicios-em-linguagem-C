#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <stdio_ext.h>

FILE *arq_cad, *arq_test;
FILE *arq_mov;

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
void login_func();
void cadastrar();
void atualiza();
enum tipo menu_conta();
void reseta();
void mostrar_cadastros();
void testar_backup();
void realizar_backup();
void abre_arquivos();

struct movimento{
    int data_mov[3];
    enum op op_mov;
    float valor;
    int codigo;
}buffer_mov;

struct cadastro{
    int conta;
    char nome[41];
    int data_abertura[3];
    enum tipo tipo_conta;
    int data_vencimento[3];
    char senha[17];
    float saldo;
}buffer;

int main()
{
    abre_arquivos(arq_cad);

    int resp;
    do{
        resp = menu();
    } while (resp != 0);

    return 0;
}

int menu()
{
    int resp;
    printf("\e[H\e[2J");
    do{
        printf("[1] Acesso ao cliente\n");
        printf("[2] Acesso ao funcionario\n");
        printf("[0] Encerrar programa\n");
        __fpurge(stdin);
        scanf("%d", &resp);
        if ((resp < 0) || (resp > 2)){
            printf("\nInsira um valor valido: ");
        }
    } while ((resp < 0) || (resp > 2));
    switch (resp){
        case 1 : login();
        break;
        case 2 : login_func();
        break;
        case 0 : printf("Programa encerrado\n");
        break;
    }
    return (resp);
}

int menu_cliente(int codigo)
{
    int resp;
    printf("\e[H\e[2J");
    printf("[1] Saque (INDISPONIVEL)\n");
    printf("[2] Deposito (INDISPONIVEL)\n");
    printf("[3] movimentacoes (INDISPONIVEL)\n");
    printf("[0] Voltar ao menu principal\n");
    do{
        __fpurge(stdin);
        scanf("%d", &resp);
        if ((resp < 0) || (resp > 3)){
            printf("Insira um valor valido: ");
        }
    } while ((resp < 0) || (resp > 3));
    switch (resp){
        case 1 : op_saque(codigo);
        break;
        case 2 : op_deposito(codigo);
        break;
        case 3 : op_movimento(codigo);
        break;
        case 4 : //op_todos_mov(codigo);
        break;
    }
    return resp;
}

int menu_funcionario()
{
    printf("\33[H\33[2J");
    int resp;
    printf("[1] Realizar um cadastro\n");
    printf("[2] Atualizar dados do cliente\n");
    printf("[3] Mostrar cadastros ativos\n");
    printf("[4] Realizar backup\n");
    printf("[5] Testar backup\n");
    printf("[6] Excluir todos os dados\n");
    printf("[0] Voltar ao menu principal\n");
    do{
        __fpurge(stdin);
        scanf("%d", &resp);
        if ((resp < 0) || (resp > 6)){
            printf("Insira um valor valido: ");
        }
    } while ((resp < 0) || (resp > 6));
    switch (resp){
        case 1 : cadastrar();
        break;
        case 2 : atualiza();
        break;
        case 3 : mostrar_cadastros();
        break;
        case 4 : realizar_backup();
        break;
        case 5 : testar_backup();
        break;
        case 6 :
            for(int i = 4; i >= 0; i --){
                char senha[17];
                printf("Insira a senha: ");
                __fpurge(stdin);
                gets(senha);
                if (strcmp(senha, "admin") != 0){
                    printf("Senha invalida\n");
                    printf("%d tentativas restantes\n", i);
                }
                if (strcmp(senha, "admin") == 0){
                    reseta();
                    break;
                }
                if (i == 0){
                    printf("Voce excedeu o limite de tentativas\n");
                    getchar();
                    break;
                }
            }
            break;
    }
    return resp;
}

void login()
{
    int codigo;
    char senha[17];
    bool acesso;

    printf("Insira o seu codigo para continuar: ");

    do{
        do{
            __fpurge(stdin);
            scanf("%d", &codigo);
            if((codigo < 1) || (codigo > 500)){
                printf("Conta invalida\nO numero da conta deve estar ");
                printf("entre 1 e 500\nInsira outro: ");
            }
        } while ((codigo < 1) || (codigo > 500));
        arq_cad = fopen("cadastros.cad", "rb");
        fseek(arq_cad, (codigo - 1)*sizeof(struct cadastro), SEEK_SET);
        fread(&buffer, sizeof(struct cadastro), 1, arq_cad);
        if (buffer.tipo_conta == fechada){
            printf("Conta nao encontrada\nInsira outra: ");
        }
    }while(buffer.tipo_conta == fechada);
    fseek(arq_cad, (codigo - 1)*sizeof(struct cadastro), SEEK_SET);
    for(int i = 4; i >= 0; i --){
        acesso = false;
        printf("Insira a senha: ");
        __fpurge(stdin);
        gets(senha);
        if (strcmp(senha, buffer.senha) != 0){
            printf("Senha invalida\n");
            printf("%d tentativas restantes\n", i);
        }
        if (strcmp(senha, buffer.senha) == 0){
            acesso = true;
            break;
        }
        if (i == 0){
            printf("Voce excedeu o limite de tentativas\n");
            system("pause");
            break;
        }
    }
    fclose(arq_cad);
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
            __fpurge(stdin);
            scanf("%d", &cod);
            if ((cod < 1) || (cod > 500))
                printf("Codigo invalido\nInsira um codigo entre 1 e 500\n");
        } while ((cod < 1) || (cod > 500));
        arq_cad = fopen("cadastros.cad", "rb");
        repetido = false;
        rewind(arq_cad);
        fseek(arq_cad, (cod - 1)*sizeof(struct cadastro), SEEK_SET);
        fread(&buffer, sizeof(struct cadastro), 1, arq_cad);
        if(buffer.tipo_conta == fechada){
            repetido = false;
        }
        else{
            repetido = true;
            printf("Codigo inserido ja utilizado\n");
        }
        fclose(arq_cad);
    } while(repetido);

    printf("Insira o nome do titular da conta: ");
    __fpurge(stdin);
    gets(buffer.nome);

    printf("Insira o tipo da conta: \n");
    buffer.tipo_conta = menu_conta();
    __fpurge(stdin);

    printf("Insira a senha da conta: ");
    gets(buffer.senha);
    __fpurge(stdin);

    printf("Insira a data de abertura da conta: \n");
    printf("Insira o dia: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_abertura[0]);
        if ((buffer.data_abertura[0] < 1) &&
        (buffer.data_abertura[0] > 31))
            printf("Insira um dia valido: ");
    } while ((buffer.data_abertura[0] < 1) &&
    (buffer.data_abertura[0] > 31));

    printf("Insira o mes: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_abertura[1]);
        if ((buffer.data_abertura[1] < 1) &&
        (buffer.data_abertura[1] > 12))
            printf("Insira um mes valido: ");
    } while ((buffer.data_abertura[1] < 1) &&
    (buffer.data_abertura[1] > 12));

    printf("Insira o ano: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_abertura[2]);
        if ((buffer.data_abertura[2] < 2021) &&
        (buffer.data_abertura[2] > 2031))
            printf("Insira um ano valido: ");
    } while ((buffer.data_abertura[2] < 2021) &&
    (buffer.data_abertura[2] > 2031));

    printf("Insira a data de vencimento da conta: ");
    printf("Insira o dia: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_vencimento[0]);
        if ((buffer.data_vencimento[0] < 1) &&
        (buffer.data_vencimento[0] > 31))
            printf("Insira um dia valido: ");
    } while ((buffer.data_vencimento[0] < 1) &&
    (buffer.data_vencimento[0] > 31));

    printf("Insira o mes: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_vencimento[1]);
        if ((buffer.data_vencimento[1] < 1) &&
        (buffer.data_vencimento[1] > 12))
            printf("Insira um mes valido: ");
    } while ((buffer.data_vencimento[1] < 1) &&
    (buffer.data_vencimento[1] > 12));

    printf("Insira o ano: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_vencimento[2]);
        if ((buffer.data_vencimento[2] < 2021) &&
        (buffer.data_vencimento[2] > 2031))
            printf("Insira um ano valido: ");
    } while ((buffer.data_vencimento[2] < 2021) &&
    (buffer.data_vencimento[2] > 2031));

    arq_cad = fopen("cadastros.cad", "rb+");
    fseek(arq_cad, (cod - 1)*sizeof(struct cadastro), SEEK_SET);
    fwrite(&buffer, sizeof(struct cadastro), 1, arq_cad);
    fclose(arq_cad);
}

void atualiza()
{
    int cod;
    char resp, nome[41];
    bool repetido;

    do{
        repetido = false;
        do{
            printf("Insira o codigo da conta [entre 1 e 500]: ");
            __fpurge(stdin);
            scanf("%d", &cod);
            if ((cod < 1) || (cod > 500))
                printf("Codigo invalido\nInsira um codigo entre 1 e 500\n");
        } while ((cod < 1) || (cod > 500));
        arq_cad = fopen("cadastros.cad", "rb");
        repetido = false;
        rewind(arq_cad);
        fseek(arq_cad, (cod - 1)*sizeof(struct cadastro), SEEK_SET);
        fread(&buffer, sizeof(struct cadastro), 1, arq_cad);
        if(buffer.tipo_conta == fechada){
            repetido = false;
            printf("Codigo inserido nao existe\n");
        }
        else{
            repetido = true;

        }
        fclose(arq_cad);
    } while(!repetido);

    printf("Insira o nome do titular da conta: ");
    __fpurge(stdin);
    gets(buffer.nome);

    printf("Insira o tipo da conta: \n");
    buffer.tipo_conta = menu_conta();
    __fpurge(stdin);

    printf("Insira a senha da conta: ");
    gets(buffer.senha);
    __fpurge(stdin);

    printf("Insira a data de abertura da conta: \n");
    printf("Insira o dia: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_abertura[0]);
        if ((buffer.data_abertura[0] < 1) &&
        (buffer.data_abertura[0] > 31))
            printf("Insira um dia valido: ");
    } while ((buffer.data_abertura[0] < 1) &&
    (buffer.data_abertura[0] > 31));

    printf("Insira o mes: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_abertura[1]);
        if ((buffer.data_abertura[1] < 1) &&
        (buffer.data_abertura[1] > 12))
            printf("Insira um mes valido: ");
    } while ((buffer.data_abertura[1] < 1) &&
    (buffer.data_abertura[1] > 12));

    printf("Insira o ano: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_abertura[2]);
        if ((buffer.data_abertura[2] < 2021) &&
        (buffer.data_abertura[2] > 2031))
            printf("Insira um ano valido: ");
    } while ((buffer.data_abertura[2] < 2021) &&
    (buffer.data_abertura[2] > 2031));

    printf("Insira a data de vencimento da conta: \n");
    printf("Insira o dia: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_vencimento[0]);
        if ((buffer.data_vencimento[0] < 1) &&
        (buffer.data_vencimento[0] > 31))
            printf("Insira um dia valido: ");
    } while ((buffer.data_vencimento[0] < 1) &&
    (buffer.data_vencimento[0] > 31));

    printf("Insira o mes: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_vencimento[1]);
        if ((buffer.data_vencimento[1] < 1) &&
        (buffer.data_vencimento[1] > 12))
            printf("Insira um mes valido: ");
    } while ((buffer.data_vencimento[1] < 1) &&
    (buffer.data_vencimento[1] > 12));

    printf("Insira o ano: ");
    do{
        __fpurge(stdin);
        scanf("%d", &buffer.data_vencimento[2]);
        if ((buffer.data_vencimento[2] < 2021) &&
        (buffer.data_vencimento[2] > 2031))
            printf("Insira um ano valido: ");
    } while ((buffer.data_vencimento[2] < 2021) &&
    (buffer.data_vencimento[2] > 2031));

    arq_cad = fopen("cadastros.cad", "rb+");
    fseek(arq_cad, (cod - 1)*sizeof(struct cadastro), SEEK_SET);
    fwrite(&buffer, sizeof(struct cadastro), 1, arq_cad);
    fclose(arq_cad);
}

enum tipo menu_conta()
{
    enum tipo tipo_conta;
    do{
        printf("[1] Simples\n");
        printf("[2] Especial\n");
        __fpurge(stdin);
        scanf("%d", &tipo_conta);
        if ((tipo_conta < fechada) &&
        (tipo_conta > especial))
            printf("Numero invalido\n");

    } while ((tipo_conta < fechada) &&
    (tipo_conta > especial));
    return (tipo_conta);
        }

        void login_func()
        {
    char senha[17];
    bool acesso;

    for(int i = 4; i >= 0; i --){
        acesso = false;
        printf("Insira a senha: ");
        __fpurge(stdin);
        gets(senha);
        if (strcmp(senha, "admin") != 0){
            printf("Senha invalida\n");
            printf("%d tentativas restantes\n", i);
        }
        if (strcmp(senha, "admin") == 0){
            acesso = true;
            break;
        }
        if (i == 0){
            printf("Voce excedeu o limite de tentativas\n");
            getchar();
            break;
        }
    }
    if (acesso){
        menu_funcionario();
    }
        }

        void reseta()
        {
    arq_cad = fopen("cadastros.cad", "wb");
    rewind(arq_cad);
    for (int i = 1; i <= 500; i ++ ){
        buffer.conta = i;
        buffer.tipo_conta = 0;
        strcpy(buffer.nome, " ");
        strcpy(buffer.senha, "admin");
        fwrite(&buffer, sizeof(struct cadastro), 1, arq_cad);
    }
    fclose(arq_cad);
        }

        void mostrar_cadastros()
        {
    arq_cad = fopen("cadastros.cad", "rb");
    while (true){
        fread(&buffer, sizeof(struct cadastro), 1, arq_cad);
        if (buffer.tipo_conta == fechada){
            printf("codigo: %d\nNome: %s\n", buffer.conta, buffer.nome);
            printf("data de abertura: %d/%d/%d\n", buffer.data_abertura[0],
                   buffer.data_abertura[1], buffer.data_abertura[2]);
            printf("data de vencimento: %d/%d/%d\n", buffer.data_vencimento[0],
                   buffer.data_vencimento[1], buffer.data_vencimento[2]);
            printf("Tipo de conta: ");
            switch(buffer.tipo_conta){
                case fechada : printf("Fechada \n");
                break;
                case simples : printf("Simples \n");
                break;
                case especial : printf("Especial \n");
                break;
            }
            printf("Saldo disponivel: R$%.2f\n\n", buffer.saldo);
        }

        if (feof(arq_cad)){
            getchar();
            break;
        }
    }
    fclose(arq_cad);
        }
        void realizar_backup()
        {
    arq_cad = fopen("cadastros.cad", "rb");
    arq_test = fopen("backup-cadastros.cad", "wb");
    while (true){
        fread(&buffer, sizeof(struct cadastro), 1, arq_cad);
        if (feof(arq_cad))
            break;
        fwrite(&buffer, sizeof(struct cadastro), 1, arq_test);
    }
    fclose(arq_cad);
    fclose(arq_test);
        }

        void testar_backup()
        {
    arq_cad = fopen("backup-cadastros.cad", "rb");
    while (true){
        fread(&buffer, sizeof(struct cadastro), 1, arq_cad);
        if (buffer.tipo_conta != fechada){
            printf("codigo: %d\nNome: %s\n", buffer.conta, buffer.nome);
            printf("data de abertura: %d/%d/%d\n", buffer.data_abertura[0],
                   buffer.data_abertura[1], buffer.data_abertura[2]);
            printf("data de vencimento: %d/%d/%d\n", buffer.data_vencimento[0],
                   buffer.data_vencimento[1], buffer.data_vencimento[2]);
            printf("Tipo de conta: ");
            switch(buffer.tipo_conta){
                case simples : printf("Simples \n\n");
                break;
                case especial : printf("Especial \n\n");
                break;
            }
        }

        if (feof(arq_cad)){
            getchar();
            break;
        }
    }
    fclose(arq_cad);
}

void op_saque(int codigo)
{
    float valor;
    char resp;
    arq_cad = fopen("cadastros.cad", "rb+");
    arq_mov = fopen("movimentacoes.cad", "ab+");
    fseek(arq_cad, (codigo - 1) * sizeof(struct cadastro), SEEK_SET);
    fread(&buffer, sizeof(struct cadastro), 1, arq_cad);
    printf("Digite o valor do saque: ");
    do{
        scanf("%f", &valor);
        if (buffer.saldo < valor)
            printf("Valor indisponivel\nInsira outro: ");
        else{
            printf("Aguarde a contagem das cedulas...\n");

            buffer.saldo -= valor;

            fseek(arq_cad, -1*sizeof(struct cadastro), SEEK_CUR);
            fwrite(&buffer, sizeof(struct cadastro), 1, arq_cad);
            buffer_mov.valor = valor;
            buffer_mov.op_mov = 2;
            buffer_mov.data_mov[0] = 5;
            buffer_mov.data_mov[1] = 8;
            buffer_mov.data_mov[2] = 2021;


            fwrite(&buffer_mov, sizeof(struct movimento), 1, arq_mov);
            getchar();

            printf("Deseja consultar seu saldo? [S/N]");
            scanf(" %c", &resp);
            resp = toupper(resp);
            if (resp == 'S'){
                printf("Saldo atual: R$%.2f\n\n", buffer.saldo);
                getchar();
            }
        }
    } while (buffer.saldo < valor);
    fclose(arq_cad);
    fclose(arq_mov);
        }
        void op_deposito(int codigo)
        {
    float valor;
    char resp;
    arq_cad = fopen("cadastros.cad", "rb+");
    arq_mov = fopen("movimentacoes.cad", "ab+");
    fseek(arq_cad, (codigo - 1) * sizeof(struct cadastro), SEEK_SET);
    fread(&buffer, sizeof(struct cadastro), 1, arq_cad);
    printf("Digite o valor do deposito: ");

    scanf("%f", &valor);

    printf("Saldo depositado com sucesso!\n");

    buffer.saldo += valor;
    fseek(arq_cad, -1*sizeof(struct cadastro), SEEK_CUR);
    fwrite(&buffer, sizeof(struct cadastro), 1, arq_cad);
    buffer_mov.valor = valor;
    buffer_mov.op_mov = 1;
    buffer_mov.data_mov[0] = 5;
    buffer_mov.data_mov[1] = 8;
    buffer_mov.data_mov[2] = 2021;
    buffer_mov.codigo = codigo;


    fwrite(&buffer_mov, sizeof(struct movimento), 1, arq_mov);

    printf("Deseja consultar seu saldo? [S/N]");
    scanf(" %c", &resp);
    resp = toupper(resp);
    if (resp == 'S'){
        printf("Saldo atual: R$%.2f\n\n", buffer.saldo);
        getchar();
    }

    fclose(arq_cad);
    fclose(arq_mov);

}

void op_movimento(int codigo)
{
    arq_mov = fopen("movimentacoes.cad", "rb");
    while(true){
        fread(&buffer_mov, sizeof(struct movimento), 1, arq_mov);
        if(feof(arq_mov))
            break;
        if(buffer_mov.codigo ==  codigo){
            printf("movimento: ");
            switch(buffer_mov.op_mov){
                case deposito : printf("Deposito\n");
                break;
                case saque : printf("Saque\n");
                break;
            }
            printf("valor: R$%.2f\n", buffer_mov.valor);
            printf("data: %d/%d/%d\n\n", buffer_mov.data_mov[0], buffer_mov.data_mov[1], buffer_mov.data_mov[2]);
        }
    }
    getchar();
}

void abre_arquivos(){
    arq_cad = fopen("cadastros.cad", "rb");
    if (arq_cad == NULL){
        arq_cad = fopen("cadastros.cad", "wb");
        for (int i = 0; i < 500; i ++){
            buffer.tipo_conta = fechada;
            fwrite(&buffer, sizeof(struct cadastro), 1, arq_cad);
        }
    }
    fclose(arq_cad);
    arq_mov = fopen("movimentacoes.cad", "rb");
    if (arq_mov == NULL){
        arq_mov = fopen("movimentacoes.cad", "wb");
    }
    fclose(arq_mov);
}