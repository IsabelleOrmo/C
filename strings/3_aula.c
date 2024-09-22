/*Faça um programa que lê uma string de 5 caracteres e inverte
esta string. No final o programa deverá imprimir a string
original e a invertida*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main () {

    char s1[6], s2[6];
    int tam = 0;

    printf("String: ");
    fgets(s1, 6, stdin);

    tam = strlen(s1);

    for (int i = 0; i < tam; i++)
    {
        s2[i]=s1[tam-1-i];
    }
    s2[tam] = '\0';
    printf("A string %s ao contrario eh %s", s1, s2);

    return 0;

}