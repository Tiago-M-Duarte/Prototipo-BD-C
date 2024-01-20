#include "bancoDados.h"
#include <stdio.h>

void criaBanco()
{
    printf("\nInfelizmente temos apenas um banco de dados funcional, faca as tabelas nele, espero que entenda, :D\n\n");
}

int main()
{
    printf("Bem vindo ao SGBD NR|NB (Nao Repara Nos Bugs),");
    int menu;
    while (menu != 0)
    {
        printf("\nescolha o que deseja fazer: (Digite o numero referente a opcao e aperte Enter)\n");
        printf("\n1 - Criar banco de dados");
        printf("\n2 - Criar tabela");
        printf("\n3 - Listar tabelas");
        printf("\n4 - Inserir registro");
        printf("\n0 - Fechar SGBD\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            criaBanco();
            break;
        case 2:
            criaTabela();
            break;
        case 3:
            listaTabelas();
            break;
        case 4:
            insereRegistro();
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}