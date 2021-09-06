#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>

int main () {
    setlocale(LC_CTYPE, "");
    struct posicao {
        int x, y;
    }pos, obj, map1, map2;
    int passos;
    int i, j, objetivo = 1;
    char direcao;
    char nome;

    pos.x = 10;
    pos.y = 10;

    map1.x = pos.x - 10;
    map1.y = pos.y - 10;

    map2.x = pos.x + 10;
    map2.y = pos.y + 10;

    do {
        for (i = map2.y; i > map1.y; i --) {
            for (j = map2.x; j < map1.x; j ++) {
                
                if (i == pos.y && j == pos.x) {
                    printf("%c ", nome);
                }
                else if (i == obj.y && j == obj.x){
                    printf("%d ", objetivo);
                }
                else printf("- ");
            }
            printf("\n");
        }

        
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
        map1.x = pos.x - 10;
        map1.y = pos.y - 10;

        map2.x = pos.x + 10;
        map2.y = pos.y + 10;

        system("clear");
    } while (pos.y <= 21 && pos.x <= 21 && pos.y >= 0 && pos.x >= 0 && objetivo < 10);

    printf("Você concluiu o desafio usando %d!", passos);
    return 0;
}