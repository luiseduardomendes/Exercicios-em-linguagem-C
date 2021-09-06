#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>

int main () {
    setlocale(LC_CTYPE, "");

    struct posicao {
        int x, y;
    }pos, map1, map2;

    int i, j;
    char direcao;

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
                    printf("o ");
                }
                else printf("- ");
            }
            printf("\n");
        }

        
        scanf(" %c", &direcao);
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
    } while (direcao == 'c');

    return 0;
}