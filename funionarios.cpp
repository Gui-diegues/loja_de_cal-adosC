#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define LISTA_FUNCIONARIO 100000

//função dos dados dos funcionarios
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
int listas ;

void cadastrarfuncionario() {
	funcionario f;
	
	
	printf("Matrícula: ");
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

// função de vizualizar funcionários
void visualizarFuncionarios () {
	if (listas == 0) {
		printf("\nNenhum funcionário cadastrado ainda.\n");
	} else {
		printf("\n--- Lista de Funcionários ---\n");
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

// função principal (menu)
int main() {
    int opcao;

    do {
        printf("\n--- MENU FUNCIONÁRIOS ---\n");
        printf("1 - Cadastrar funcionário\n");
        printf("2 - Visualizar funcionários\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarfuncionario();
                break;
            case 2:
                visualizarFuncionarios();
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}