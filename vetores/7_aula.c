/*Ler um vetor A com 10 elementos inteiros correspondentes as
idades de um grupo de pessoas. Escreva um programa que
determine e escreva a idade média dos elementos lidos e
quantos elementos são menores que a média.
*/

#include <stdio.h>
int main (){

 int A[10], media = 0, soma = 0, cont = 0;

 //lendo os valores + verificação
 printf("Digite a idade das pessoas do grupo: \n");
    for(int i =0; i < 10; i++){        
        scanf("%d", &A[i]);
        if(A[i] < 0 || A[i] > 129){
            printf("Insira uma idade válida!\n");
            i--;
        }
    }

// idade media
for(int i = 0; i <10; i++){
    soma+= A[i];
}

media = soma/10;

for(int i = 0; i < 10; i++){
    if(A[i]<media){
        cont++;
    }
}

printf("A media das idade e %d e existem %d pessoas com idade abaixo da media", media, cont);

return 0;
}