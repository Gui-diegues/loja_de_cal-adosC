#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRODUTOS 100 
#define MAX_VENDAS 100 

//representacao dos produtos
typedef struct {
    int codigo;
    char descricao[50];
    int tamanho;
    char cor[20];
    char marca[30];
    int quantidade;
    float valor;
} Produto;

// representacao da venda
typedef struct {
    int codigoProduto;
    int quantidadeVendida;
    float valorTotal;
    char dataHora[30];
} Venda;

Produto estoque[MAX_PRODUTOS];
Venda vendas[MAX_VENDAS];
int total = 0;
int totalVendas = 0;

// verificar se o codigo ja� existe
int codigoExistente(int codigo) {
    for (int i = 0; i < total; i++) {
        if (estoque[i].codigo == codigo) {
            return 1;
        }
    }
    return 0;
}

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


// listar os produtos
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

// buscar os produto pelo codigo
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

// Efetuar venda
void efetuarVenda() {
    if (total == 0) {
        printf("Nao ha produtos cadastrados!\n");
        return;
    }

    int codigo, qtd;
    printf("Digite o codigo do produto para venda: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Produto: %s | Quantidade disponivel: %d\n", estoque[i].descricao, estoque[i].quantidade);
            printf("Quantidade a vender: ");
            scanf("%d", &qtd);

            if (qtd > estoque[i].quantidade) {
                printf("Estoque insuficiente!\n");
                return;
            }

            // atualizar estoque
            estoque[i].quantidade -= qtd;

            // calcula valor
            float totalVenda = estoque[i].valor * qtd;

            // salva venda
            if (totalVendas < MAX_VENDAS) {
                time_t agora = time(NULL);
                strftime(vendas[totalVendas].dataHora, 30, "%d/%m/%Y %H:%M:%S", localtime(&agora));
                vendas[totalVendas].codigoProduto = codigo;
                vendas[totalVendas].quantidadeVendida = qtd;
                vendas[totalVendas].valorTotal = totalVenda;
                totalVendas++;
            }

            // nota da venda
            printf("\n===== NOTA DE VENDA =====\n");
            printf("Produto: %s\n", estoque[i].descricao);
            printf("Marca: %s\n", estoque[i].marca);
            printf("Quantidade: %d\n", qtd);
            printf("Valor unitario: %.2f\n", estoque[i].valor);
            printf("Total: %.2f\n", totalVenda);
            printf("=========================\n");

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
        
    switch(opcao){
         case 1 :
        	printf("Funcionalidade de funcionario ainda não implementada \n");
            break;
        case 2 :
            do { 
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
    break;
        case 3 :
		efetuarVenda();
		break;
	case 4 :
		printf("Saindo do programa...\n");
		break;
    default :
    	printf("Opção inválida\n");
    }
    
} while(opcao != 4);
    
    system("pause"); // <- faz o programa esperar antes de fechar
    return 0;
    }


