#ifndef QUANTIDADES_H
#define QUANTIDADES_H

#include "../include/tipos.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void percentual_de_voos_realizado_por_aeronave(void);
void mostra_percentuais_por_aeronave(void);
float consumo_total_de_combustivel_em_intervalo_de_datas(data_t inicio, data_t fim);
int percentual_de_voos_por_destino_em_intervalo_de_datas(data_t inicio, data_t fim);
void mostra_percentuais_e_destinos(void);
bool destino_ja_foi_calculado(string *destinos, int n_destinos_registrados, int posicao_rotas);

#endif
