/*Fazer um programa que faz a leitura de dois vetores X e Y, ambos
com N reais (N deve ser lido tb), com tamanho máximo igual a 20.
Efetue a multiplicação dos respectivos pares de elementos de X
por Y, gerando um terceiro vetor Z. Imprima os vetores X, Y e Z.*/

#include<stdio.h>

int main () {

     int n;
    printf("Quantos elementos?");
    scanf("%d", &n);
    
    int  x[n], y[n], z[n];
    
    printf("Vetor x: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    
    printf("Vetor y: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &y[i]);
    }
    
    for(int i =0; i < n; i++){
        z[i]=x[i]*y[i];
    }
    
    printf("A multiplicação de x por y é: ");
    for(int i = 0; i < n; i++){
        printf("%d \n", z[i]);
    }
    
    return 0;



}

