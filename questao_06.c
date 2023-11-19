#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD 10
#define MAXIMO 50

//Recebe um vetor de inteiros e a quantidade de elementos
//Preenche o vetor com valores pseudo-aleatórios
void preencher_vetor(int*, int);

//Recebe um vetor de inteiros e a quantidade de elementos
//Retorna a média aritmética dos valores
float media_artimetica(int*, int);

//Recebe um vetor de inteiros e a quantidade de elementos
//Retorna o valor que mais se repete no vetor
int moda(int*, int);

//Recebe um vetor de inteiros e a quantidade de elementos
//Modifica o vetor recebido e o ordena por bubble sort
void ordenar_bolha(int*, int);

//Recebe um vetor de inteiros e a quantidade de elementos
//Retorna a mediana dos valores
float mediana(int*, int);

int main()
{
    int v[QTD];
    int mod;
    float media, med;

    preencher_vetor(v, QTD);

    med = mediana(v, QTD);
    mod = moda(v, QTD); //OBS: caso nenhum valor se repita, a função considera o primeiro elemento como a moda
    media = media_artimetica(v, QTD);

    puts("\n");

    printf("Média artimética: %.2f\n", media);
    printf("Moda: %d\n", mod); //Nota: para facilitar testes, mudar a macro MAXIMO para um número menor
    printf("Mediana: %.2f\n", med);


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


float media_artimetica(int *v, int qtd)
{
    int s = 0;
    for (unsigned int i = 0; i < qtd; i++) {
        s += *(v + i);
    }

    return (float)s/qtd;
}

int moda(int *v, int qtd)
{
    //O primeiro elemento é o número em si, o segundo é a quantidade de repetições do mesmo
    int mais_ocorrencias[] = {*v, 0};
    int qtd_ocorrencias;
    
    //Percorrer os elementos
    for (unsigned int i = 0; i < qtd; i++) {
        qtd_ocorrencias = 0;
        
        //Contar repetições
        for (unsigned int k = 0; k < qtd; k++) {
            if (*(v + i) == *(v + k)) {
                qtd_ocorrencias++;
            }
        }

        //Atualizar o vetor contendo os dados do elemento mais repetido
        if (qtd_ocorrencias > *(mais_ocorrencias + 1)) {
            *mais_ocorrencias = *(v + i);
            *(mais_ocorrencias + 1) = qtd_ocorrencias;
        }
    }

    return *mais_ocorrencias;
}

void ordenar_bolha(int *v, int n)
{
    puts("\n");
    puts("Ordenado por bubble sort");
    for (unsigned int i = 0; i < n-1; i++) {
        for (unsigned int k = 0; k < n-1; k++) {
            if (*(v+k) > *(v+(k+1))) {
                *(v+k) = *(v+k) ^ *(v+(k+1));
                *(v+(k+1)) = *(v+k) ^ *(v+(k+1));
                *(v+k) = *(v+k) ^ *(v+(k+1));
            }
        }
    }

    //Só para facilitar a visualização na hora de testar
    for (unsigned int j = 0; j < n; j++) {
        printf("%d; Endereço: %p\n", *(v + j), (v + j));
    }
}


float mediana(int *v, int n) 
{
    ordenar_bolha(v, n);

    if (n%2) {
        return (float) *(v+((n-1)/2));
    } else {
        return (float) (*(v+(n/2)) + *(v+((n/2)-1))) / 2;
    }
}