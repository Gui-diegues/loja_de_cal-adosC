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
