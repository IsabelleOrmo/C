/*Elabore um programa que leia um nome completo de até
100 caracteres e imprima as iniciais deste nome. Exemplo:
João Carlos Nascimento da Silva, será impresso JCNDS.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main () {

    char nome[100], iniciais[100];
    int tam = 0, j = 0;

    printf("Nome: ");
    fgets(nome, 100, stdin);
    tam = strlen(nome);

    for (int i = 0; i < tam - 1; i++)
    {
        if(isupper(nome[i]) > 0){
            iniciais[j]=nome[i];
            j++;
        }
    }

    iniciais[j] = '\0';

    printf("\n As iniciais do nome %s sao %s", nome, iniciais);

    return 0;

}