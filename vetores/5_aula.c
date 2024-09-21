/*Ler um vetor de inteiros 10 posições. Escreva a seguir o valor e a
posição do maior e menor elementos lidos.*/
#include <stdio.h>
int main (){
    int vetor[10], menor, maior, pMenor = 0, pMaior = 0;
    printf("Insira 10 posições para o vetor: \n");
    for(int i=0; i < 10; i++){
        scanf("%d", &vetor[i]);
    }

    menor = vetor[0];
    maior = vetor[0];

    for (int i =0; i < 10; i++) {
        if(vetor[i] <= menor){
            menor = vetor[i];
            pMenor = i;
        }
        if (vetor[i] >= maior) {
            maior = vetor[i];
            pMaior = i;
        }
    }

    printf("Vetor[%d]: %d é o menor", pMenor, menor);
    printf("\nVetor[%d]: %d é o maior", pMaior, maior);
}