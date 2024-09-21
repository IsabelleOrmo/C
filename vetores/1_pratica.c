/*Fazer um programa que faz a leitura de um vetor X com N
reais , com tamanho máximo igual a 20 e N deverá ser lido.
vetor.Calcula o somatório de todos os elementos do
Imprimir o vetor lido e o valor do somatório.
O somatório é dado por: S = S + X[i]; para i = 0, 1, 2, ..., N-1
*/


#include <stdio.h>
#include <stdbool.h>
int main (){

int n;
bool verifica = false; 
printf("Tamanho do vetor? \n");
while(verifica == false){
    scanf("%d", &n);
    if(n > 20 || n <= 0){
        printf("Insira um valor valido! \n Entre 1 e 20\n");
    } else {
        verifica = true; 
    }
}

float x[n], s = 0;
printf("Valores do vetor: \n");
for(int i = 0; i < n; i++){
    scanf("%f", &x[i]);
    s = s + x[i];
}

printf("Vetor lido: \n");
for(int i = 0; i < n; i++){
    printf("\n%.2f", x[i]);
}

printf("\nSomatorio: %.2f", s);

return 0;
}