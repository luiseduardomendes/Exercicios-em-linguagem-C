#include <stdio.h>
#define NUM_REPRESENT 10

int main() {
    int codigo, itens, totalVendas = 0;
    float valorVenda, comissao, totalComissoes = 0;

    printf("Digite o codigo do funcionario [0 para parar]: ");
    scanf("%d", codigo);

    while (codigo > 0){
        printf("Digite o valor da venda: R$");
        scanf("%f", &valorVenda);

        do{
            printf("Digite a quantidade de itens: ");
            scanf("%d", &itens);
            if (itens <= 0) {
                printf("Insira uma quantidade valida\n");
            }
        } while (itens <= 0);

        if (itens < 20) {
            comissao = valorVenda * 0.1;
        }
        else if(itens < 50) {
            comissao = valorVenda * 0.15;
        }
        else if (itens < 75) {
            comissao = valorVenda * 0.2;
        }
        else {
            comissao = valorVenda * 0.25;
        }

        totalVendas += valorVenda;
        totalComissoes += comissao;

        printf("Valor da venda: R$%.2f\n", valorVenda);
        printf("Comissao recebida: R$%.2f\n", comissao);

        do {
            printf("Digite o codigo do funcionario [0 para parar]: ");
            scanf("%d", &codigo);
            if (codigo < 0 || codigo > 10){
                printf("Digite um codigo valido\n");
            }
        } while (codigo < 0 || codigo > 10);
    } 

    printf("Valor total das vendas: R$%.2f\n", totalVendas);
    printf("Valor total de comissoes: R$%.2f\n", totalComissoes);

    return 0;
}