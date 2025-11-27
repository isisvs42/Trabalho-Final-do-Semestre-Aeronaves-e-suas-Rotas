#include "./include/exportar_txt.h"
#include "./include/tipos.h"
#include "./include/listagens.h"
#include <stdio.h>

void exportar_dados_arquivo_texto_aeronaves(string nome_arq, aeronaves_t *lista){
    FILE *fp_arquivo = NULL;
    fp_arquivo = fopen(nome_arq, "w");

    while(lista){
        mostrar_aeronave(lista, fp_arquivo);
        lista = lista->prox;
    }

    fclose(fp_arquivo);
}

void exportar_dados_arquivo_texto_rotas(string nome_arq, rotas_t *lista){
    FILE *fp_arquivo = NULL;
    fp_arquivo = fopen(nome_arq, "w");

    while(lista){
        mostrar_aeronave(lista, fp_arquivo);
        lista = lista->prox;
    }

    fclose(fp_arquivo);
}
