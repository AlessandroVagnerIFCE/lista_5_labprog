#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMO 100

//Recebe um vetor de inteiros e a quantidade de elementos
//Preenche o vetor com valores pseudo-aleatórios
void preencher_vetor(int*, int);

//Recebe um vetor de inteiros, a quantidade de elementos e o endereço do ponteiro para retorno
//Modifica o valor do ponteiro de retorno para que seja o endereço do menor elemento do vetor
void obter_menor_valor(int*, int, int**);

int main(int argc, char *argv[])
{

    if (argc != 2) {
        printf("Sintaxe do comando:\n %s tamanho_do_vetor\n", *argv);
        exit(1);
    }

    //Gerar vetor
    int *v = NULL;
    unsigned int qtd = abs(atoi(*(argv + 1))); //Evitar uma quantidade negativa

    v = (int*) malloc(qtd * sizeof(int));

    if (!v) {
        puts("Não há memória disponível");
        exit(1);
    }

    preencher_vetor(v, qtd);

    //Imprimir o endereço do menor valor
    int *menor_valor = NULL;
    obter_menor_valor(v, qtd, &menor_valor); //OBS: precisa usar o endereço do ponteiro no valor do retorno
    printf("Endereço do menor valor: %p\n", menor_valor);

    free(v);

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

void obter_menor_valor(int *v, int qtd, int **r)
{
    *r = v; //O ponteiro não pode ser alterado diretamente dentro dessa função, precisa usar o endereço dele

    for (unsigned int i = 1; i < qtd; i++) { //Nesse caso o loop começa em 1, já que por padrão menor = *v
        if (*(v + i) < **r) {
            *r = (v + i);
        }
    }
}