/*Faça um programa que lê um número não determinado de valores
inteiros e positivos, e para cada valor lido:
a) calcula e escreve o seu fatorial;
b) calcula e escreve os seus divisores;
c) Você deverá construir o programa, elaborando as seguintes
funções:
Modularização
 Ler_num(int &x) – função que lê um valor inteiro
 int Fatorial(int N) – função que retorna o fatorial de um
número inteiro N
 void divisores(int valor) – função que imprime os
divisores de um número
*/

#include <stdio.h>

void ler_num(int *x){
    printf("Insira um número positivo: ");
    do
    {
        scanf("%d", x);
        if(*x<0){
            printf("Apenas valores positivos!");
        }
    } while (*x<0);
}

int fatorial(int n){
   int fatorial = 1;
   for (int i = 2; i <= n; i++) {  
        fatorial *= i;
    }

   return fatorial;
}

void divisores(int valor){
    for (int i = 1; i <= valor; i++)
    {
        if(valor%i==0){
            printf("%d eh divisor de %d\n", i, valor);
        }
    }
}

int main (){

    int x = 1;
    printf("Digite 0 para encerrar a execução. \n");
    while (x!=0)
    {
      ler_num(&x);
      int fat = fatorial(x);
      printf("O fatorial de %d eh %d\n", x, fat);
      divisores(x);
    }
    
   return 0;
}