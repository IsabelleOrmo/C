/*
Você deve desenvolver um programa que simule um sistema de atendimento ao cliente em uma fila. O sistema
deve permitir que os usuários realizem as seguintes operações:
1. Adicionar Cliente: O programa deve permitir que o usuário insira um novo cliente na fila. Cada cliente terá
um identificador (ID) e um nome.
2. Atender Cliente: O programa deve permitir que o usuário atenda o cliente que está na frente da fila. Ao
atender um cliente, seu ID e nome devem ser exibidos e removido da lista.
3. Exibir Fila: O programa deve mostrar a lista de clientes na fila, na ordem de chegada.
4. Sair do Programa: O usuário deve poder sair do programa quando desejar.
Requisitos:
 Estruturas: Use uma lista encadeada para implementar a fila.
 Validação: O programa deve verificar se a fila está vazia antes de atender um cliente e exibir uma
mensagem apropriada.
 Interface: Utilize um menu interativo para que o usuário possa escolher as operações.
 Gerenciamento de Memória: Certifique-se de liberar a memória alocada para os clientes atendidos.

Estrutura Sugerida
1. Definição das Estruturas:
o Estrutura para representar um cliente.
o Estrutura para a fila.
2. Funções Necessárias:
o insertClient: para adicionar um cliente à fila.
o attendClient: para atender o cliente na frente da fila (e remove-lo).
o printLista: para exibir os clientes na fila.
o freeLista: para liberar a memória da fila.
3. Função main:
o Implementar um menu interativo que permite ao usuário realizar as operações.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
    int id;
    char nome[100];
    struct no* next;
};

struct fila{
    struct no* first;
    struct no* last;
};

int validarId(struct fila* f, int id){
    struct no* atual = f->first;
    while (atual!=NULL)
    {
        int idAtual = atual->id;
        if (idAtual==id)
        {
            printf("ID já cadastrado.\n");
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}

void insertClient(struct fila* f){
    char nome[100];
    int id, validar = 1;
    while (validar==1)
    {
        printf("ID do cliente: ");
        scanf("%d", &id);
        getchar();
        validar = validarId(f, id);
    }

    printf("\nNome do cliente: ");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    struct no* novo = (struct no*)malloc(sizeof(struct no));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->next = NULL;
    
    if (f->last==NULL)
    {
        f-> first = novo;
    } else {
        f-> last -> next = novo;
    }

    f-> last = novo;
    
}

void attendClient(struct fila* f){
    if(f->first==NULL){
        printf("Nenhum cliente para ser atendido.\n");
        return;
    }

    struct no* temp = f->first;
    printf("Atendido: %d. %s\n", temp->id, temp->nome);
    f->first = f->first->next;
    if (f->first==NULL)
    {
        f -> last = NULL;
    }
    
    free(temp);
}

void printLista(struct fila* f){
    struct no* atual = f->first;
    if (atual==NULL)
    {
        printf("Nenhum cliente para ser atendido.\n");
        return;
    }

    while (atual!=NULL)
    {
        printf("%d. %s\n", atual->id, atual->nome);
        atual = atual->next;
    }
    
}

void freeLista(struct fila* f){
    struct no* atual = f->first;
    while (atual!=NULL)
    {
        struct no* temp = atual;
        atual = temp->next;
        free(temp);
    }

    f->first = NULL;
    f->last = NULL;

}

int main(){
    struct fila* f = (struct fila*)malloc(sizeof(struct fila));
    f->first = NULL;
    f->last = NULL;
    int opcao = 0;
        while (opcao != 4) {
        printf("\n1. Adicionar Cliente\n");
        printf("2. Atender Cliente\n");
        printf("3. Exibir Fila\n");
        printf("4. Sair do sistema\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                insertClient(f);
                break;
            case 2:
                attendClient(f);
                break;
            case 3:
                printLista(f);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                freeLista(f);
                free(f);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}