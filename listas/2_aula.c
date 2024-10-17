#include <stdio.h>
#include <stdlib.h>

struct No {
    int n;
    struct No *proximo;
};

struct No* inicializar() {
    return NULL;
}

struct No* inserir(struct No *lista, int n) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->n = n;
    novo->proximo = lista;
    return novo;
}

struct No* multiplicacao(int k, struct No *listaX) {
    struct No *listaMulti = inicializar();
    struct No *atual = listaX;
    int numMulti;
    while (atual != NULL) {
        struct No *multiplicado = (struct No*) malloc(sizeof(struct No));
        numMulti = atual->n*k;
        multiplicado->n = numMulti;
        multiplicado->proximo = listaMulti; 
        listaMulti = multiplicado;
        atual = atual->proximo;
    }

    return listaMulti;
}

void exibir(struct No *lista) {
    struct No *dado = lista;
    while (dado != NULL) {
        printf("%d -> ", dado->n);
        dado = dado->proximo;
    }
    printf("NULL\n");
}


int main() {
    int qtnd, k, valor;

    struct No *listaX = inicializar();
    struct No *listaMulti;

    printf("Quantos valores deseja inserir na lista? ");
    scanf("%d", &qtnd);
    printf("\nINSERINDO VALORES\n");
    for (int i = 0; i < qtnd; i++) {
        printf("Número: ");
        scanf("%d", &valor);
        listaX = inserir(listaX, valor);
    }
    printf("\nMultiplicar a lista por: ");
    scanf("%d", &k);

    listaMulti = multiplicacao(k, listaX);

    printf("\nEXIBINDO\n");
    printf("Lista: ");
    exibir(listaX);
    printf("Lista Multiplicada por %d: ", k);
    exibir(listaMulti);


    return 0;
}
