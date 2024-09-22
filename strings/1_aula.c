/*Elabore um programa que leia uma um caractere e uma string
de no máximo 20 caracteres. O programa deverá determinar
o número de vezes que esse caractere aparece na string*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main () {

    char x, palavra[20];
    int cont = 0, tam = 0;

    printf("Caracter: ");
    scanf("%c", &x);

    getchar(); 

    printf("Palavra: ");
    fgets(palavra, 20, stdin);

    tam = strlen(palavra);

    for(int i = 0; i < tam; i++){
        if(palavra[i]==x){
            cont++;
        }
    }

    printf("O caracter %c aparaece na palavra %s %d vezes", x, palavra, cont);

    return 0;

}