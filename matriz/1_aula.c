/*Faça um algoritmo que leia uma matriz M 5x5 de númeors
reias. O programa deve determinar o maior número da
matriz e a sua posição (linha, coluna).*/


#include<stdio.h>
#define T 5
int main () {

    float m[T][T], maior;
    int coluna, linha;

    printf("Valores da matriz: \n");
    for(int i = 0; i<T; i++){
        for(int j = 0; j <T; j++){
            printf("Linha %d Coluna %d: ", i, j);
            scanf("%f", &m[i][j]);
        }
    }

    maior = m[0][0];

    for(int i = 0; i<T; i++){
        for(int j = 0; j <T; j++){
            if(m[i][j] >= maior){
                maior = m[i][j];
                coluna = j;
                linha = i;
            }
    }}
    
    for(int i = 0; i<T; i++){
        for(int j = 0; j <T; j++){
            printf("%.2f ", m[i][j]);
    }
        printf("\n");
    }

    printf("\n O maior valor da matriz é %.2f na posicao %d %d", maior, linha, coluna);

    return 0;

}