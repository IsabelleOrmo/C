/*Faça uma função imprime os divisores do numero inteiro natural lido
*/

#include <stdio.h>

int validar(){
   int n, cont = 0;
   printf("Insira um numero natural inteiro: ");
   while (cont == 0)
   {
      scanf("%d", &n);
      if(n>=0){
         cont++;
      } else {
         printf("Numeros positivos por favor!\n");
      }
   }
   return n;
}

void divisores(int n){
   for (int i = 1; i < n+1; i++)
   {
      if(n%i==0){
         printf("%d eh divisor de %d\n", i, n);
      }
   }
   return;
}

int main (){

   int n;
   n = validar();
   divisores(n);

   return 0;
}