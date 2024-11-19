/*
Fazer um programa que faz a leitura de uma lista X, com N
inteiros (N deverá ser lido). Gere uma segunda lista com os
valores de X em ordem inversa. Imprimir X e a lista com a
ordem inversa.
*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int n;
    struct no* proximo;
};

struct no* inserir(struct no* lista, int n){
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    novo->n= n;
    novo->proximo = lista;
    return novo;
}

struct no* inverso(struct no* lista){
    struct no *listaInversa  = NULL;
    struct no *atual = lista; 
   
   while (atual!=NULL)
   {
        listaInversa = inserir(listaInversa, atual->n);
        atual = atual->proximo;
   }
   
    return listaInversa;
}

void mostrarLista(struct no *lista){
    struct no *atual = lista;

    while (atual!=NULL)
    {
        printf("%d \n", atual->n);
        atual = atual->proximo;
    }
    
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
    struct no *listaInversa = NULL;
    int qntd, n;
    int cont = 0;
    printf("Quantidade de elementos: ");
    scanf("\n%d", &qntd);
    while (cont<qntd)
    {
        printf("\nElemento %d: ", cont+1);
        scanf("%d", &n);
        lista = inserir(lista, n);
        cont++;
    }

    listaInversa = inverso(lista);
    printf("\nLista incial: \n");
    mostrarLista(lista);
    printf("\nLista inversa: \n");
    mostrarLista(listaInversa);
    liberar(lista);
    return 0;
}