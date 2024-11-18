/*Elabore um programa que utilize recursividade
que recebe um vetor de inteiros e retorna o
mesmo vetor em ordem crescente.
*/
#include <stdio.h>


int fatorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fatorial(n - 1);
}

int main() {
    int num;
    int resultado;
    printf("Num: ");
    scanf("%d", &num);
    resultado = fatorial(num);
    printf("%d",resultado);
    return 0;
}
