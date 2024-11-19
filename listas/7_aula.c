/*
Ler uma lista A com 10 elementos inteiros correspondentes às
idades de um grupo de pessoas. Escreva um programa que
determine e escreva a idade média dos elementos lidos e
quantos elementos são menores que a média.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct no
{
    int n;
    struct no *proximo;
};

struct no* inserir(struct no *lista, int idade){
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    novo->n = idade;
    novo->proximo = lista;
    return novo;
}

float media(struct no *lista){
    struct no *atual = lista;
    float cont = 0, soma = 0, media = 0;
    while (atual!=NULL)
    {
        soma = soma + atual->n;
        cont++;
        atual = atual->proximo;
    }

    media = (soma/cont);

    return media;
}

int menorQueMedia(struct no *lista, float media){
    struct no *atual = lista;
    int cont = 0;
    while (atual!=NULL)
    {
        if (atual->n<media)
        {
            cont++;
        }
        
        atual = atual->proximo;
    }
    return cont;
}

void liberar(struct no *lista){
    struct no *atual = lista;
    while (atual!=NULL)
    {
        struct no *temp = atual;
        atual =  atual->proximo;
        free(temp);
    }
    
}

int main(){
    struct no *lista = NULL;
    int cont = 0, idade;
    float med = 0;
    while (cont<MAX)
    {
        printf("\nIdade: ");
        scanf("%d", &idade);
        lista = inserir(lista, idade);
        cont++;
    }

    med = media(lista);
    printf("\nMédia das idades: %.2f", med);
    printf("\n%d pessoas tem idade abaixo da media", menorQueMedia(lista, med));
    liberar(lista);
    return 0;
}
