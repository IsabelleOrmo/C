/*Fazer um programa que faz a leitura de um vetor X com N reais ,
com tamanho máximo igual a 20 e N deverá ser lido. Calcule o
somatório de todos os elementos do vetor. Imprimir o vetor lido
e o valor do somatório.*/

#include <stdbool.h>
#include <stdio.h>

int main()
{
   int n, soma = 0;
   bool valida = true;

   while(valida == true ) {
   printf("N elementos? ");
   scanf("%d", &n);
   if(n <= 20){
    valida = false;
   }}

    int x[n];
    printf("Vetor x: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }

    for(int i = 0; i < n; i++){
        soma = soma + x[i];
    }

    printf("A soma do vetor lido é %d e o vetor lido foi: \n", soma);
    for(int i = 0; i < n; i++){
        printf("%d ", x[i]);
    }

      return 0;
}