#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Recebe uma matriz de inteiros, a quantidade de linhas e de colunas, o valor máximo e o valor mínimo
//Preenche a matriz com valores pseudo-aleatórios
void preencher_matriz(int*, int, int, int, int);

//Recebe uma matriz de inteiros, a quantidade de linhas e de colunas
//Imprime a matriz seguindo as linhas e as colunas
void imprimir_matriz(int*, int, int);

//Recebe uma matriz de inteiros, a quantidade de linhas e de colunas
//Retorna a paridade do somatório da diagonal principal
unsigned char paridade_diagonal(int*, int, int);

int main()
{
    srand(time(NULL));

    unsigned int lin, col;
    int min, max;
    int *m = NULL;

    unsigned char paridade;

    puts("Insira a quantidade de linhas:");
    scanf("%u", &lin);
    puts("Insira a quantidade de colunas:");
    scanf("%u", &col);

    puts("Insira o valor máximo:");
    scanf("%d", &max);
    puts("Insira o valor mínimo:");
    scanf("%d", &min);

    //Gerar matriz
    m = (int*) malloc(lin*col*sizeof(int));

    if (!m) {
        puts("Não há memória disponível");
        exit(1);
    }

    preencher_matriz(m, lin, col, max, min);
    
    puts("\n");
    imprimir_matriz(m, lin, col);
    
    puts("\n");
    paridade = paridade_diagonal(m, lin, col);
    printf("O somatório da diagonal principal é %s\n", paridade ? "ímpar" : "par");

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

unsigned char paridade_diagonal(int *m, int lin, int col)
{
    int s = 0;
    for (unsigned int i = 0; i < lin; i++) {
        for (unsigned int j = 0; j < col; j++) {
            if (i == j) {
                s += *((m + j) + (i*col));
            }
        }
    }

    //Retorna 1 se for ímpar, 0 se for par;
    unsigned char paridade = (unsigned char) s%2;
    return paridade;
}