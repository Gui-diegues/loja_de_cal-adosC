#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUTOS 100   //max de itens no estoque 

//representação dos produtos
typedef struct {
    int codigo;
    char descricao[50];
    int tamanho;
    char cor[20];
    char marca[30];
    int quantidade;
    float valor;
} Produto;

Produto estoque[MAX_PRODUTOS];
int total = 0;


// Cadastrando os produtos
void cadastrarProduto() {
    if (total < MAX_PRODUTOS) {
        Produto p;

        printf("Codigo: ");
        scanf("%d", &p.codigo);
        getchar(); // limpar o buffer

        printf("Descricao: ");
        fgets(p.descricao, 50, stdin);
        p.descricao[strcspn(p.descricao, "\n")] = 0; // remover o \n

        printf("Tamanho: ");
        scanf("%d", &p.tamanho);
        getchar();

        printf("Cor: ");
        fgets(p.cor, 20, stdin);
        p.cor[strcspn(p.cor, "\n")] = 0;

        printf("Marca: ");
        fgets(p.marca, 30, stdin);
        p.marca[strcspn(p.marca, "\n")] = 0;

        printf("Quantidade: ");
        scanf("%d", &p.quantidade);

        printf("Valor: ");
        scanf("%f", &p.valor);

        estoque[total] = p;
        total++;
        printf("Produto cadastrado com sucesso!\n");
    } else {
        printf("Estoque cheio!\n");
    }
}


// Função para listar os produtos
void listarProdutos() {
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("Codigo: %d | Descricao: %s | Tamanho: %d | Cor: %s | Marca: %s | Quantidade: %d | Valor: %.2f\n",
               estoque[i].codigo,
               estoque[i].descricao,
               estoque[i].tamanho,
               estoque[i].cor,
               estoque[i].marca,
               estoque[i].quantidade,
               estoque[i].valor);
    }
}

// Função para buscar os produto pelo código
void buscarProduto() {
    int codigo;
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++) {
        if (estoque[i].codigo == codigo) {
            printf("\n=== Produto Encontrado ===\n");
            printf("Codigo: %d\n", estoque[i].codigo);
            printf("Descricao: %s\n", estoque[i].descricao);
            printf("Tamanho: %d\n", estoque[i].tamanho);
            printf("Cor: %s\n", estoque[i].cor);
            printf("Marca: %s\n", estoque[i].marca);
            printf("Quantidade: %d\n", estoque[i].quantidade);
            printf("Valor: %.2f\n", estoque[i].valor);
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

int main(){
    int opcao, opcaoitem;
    
    do{ 
    printf("LOJA DE CALCADOS\n\n");
    printf("Escolha uma opcao:\n");
    printf(" 1.Funcionario\n 2.Item\n 3.Efetuar venda\n 4.Exit\n");
    scanf("%d", &opcao);
  }while (opcao < 1 || opcao > 4);

   if (opcao == 2){ do {
        printf("\n==== MENU ESTOQUE ====\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Buscar Produto\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcaoitem);

        switch (opcaoitem) {
            case 1: cadastrarProduto(); break;
            case 2: listarProdutos(); break;
            case 3: buscarProduto(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcaoitem != 0);
}
    
    system("pause"); // <- faz o programa esperar antes de fechar
    return 0;
    }

