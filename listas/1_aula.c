/*Fazer um programa que faz a leitura de duas listas X e Y, ambas com
N reais (N deve ser lido tb). Efetue a multiplicação dos respectivos
pares de elementos de X por Y, gerando uma terceira lista Z.
Imprima as listas X, Y e Z.*/

#include <stdio.h>
#include <stdlib.h>

struct no {
    int n;
    struct no * proximo;
};

struct no* inicializar() 
{
    return NULL;
}


struct no * inserirLista(struct no *lista, int n){
    struct no *entrada = (struct no*) malloc(sizeof(struct no));
    entrada->n = n;
    entrada->proximo = lista;
    return entrada;
}


struct no* multiplicacao(struct no *listaX, struct no *listaY){
    int nX, nY;
    struct no *listaZ = NULL;
    
    struct no *atualX = listaX;
    struct no *atualY = listaY;

    while(atualX != NULL && atualY != NULL){
            nX = atualX->n;
            nY = atualY->n;

            struct no *novo = (struct no*) malloc(sizeof(struct no)); 
            novo->n = nX*nY;
            novo->proximo = NULL;
            if(listaZ == NULL) listaZ = novo;
            else
            {
                novo->proximo = listaZ;
                listaZ = novo;
            }
            atualX = atualX->proximo;
            atualY = atualY->proximo;
    }
    return listaZ;
}

//printar 
void exibir(struct no *lista){
    struct no *atual = lista;

    while(atual != NULL){
        printf("%d -> ", atual->n);
        atual = atual->proximo;
    }
    printf("NULL\n");
}


int main (){
    int qntd, cont = 0, valor;

    struct no *listaX = inicializar();
    struct no *listaY = inicializar();
    

    printf("Quantos valores deseja inserir? ");
    scanf("%d", &qntd);
    printf("\nInserindo na lista X\n");
    while(cont < qntd){
        printf("Valor: ");
        scanf("%d", &valor);
        listaX = inserirLista(listaX, valor);
        cont++;
    }
    printf("\nInserindo na lista Y\n");
    cont = 0;
    while(cont < qntd){
        printf("Valor: ");
        scanf("%d", &valor);
        listaY = inserirLista(listaY, valor);
        cont++;
    }
    struct no *listaZ = multiplicacao(listaX, listaY);
    printf("\n EXIBINDO VALORES\n");
    printf("LISTA X: ");
    exibir(listaX);
    printf("LISTA Y: ");
    exibir(listaY);
    printf("LISTA Z: ");
    exibir(listaZ);

    return 0;

}