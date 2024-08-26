/*Fazer um programa que faz a leitura de um vetor X com N inteiros,
com tamanho máximo igual a 20 e N deverá ser lido. Multiplique
cada elemento do vetor por um inteiro K (K também deverá ser
lido). Imprimir o vetor lido, o valor da variável K e o vetor
multiplicado por K.
VETORES
*/

#include <stdio.h>
#include <stdbool.h>
int main()
{
   int n, k;
   bool valida = true;

   while(valida == true ) {
   printf("N elementos? ");
   scanf("%d", &n);
   if(n <= 20){
    valida = false;
   }
   }

    printf("Valores do vetor X: ");
    int x[n], kVetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }

    printf("Valor de K: ");
    scanf("%d", &k);

    for(int i = 0; i < n; i++){
        kVetor[i] = x[i]*k;
    }

    printf("O vetor ");
     for(int i = 0; i < n; i++){
        printf("%d ", x[i]);
    }
    printf("foi multiplicado por %d e passou a ser: \n", k);
         for(int i = 0; i < n; i++){
        printf("%d ", kVetor[i]);
    }

    return 0;
}