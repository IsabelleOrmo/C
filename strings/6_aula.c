/*Elabore um programa que leia uma string de no máximo 10
caracteres. O programa deverá imprimir a string sem suas
vogais*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main () {

    char string10[11], semvogais[11];
    int tam, j = 0;

    printf("String: ");
    fgets(string10, 11, stdin);
    tam = strlen(string10);
    for (int i = 0; i < tam; i++)
    {
        if (string10[i] != 'a' && string10[i] != 'A' && string10[i] != 'e' && string10[i] != 'E' && string10[i] != 'i' && string10[i] != 'I' && string10[i] != 'o' && string10[i] != 'O' && string10[i] != 'u' && string10[i] != 'U')
        { 
            semvogais[j]=string10[i];
            j++;
        }
    }

    semvogais[j] = '\0';
    
    printf("A palavra %s sem vogais eh %s", string10, semvogais);

    return 0;

}