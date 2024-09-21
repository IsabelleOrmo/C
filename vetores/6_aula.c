/*Fazer um programa em C para ler um vetor de inteiros positivos
de 15 posições. Imprimir a quantidade de números pares e a
quantidade de múltiplos de 5*/

#include <stdio.h>
int main (){
    int vetor[15], par = 0, m5 = 0;
    printf("Insira as 15 posições: \n");
    //inserindo valores no vetor
    for (int i =0; i < 10; i++){
        scanf("%d", &vetor[i]);
    }

    //lendo a quantidade de numeros pares e multiplos de 5
    for(int i = 0; i <10; i++){
        if(vetor[i]%2==0){
            par++;
        }
        if(vetor[i]%5==0){
            m5++;
        }
    }

    printf("Existem %d numeros pares e %d multiplos de 5", par, m5);
    
return 0;
}