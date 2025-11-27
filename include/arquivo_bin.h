#ifndef ARQUIVO_BIN_H
#define ARQUIVO_BIN_H

#include "../include/tipos.h"
#include <stdio.h>
#include <stdlib.h>

void salvar_dados_arq_bin_aeronaves(aeronaves_t *lista, char* nome_arq);
void ler_dados_arq_bin_aeronaves(char* nome_arq, aeronaves_t **lista);

void salvar_dados_arq_bin_rotas(rotas_t *lista, char* nome_arq);
void ler_dados_arq_bin_rotas(char* nome_arq, rotas_t **lista);

#endif
