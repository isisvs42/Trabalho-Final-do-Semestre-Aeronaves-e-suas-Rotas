#include "../include/apagar.h"

// apagar aeronave
void apagar_aeronave(aeronaves_t *aeronave, aeronaves_t **lista_aeronaves){
    aeronaves_t *anterior = NULL;

    // verifica se o dado a ser apagado é o primeiro da lista
    if (*lista_aeronaves == aeronave){

        *lista_aeronaves = aeronave->prox;

    } else {
        
        anterior = localizar_aeronave_anterior(aeronave, *lista_aeronaves);
        anterior->prox = aeronave->prox;

    }
    
    free(aeronave);
}

aeronaves_t* localizar_aeronave_anterior(aeronaves_t *aeronave, aeronaves_t *lista_aeronaves){
    if(aeronave == lista_aeronaves){
        return lista_aeronaves;
    }

    while(lista_aeronaves) {
        if(lista_aeronaves->prox == aeronave)
            return lista_aeronaves;
        lista_aeronaves = lista_aeronaves->prox;
     }
}

void apagar_rota(rotas_t *rota, rotas_t **lista_rotas){
    rotas_t *anterior = NULL;
    
    if(rota == *lista_rotas)
        *lista_rotas = rota->prox;
    else {
        anterior = localizar_rota_anterior(rota, *lista_rotas);
        anterior->prox = rota->prox;
    }

    free(rota);
}

rotas_t* localizar_rota_anterior(rotas_t *rota, rotas_t *lista_rotas){
    if(rota == lista_rotas){
        return lista_rotas;
    }

    while(lista_rotas){
        if(lista_rotas->prox == rota)
            return lista_rotas;
        lista_rotas = lista_rotas->prox;
    }
}
