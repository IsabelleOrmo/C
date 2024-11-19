/*
Ler uma lista de inteiros de N posições. Escreva a seguir o valor e
a posição do maior e menor elementos lidos.
*/

#include <stdio.h>
#include <stdlib.h>

struct no
{
    int n;
    struct no *proximo;
};

struct no* inserir(struct no *lista, int n){
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    novo->n = n;
    novo->proximo = lista;
    return novo;
}

void maiorValor(struct no *lista) {
    struct no *atual = lista;
    int posMaior = 0, pos = 0;
    int numMaior = atual->n;

    while (atual != NULL) {
        if (atual->n > numMaior) {
            numMaior = atual->n;
            posMaior = pos;
        }
        pos++;
        atual = atual->proximo;
    }

    printf("\nMaior número da lista: %d\n", numMaior);
    printf("Posição do maior número: %d\n", posMaior);
}

void menorValor(struct no *lista) {
    struct no *atual = lista;
    int posMenor = 0, pos = 0;
    int numMenor = atual->n;

    while (atual != NULL) {
        if (atual->n < numMenor) {
            numMenor = atual->n;
            posMenor = pos;
        }
        pos++;
        atual = atual->proximo;
    }

    printf("\nMenor número da lista: %d\n", numMenor);
    printf("Posição do menor número: %d\n", posMenor);
}

void mostrarLista(struct no *lista){
    struct no *atual = lista;
    int cont = 0;
    printf("LISTA\n");
    printf("posicao   numero\n");
    while (atual!=NULL)
    {
        printf("%d     %d\n", cont, atual->n);
        atual = atual->proximo;
        cont++;
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

    mostrarLista(lista);
    menorValor(lista);
    maiorValor(lista);
    liberar(lista);
    return 0;
}
