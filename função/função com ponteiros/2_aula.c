/*Construa um programa em C que leia um número inteiro não
negativo e determine a soma dos seus divisores. A soma dever ser
efetuada através de uma função somadiv e o resultado
impresso no programa principal. O protótipo da função é:
void somadiv(int x, int*y);*/

#include <stdio.h>

void somadiv(int x, int*y){
    *y = 0;
    for (int i = 1; i <= x; i++)
    {
        if(x%i==0){
            *y= *y + i;
        }
    }
}

int validar(){
    int x;
    do
    {
      scanf("%d", &x);
      if(x<0){
        printf("Apenas números positivos!\n");
      }
    } while (x<0);
    return x;
}

int main (){

    int n, soma;
    printf("Numero inteiro positivo: ");
    n = validar();
    somadiv(n, &soma);
    printf("A soma dos divisores de %d eh %d", n, soma);
   return 0;
}