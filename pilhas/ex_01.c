/*
Enunciado: Sistema de Gerenciamento de Pilha de Documentos
Você deve desenvolver um programa que simule o gerenciamento de uma pilha de documentos em um sistema. O programa deve permitir que o usuário realize as seguintes operações:
Operações:
Adicionar Documento
O programa deve permitir que o usuário insira um novo documento na pilha. Cada documento terá um identificador (ID) e um nome.
Remover Documento
O programa deve permitir que o usuário remova o documento do topo da pilha. O ID e o nome do documento removido devem ser exibidos.
Exibir Documentos na Pilha
O programa deve exibir todos os documentos na pilha, começando pelo topo. Se a pilha estiver vazia, exiba uma mensagem apropriada.
Sair do Programa
O usuário deve poder sair do programa quando desejar.

Estrutura para representar um documento.
Estrutura para a pilha.
Funções Necessárias:
pushDocument: Para adicionar um documento na pilha.
popDocument: Para remover o documento no topo da pilha.
printStack: Para exibir os documentos na pilha.
freeStack: Para liberar a memória da pilha ao encerrar o programa.
Função main:

Implementar o menu interativo que permite ao usuário realizar as operações acima.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct documento{
    int cod;
    char tipo[50];
    char nome[150];
    struct documento* next;
};

struct pilha{
    struct documento* top;
};

int validarCodigo(struct pilha* p, int cod){
    struct documento* atual = p->top;
    if (atual!=NULL)
    {
       if(cod==atual->cod)
       {
            printf("Codigo ja cadastrado, tente novamente.\n");
            return 1;
       }
       atual = atual->next;
    }

    return 0; 
}

void pushDocument(struct pilha* p, int cod, char tipo[50], char nome[100]){
    struct documento* novo = (struct documento*)malloc(sizeof(struct documento));
    novo->cod = cod;
    strcpy(novo->tipo, tipo);
    strcpy(novo->nome, nome);

    novo->next = p->top;
    p->top = novo;
}

void printStack(struct pilha* p){
    struct documento* atual = p->top;
    if (atual == NULL)
    {
        printf("Nenhum documento para ser trabalhado.\n");
        return;
    }
    while (atual != NULL)
    {
        printf("Codigo: %d, Tipo: %s, Nome: %s\n", atual->cod, atual->tipo, atual->nome);
        atual = atual->next;
    }

}

void popDocument(struct pilha* p){
    if (p->top == NULL)
    {
        printf("Não há nenhum documento!\n");
        return;
    }
    
    struct documento* temp = p->top;

    p->top = p->top->next;
    free(temp);
}

void freeStack(struct pilha* p){
    struct documento* atual = p->top;
    while (atual!=NULL)
    {
        struct documento* temp = atual;
        atual = atual->next;
        free(temp);
    }

    p->top = NULL;
    
}

int main() {
    struct pilha* p = (struct pilha*)malloc(sizeof(struct pilha));
    p->top = NULL;
    
    int opcao,c;
    int cod, validar = 0;
    int flag = 0;
    char tipo[50], nome[150];

    do {
        opcao = 0;
        printf("\n1. Adicionar Documento\n");
        printf("2. Remover Documento\n");
        printf("3. Exibir Pilha de Documentos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while ((c = getchar()) != '\n' && c != EOF);  

        switch (opcao) {
            case 1:
            flag = 0;
            while (flag == 0)
            {
                    printf("Informe o código do documento: ");
                    scanf("%d", &cod);
                    getchar();  
                    validar = validarCodigo(p, cod);
                    if (validar!=1)
                    {
                        printf("Informe o tipo do documento: ");
                        fgets(tipo, sizeof(tipo), stdin);
                        tipo[strcspn(tipo, "\n")] = '\0'; 

                        printf("Informe o nome do documento: ");
                        fgets(nome, sizeof(nome), stdin);
                        nome[strcspn(nome, "\n")] = '\0'; 

                        pushDocument(p, cod, tipo, nome);
                        flag = 1;
                    }

                }
                break;
            case 2:
                popDocument(p);
                break;

            case 3:
                printStack(p);
                break;

            case 4:
                printf("Saindo do sistema...\n");
                freeStack(p);
                free(p);
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}