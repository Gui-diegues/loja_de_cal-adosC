#include <stdio.h>
#include <stdlib.h>
int main(){
    int opcao;
    
    printf("LOJA DE CALCADOS\n\n");
    printf("Escolha uma opcao:\n");
    printf(" 1.Funcionario\n 2.Item\n 3.Efetuar venda\n 4.exit\n");
    scanf("%d", &opcao);
    
    
    system("pause"); // <- faz o programa esperar antes de fechar
    return 0;
    }
