#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>


#define MAX_PRODUTOS 100   //max de itens no estoque
#define MAX_VENDAS 100 //max de vendas registradas

//Obs.: As minhas partes terminam com o comentário "Joás" ao final do meu incremento.
//Feito por: Luna N., JOÁS.
typedef struct{
	unsigned short nota_da_avaliacao;
	unsigned char comentario[100];
} Avaliacao; //Joás


//representação dos produtos
typedef struct {
    int codigo, quantidade, tamanho;
    char descricao[50], cor[20], marca[30];
    float valor;
} Produto;

// representação da venda
typedef struct {
    int codigoProduto, quantidadeVendida;
    float valorTotal;
    char dataHora[30];
} Venda;

Venda vendas[MAX_VENDAS];
Produto estoque[MAX_PRODUTOS];

int total = 0, totalVendas = 0; //"total" se refere ao total do estoque.

// verificar se o código já existe
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
        p.descricao[strcspn(p.descricao, "\n")] = '\0'; // remover o \n

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
        printf("\n| Codigo: %d \n| Descricao: %s \n| Tamanho: %d \n| Cor: %s \n| Marca: %s \n| Quantidade: %d \n| Valor: %.2f\n",
               estoque[i].codigo,
               estoque[i].descricao,
               estoque[i].tamanho,
               estoque[i].cor,
               estoque[i].marca,
               estoque[i].quantidade,
               estoque[i].valor
			);
    }
}

// Função para buscar os produto pelo código
void buscarProduto() {
    int codigo;
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++) {
        if (estoque[i].codigo == codigo) {
            printf(
					"\n=== Produto Encontrado ===\n"
		        	"Codigo: %d\n", estoque[i].codigo
		            "Descricao: %s\n", estoque[i].descricao
		            "Tamanho: %d\n", estoque[i].tamanho
		            "Cor: %s\n", estoque[i].cor
		            "Marca: %s\n"estoque[i].marca
		            "Quantidade: %d\n"
		            "Valor: %.2f\n",
					estoque[i].quantidade, estoque[i].valor
				);
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

// Efetuar venda
void efetuarVenda() {
    if (total == 0) {
        printf("Não há produtos cadastrados.\n");
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
	
    setlocale(LC_ALL, "Portuguese");

    unsigned short opcao, opcaoitem;

    do{
        printf(
			"\n\nObs.:Não iserir nenhum caractere que não seja número."
			"\nO leitor lerá o primeiro caractere como resposta, mesmo sendo espaços em branco."
			"\n\nLOJA DE CALCADOS"
	        "\n\nEscolha uma opção:"
	        "\n\t1|Funcionário\n\t2|Item\n\t3|Efetuar venda\n\t4|Saída"
	        "\n\nOpção: "
		);
        scanf("%d", &opcao);
       
        switch(opcao){
            case 1:
                printf("\n\nFuncionalidade de funcionario ainda não implementada \n");
                break;
            case 2:
                do{
                    printf(
						"\n\nObs.:Não iserir nenhum caractere que não seja número."
						"O leitor lerá o primeiro caractere como resposta, mesmo sendo espaços em branco."
						"\n\n==== MENU ESTOQUE ===="
	                    "\n1 - Cadastrar Produto"
	                    "\n2 - Listar Produtos"
	                    "\n3 - Buscar Produto"
	                	"\n0 - Sair"
	                    "\n\nEscolha: "
					);
                    scanf("%d", &opcaoitem);

                    switch (opcaoitem) {
                        case 1:
                            cadastrarProduto();
                            break;
                        case 2:
                            listarProdutos();
                            break;
                        case 3:
                            buscarProduto();
                            break;
                        case 0:
                            break;
                        default:
                            printf("\n\nOpcao invalida!\n");
                            break;
                    }
                } while (opcaoitem != '0');
                break;
            case 3:
                efetuarVenda();
                break;
            case 4:
                break;
            default:
                printf("\n\nOpção inválida\n");
                break;
            }
		printf("\n\n\n=========================================================================================");
    } while(opcao != '4');

	unsigned short quer_avaliar;
	printf("\n\nGostaria de nos avaliar?(0:Não; 1:Sim)");
	scanf("%d", &quer_avaliar); getchar();

	//Feito por: Luna N., JOÁS.
	if(quer_avaliar){
		Avaliacao avaliando;
		printf("\n\n\n=================AVALIAÇÃO=================");
		do{
			printf("\n\nDe zero a dez({x e N | 0 <= x <= 10}), qual nota você atribui ao serviço? ");
			scanf("%d", avaliando.nota_da_avaliacao); getchar();
		}while(avaliando.nota_da_avaliacao > 10 || avaliando.nota_da_avaliacao < 0);		

		printf("\n\nInsere um comentário que justifique a nota: \n\n\t");
		fgets(avaliando.comentario, 100, stdin);

		avaliando.comentario[strcspn(avaliando.comentario, "\n")] = '\0';
	}
	
    printf("=======OPERAÇÃO FINALIZADA=======");// Joás

    system("pause"); // <- faz o programa esperar antes de fechar
    return 0;
}
