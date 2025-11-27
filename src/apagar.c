#include "../include/apagar.h"

// apagar aeronave
void apagar_aeronave(aeronaves_t *aeronave, aeronaves_t **lista_aeronaves){
    aeronaves_t *anterior = NULL;

    // verifica se o dado a ser apagado é o primeiro da lista
    if (*lista_aeronaves == aeronave){

        *lista_aeronaves = aeronave->prox;

    } else {
        
        anterior = localizar_anterior(aeronave, *lista_aeronaves);
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
