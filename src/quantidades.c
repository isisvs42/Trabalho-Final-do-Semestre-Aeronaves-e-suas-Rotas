#include "../include/quantidades.h"

void percentual_de_voos_realizado_por_aeronave(aeronaves_t *lista_aeronaves, rotas_t *lista_rotas){
    int tot_voos = 0, voos = 0;
    rotas_t *copia = lista_rotas;
    float percentual;
    // cálculo do total de voos
    while(copia){
        tot_voos++;
        copia = copia->prox;
    }

    // cálculo do percentual de cada aeronave
    while(lista_aeronaves){
        voos = 0;
        copia = lista_rotas;

        while(copia){
            if(lista_aeronaves->codigo_aeronave == copia->codigo_da_aeronave)
                voos++;
            
            copia = copia->prox;
        }

        percentual = ((float)voos/tot_voos)*100;
        printf("Aeronave %u -> %05.2f%% dos voos.\n", lista_aeronaves->codigo_aeronave, percentual);

        lista_aeronaves = lista_aeronaves->prox;
    }
}

float consumo_total_de_combustivel_em_intervalo_de_datas(data_t inicio, data_t fim, rotas_t* lista_rotas){
    float consumo_total = 0.0;
    while(lista_rotas){
        if(inicio.numero <= lista_rotas->data.numero && lista_rotas->data.numero <= fim.numero)
            consumo_total += lista_rotas->combustivel_necessario;
        
        lista_rotas = lista_rotas->prox;
    }

    printf("O consumo total de combustivel nesse intervalo de datas foi de %.2f L.\n", consumo_total);
}

void percentual_de_voos_por_destino_em_intervalo_de_datas(data_t inicio, data_t fim, rotas_t* lista_rotas){
    int tot_voos = 0, voos = 0, qtd_destinos = 0;
    rotas_t *copia = lista_rotas, *copia2 = lista_rotas;
    float percentual;
    string *destinos = NULL;

    // cálculo do total de voos no intervalo de datas
    while(copia){
        if(inicio.numero <= copia->data.numero && copia->data.numero <= fim.numero)
            tot_voos++;
        
        copia = copia->prox;
    }

    // segunda parte do cálculo
    if (tot_voos > 0){
        copia = lista_rotas;

        while(copia){
            copia2 = lista_rotas;
            voos = 0;

            if(inicio.numero <= copia->data.numero && copia->data.numero <= fim.numero){

                if(!destino_ja_foi_calculado(copia, lista_rotas, &destinos, &qtd_destinos)){

                    // cálculo do total de voos para o destino
                    while(copia2){

                        if(!strcmp(copia->destino, copia2->destino))
                            voos++;

                        copia2 = copia2->prox;
                    }

                    // cálculo do percentual
                    percentual = ((float)voos/tot_voos)*100;
                    printf("Destino %s...................... %05.2f%%\n", copia->destino, percentual);
                }
                
            }

            copia = copia->prox;
        }

    } else 
        printf("Nao ha voos para esse intervalo de datas.\n");

    free(destinos);
}

bool destino_ja_foi_calculado(rotas_t *rota, rotas_t *lista_rotas, string **destinos, int *qtd_destinos){
    if(*destinos == NULL){ // nenhum destino foi calculado ainda
        *destinos = calloc(1, sizeof(string));
        strcpy(*(*destinos), rota->destino);
        *qtd_destinos += 1;
        return false;

    } else {
        for(int i = 0; i < *qtd_destinos; i++){
            if(!strcmp(rota->destino, *(*(destinos+i))))
                return true;
        }

        *destinos = realloc(*destinos, sizeof(string)*((*qtd_destinos)+1));
        strcpy(*(*destinos + (*qtd_destinos)), rota->destino);
        *qtd_destinos += 1;
    }
    return false;
}
