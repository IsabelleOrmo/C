/*Elabore um programa que contenha duas funções:
• Uma função que lê um número real e o retorna.
• E uma função que a partir do número real lido retorna a
parte fracionária do mesmo*/

#include <stdio.h>

float obterNumero(){
   float n;
   printf("Digite um numero real: ");
   scanf("%f", &n);
   return n;
}

float fracionario(float n){
   return n - (int)n;
}

int main (){

   float n, frac;
   n = obterNumero();
   frac = fracionario(n);
   printf("A parte fracionaria do numero %f eh %f", n, frac);
   
   return 0;
}