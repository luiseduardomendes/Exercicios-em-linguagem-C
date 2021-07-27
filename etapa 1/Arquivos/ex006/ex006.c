#include <stdio.h>
#include <stdlib.h>

FILE *arquivo, *arq_novo;

int main()
{
    float num = 1;
    int cont = 0;

    // opcional para preenchimento de arquivo, caso necessario
    /*arquivo = fopen("ex056.1.dat", "wb");
    scanf("%f", &num);
    while(num != 0){
        fwrite(&num, sizeof(float), 1, arquivo);
        scanf("%f", &num);
    }
    fclose(arquivo);*/

    arquivo = fopen("ex056.1.dat", "rb");
    arq_novo = fopen("ex056.2.dat", "wb");
    if ((arquivo == NULL) || (arq_novo == NULL)){
        printf("Falha ao abrir arquivo\n");
        exit(1);
    }

    while(1){
        fread(&num, sizeof(float), 1, arquivo);
        if (!feof(arquivo))
            cont++;
        else
            break;
    }

    fseek(arquivo,-1*sizeof(float), SEEK_END);

    for(int i = 0; i < cont; i ++){
        fread(&num, sizeof(float), 1, arquivo);
        printf("%.2f ", num);
        fwrite(&num, sizeof(float), 1, arq_novo);
        fseek(arquivo, -2*sizeof(float), SEEK_CUR);
    }

    fclose(arquivo);
    fclose(arq_novo);
    remove("ex056.1.dat");
    rename("ex056.2.dat", "ex056.1.dat");
    return 0;
}
