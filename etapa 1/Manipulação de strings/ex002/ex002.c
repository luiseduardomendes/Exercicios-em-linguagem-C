/* O programa a seguir apresenta uma resolucao para o seguinte exercicio:

exercício 10.3) Dado um texto, faça um programa que isole cada palavra deste
texto e verifique se é um palíndromo, conforme mostrado no Exercício 10.3, na
Seção 10.3. As palavras são separadas por caracteres de espaço em branco, ou
pelos símbolos “,”, “.”, “!”, “:” e “;”. A saída do programa deve ser cada uma 
das palavras identificadas, seguida por uma mensagemindicando se a palavra é ou 
não um palíndromo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    //Funcoes
    bool Palindromo(char mat[50][21], int i);
    void Organiza(char vet[101], char mat[50][21]);
    void Print(char mat[51][21]);
    //Arrays
    char vet[101] = {' '};
    char mat[50][21] = {' '};
    //Variaveis
    printf("escreva uma texto: \n");
    gets(vet);
    Organiza(vet, mat);
    Print(mat);


}
void Organiza(char vet[101], char mat[50][21])
{
    int i, j, k;

    for (j = 0; j < 101; j ++){
        if ( ( (vet[j] >= 'a') && (vet[j] <= 'z') ) || ( (vet[j] >= 'A') && (vet[j] <= 'Z') ) ){
            mat[i][k] = vet[j];
            k ++;
        }
        if(vet[j] == ' '){
            i ++;
            k = 0;
        }
        if(vet[j] == '\0'){
            break;
        }
    }
}
void Print(char mat[50][21])
{
    bool Palindromo(char mat[50][21], int i);
    int i, j;

    for (i = 0; i < 50; i ++){
        for (j = 0; j < 21; j ++){
            if (mat[i][j] != ' '){
                printf("%c", mat[i][j]);

            }
        }
        if ( ( (mat[i][0] >= 'a') && (mat[i][0] <= 'z') ) ||
            ( (mat[i][0] >= 'A') && (mat[i][0] <= 'Z') ) ){
            if (Palindromo(mat, i) == true)
                printf(" = eh palindromo");
            else
                printf(" = nao eh palindromo");

        printf("\n");
        }
    }
}
bool Palindromo(char mat[50][21], int i)
{
    int j, frente = 0, atras;
    bool resposta = true;

    for (j = 0; j < 21; j ++){
        if ((mat[i][j] == ' ') || (mat[i][j] == '\0')){
            atras = j - 1;
            break;
        }
    }
    while ((resposta = true) && (atras >= frente)){
        if (mat[i][frente] != mat[i][atras]){
            resposta = false;
            break;
        }
        else{
            frente ++;
            atras --;
        }
    }
    return(resposta);
}
