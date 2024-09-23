/*Construa um programa que seja constituído das seguintes
funções
 Ler um vetor de inteiros de 20 posíções
 Função que retorna a quantidade de números pares e a
quantidade de múltiplos de 5
 Função que retorna a média do vetor e quantos valores são
maiores que essa média*/

#include <stdio.h>
#define tam 5

void lerVetor(int vetor[tam]){
    printf("\nValores do vetor: \n");
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
}

int quantidades(int vetor[tam], int *par, int *multiplo){
    *par = 0;
    *multiplo = 0;
    
    for (int i = 0; i < tam; i++)
    {
        if(vetor[i]%2==0){
            *par = *par + 1;
        }
        if(vetor[i]%5==0){
            *multiplo = *multiplo + 1;
        }
    }
}

float mediaCalcula(int vetor[tam], float *media, int *maiorQue){
    int soma = 0;
    *maiorQue = 0;
    for (int i = 0; i < tam; i++)
    {
        soma += vetor[i];
    }

    *media = soma/tam;

    for (int i = 0; i < tam; i++)
    {
        if(vetor[i]>*media){
            *maiorQue = *maiorQue + 1;
        }
    }
}

int main (){

    int vetor[tam], par, multiplo, maiorQue;
    float media;

    lerVetor(vetor);
    quantidades(vetor, &par, &multiplo);
    mediaCalcula(vetor, &media, &maiorQue);
    
    printf("\n %d mumeros pares. \n %d multiplos de 5. \n %.2f eh a media. \n %d numeros sao maiores que a media", par, multiplo, media, maiorQue);

   return 0;
}