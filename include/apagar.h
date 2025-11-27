#ifndef APAGAR_H
#define APAGAR_H

#include "../include/tipos.h"
#include <stdio.h>
#include <stdlib.h>

void apagar_aeronave(aeronaves_t *aeronave, aeronaves_t **lista_aeronaves);
aeronaves_t* localizar_aeronave_anterior(aeronaves_t *aeronave, aeronaves_t *lista_aeronaves);

#endif
