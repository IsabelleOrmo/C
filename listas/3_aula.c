/*
Fazer um programa que faz a leitura de uma lista X com N reais
(N deverá ser lido). Calcule o somatório de todos os elementos
da lista. Imprimir a lista lida e o valor do somatório.*/

#include <stdio.h>
#include <stdlib.h>

struct No{
    int n;
    struct No* proximo;
};

struct No* inserir(struct No *lista, int n){
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->n = n;
    novo->proximo = lista;
    return novo;
}

int somatorio(struct No *lista){
    struct No *atual = lista;
    int soma = 0;
    int numSoma;
    while (atual!=NULL)
    {
        numSoma = atual->n;
        soma = soma + numSoma;
        atual = atual->proximo;
    }
    
    return soma;
}

void mostrarLista(struct No *lista){
    struct No *atual = lista;
    while (atual!=NULL)
    {
        printf("%d \n", atual->n);
        atual = atual->proximo;
    }
}

void liberar(struct No *lista){
    struct No *atual = lista;
    while (atual!=NULL)
    {
       struct No *temp = atual;
       atual = atual->proximo;
       free(temp);
    } 
}

int main(){
    struct No* lista = NULL; 
    int qntd, n, soma;
    int cont = 0;
    printf("Quantos elementos serão inseridos?\n");
    scanf("%d", &qntd);
    while (cont<qntd)
    {
        printf("Elemento %d: ", cont+1);
        scanf("%d", &n);
        lista = inserir(lista, n);
        cont++;
    }

    printf("Lista: \n");
    mostrarLista(lista);
    soma = somatorio(lista);

    printf("A soma dos elementos é %d", soma);
    liberar(lista);
    return 0;
}