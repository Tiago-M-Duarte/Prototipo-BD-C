#include "bancoDados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int obterProximoID(FILE *tabela)
{
    int id = 1; // Valor inicial

    fseek(tabela, 0, SEEK_SET); // Voltar para o início do arquivo

    char linha[100];
    while (fgets(linha, sizeof(linha), tabela) != NULL)
    {
        if (linha[0] == '\n') // Ignorar linhas em branco (fim da tabela)
            continue;

        sscanf(linha, "%*s %d", &id);
    }

    return id + 1; // Retornar o próximo ID disponível
}

void insereRegistro()
{
    FILE *db_file = fopen(db, "r");

    int codigo = 1;
    char linha[MAX_TABELA_NOME + 5]; // Tamanho máximo do nome da tabela + ".txt"

    printf("Tabelas disponíveis:\n");
    int inCampo = 0; // Variável para indicar linha de campo

    while (fgets(linha, sizeof(linha), db_file) != NULL)
    {
        linha[strcspn(linha, "\n")] = '\0';

        if (linha[0] == '\0')
        {
            // Linha em branco, indicando o fim da tabela
            inCampo = 0;  // Reinicia a variável quando encontrar uma linha em branco
            continue;
        }

        if (inCampo)
        {
            // Se estiver dentro de uma linha de campo, pule para a próxima iteração
            continue;
        }

        if (strstr(linha, ".txt") != NULL) {
            // Linha contendo o nome da tabela
            printf("%d - %s\n", codigo++, linha);
            inCampo = 1; // Marca que próxima linha é de campo
        }
    }

    int escolha;
    printf("Escolha o código da tabela para inserir um registro: ");
    scanf("%d", &escolha);

    codigo = 1;
    while (fgets(linha, sizeof(linha), db_file) != NULL && codigo != escolha)
    {
        linha[strcspn(linha, "\n")] = '\0';
        if (linha[0] == '\0')
        {
            continue;
        }
        codigo++;
    }

    
    fclose(db_file);
}

void listaTabelas()
{

    FILE *db_file = fopen(db, "r");
    if (db_file == NULL)
    {
        printf("Erro ao abrir o arquivo do banco de dados.\n");
        return;
    }

    char linha[MAX_TABELA_NOME + 5]; // Tamanho máximo do nome da tabela + ".txt"

    while (fgets(linha, sizeof(linha), db_file) != NULL)
    {
        // Remover a quebra de linha do final
        linha[strcspn(linha, "\n")] = '\0';

        if (linha[0] == '\0')
        {
            // Ignorar linhas em branco, indicando o fim da tabela
            continue;
        }

        printf("Tabela: %s\n", linha);

        while (fgets(linha, sizeof(linha), db_file) != NULL && linha[0] != '\n')
        {
            // Remover a quebra de linha do final
            linha[strcspn(linha, "\n")] = '\0';
            printf("  Campo: %s\n", linha);
        }

        printf("\n");
    }

    fclose(db_file);
}