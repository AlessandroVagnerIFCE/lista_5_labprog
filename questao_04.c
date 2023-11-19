#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD 10
#define MAXIMO 100

//Recebe um vetor de inteiros e a quantidade de elementos
//Preenche o vetor com valores pseudo-aleatórios
void preencher_vetor(int*, int);

//Recebe um vetor de inteiros, a quantidade de elementos e um vetor de float para retorno
//Faz a normalização dos dados
void normalizar(int*, int, float*);

int main()
{
    int x[QTD];
    float y[QTD]; //Tipo float devido às operações de normalização
    preencher_vetor(x, QTD);
    puts("\n");
    normalizar(x, QTD, y);

    return 0;
}

void preencher_vetor(int *v, int qtd)
{
    srand(time(NULL));
    for (unsigned int i = 0; i < qtd; i++) {
        *(v + i) = rand()%MAXIMO;
        printf("%d; Endereço: %p\n", *(v + i), (v + i));
    }
}

void normalizar(int *v, int qtd, float *r)
{
    int menor = *v;
    int maior = *v;

    //Obter o menor e o maior elemento
    for (unsigned int k = 1; k < qtd; k++) {
        if (*(v + k) < menor) {
            menor = *(v + k);
        } else if (*(v + k) > maior) {
            maior = *(v + k);
        }
    }

    //Normalizar os dados
    for (unsigned int i = 0; i < qtd; i++) {
        *(r + i) = (float)(*(v + i) - menor)/(maior - menor);
        printf("%.2f; Endereço: %p\n", *(r + i), (r + i));
    }
}