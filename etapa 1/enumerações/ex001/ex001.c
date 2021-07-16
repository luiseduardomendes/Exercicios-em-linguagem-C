#include <stdio.h>
#include <stdlib.h>

int main ()
{
    enum nrs {UM = 1, DOIS, TRES, QUATRO, CINCO};
    enum nrs num, i;
    printf("Digite um valor de 1 a 5: \n");
    scanf("%d", &num);
    printf("%d\n", UM);
    for (i = UM; i <= CINCO; i++)
    {
        switch (i)
        {
            case UM : printf("O valor digitado por extenso eh um\n");
                break;
            case DOIS : printf("O valor digitado por extenso eh dois\n");
                break;
            case TRES : printf("O valor digitado por extenso eh tres\n");
                break;
            case QUATRO : printf("O valor digitado por extenso eh quatro\n");
                break;
            case CINCO : printf("O valor digitado por extenso eh cinco\n");
                break;
        }
    }
}
