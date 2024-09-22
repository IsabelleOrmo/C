/* Fazer um programa em C para ler um vetor de inteiros positivos
de 15 posições, no máximo. O programa deverá ordenar o vetor
na forma crescente.
*/

#include <stdio.h>
int main (){

int vetor[15], cont = 0, valor;
printf("Insira ate 15 numeros no vetor \n Digite -1 para encerrar \n");
while(cont<15){
    scanf("%d", &valor);
    if(valor == -1 ){
        break;
    }
    if(valor < 0){
        printf("Insira um numero positivo por favor\n");
    } else {
        vetor[cont] = valor;
        cont++;
    }
}

for(int i = 0; i < cont - 1; i++){
    for(int j = i+1; j < cont; j++){
        if(vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
    }
}

for(int i = 0; i < cont; i++){
    printf("\n%d", vetor[i]);
}

return 0;
}