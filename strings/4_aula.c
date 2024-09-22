/*Faça um programa que leia o nome e sobrenome de uma
pessoa. O programa deve escrever o nome e o sobrenome numa
única string. Deverá ser impresso, a nova string, o tamanho dela
a primeira e a última letra da string.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main () {

    char nome[45], sobrenome[45], fullName[150], primeira, ultima;
    int tam = 0;
    printf("Nome: ");
    fgets(nome, 45, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("Sobrenome: ");
    fgets(sobrenome, 45, stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';

    strcpy(fullName, nome);
    strcat(fullName, " ");
    strcat(fullName, sobrenome);


    tam = strlen(fullName);
    primeira = fullName[0];
    ultima = fullName[tam - 1];

    printf("\n NOME COMPLETO: %s \n Tamanho da string: %d \n Primeira letra: %c \n Ultima letra: %c", fullName, tam, primeira, ultima);
    


    return 0;

}