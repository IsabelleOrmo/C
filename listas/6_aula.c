/*
Fazer um programa em C para ler uma lista de inteiros positivos
de 15 posições. Imprimir a quantidade de números pares e a
quantidade de múltiplos de 5
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 15

struct no{
    int n;
    struct no *proximo;
};

struct no* inserir(struct no *lista, int n){
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    novo->n = n;
    novo->proximo = lista;
    return novo;
}

int pares(struct no *lista){
    struct no *atual = lista;
    int cont = 0;
    while (atual!=NULL)
    {
       if (atual->n%2==0)
       {
            cont++;
       }

       atual = atual->proximo;
    }
    
    return cont;
}

int multiplos(struct no *lista){
    struct no *atual = lista;
    int cont = 0;
    while (atual!=NULL)
    {
        if (atual->n%5==0)
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
       atual = atual->proximo;
       free(temp);
    } 
}

int main(){
    struct no *lista = NULL;
    int n, cont = 0, par = 0, multi = 0;
    while (cont<MAX)
    {
        printf("Elemento %d: ", cont + 1);
        scanf("%d", &n);
        lista = inserir(lista, n);
        cont++;
    }
    
    par = pares(lista);
    multi = multiplos(lista);

    printf("\nQuantidade de numeros pares: %d", par);
    printf("\nQuantidade de numeros multiplos de 5: %d", multi);

    liberar(lista);

    return 0;
}