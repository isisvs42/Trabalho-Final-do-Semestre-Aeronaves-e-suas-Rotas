#ifndef QUANTIDADES_H
#define QUANTIDADES_H

#include "../include/tipos.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void percentual_de_voos_realizado_por_aeronave(aeronaves_t *lista_aeronaves, rotas_t *lista_rotas);
float consumo_total_de_combustivel_em_intervalo_de_datas(data_t inicio, data_t fim, rotas_t* lista_rotas);
void percentual_de_voos_por_destino_em_intervalo_de_datas(data_t inicio, data_t fim, rotas_t* lista_rotas);
void calculo_voos_destino(rotas_t *rota, verificacao_destinos_t **destinos, int *qtd_destinos);

#endif
