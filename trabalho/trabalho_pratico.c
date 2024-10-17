#define MAX 100
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    char pessoa[100]; 
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

    if (livrolist[aux].quant_disp !=0) {
        printf("Empréstimos: \nDigite 1 caso queira parar a inserção.\n");
        printf("Nome das pessoas que pegaram emprestado: \n");
        for (int aux2 = 0; aux2 < (livrolist[aux].quant_disp); aux2++) {
            printf("Pessoa %d: ", aux2 + 1);
            scanf(" %[^\n]", pessoa);
            
            if (strcmp(pessoa, "1") == 0) {
                break;
            }
            
            strcpy(livrolist[aux].nome_emp[aux2], pessoa);
        }
    }

    (*posicao)++;
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
                printf("%s\n", livrolist[i].nome_emp[j]);
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
                    printf("%s\n", livrolist[i].nome_emp[j]);
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


int main (){
    struct livro livrolist[MAX];
    int posicao=0,opc=-1;
    while(opc!=0){
        printf("\nMenu:\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Exibir livros\n");
        scanf("%i",&opc);
        
        switch(opc){
            case 1:
                cadastrar(livrolist, &posicao);
                break;
            case 2:
                exibir(livrolist, &posicao);
                break;
        }
  }
  
  return 0;
}