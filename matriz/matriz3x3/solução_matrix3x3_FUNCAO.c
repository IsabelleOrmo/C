#include <stdio.h>
#include <math.h>

void getDeterminante(float M[3][3], float *det){
    *det = (((M[0][0]*M[1][1]*M[2][2]) + (M[0][1]*M[1][2]*M[2][0]) + (M[0][2]*M[1][0]*M[2][1])) - (M[0][0]*M[1][2]*M[2][1]) - (M[0][1]*M[1][0]*M[2][2]) - (M[0][2]*M[1][1]*M[2][0]));
}

void getAdj(float M[3][3], float ADJ[3][3]){
    ADJ[0][0] = ((M[1][1]*M[2][2]) - (M[1][2]*M[2][1]));
    ADJ[0][1] = ((M[0][2]*M[2][1]) - (M[0][1]*M[2][2]));
    ADJ[0][2] = ((M[0][1]*M[1][2]) - (M[0][2]*M[1][1]));
    ADJ[1][0] = ((M[1][2]*M[2][0]) - (M[1][0]*M[2][2]));
    ADJ[1][1] = ((M[0][0]*M[2][2]) - (M[0][2]*M[2][0]));
    ADJ[1][2] = ((M[0][2]*M[1][0]) - (M[0][0]*M[1][2]));
    ADJ[2][0] = ((M[1][0]*M[2][1]) - (M[1][1]*M[2][0]));
    ADJ[2][1] = ((M[0][1]*M[2][0]) - (M[0][0]*M[2][1]));
    ADJ[2][2] = ((M[0][0]*M[1][1]) - (M[0][1]*M[1][0]));
}

void Multiply(float M[3][3], float I[3], float S[3]){
       for(int i = 0; i < 3; i++){
        S[i] = 0;
        for(int j = 0; j < 3; j ++){
            S[i] += M[i][j] * I[j];
        }
    }
}

void getInv(float M[3][3], float Inv[3][3]){
    float det, ADJ[3][3];
    getDeterminante(M, &det);
    getAdj(M, ADJ);
    float valor = 1/det;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j ++){
            ADJ[i][j] *= valor;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j ++){
            Inv[i][j] = ADJ[i][j];
        }
    }
    
}

void getSol(float M[3][3], float I[3], float S[3]){
    float Inv[3][3];
    getInv(M, Inv);
    Multiply(Inv, I, S);
}

int main()
{
    float M[3][3];
    float I[3];
    float S[3];
    
    //recebendo os valores da matriz
    printf("Insira os valores da matriz 3x3: \n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j ++){
            scanf("%f", &M[i][j]);
        }
    }
    
    //recebendo o vetor igualdade
    printf("Insira os valores do vetor igualdade: \n");
    for(int i = 0; i < 3; i++){
        scanf("%f", &I[i]);
    }
    
    getSol(M, I, S);
   
    
    //printando a solução
    printf("Os valores de x, y e z são: \n");
    for(int i = 0; i < 3; i++){
        printf("%2.f ", S[i]);
    }


return 0;
}