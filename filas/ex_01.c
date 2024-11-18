/*
Bem-vindo ao Sistema de Atendimento!
1. Adicionar Cliente
2. Atender Cliente
3. Exibir Fila
4. Sair
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    char nome[50];
    struct No* next;
};

struct fila{
    struct No* first;
    struct No* last;
};

void cadastrar(struct fila* f, char* nome) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    strcpy(novo->nome, nome);
    novo->next = NULL;

    if (f->last == NULL) {
        f->first = novo;
    } else {
        f->last->next = novo;
    }

    f->last = novo;
}

void atendido(struct fila* f) {
    if (f->first == NULL) {
        printf("Nenhum cliente para ser atendido!\nBom trabalho :)\n");
        return;
    }

    struct No* temp = f->first;
    printf("Atendido: %s", temp->nome); 
    f->first = f->first->next;

    if (f->first == NULL) {
        f->last = NULL;
    }

    free(temp);
}

void exibir(struct fila* f){
    struct No* atual = f->first;
    int cont = 1;
    if (atual==NULL)
    {
        printf("Nenhum cliente para ser atendido!\nBom trabalho :)\n");
        return;
    }
    while (atual!=NULL)
    {
        printf("\n%d. %s", cont, atual->nome);
        cont++;
        atual = atual->next;
    }
    
    printf("\nFim\n");
}

void liberarFila(struct fila* f){
    struct No* atual = f->first;
    while (atual!=NULL)
    {
        struct No* temp = atual;
        atual = temp->next;
        free(temp);
    }

    f->first = NULL;
    f->last = NULL;
    
}

int main(){
    struct fila* f =(struct fila*)malloc(sizeof(struct fila));
    f->first = NULL;
    f->last = NULL;
    int cont = 0;
    char nome[50];
    while (cont!=4)
    {
        printf("\n1. Adicionar Cliente\n");
        printf("2. Atender Cliente\n");
        printf("3. Exibir Fila\n");
        printf("4. Sair\n");
        scanf("%d", &cont);
        getchar();
        if (cont==1)
        {
            printf("Nome do cliente: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n'
            cadastrar(f, nome);
        } if (cont==2)
        {
            atendido(f);
        } if (cont==3)
        {
           exibir(f);
        }
    }

    liberarFila(f);
    free(f);
    
    return 0;
}
