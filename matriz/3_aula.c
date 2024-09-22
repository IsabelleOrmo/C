/*Elabore um programa que leia uma matriz de reais 10x10 e
determine:
• A soma da linha 4.
• O menor elemento da coluna 5.
• O maior elemento da diagonal principal*/
#include<stdio.h>
#define T 5
int main () {

    float M[T][T], soma = 0, menor, maior;
    
    printf("Valores da matriz: \n");
    for(int i = 0; i < T; i++){
        for (int j = 0; j < T; j++)
        {
            scanf("%f", &M[i][j]);
        }
    }

    menor = M[0][4];
    maior = M[0][0];

    //soma linha 4
    for (int j = 0; j < T; j++)
        {
            soma = soma + M[4][j];
        }

    //menor elemento coluna 5
    for(int i = 0; i < T; i++){
        if(M[i][4] < menor){
            menor = M[i][4];
        }
    }

    //maior elemento diagonal principal
    for(int i = 0; i < T; i++){
        for (int j = 0; j < T; j++)
        {
           if(i==j){
            if(M[i][j]>= maior){
                maior = M[i][j];
            }
           }
        }
    }

    //printando
    printf("\nMatriz: \n");
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            printf(" %.2f ", M[i][j]);
        }
        printf("\n");
    }

    printf("\n Soma da linha 4: %.2f", soma);
    printf("\n O menor elemento da coluna 5: %.2f", menor);
    printf("\n Maior elemento da diagonal principal: %.2f", maior);


    return 0;

}