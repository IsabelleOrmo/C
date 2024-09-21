/*Elaborar um programa que leia um vetor de no máximo 15
elementos inteiros. O programa deverá imprimir o vetor e
informar quantos números são maiores que 30*/

#include <stdio.h>
int main (){

int vetor[15], valor = 0, cont30 = 0, cont = 0;

printf("Insira ate 15 valores no vetor quando quiser parar digite -1\n");
while(cont < 15){
    scanf("%d", &valor);
    if(valor == -1){
        break;
    } 
    if (valor < 0) {
        printf("Apenas numeros positivos \n");
    }
    else {
        vetor[cont] = valor;
        cont++;
        if(valor > 30){
            cont30++;
        }
    }
}

printf("Vetor digitado: \n");
for(int i = 0; i < cont; i ++){
    printf("\n%d", vetor[i]);
}

printf("\nDesse vetor, %d sao numeros maiores que 30", cont30);

return 0;
}