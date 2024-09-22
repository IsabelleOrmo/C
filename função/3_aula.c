/*Elabore um programa que contenha uma função que dado um numero
inteiro natural ela retorne o seu fatorial.
Faça uma função que válide o inpout do numero
*/

#include <stdio.h>

float fatorial(int n){
   float fatorial = 1;
   for (int i = 2; i <= n; i++) {  
        fatorial *= i;
    }

   return fatorial;
}

int validar(){
   int n;
   printf("Insira um número inteiro natural: ");
   do
   {
      scanf("%d", &n);
      if(n<0){
         printf("Apenas números positivos e inteiros!\n");
      }
   } while (n<0);
   return n;
}

int main (){

   int n;
   float fat;
   n = validar();
   fat = fatorial(n);

   printf("O fatorial de %d é %.2f", n, fat);

   return 0;
}