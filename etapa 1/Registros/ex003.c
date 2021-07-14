#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct reg{
    float x;
    float y;
};
struct reg leitura();

int main()
{
    struct reg ponto1, ponto2, ponto3;

    ponto1 = leitura();
    ponto2 = leitura();
    ponto3 = leitura();
    distancia(ponto1, ponto2);
    distancia(ponto2, ponto3);
    distancia(ponto1, ponto3);
    return 0;
}

struct reg leitura()
{
    struct reg lido;
    printf("Digite a coordenada x\n");
    scanf("%f", &lido.x);
    printf("Digite a coordenada y\n");
    scanf("%f", &lido.y);
    return lido;
}
float distancia(struct reg ponto1, struct reg ponto2 )
{
    int d = sqrt(sqr(ponto2.x - ponto1.x) + sqr(ponto2.y - ponto1.y));
    return d;
}
bool triangulo(float d1, float d2, float d3)
{
    bool resp = true;
    if ((d1 > d2 + d3) || (d2 > d1 + d3) || (d3 > d1 + d2)){
        resp = false
    }
    return resp;
}
