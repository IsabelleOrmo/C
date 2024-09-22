/*Faça um programa em C que lê uma string de no máximo 10
caracteres e no final imprime quantas letras ‘a’ tem essa string.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main () {

    char palavra[11];
    int cont =0;

    printf("Qual a palavra? ");
    fgets(palavra, 11, stdin);

    int tam = strlen(palavra);

    for(int i = 0; i<tam; i++){
        if(palavra[i]=='a' || palavra[i]=='A'){
            cont++;
        }
    }

    printf("\n Na palavra %s o caractere A aparece %d vezes.", palavra, cont);

    return 0;

}