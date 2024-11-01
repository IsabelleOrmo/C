#define MAX 100
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct livro {
    char titulo[50];
    char autor[50];
    int num_p;
    int ano_pub;
    int id;
    int quant_disp;
    char nome_emp[10][50];
};


void cadastrar(struct livro *livrolist, int *posicao) {
    int aux = *posicao;
    printf("Titulo: ");
    scanf(" %[^\n]", livrolist[aux].titulo);
    printf("Autor: ");
    scanf(" %[^\n]", livrolist[aux].autor);
    printf("Numero de Paginas: ");
    scanf("%i", &livrolist[aux].num_p);
    printf("Ano de publicacao: ");
    scanf("%i", &livrolist[aux].ano_pub);
    printf("Codigo Unico(ID): ");
    scanf("%i", &livrolist[aux].id);
    printf("Quantidade disponivel(MAX 10): ");
    scanf("%i", &livrolist[aux].quant_disp);
    
    while (livrolist[aux].quant_disp > 10) {
        printf("Excede a quantidade maxima! Digite novamente (MAX 10): ");
        scanf("%i", &livrolist[aux].quant_disp);
    }

    (*posicao)++;
}


void maiusculas(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]); 
    }
}


void emprestar(struct livro *livrolist, int *posicao){
    int aux = *posicao, id;
    char pessoa[100];

    printf("\n ID do livro para emprestimo: ");
    scanf("%d", &id);
    bool encontrado = false;
    for (int i = 0; i < aux; i++) {
        if(livrolist[i].id==id){
            encontrado = true;
            if (livrolist[i].quant_disp !=0) {
                printf("Empréstimos: \nDigite 1 caso queira parar a inserção.\n");
                printf("Nome das pessoas que pegaram emprestado: \n");
                for  (int j = 10 - livrolist[i].quant_disp; j < 10; j++) {
                    printf("Pessoa: ");
                    scanf(" %[^\n]", pessoa);
                
                    if (strcmp(pessoa, "1") == 0) {
                        break;
                    } 

                    maiusculas(pessoa);

                    strcpy(livrolist[i].nome_emp[j], pessoa);
                    livrolist[i].quant_disp = livrolist[i].quant_disp - 1;
                }
            } else {
                printf("Não há exemplares disponiveis");
            }
        }
    }
    if (!encontrado) printf("Id não encontrado");
}


void exibir(struct livro *livrolist, int *posicao) {
    int aux = *posicao, escolha, id, existe = false;

    printf("\n1 - Listar todos os livros");
    printf("\n2 - Listar livro por ID");
    printf("\nEscolha: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        for (int i = 0; i < aux; i++) {
            printf("\nTitulo: %s\n", livrolist[i].titulo);
            printf("Autor: %s\n", livrolist[i].autor);
            printf("Numero de Paginas: %d\n", livrolist[i].num_p);
            printf("Ano de publicacao: %d\n", livrolist[i].ano_pub);
            printf("Codigo Unico(ID): %d\n", livrolist[i].id);
            printf("Quantidade disponivel(MAX 10): %d\n", livrolist[i].quant_disp);
            printf("Emprestado para: \n");
            for (int j = 0; j < 10 - livrolist[i].quant_disp; j++) {
                if (strcmp(livrolist[i].nome_emp[j], "") != 0) {
                    printf("%s\n", livrolist[i].nome_emp[j]);
                }
                
            }
            printf("\n");  
        }
    } else if (escolha == 2) {
        printf("\nID para busca: ");
        scanf("%d", &id);

        for (int i = 0; i < aux; i++) {
            if (livrolist[i].id == id) {
                printf("\nTitulo: %s\n", livrolist[i].titulo);
                printf("Autor: %s\n", livrolist[i].autor);
                printf("Numero de Paginas: %d\n", livrolist[i].num_p);
                printf("Ano de publicacao: %d\n", livrolist[i].ano_pub);
                printf("Codigo Unico(ID): %d\n", livrolist[i].id);
                printf("Quantidade disponivel(MAX 10): %d\n", livrolist[i].quant_disp);
                printf("Emprestado para: \n");
                for (int j = 0; j < 10 - livrolist[i].quant_disp; j++) {
                    if (strcmp(livrolist[i].nome_emp[j], "") != 0) {
                    printf("%s\n", livrolist[i].nome_emp[j]);
                    }
                }
                existe = true;  
                break;
            }
        }

        if (existe==false) {
            printf("Livro com ID %d não encontrado.\n", id);
        }
    } 
}


void excluir(struct livro *livrolist, int *posicao){
    int aux;
    printf("ID do livro que deseja excluir da base de dados:");
    scanf("%i",&aux);
    for(int x=0;x<*posicao;x++){
        if(aux==livrolist[x].id){
            for (int y = x; y < *posicao - 1; y++) {
                livrolist[y] = livrolist[y + 1];
            }
            (*posicao)--;
            printf("Livro excluido\n");
            return;
        }  
        printf("Livro nao encontrado\n");
    }
}

void devolucao (struct livro *livrolist, int *posicao){
    int id;
    char pessoa[100];
    printf("Digite o id do livro: ");
    scanf("%i",&id);
    for (int aux=0;aux<*posicao;aux++){
        if(livrolist[aux].id==id){
            printf("Nome da pessoa que fez a devolucao: ");
             scanf(" %[^\n]", pessoa);
             maiusculas(pessoa);\
             
             for (int aux2=0;aux<*posicao;aux2++){
                 if(strcmp(livrolist[aux].nome_emp[aux2], pessoa) == 0){
                     for (int aux3 = aux2; aux3 <*posicao - 1;aux3++){
                         strcpy(livrolist[aux].nome_emp[aux3], livrolist[aux].nome_emp[aux3 + 1]);

                     }
                     printf("Devolucao feita\n");
                     livrolist[aux].quant_disp = livrolist[aux].quant_disp + 1;
                     return;
                 }
             }
                printf("Pessoa nao encontrada\n");
                return ;
        }
    }
    printf("Id invalido, livro nao encontrado");
}

int main (){
    struct livro livrolist[MAX];
    int posicao=0,opc=-1;
    while(opc!=0){
        printf("\nMenu:\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Exibir livros\n");
        printf("3 - Emprestar livro\n");
        printf("4 - Devolucao de livro\n");
        printf("5 - Remover livro\n");
        scanf("%i",&opc);
        
        switch(opc){
            case 1:
                cadastrar(livrolist, &posicao);
                break;
            case 2:
                exibir(livrolist, &posicao);
                break;
            case 3:
                emprestar(livrolist, &posicao);
                break;
                
            case 4:
                devolucao(livrolist, &posicao);
                break;
                
            case 5:
                excluir(livrolist, &posicao);
                break;
        
        }
  }
  
  return 0;
}