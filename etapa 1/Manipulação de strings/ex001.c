/* O programa a seguir apresenta uma resolucao para o seguinte exercicio:

exercício 10.2) Um texto é composto de palavras tendo, cada uma, 10 ou menos
caracteres. Escreva um programa que leia um texto de até 100 palavras e depois
as imprima em ordem alfabética */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 100

int main()
{
    //Funcoes
    void Permuta(char mat[51][20], int i);
    void Organiza(char mat[51][20], char vet[101]);
    void Print(char mat[51][20]);
    //Arrays
    char mat[51][20] = {' '};
    char vet[101] = {' '};
    //Inicio
    printf("Escreva uma frase ");
    gets(vet);
    Organiza(mat, vet);
    Print(mat);
    system("pause");
}
void Organiza(char mat[51][20], char vet[101])
{
    //Funcoes
    void Permuta(char mat[51][20], int i);
    //Variaveis
    bool troca = true;
    int i, j, k = 0;
    //Inicio
    for (j = 0; j < max; j ++){
        if ( ( (vet[j] >= 'a') && (vet[j] <= 'z') ) || ( (vet[j] >= 'A') && (vet[j] <= 'Z') ) ){
            mat[i][k] = vet[j];
            k ++;
        }
        if (vet[j] == ' '){
            i ++;
            k = 0;
        }
        if (vet[j] == '\0')
            break;
    }
    while (troca == true){
        troca = false;
        for (i = 0; i < 50; i ++){
            if ((mat[i][0] > mat[i + 1][0]) && (mat[i + 1][0] != ' ')){
                Permuta(mat, i);
                troca = true;
            }
        }
    }
}
void Permuta(char mat[51][20], int i)
{
    //Arrays e variaveis
    char aux[20];
    int j;
    //Inicio
    for (j = 0; j < 20; j ++){
        aux[j] = mat[i][j];
        mat[i][j] = mat[i + 1][j];
        mat[i + 1][j] = aux[j];
    }
}
void Print(char mat[51][20])
{
    //Variaveis
    int i, j;
    //Inicio
    printf("\nPalavras em ordem alfabetica: \n");
    for (i = 0; i < 50; i ++){
        for (j = 0; j < 20; j ++){
            if (mat[i][j] != 0){
                printf("%c", mat[i][j]);
            }
        }
        if (mat[i][j] != 0){
            printf("\n");
        }
    }
    printf("\n");
}
