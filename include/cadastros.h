#ifndef CADASTROS_H
#define CADASTROS_H
#include "../include/tipos.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// cadastro de aeronaves
aeronaves_t *localizar_aeronave_por_codigo(unsigned int codigo_aeronave, aeronaves_t *lista_aeronaves);
aeronaves_t *nova_aeronave(unsigned int codigo_aeronave);
void registrar_fabricante(aeronaves_t *aeronave);
void registrar_tipo(aeronaves_t *aeronave);
void registrar_situacao(aeronaves_t *aeronave);
void inserir_aeronave_pelo_inicio(aeronaves_t *aeronave, aeronaves_t **end_lista_aeronaves);
void inserir_aeronave_pelo_fim(aeronaves_t *aeronave, aeronaves_t **end_lista_aeronaves);
aeronaves_t* localizar_ultima_aeronave(aeronaves_t *lista_aeronaves);

// cadastro de rotas
rotas_t *nova_rota(aeronaves_t *aeronave, unsigned int codigo_rota, bool carga);
void registrar_nomes_tripulacao(rotas_t* rota, int n_tripulacao);
rotas_t *localizar_rota_por_codigo(unsigned int codigo_rota, rotas_t *lista_rotas);
bool eh_carga(aeronaves_t *aeronave);
bool esta_operando(aeronaves_t *aeronave);
void inserir_rota_pelo_inicio(rotas_t *rota, rotas_t **end_lista_rotas);
void inserir_rota_pelo_fim(rotas_t *rota, rotas_t **end_lista_rotas);
rotas_t* localizar_ultima_rota(rotas_t *lista_rotas);

#endif
