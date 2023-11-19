#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Recebe uma matriz de inteiros, a quantidade de linhas e de colunas, o valor máximo e o valor mínimo
//Preenche a matriz com valores pseudo-aleatórios
void preencher_matriz(int*, int, int, int, int);

//Recebe uma matriz de inteiros, a quantidade de linhas e de colunas
//Imprime a matriz seguindo as linhas e as colunas
void imprimir_matriz(int*, int, int);

//Recebe uma matriz de inteiros, a quantidade de linhas e de colunas, e o valor limiar
//Binariza os elementos da matriz, sendo 1 se maior que o limiar ou 0 caso contrário;
void binarizar(int*, int, int, int);

int main()
{
    srand(time(NULL));

    unsigned int lin, col;
    int min, max, t;
    int *m = NULL;

    puts("Insira a quantidade de linhas:");
    scanf("%u", &lin);
    puts("Insira a quantidade de colunas:");
    scanf("%u", &col);

    puts("Insira o valor máximo:");
    scanf("%d", &max);
    puts("Insira o valor mínimo:");
    scanf("%d", &min);
    puts("Insira o valor limiar:");
    scanf("%d", &t);

    //Gerar matriz
    m = (int*) malloc(lin*col*sizeof(int));

    if (!m) {
        puts("Não há memória disponível");
        exit(1);
    }

    preencher_matriz(m, lin, col, max, min);
    
    puts("\n");
    imprimir_matriz(m, lin, col);
    
    //Binarizar
    puts("\n");
    binarizar(m, lin, col, t);
    imprimir_matriz(m, lin, col);

    free(m);

    return 0;
}

void preencher_matriz(int *m, int lin, int col, int max, int min)
{
    for (unsigned int i = 0; i < lin*col; i++) {
        *(m + i) = (rand()%max) + min;
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

void binarizar(int *m, int lin, int col, int t)
{
    for (unsigned int i = 0; i < lin*col; i++) {
        if (*(m + i) > t) {
            *(m + i) = 1;
        } else {
            *(m + i) = 0;
        }
    }
}