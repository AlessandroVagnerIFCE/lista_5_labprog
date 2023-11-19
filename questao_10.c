#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 7

//Recebe um vetor de inteiros e a quantidade de elementos
//Preenche o vetor com valores pseudo-aleatórios
void preencher_vetor(int*, int);

//Recebe uma matriz de inteiros, a quantidade de linhas e de colunas
//Imprime a matriz seguindo as linhas e as colunas
void imprimir_matriz(int*, int, int);

int main()
{
    srand(time(NULL));

    int x[TAM];
    int y[TAM];
    int m[TAM*TAM];

    //Gerar os vetores
    puts("Vetor X:");
    preencher_vetor(x, TAM);

    puts("\n");

    puts("Vetor Y:");
    preencher_vetor(y, TAM);

    puts("\n");

    //Preencher a matriz com 0 em todos os valores para evitar lixo de memória
    for (unsigned char i = 0; i < TAM*TAM; i++) {
        *(m + i) = 0;
    }

    //Processar os dados e preencher a matriz
    for (unsigned char i = 0; i < TAM; i++) {
        //*((m + j) + (i*col))
        *((m + *(x + i)) + (*(y + i) * TAM)) += 1;
    }

    //Imprimir a matriz
    imprimir_matriz(m, TAM, TAM);

    return 0;
}

void preencher_vetor(int *v, int qtd)
{
    for (unsigned int i = 0; i < qtd; i++) {
        *(v + i) = rand()%TAM;
        printf("%d; Endereço: %p\n", *(v + i), (v + i));
    }
}

void imprimir_matriz(int *m, int lin, int col)
{
    for (unsigned int i = 0; i < lin; i++) {
        for (unsigned int j = 0; j < col; j++) {
            printf("%02d ", *((m + j) + (i*col)));
        }
        printf("\n");
    }
}
