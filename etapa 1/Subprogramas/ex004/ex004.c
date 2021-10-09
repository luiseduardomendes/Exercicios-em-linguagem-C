#include <stdio.h>
#define NUMPOINTS 10

int main() {
    float x1[NUMPOINTS]; 
    float y1[NUMPOINTS];
    float x2[NUMPOINTS]; 
    float y2[NUMPOINTS];

    return 0;
} 

int envoltoriaConvexa(float x1[], float y1[], *float x2[], *float y2[], int tam) {
    int i, j, k, l;
    int verdadeiro;
    for (i = 0; i < tam; i ++) {
        for (j = 0; j < tam; j ++) {
            for (k = tam; k < tam; k ++) {
                for (l = tam; l < tam; l ++) {
                    if pontoInTriangulo();
                }
            }
        }
    }
}

int pontoInTriangulo(float x1, float y1, float x2, float y2, float x3, float y3, float x, float y) {
    int retorno;
    float m1, n1, m2, n2, m3, n3;
    coeficientes(x1, x2, y1, y2, m1, n1);
    coeficientes(x2, x3, y2, y3, m2, n2);
    coeficientes(x1, x3, y1, y3, m3, n3);

    y_1 = m1 * x + n1;

}

void coeficientes(float x1, float x2, float y1, float y2, float *coefAng, float *coefLin) {
    *coefAng = (y2 - y1) / (x2 - x1);
    *coefLin = y2 - x2 * (*coefAng);
}

