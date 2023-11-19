#include <stdio.h>
#include <stdlib.h>

#define MAX_OP 1

//Recebe dois inteiros
//Imprime a soma dos valores
void somar(int, int);

//Recebe dois inteiros
//Imprime a multiplicação dos valores
void multiplicar(int, int);

int main(int argc, char *argv[])
{
    void (*op[])(int, int) = {somar, multiplicar};

    if (argc != 4) {
        printf("Sintaxe do comando:\n %s numero_x numero_y cod_operação\n", *argv);
        exit(1);
    }

    int x = atoi(*(argv + 1));
    int y = atoi(*(argv + 2));
    int cod = atoi(*(argv + 3));

    if ((cod < 0) || (cod > MAX_OP)) {
        puts("Operação inválida");
        exit(2);
    }

    (*op[cod])(x, y);

    return 0;
}

void somar(int n, int m)
{
    printf("%d + %d = %d\n", n, m, n + m);
}

void multiplicar(int n, int m)
{
    printf("%d * %d = %d\n", n, m, n * m);
}