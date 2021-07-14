#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct reg{
    float x;
    float y;
};
struct reg leitura();
float distancia(struct reg ponto1, struct reg ponto2);
bool triangulo(float d1, float d2, float d3);

int main()
{
    struct reg ponto1, ponto2, ponto3;
    float d1, d2, d3;

    ponto1 = leitura();
    ponto2 = leitura();
    ponto3 = leitura();
    d1 = distancia(ponto1, ponto2);
    d2 = distancia(ponto2, ponto3);
    d3 = distancia(ponto1, ponto3);
    if (triangulo(d1, d2, d3)){
        printf("Eh possivel formar um triangulo a partir dos dados inseridos\n");
        printf("Os lados do triangulo sao %.2f %.2f %.2f", d1, d2, d3);
    }
    else{
        printf("Nao eh possivel formar um triangulo a partir dos dados inseridos\n");
    }
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
    float d;
    d = sqrt(pow((ponto2.x - ponto1.x), 2) + pow(ponto2.y - ponto1.y, 2));
    return d;
}
bool triangulo(float d1, float d2, float d3)
{
    bool resp = true;
    if ((d1 > d2 + d3) || (d2 > d1 + d3) || (d3 > d1 + d2)){
        resp = false;
    }
    return resp;
}
