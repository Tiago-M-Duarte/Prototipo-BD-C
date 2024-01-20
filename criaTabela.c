#include "bancoDados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int criaTabela()
{
    char tabNome[MAX_TABELA_NOME];
    printf("Qual o nome da tabela que deseja criar? ");
    scanf("%s", tabNome);
    strcat(tabNome, ".txt");

    FILE *tabela;
    tabela = fopen(tabNome, "r");

    // Verificar existencia de tabela
    if (tabela == NULL)
    {
        tabela = fopen(tabNome, "w");
        if (tabela == NULL)
        {
            printf("Erro na criacao da tabela.\n");
            return 1;
        }
        // Criar arquivo de tabela e começar gravação de campos
        FILE *db_a;
        db_a = fopen(db, "a");
        fputs(strcat(tabNome, "\n"), db_a);
        printf("Certo, o campo id ja foi criado como incrementador numerico\n");
        int tipoCampo = -1;
        while (tipoCampo != 0)
        {
            char campoNome[MAX_CAMPO_NOME];
            // Escolha do tipo de campo
            printf("Qual sera o tipo de dado do proximo campo da tabela: (Digite o numero referente a opcao e aperte Enter)\n");
            printf("\n1 - Char");
            printf("\n2 - Int");
            printf("\n3 - Float");
            printf("\n4 - Double");
            printf("\n5 - String[50]");
            printf("\n0 - Nao desejo gerar mais nenhum campo\n");
            scanf("%d", &tipoCampo);
            // Gravação do campo
            if (tipoCampo != 0)
            {
                printf("Agora digite o nome do campo: (de ate 50 caracteres)\n");
                scanf("%s", campoNome);
                switch (tipoCampo)
                {
                case 1:
                    strcat(campoNome, " char\n");
                    break;
                case 2:
                    strcat(campoNome, " int\n");
                    break;
                case 3:
                    strcat(campoNome, " float\n");
                    break;
                case 4:
                    strcat(campoNome, " double\n");
                    break;
                case 5:
                    strcat(campoNome, " string[50]\n");
                    break;
                }
                fputs(campoNome, db_a);
                printf("Campo criado com sucesso!\n");
            }
        }
        // Finalização e fechamento de tabela
        fputs("\n", db_a);
        fclose(db_a);
    }
    else
    {
        printf("Tabela ja criada!\n");
    }
    // Fechamento do banco de dados
    fclose(tabela);
    return 0;
}