#include "../include/exportar_dados.h"
#include "../include/tipos.h"
#include "../include/listagens.h"
#include <stdio.h>

void exportar_dados_arquivo_texto_aeronaves(string nome_arq, aeronaves_t *lista){
    FILE *fp_arquivo = NULL;
    fp_arquivo = fopen(nome_arq, "w");

    if (!fp_arquivo) {
        printf("Erro ao abrir arquivo %s\n", nome_arq);
        return;
    }


    while(lista){
        mostrar_aeronave(lista, fp_arquivo);
        lista = lista->prox;
    }

    fclose(fp_arquivo);
}

void exportar_dados_arquivo_texto_rotas(string nome_arq, rotas_t *lista){
    FILE *fp_arquivo = NULL;
    fp_arquivo = fopen(nome_arq, "w");

    if (!fp_arquivo) {
        printf("Erro ao abrir arquivo %s\n", nome_arq);
        return;
    }

    while(lista){
        mostrar_rota(lista, fp_arquivo);
        lista = lista->prox;
    }

    fclose(fp_arquivo);
}

void exportar_dados_arquivo_csv_aeronaves(string nome_arq, aeronaves_t *lista){
    FILE *fp_arquivo = NULL;
    fp_arquivo = fopen(nome_arq, "w");

    if (!fp_arquivo) {
        printf("Erro ao abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp_arquivo, "IDENTIFICAÇÃO;FABRICANTE;MODELO;PREFIXO;ANO DE FABRICAÇÃO;TIPO;SITUAÇÃO;TRIPULAÇÃO NECESSÁRIA\n"); // títulos das colunas
    while(lista){
        fprintf(fp_arquivo, "%u;", lista->codigo_aeronave);
        mostrar_fabricante(lista->fabricante, fp_arquivo);
        fprintf(fp_arquivo, ";%s;%s;%i;", lista->modelo, lista->prefixo, lista->ano_de_fabricacao);
        mostrar_tipo(lista->tipo, fp_arquivo);
        fprintf(fp_arquivo, ";");
        mostrar_situacao(lista->situacao, fp_arquivo);
        fprintf(fp_arquivo, ";%i\n", lista->tripulacao_necessaria);

        lista = lista->prox;
    }

    fclose(fp_arquivo);
}

void exportar_dados_arquivo_csv_rotas(string nome_arq, rotas_t *lista){
    FILE *fp_arquivo = NULL;
    fp_arquivo = fopen(nome_arq, "w");

    if (!fp_arquivo) {
        printf("Erro ao abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp_arquivo, "CÓDIGO DA AERONAVE ALOCADA;CÓDIGO DA ROTA;DATA;HORA;ORIGEM;DESTINO;TEMPO DE VOO (EM H);COMBUSTÍVEL NECESSÁRIO (EM L);QUANTIA DE PASSAGEIROS;QUANTIA DE CARGA (EM KG)\n");
    while(lista){
        fprintf(fp_arquivo, "%u;%u;%02d/%02d/%02d;%02d:%02d;%s;%s;%u;%.2f;%u;%u\n", lista->codigo_da_aeronave, lista->codigo_da_rota, lista->data.dia, lista->data.mes, lista->data.ano, lista->hora.horas, lista->hora.minutos,
        lista->origem, lista->destino, lista->tempo_estimado_de_voo, lista->combustivel_necessario, lista->n_passageiros, lista->n_carga);

        lista = lista->prox;
    }

    fclose(fp_arquivo);
}

void exportar_dados_arquivo_html_aeronaves(string nome_arq, aeronaves_t *lista){
    FILE *fp_arquivo = NULL;
    fp_arquivo = fopen(nome_arq, "w");

    if (!fp_arquivo) {
        printf("Erro ao abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp_arquivo, "<HTML> <HEAD> <TITLE> RELATÓRIO DE AERONAVES </TITLE> </HEAD> <BODY> \n");
    fprintf(fp_arquivo, "<TABLE border = '1'> <TR>");
    fprintf(fp_arquivo, "<TH> IDENTIFICAÇÃO </TH>"); // títulos das colunas
    fprintf(fp_arquivo, "<TH> FABRICANTE </TH>");
    fprintf(fp_arquivo, "<TH> MODELO </TH>");
    fprintf(fp_arquivo, "<TH> PREFIXO </TH>");
    fprintf(fp_arquivo, "<TH> ANO DE FABRICAÇÃO </TH>");
    fprintf(fp_arquivo, "<TH> TIPO </TH>");
    fprintf(fp_arquivo, "<TH> SITUAÇÃO </TH>");
    fprintf(fp_arquivo, "<TH> TRIPULAÇÃO NECESSÁRIA </TH> </TR>\n");

    while(lista){
        fprintf(fp_arquivo, "<TR>");
        fprintf(fp_arquivo, "<TD> %u </TD>", lista->codigo_aeronave);
        fprintf(fp_arquivo, "<TD>");mostrar_fabricante(lista->fabricante, fp_arquivo);fprintf(fp_arquivo, "</TD>");
        fprintf(fp_arquivo, "<TD> %s </TD>", lista->modelo);
        fprintf(fp_arquivo, "<TD> %s </TD>", lista->prefixo);
        fprintf(fp_arquivo, "<TD> %i </TD>", lista->ano_de_fabricacao);
        fprintf(fp_arquivo, "<TD>");mostrar_tipo(lista->tipo, fp_arquivo);fprintf(fp_arquivo, "</TD>");
        fprintf(fp_arquivo, "<TD>");mostrar_situacao(lista->situacao, fp_arquivo);fprintf(fp_arquivo, "</TD>");
        fprintf(fp_arquivo, "<TD> %i </TD>", lista->tripulacao_necessaria);
        fprintf(fp_arquivo, "</TR>\n");

        lista = lista->prox;
    }

    fprintf(fp_arquivo, "</TABLE> </BODY> </HTML>\n");
    fclose(fp_arquivo);
}

void exportar_dados_arquivo_html_rotas(string nome_arq, rotas_t *lista){

}
