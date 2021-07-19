#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define num_func 2

struct registro{
        int codigo;
        float salario;
        int idade;
        char sexo;
};

int aumenta_salario(float salario);
void num_mulheres(struct registro vetor[num_func]);
float idade_media(struct registro vetor[num_func]);
void idade_salario_mulheres(struct registro vetor[num_func]);

int main()
{
    int i, busca, vet_func;
    bool encontrado;
    char aumento, resposta;
    struct registro vetor[num_func];
    for (i = 0; i < num_func; i ++){
        vetor[i].codigo = 0;
        vetor[i].idade = 0;
        vetor[i].salario = 0;
        vetor[i].sexo = 'P';
    }
    for (i = 0; i < num_func; i ++){
        printf("\nCodigo:...:%d", vetor[i].codigo);
        printf("\nSalario:..:%.2f", vetor[i].salario);
        printf("\nIdade:....:%d", vetor[i].idade);
        printf("\nSexo:.....:%c\n", vetor[i].sexo);
    }
    for (i = 0; i < num_func; i ++){
        printf("insira os dados de um funcionario: \n");
        printf("Codigo: ");
        scanf("%d", &vetor[i].codigo);
        printf("Salario: ");
        scanf("%f", &vetor[i].salario);
        printf("Idade: ");
        scanf("%d", &vetor[i].idade);
        printf("Sexo [M, F, O (outro)]: ");
        scanf("%s", &vetor[i].sexo);
    }
    do{
        encontrado = false;
        printf("Insira o codigo do funcionario para buscar suas informacoes: ");
        scanf("%d", &busca);
        for (i = 0; i < num_func; i ++){
            if (busca == vetor[i].codigo){
                printf("\nCodigo:...:%d", vetor[i].codigo);
                printf("\nSalario:..:%.2f", vetor[i].salario);
                printf("\nIdade:....:%d", vetor[i].idade);
                printf("\nSexo:.....:%c\n", vetor[i].sexo);
                vet_func = i;
                encontrado = true;
            }
        }
        if (encontrado == false){
            printf("Codigo nao encontrado.\n");
        }
        else{
            printf("Deseja aumentar o salario desse funcionario em 10%%? [S/N]\n");
            scanf("%s", &aumento);
            if (aumento == 'S')
                vetor[i].salario = aumenta_salario(vetor[i].salario);
        }
        printf("Deseja realizar outra busca? [S/N]\n");
        scanf("%s", &resposta);
    }while(resposta == 'S');
    num_mulheres(vetor);
    printf("A media de idade na empresa eh %.2f anos\n", idade_media(vetor));
    printf("Mulheres na empresa:\n");
    idade_salario_mulheres(vetor);
}
int aumenta_salario(float salario)
{
    salario *= 1.1;
    return salario;
}
void num_mulheres(struct registro vetor[num_func])
{
    int i, mulheres;
    for(i = 0; i < num_func; i ++){
        if (vetor[i].sexo == 'F'){
            mulheres ++;
        }
    }
    printf("\nO numero de mulheres na empresa eh %d\n", mulheres);
}
float idade_media(struct registro vetor[num_func])
{
    int i, num;
    float soma = 0, media;
    for (i = 0; i < num_func; i ++){
        if (vetor[i].idade != 0){
            soma += vetor[i].idade;
            num ++;
        }
    }
    printf("Num = %d", num);
    media = soma / num;
    return media;
}
void idade_salario_mulheres(struct registro vetor[num_func])
{
    int i;
    for (i = 0; i < num_func; i++){
        if (vetor[i].sexo == 'F'){
            printf("\nCodigo: %d, Salario: R$%.2f\n");
        }
    }
}
