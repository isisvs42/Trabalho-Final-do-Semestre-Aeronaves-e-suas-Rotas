#ifndef LISTAGENS_H
#define LISTAGENS_H

#include "../include/tipos.h"
#include <stdio.h> // para o FILE

// mostrar aeronaves
void listar_aeronaves(aeronaves_t *lista);
void mostrar_aeronave(aeronaves_t *aeronave, FILE *fp);
void mostrar_fabricante(fabricantes_t fabricante);
void mostrar_tipo(tipos_t tipo);
void mostrar_situacao(situacao_t situacao);

// listagens de aeronaves
void listagem_aeronaves_prefixo(string prefixo, aeronaves_t *lista);
void listagem_aeronaves_fabricante(fabricantes_t fabricante, aeronaves_t *lista);
void listagem_aeronaves_tipo(tipos_t tipo, aeronaves_t *lista);
void listagem_aeronaves_modelo(string modelo, aeronaves_t *lista);
void listagem_aeronaves_ano_fabricacao(int ano, aeronaves_t *lista);
void listagem_aeronaves_situacao(situacao_t situacao, aeronaves_t *lista);

// listagens de rotas
void mostrar_rota(rotas_t *rota, FILE *fp);
void listagem_rotas_data(data_t inicio, data_t fim, rotas_t *lista_rotas);
void listagem_rotas_destino(string destino, rotas_t *lista_rotas);
void listagem_rotas_origem(string origem, rotas_t *lista_rotas);
void listagem_rotas_numero_passageiros(int n_passageiros, rotas_t *lista_rotas);
void mostrar_rota_maior_n_passageiros(rotas_t *lista_rotas);
void mostrar_rota_menor_n_pasageiros(rotas_t *lista_rotas);

/*int calculo_rotas_com_maior_n_pass(rotas_t **maiores_rotas, aeronaves_t *lista_aeronaves, rotas_t *lista_rotas);
void listagem_rotas_maior_n_passageiros(rotas_t *maiores_rotas, int k);
int calculo_rotas_com_menor_n_pass(rotas_t **menores_rotas, aeronaves_t *lista_aeronaves, rotas_t *lista_rotas);
void listagem_rotas_menor_n_passageiros(rotas_t *menores_rotas, int k);*/

#endif
