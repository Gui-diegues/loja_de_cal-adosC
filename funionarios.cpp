#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define LISTA_FUNCIONARIO 100000

//fun��o dos dados dos funcionarios
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
	
	
	printf("Matr�cula: ");
	scanf("%d", &f.matricula);
	getchar();
	
	printf("Nome: ");
	fgets(f.nome, 50, stdin);
	f.nome[strcspn(f.nome, "\n")] = 0;
	
	printf("Endere�o: ");
	fgets(f.endereco, 30, stdin);
	f.endereco[strcspn(f.endereco, "\n")] = 0;
	
	printf("Telefone: ");
	scanf("%d", &f.telefone);
	
	printf("Data de nascimento:\n");
	
	printf("Dia: ");
	scanf("%d", &f.dia);
	
	printf("M�s: ");
	scanf("%d", &f.mes);
	
	printf("Ano: ");
	scanf("%d", &f.ano);
	
	printf("Sal�rio: ");
	scanf("%d", &f.salario);
	getchar();
	
	printf("Experi�ncia: ");
	fgets(f.experiencia, 200, stdin);
	f.experiencia[strcspn(f.experiencia, "\n")] = 0;
	
	lista[listas] = f;
	listas++;
	printf("Funcion�rio cadastrado com sucesso!/n");
}

// fun��o de vizualizar funcion�rios
void visualizarFuncionarios () {
	if (listas == 0) {
		printf("\nNenhum funcion�rio cadastrado ainda.\n");
	} else {
		printf("\n--- Lista de Funcion�rios ---\n");
		for (int i = 0; i < listas; i++) {
			printf("\nFuncion�rio %d: \n", i + 1);
			printf("Matr�cula: %d\n", lista[i].matricula);
			printf("Nome: %s\n", lista[i].nome);
			printf("Endere�o: %s\n", lista[i].endereco);
			printf("Telefone: %d\n", lista[i].telefone);
			printf("Data de nascimento: %02d/%02d/%04d\n", lista[i].dia, lista[i].mes, lista[i].ano);
			printf("Sal�rio: R$ %d\n", lista[i].salario);
			printf("Experi�ncia: %s\n", lista[i].experiencia);
		}
	}
}

// fun��o principal (menu)
int main() {
    int opcao;

    do {
        printf("\n--- MENU FUNCION�RIOS ---\n");
        printf("1 - Cadastrar funcion�rio\n");
        printf("2 - Visualizar funcion�rios\n");
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
                printf("Op��o inv�lida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}