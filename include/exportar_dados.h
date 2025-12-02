#ifndef EXPORTAR_DADOS_H
#define EXPORTAR_DADOS_H

#include "../include/tipos.h"
#include <stdio.h>

void exportar_dados_arquivo_texto_aeronaves(string nome_arq, aeronaves_t *lista);
void exportar_dados_arquivo_texto_rotas(string nome_arq, rotas_t *lista);

void exportar_dados_arquivo_csv_aeronaves(string nome_arq, aeronaves_t *lista);
void exportar_dados_arquivo_csv_rotas(string nome_arq, rotas_t *lista);

void exportar_dados_arquivo_html_aeronaves(string nome_arq, aeronaves_t *lista);
void exportar_dados_arquivo_html_rotas(string nome_arq, rotas_t *lista);

#endif
