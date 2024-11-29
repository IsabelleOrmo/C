/*
Isabelle Ormo Crenonini
24007567
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // biblioteca para incluir a função toupper

// Estrutura para um contato
struct Contato {
    char nome[50];
    char celular[15];
    struct Contato* esquerda;
    struct Contato* direita;
};

//Função para deixar uma string em uppercase
void upperCase(char* str) {
    for (int i = 0; str[i]; i++) { // percorre todos os caracteres da string os deixando maiusculo
        str[i] = toupper(str[i]);
    }
}

// Prototipos das funções
struct Contato* inserir(struct Contato* raiz, struct Contato* novo);
struct Contato* buscar(struct Contato* raiz, const char* nome);
struct Contato* remover(struct Contato* raiz, const char* nome);
void listar(struct Contato* raiz);
void menu();
void LiberarNo(struct Contato *contato);
void Liberar(struct Contato *raiz);

int main() {
    struct Contato* raiz = NULL;
    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        getchar(); //limpar o buffer para evitar erros ao ler strings
        switch (opcao) {
        case 1: {
            // Adicionar contato
            char nome[50];
            struct Contato* novo = (struct Contato*)malloc(sizeof(struct Contato));
            printf("Nome: ");
            scanf(" %[^\n]", nome); //permitir espaços
            upperCase(nome);
            /*Utilizando toupper pois a comparação de strings é case sensitive,
            dessa forma evitamos o cadastro de dois contatos iguais*/
            strcpy(novo->nome, nome);
            printf("Celular: ");
            scanf(" %[^\n]", novo->celular);
            novo->esquerda = NULL;
            novo->direita = NULL;
            raiz = inserir(raiz, novo);
            break;
        }
        case 2: {
            // Buscar contato
            char nome[50];
            printf("Nome para buscar: ");
            scanf(" %[^\n]",  nome);
            upperCase(nome);
            struct Contato* encontrado = buscar(raiz, nome);
            if (encontrado) {
            printf("Contato encontrado: %s, Celular: %s\n", encontrado->nome, encontrado->celular);
            } else {
            printf("Contato não encontrado.\n");
            }
            break;
        }
        case 3: {
            // Remover contato
            char nome[50];
            printf("Nome para remover: ");
            scanf(" %[^\n]", nome);
            upperCase(nome);
            raiz = remover(raiz, nome);
            break;
        }
        case 4: {
            // Listar contatos
            printf("Contatos:\n");
            listar(raiz);
            break;
        }
        case 5:
            printf("Saindo...\n");
            break;
            default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    //Liberando memoria
    Liberar(raiz);

    return 0;
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Adicionar contato\n");
    printf("2. Buscar contato\n");
    printf("3. Remover contato\n");
    printf("4. Listar contatos\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

int compararNomes(char* nome1, char* nome2) {
    return strcmp(nome1, nome2);
    /*
    valor negativo: se nome1 é menor que nome2.
    zero se são iguais.
    valor positivo: se nome1 é maior que nome2.
    */
}

// Função para inserir um contato na árvore
struct Contato* inserir(struct Contato* raiz, struct Contato* novo) {
    // Se a raiz estiver vazia (arvore vazia) insere o contato na raiz
    if (raiz == NULL) {
        return novo;
    }

    int comparacao = compararNomes(novo->nome, raiz->nome);

    if (comparacao < 0) {
        raiz->esquerda = inserir(raiz->esquerda, novo);
    } else if (comparacao > 0) {
        raiz->direita = inserir(raiz->direita, novo);
    } else {
        printf("\nContato já existente.\n");
        free(novo); // Libera memória do contato duplicado
    }

    return raiz;
}

// Função para buscar um contato na árvore
struct Contato* buscar(struct Contato* raiz, const char* nome) {
    if (raiz == NULL) {
        return NULL; // Se não encontrou, retorna NULL
    }

    int comparacao = compararNomes((char*)nome, raiz->nome);

    if (comparacao == 0) {
        return raiz; // Retorna o contato encontrado
    } else if (comparacao < 0) {
        return buscar(raiz->esquerda, nome); // Busca no lado esquerdo
    } else {
        return buscar(raiz->direita, nome); // Busca no lado direito
    }
}

// Função para remover um contato da árvore
struct Contato* remover(struct Contato* raiz, const char* nome) {
    if (raiz == NULL) {
        printf("Nenhum contato adicionado\n");
        return NULL; // Corrigir retorno para NULL
    }

       int comparacao = compararNomes((char*)nome, raiz->nome);

    if (comparacao < 0) {
        // Busca no lado esquerdo
        raiz->esquerda = remover(raiz->esquerda, nome);
    } else if (comparacao > 0) {
        // Busca no lado direito
        raiz->direita = remover(raiz->direita, nome);
    } else {
        // Contato encontrado
        if (raiz->esquerda == NULL) {
            struct Contato* temp = raiz->direita;
            free(raiz);
            printf("\nContato removido.\n");
            return temp;
        } else if (raiz->direita == NULL) {
            struct Contato* temp = raiz->esquerda;
            free(raiz);
            printf("\nContato removido.\n");
            return temp;
        }

        // Nó com dois filhos: obter o menor nó da subárvore direita
        struct Contato* temp = raiz->direita;
        while (temp && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }

        // Copiar os dados do sucessor na ordem
        strcpy(raiz->nome, temp->nome);
        strcpy(raiz->celular, temp->celular);

        // Remover o sucessor na order
        raiz->direita = remover(raiz->direita, temp->nome);
    }

    return raiz;
}

// Função para listar todos os contatos em ordem alfabética
void listar(struct Contato* raiz) {
    if (raiz != NULL) {
        // Primeiro, imprime a subárvore esquerda
        listar(raiz->esquerda);

        // Imprime o contato no nó atual
        printf("\n----------------\n");
        printf("Nome: %s\nCelular: %s\n", raiz->nome, raiz->celular);
        printf("-----------------\n");

        // Depois, imprime a subárvore direita
        listar(raiz->direita);
    }
}

// Função para liberar a memória da árvore
void LiberarNo(struct Contato *contato) {
    if (contato != NULL) {
        LiberarNo(contato->esquerda);  // Libera a subárvore esquerda
        LiberarNo(contato->direita);   // Libera a subárvore direita
        free(contato);                 // Libera o nó atual
    }
}

void Liberar(struct Contato *raiz) {
    LiberarNo(raiz);  // Libera todos os nós da árvore
}
