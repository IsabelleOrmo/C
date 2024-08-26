/*Fazer um programa que faz a leitura de um vetor X, com N
inteiros, com tamanho máximo igual a 20 e N deverá ser lido.
Gere um segundo vetor com os valores do vetor X em ordem
inversa. Imprimir o vetor X e vetor com a ordem inversa*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
   int n;
   bool valida = true;

   while(valida == true ) {
   printf("N elementos? ");
   scanf("%d", &n);
   if(n <= 20){
    valida = false;
   }
   }

   
   int x[n], xInverso[n];
   printf("Numeros do vetor X: \n");
   for(int i = 0; i < n; i++){
       scanf("%d",&x[i]);
   }

   for(int i = 0; i <n; i++){
       xInverso[((n-1)-i)] = x[i];
   }

   printf("\n O inverso do vetor ");
   for(int i=0; i < n; i++){
      printf("%d ", x[i]);
   }

   printf("é ");
   for(int i=0; i < n; i++){
      printf("%d ", xInverso[i]);
   }
  

    return 0; 

}