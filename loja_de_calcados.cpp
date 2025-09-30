#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define LISTA_FUNCIONARIO 100000
#define MAX_PRODUTOS 100 
#define MAX_VENDAS 100 


//Estrutura dos dados dos funcionarios
typedef struct{
	int matricula;
	char nome [50];
	char endereco [30];
	int telefone;
	int dia;
	int mes;
	int ano;
	int salario;
	char experiencia [200];
	
} funcionario;

funcionario lista [LISTA_FUNCIONARIO];
int listas = 0; // !! Incializar com 0 !!

void cadastrarfuncionario() {
	funcionario f;
	
	
	printf("Matrácula: ");
	scanf("%d", &f.matricula);
	getchar();
	
	printf("Nome: ");
	fgets(f.nome, 50, stdin);
	f.nome[strcspn(f.nome, "\n")] = 0;
	
	printf("Endereço: ");
	fgets(f.endereco, 30, stdin);
	f.endereco[strcspn(f.endereco, "\n")] = 0;
	
	printf("Telefone: ");
	scanf("%d", &f.telefone);
	
	printf("Data de nascimento:\n");
	
	printf("Dia: ");
	scanf("%d", &f.dia);
	
	printf("Mês: ");
	scanf("%d", &f.mes);
	
	printf("Ano: ");
	scanf("%d", &f.ano);
	
	printf("Salário: ");
	scanf("%d", &f.salario);
	getchar();
	
	printf("Experiência: ");
	fgets(f.experiencia, 200, stdin);
	f.experiencia[strcspn(f.experiencia, "\n")] = 0;
	
	lista[listas] = f;
	listas++;
	printf("Funcionário cadastrado com sucesso!/n");
}

// fun��o de vizualizar funcion�rios
void visualizarFuncionarios () {
	if (listas == 0) {
		printf("\nNenhum funcion�rio cadastrado ainda.\n");
	} else {
		printf("\n--- Lista de Funcion�rios ---\n");
		for (int i = 0; i < listas; i++) {
			printf("\nFuncionário %d: \n", i + 1);
			printf("Matrícula: %d\n", lista[i].matricula);
			printf("Nome: %s\n", lista[i].nome);
			printf("Endereço: %s\n", lista[i].endereco);
			printf("Telefone: %d\n", lista[i].telefone);
			printf("Data de nascimento: %02d/%02d/%04d\n", lista[i].dia, lista[i].mes, lista[i].ano);
			printf("Salário: R$ %d\n", lista[i].salario);
			printf("Experiência: %s\n", lista[i].experiencia);
		}
	}
}


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

// verificar se o codigo já existe !! (usado em cadastrarProduto) !!
int codigoExistente(int codigo) {
    for (int i = 0; i < total; i++) {
        if (estoque[i].codigo == codigo) {
            return 1;
        }
    }
    return 0; !!/ // Código não encontrado
}

// Cadastrando os produtos
void cadastrarProduto() {
    if (total < MAX_PRODUTOS) {
        Produto p;

        printf("Codigo: ");
            if (scanf("%d", &p.codigo) != 1) { // !!Agora ele ira verificar se a leitura foi bem sucedida!!
                printf("Entrada inválida. Tente novamente.\n");
                while (getchar() != '\n'); // !!Vai Limpa buffer!!
                continue;
            }
            if (codigoExistente(p.codigo)) {
                printf("Erro: Código %d já existe! Tente outro.\n", p.codigo);
            }
        } while (codigoExistente(p.codigo));

        getchar(); // !!limpar o buffer depois do ultimo scanf!!

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
         printf("Estoque cheio! Não é possível cadastrar mais produtos.\n"); // !! Só embelezei :) !!
    }
}


// listar os produtos
void listarProdutos() {
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
            // !! limpeza e adição do 'estoque atual'
     printf("\n--- ESTOQUE ATUAL ---\n");
    for (int i = 0; i < total; i++) {
        printf("Cód: %d | Desc: %s | Tam: %d | Cor: %s | Marca: %s | Qtd: %d | Valor: R$ %.2f\n",
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
    printf("Digite o código do produto: ");
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
    printf("Produto não encontrado.\n");
}

// Efetuar venda
void efetuarVenda() {
    if (total == 0) {
        printf("Não há produtos cadastrados!\n");
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

             if (qtd <= 0) {
                printf("A quantidade a vender deve ser maior que zero.\n"); // !! indicar que a quantidade nao pode ser 0 !!
                return;
            }

            if (qtd > estoque[i].quantidade) {
                printf("Estoque insuficiente! Temos apenas %d unidades.\n", estoque[i].quantidade); // !! Enfeitando o codigo e solidificando as informações !!
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
                printf("\nVenda registrada com sucesso!\n");
            } else {
                printf("\nAVISO: Limite máximo de vendas (%d) atingido. A venda não foi registrada no histórico.\n", MAX_VENDAS); // !!Uma Pequena Alteração para que ele identifique e trate caso o limite de vendas seja atingido !!
            }

            // nota da venda
            printf("\n===== NOTA DE VENDA =====\n");
            printf("Produto: %s\n", estoque[i].descricao);
            printf("Marca: %s\n", estoque[i].marca);
            printf("Quantidade: %d\n", qtd);
            printf("Valor unit�rio: %.2f\n", estoque[i].valor);
            printf("Total: %.2f\n", totalVenda);
            printf("Data/Hora: %s\n", (totalVendas <= MAX_VENDAS ? vendas[totalVendas-1].dataHora : "Não registrada")); // !! A Implementação foi para dizermos ao compilador "Se a venda foi salva, me dê a data dela. Se não, me dê o texto 'Não registrada' " !!
            printf("=========================\n");

            return;
        }
    }
    printf("Produto não encontrado.\n");
}

int main(){
    int opcao, //!! 'opcaoitem;' não necessaria nessa linha de codigo !!
    int opcaoFuncionario; // !!NOVA VARIÁVEL: Para o sub-menu de Funcionário!!
    int opcaoItem; // !!Variável para o sub-menu de Item/Estoque!!
    setlocale(LC_ALL, "Portuguese");

    // !! Fiz mais alguma implementações de codigo para deixar ele mais solido e unico !!
    do{ 
    printf("\n============================\n");
        printf("    LOJA DE CALCADOS - MENU\n");
        printf("============================\n");
        printf("Escolha uma opcao:\n");
        printf(" 1. Funcionário\n 2. Item/Estoque\n 3. Efetuar venda\n 4. Exit\n");
        printf("Escolha: ");
        if (scanf("%d", &opcao) != 1) { // Leitura segura e robusta
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            opcao = 0; // Força uma opção inválida para repetir o loop
            continue;
        }
    switch(opcao){
         case 1 :
         // !! CORRIGI USANDO 'opcaoFuncionario' E TRATEI O 'getcha' !!
        do {
        printf("\n--- MENU FUNCIONÁRIOS ---\n");
        printf("1 - Cadastrar funcionário\n");
        printf("2 - Visualizar funcionários\n");
        printf("3 - Voltar ao Menu Principal\n"); // !! Troca do Sair por >> Voltar ao Menu Principal !!
        printf("Escolha: ");
        if (scanf("%d", &opcaoFuncionario) != 1) { //!! scanf("%d", &opcao); << apenas fiz a troca do mesmo  !!
             printf("Entrada inválida! Tente novamente.\n");
             while (getchar() != '\n'); // !! Fiz um pequeno retoquepois o scanf ja trata a entrada !!
             opcaoFuncionario = 99; // !! Força repetição !!
             continue;

        switch (opcaoFuncionario) { // !! Implementação do Funcionario !!
            case 1: cadastrarfuncionario(); break;
            case 2: visualizarFuncionarios(); break;
            case 3: printf("Saindo do programa...\n"); break;
            default: printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcaoFuncionario != 3); // !! Apenas implementei o Funcionario !!
            break;
        
        case 2 :
            opcaoItem = 0; // !! Vai Inicializar para entrar no loop !!
            do { 
            printf("\n==== MENU ESTOQUE ====\n");
            printf("1 - Cadastrar Produto\n");
            printf("2 - Listar Produtos\n");
            printf("3 - Buscar Produto\n");
            printf("0 - Voltar ao Menu Principal\n");
            printf("Escolha: ");
            if (scanf("%d", &opcaoItem) != 1) {
                while (getchar() != '\n');
                opcaoItem = 99; // !! Força repetição !!
                continue;
            }

        switch (opcaoitem) {
            case 1: cadastrarProduto(); break;
            case 2: listarProdutos(); break;
            case 3: buscarProduto(); break;
            case 0: printf("Voltando...\n"); break; // !! mudei de saindo para voltando !!
            default: printf("Opcão inválida!\n");
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
    	printf("Opcão inválida!\n");
    }
    
} while(opcao != 4);
    
    system("pause"); // <- faz o programa esperar antes de fechar !! retirar caso não estiver no sistema operacinal Windowns !!
    return 0;
}

    
    
    
    
    
// Participantes: Guilherme Diegues, Lana Reis, Pedro Domingos, Leandra Bazilio, Yrllan, Jayane Ellen e Jo�s Luna.
