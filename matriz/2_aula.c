/*Faça um algoritmo que leia uma matriz de inteiros 5x3 e
construa sua transposta. O programa deverá imprimir as
duas matrizes, a original e a transposta.*/

#include<stdio.h>
#define L 5
#define C 3
int main () {

    int M[L][C], T[C][L];
    printf("Valores da matriz: \n");
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &M[i][j]);
        }
        
    }

    //matriz transposta
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < L; j++)
        {
            T[i][j] = M[j][i];
        }
    }

    //printando
    printf("Matriz: \n");
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf(" %d ", M[i][j]);
        }
        printf("\n");
    }

    printf("\nTransposta: \n");
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < L; j++)
        {
            printf(" %d ", T[i][j]);
        }
        printf("\n");
    }

    
    return 0;

}