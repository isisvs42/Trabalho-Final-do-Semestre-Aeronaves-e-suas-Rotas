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

    if (!consumo_total)
        printf("Nao ha aeronaves nesse intervalo");
    else
        printf("O consumo total de combustivel nesse intervalo de datas foi de %.2f L.\n", consumo_total);
}

void percentual_de_voos_por_destino_em_intervalo_de_datas(data_t inicio, data_t fim, rotas_t* lista_rotas){
    int tot_voos = 0, qtd_destinos = 0;
    rotas_t *copia = lista_rotas;
    float percentual;
    verificacao_destinos_t *destinos = NULL;

    // cálculo do total de voos no intervalo de datas
    while(copia){
        if(inicio.numero <= copia->data.numero && copia->data.numero <= fim.numero)
            tot_voos++;
        
        copia = copia->prox;
    }

    // segunda parte do cálculo
    if (tot_voos > 0){
        copia = lista_rotas;

        // cálculo do total de voos para o destino
        while(copia){
            if(inicio.numero <= copia->data.numero && copia->data.numero <= fim.numero)
                calculo_voos_destino(copia, &destinos, &qtd_destinos);
                
            copia = copia->prox;
        }

        // cálculo do percentual
        printf("\n");
        for(int i = 0; i < qtd_destinos; i++){
            percentual = ((float)(destinos+i)->voos_pro_destino/tot_voos)*100;
            printf("%05.2f%% dos voos foram para o destino %s\n", (destinos+i)->destino, percentual);
        }
        printf("\n");

    } else 
        printf("Nao ha voos para esse intervalo de datas.\n");

    free(destinos);
}

void calculo_voos_destino(rotas_t *rota, verificacao_destinos_t **destinos, int *qtd_destinos){
    verificacao_destinos_t novo_destino;

    if(!*destinos){ // nenhum destino foi calculado ainda
        *destinos = calloc(1, sizeof(verificacao_destinos_t));
        
        strcpy(novo_destino.destino, rota->destino);
        novo_destino.voos_pro_destino = 1;

        *(*destinos) = novo_destino;
        *qtd_destinos += 1;
        return;
    }

    // se o destino já foi armazenado, incremento em 1 a quantidade de vezes que esse destino foi contado
    for(int i = 0; i < *qtd_destinos; i++){
        if(!strcmp(rota->destino, (*destinos+i)->destino)){
            (*destinos+i)->voos_pro_destino++;
            return;
        }
    }

    // se esse destino não foi registrado ainda, vamos registrá-lo
    *destinos = realloc(*destinos, sizeof(verificacao_destinos_t) * ((*qtd_destinos)+1));

    strcpy(novo_destino.destino, rota->destino);
    novo_destino.voos_pro_destino = 1;

    *(*destinos+*qtd_destinos) = novo_destino;
    *qtd_destinos += 1;

}
