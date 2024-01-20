#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H

#include <stdio.h>

#define db "db.txt"
#define MAX_TABELA_NOME 50
#define MAX_CAMPO_NOME 60

int criaTabela();
int obterProximoID(FILE *tabela);
void insereRegistro();
void listaTabelas();

#endif
