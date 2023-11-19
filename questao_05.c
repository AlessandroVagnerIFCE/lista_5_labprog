#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMO 100

//Recebe um vetor de inteiros e a quantidade de elementos
//Preenche o vetor com valores pseudo-aleatórios
void preencher_vetor(float*, int);


//Recebe um vetor de floats e a quantidade de elementos
//Retorna a soma de todos os elementos do vetor
float somar_float(float*, int);

int main(int argc, char *argv[])
{

    if (argc != 2) {
        printf("Sintaxe do comando:\n %s tamanho_do_vetor\n", *argv);
        exit(1);
    }

    //Gerar vetor
    float *v = NULL;
    unsigned int qtd = abs(atoi(*(argv + 1))); //Evitar uma quantidade negativa

    v = (float*) malloc(qtd * sizeof(float));

    if (!v) {
        puts("Não há memória disponível");
        exit(1);
    }

    preencher_vetor(v, qtd);

    puts("\n");
    float soma = somar_float(v, qtd);
    printf("Soma dos valores do vetor: %.2f\n", soma);

    free(v);

    return 0;
}

void preencher_vetor(float *v, int qtd)
{
    srand(time(NULL));
    for (unsigned int i = 0; i < qtd; i++) {
        *(v + i) = ((float)rand()/RAND_MAX) + rand()%MAXIMO;
        printf("%.2f; Endereço: %p\n", *(v + i), (v + i));
    }
}

float somar_float(float *v, int qtd)
{
    float s = 0;
    for (unsigned int i = 0; i < qtd; i++) {
        s += *(v + i);
    }
    
    return s;
}