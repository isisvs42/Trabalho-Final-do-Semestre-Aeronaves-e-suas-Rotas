#ifndef APAGAR_H
#define APAGAR_H

#include "../include/tipos.h"
#include <stdio.h>
#include <stdlib.h>

void apagar_aeronave(aeronaves_t *aeronave, aeronaves_t **lista_aeronaves);
aeronaves_t* localizar_aeronave_anterior(aeronaves_t *aeronave, aeronaves_t *lista_aeronaves);

void apagar_rota(rotas_t *rota, rotas_t **lista_rotas);
rotas_t* localizar_rota_anterior(rotas_t *rota, rotas_t *lista_rotas);

#endif
