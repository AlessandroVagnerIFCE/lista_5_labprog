#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define QTD 10
#define MAXIMO 100

//Recebe um vetor de inteiros e a quantidade de elementos
//Preenche o vetor com valores pseudo-aleatórios
void preencher_vetor(int*, int);

//Recebe dois vetores e a quantidade de elementos
//Retorna o erro quadrático médio entre os dois vetores
float eqm(int*, int*, int);

int main()
{
    srand(time(NULL));

    int a[QTD];
    int b[QTD];

    puts("\n");
    preencher_vetor(a, QTD);
    puts("\n");
    preencher_vetor(b, QTD);
    puts("\n");

    float erro_quadratico_medio = eqm(a, b, QTD);
    printf("Erro quadrático médio: %.2f\n", erro_quadratico_medio);

    return 0;
}

void preencher_vetor(int *v, int qtd)
{
    for (unsigned int i = 0; i < qtd; i++) {
        *(v + i) = rand()%MAXIMO;
        printf("%d; Endereço: %p\n", *(v + i), (v + i));
    }
}

float eqm(int *x, int *y, int qtd)
{
    unsigned int s = 0;
    for (unsigned int i = 0; i < qtd; i++) {
        s += (int) pow((*(x + i) - *(y + i)), 2); //Somatório de (Xi - Yi)²
        //printf("%d\n", s);
    }

    return (float)s/qtd;
}