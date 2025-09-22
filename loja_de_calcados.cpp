#include <stdio.h>
#include <stdlib.h>

int main(){
    int opcao, opitem, codigo, quantidade;
    char descricao[50], tamanho[10], cor[10], marca[30];
    float valor;
  do{ 
    printf("LOJA DE CALCADOS\n\n");
    printf("Escolha uma opcao:\n");
    printf(" 1.Funcionario\n 2.Item\n 3.Efetuar venda\n 4.Exit\n");
    scanf("%d", &opcao);
  }while (opcao < 1 || opcao > 4);
  
    if(opcao == 2){
        printf("1.Cadastra novo item\n 2.Ver estoque\n");
        scanf("%d", &opitem);
    }  
    if(opitem == 1){
        printf("Digite o codigo do produto: ");
        scanf("%d", &codigo);

        printf("Digite a descricao do produto: ");
        scanf(" %[^\n]", descricao); // Lê até a quebra de linha 

        printf("Digite o tamanho do produto: ");
        scanf(" %s", tamanho);

        printf("Digite a cor: ");
        scanf(" %s", cor);

        printf("Digite o valor: ");
        scanf("%f", &valor);

        printf("Qual marca: ");
        scanf(" %s", marca);

        printf("Quantos produtos voce deseja adicionar ao estoque: ");
        scanf("%d", &quantidade);

        // Exibir dados lidos
        printf("\n--- Produto Cadastrado ---\n");
        printf("Codigo: %d\nDescricao: %s\nTamanho: %s\nCor: %s\nValor: %.2f\nMarca: %s\nQuantidade: %d\n",
               codigo, descricao, tamanho, cor, valor, marca, quantidade);

    
             
    }
    
    system("pause"); // <- faz o programa esperar antes de fechar
    return 0;
    }
