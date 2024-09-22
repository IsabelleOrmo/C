/*Construir um programa que faz a leitura de uma matriz
quadrada de reais de tamanho N por N (máximo 20 x 20).
Somar todos os elementos da diagonal principal.
Imprimir a matriz lida e o valor da soma obtido.*/

#include <stdio.h>
#include <stdbool.h>

int main() {
   int n, soma = 0;
   bool valida = true;

   while(valida == true ) {
   printf("N elementos? ");
   scanf("%d", &n);
   if(n <= 20){
    valida = false;
   }}

    int m[n][n];
    printf("Insira os valores da matriz: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &m[i][j]);
        }
    }

    printf("Matriz: \n");
    for (int i = 0; i < n; i++) {
        printf("\n\t\n");
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
    }}

     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
                if(j==i){
                    soma = soma + m[i][j];
    }}}

    printf("\n A soma da diagonal da matris é %d ", soma);
    return 0;
}
