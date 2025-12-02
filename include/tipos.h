#ifndef TIPOS_H
#define TIPOS_H

#define T_STRING         20
#define T_TRIPULACAO     50

typedef char string[T_STRING];

typedef enum {AIRBUS = 1, BOEING, EMBRAER} fabricantes_t;

typedef enum {CARGA = 1, PASSAGEIRO} tipos_t;

typedef enum {OPERACAO = 1, MANUTENCAO} situacao_t;

typedef struct data {
    int dia;
    int mes;
    int ano;
    int numero;
} data_t;

typedef struct hora {
    int horas;
    int minutos;
} hora_t;

typedef struct aeronave {
    unsigned int codigo_aeronave;
    string modelo;
    fabricantes_t fabricante; // 1 - airbus/2 - boeing/ 3 - embraer
    string prefixo;
    int ano_de_fabricacao;
    tipos_t tipo; // 1 = carga e 2 = passageiro
    int n_passageiros_max;
    situacao_t situacao; // 1 = em operação e 2 = em manutenção
    int tripulacao_necessaria; // (quantidade de pilotos (piloto e co-piloto) + quantidade de membros da comissaria de bordo)
    int vezes_que_entrou_em_manutenção;
    struct aeronave *prox;
} aeronaves_t;

typedef struct rotas {
    unsigned int codigo_da_aeronave;
    unsigned int codigo_da_rota;
    data_t data;
    hora_t hora;
    string origem;
    string destino;
    int codigo_destino;
    unsigned int tempo_estimado_de_voo;
    float combustivel_necessario;
    unsigned int n_passageiros;
    unsigned int n_carga;
    string nomes_tripulacao[T_TRIPULACAO];
    struct rotas *prox;
} rotas_t;

typedef struct verificacao_destinos{
    string destino;
    int voos_pro_destino;
} verificacao_destinos_t;

#endif
