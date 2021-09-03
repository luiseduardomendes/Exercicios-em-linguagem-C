
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>
#define TAMANHO 21

int main()
{
    setlocale(LC_ALL, "");
    struct posicao {
        int x, y;
    }pos, obj;
    int passos;
    int i, j, objetivo = 1;
    char direcao;
    char nome;

    srand(time(NULL));

    obj.x = ((float)rand() / RAND_MAX) * (TAMANHO-1);
    obj.y = ((float)rand() / RAND_MAX) * (TAMANHO-1);

    pos.x = 10;
    pos.y = 10;

    printf("Insira a letra para seu nome: ");
    scanf("%c", &nome);
    system("cls");

    do {
        for (i = TAMANHO; i > 0; i --) {
            for (j = 0; j < TAMANHO; j ++) {
                if (pos.x == obj.x && pos.y == obj.y){
                    obj.x = ((float)rand() / RAND_MAX) * (TAMANHO);
                    obj.y = ((float)rand() / RAND_MAX) * (TAMANHO);
                    objetivo ++;
                }
                else if (i == pos.y && j == pos.x) {
                    printf("%c ", nome);
                }
                else if (i == obj.y && j == obj.x){
                    printf("%d ", objetivo);
                }
                else printf("- ");
            }
            printf("\n");
        }
        fflush(stdin);
        scanf(" %c", &direcao);
        passos ++;
        direcao = toupper(direcao);
        if(direcao == 'A' || direcao == 'S' || direcao == 'D' || direcao == 'W') {
            switch (direcao) {
                case 'A' : pos.x --;
                break;
                case 'D' : pos.x ++;
                break;
                case 'S' : pos.y --;
                break;
                case 'W' : pos.y ++;
                break;
            }
        }
        system("cls");
    } while (pos.y <= 21 && pos.x <= 21 && pos.y >= 0 && pos.x >= 0 && objetivo < 10);

    printf("Você concluiu o desafio usando %d!", passos);
    return 0;
}
