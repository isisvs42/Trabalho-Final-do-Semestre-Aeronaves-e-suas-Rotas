#include "../include/listagens.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// mostrar aeronaves
void listar_aeronaves(aeronaves_t *lista){
    while(lista){
        mostrar_aeronave(lista, stdout);
        lista = lista->prox;
    }
}

void mostrar_aeronave(aeronaves_t *aeronave, FILE *fp){
    fprintf(fp, "Identificacao.................... %u\n", aeronave->codigo_aeronave);
    fprintf(fp, "Fabricante....................... "); mostrar_fabricante(aeronave->fabricante, fp);
    fprintf(fp, "Modelo........................... %s\n", aeronave->modelo);
    fprintf(fp, "Prefixo.......................... %s\n", aeronave->prefixo);
    fprintf(fp, "Ano de fabricacao................ %i\n", aeronave->ano_de_fabricacao);
    fprintf(fp, "Tipo............................. "); mostrar_tipo(aeronave->tipo, fp);
    fprintf(fp, "Situacao......................... "); mostrar_situacao(aeronave->situacao, fp);
    fprintf(fp, "Tripulacao necessaria............ %i\n", aeronave->tripulacao_necessaria);
    fprintf(fp, "\n");
}

void mostrar_fabricante(fabricantes_t fabricante, FILE *fp){
    switch (fabricante){
        case AIRBUS:
            fprintf(fp, "Airbus\n");
            break;
        
        case BOEING:
            fprintf(fp, "Boeing\n");
            break;

        case EMBRAER:
            fprintf(fp, "Embraer\n");
            break;
    }
}

void mostrar_tipo(tipos_t tipo, FILE *fp){
    switch(tipo){
        case CARGA:
            fprintf(fp, "Carga\n");
            break;
        case PASSAGEIRO:
            fprintf(fp, "Passageiro\n");
            break;
    }
}

void mostrar_situacao(situacao_t situacao, FILE *fp){
    switch (situacao){
        case OPERACAO:
            fprintf(fp, "Em operacao\n");
            break;
        
        case MANUTENCAO:
            fprintf(fp, "Em manutencao\n");
            break;
        }
}

// listagens de aeronaves
void listagem_aeronaves_prefixo(string prefixo, aeronaves_t *lista){
    bool flag = false;
    while(lista){
        if(!strcmp(lista->prefixo, prefixo)){
            mostrar_aeronave(lista, stdout);
            flag = true;
        }
        lista = lista->prox;
    }
    if(!flag)
        printf("Nenhuma aeronave encontrada.\n");
}

void listagem_aeronaves_fabricante(fabricantes_t fabricante, aeronaves_t *lista){
    bool flag = false;
    while(lista){
        if(fabricante == lista->fabricante){
            mostrar_aeronave(lista, stdout);
            flag = true;
        }
        lista = lista->prox;
    }
    if(!flag)
        printf("Nenhuma aeronave encontrada.\n");
}

void listagem_aeronaves_tipo(tipos_t tipo, aeronaves_t *lista){
    bool flag = false;
    while(lista){
        if(tipo == lista->tipo){
            mostrar_aeronave(lista, stdout);
            flag = true;
        }
        lista = lista->prox;
    }
    if(!flag)
        printf("Nenhuma aeronave encontrada.\n");
} 

void listagem_aeronaves_modelo(string modelo, aeronaves_t *lista){
    bool flag = false;
    while(lista){
        if(!strcmp(lista->modelo, modelo)){
            mostrar_aeronave(lista, stdout);
            flag = true;
        }
        lista = lista->prox;
    }
    if(!flag)
        printf("Nenhuma aeronave encontrada.\n");    
}

void listagem_aeronaves_ano_fabricacao(int ano, aeronaves_t *lista){
    bool flag = false;
    while(lista){
        if(ano == lista->ano_de_fabricacao){
            mostrar_aeronave(lista, stdout);
            flag = true;
        }
        lista = lista->prox;
    }
    if(!flag)
        printf("Nenhuma aeronave encontrada.\n");
}

void listagem_aeronaves_situacao(situacao_t situacao, aeronaves_t *lista){
    bool flag = false;
    while(lista){
        if(situacao == lista->situacao){
            mostrar_aeronave(lista, stdout);
            flag = true;
        }
        lista = lista->prox;
    }
    if(!flag)
        printf("Nenhuma aeronave encontrada.\n");
}

// mostrar rotas
void mostrar_rota(rotas_t *rota, FILE *fp){
    fprintf(fp, "Codigo da aeronave alocada........ %u\n", rota->codigo_da_aeronave);
    fprintf(fp, "Codigo da rota.................... %u\n", rota->codigo_da_rota);
    fprintf(fp, "Data.............................. %02d/%02d/%02d\n", rota->data.dia, rota->data.mes, rota->data.ano);
    fprintf(fp, "Hora.............................. %02d:%02d\n", rota->hora.horas, rota->hora.minutos);
    fprintf(fp, "Origem............................ %s\n", rota->origem);
    fprintf(fp, "Destino........................... %s\n", rota->destino);
    fprintf(fp, "Tempo de voo (em h)............... %u\n", rota->tempo_estimado_de_voo);
    fprintf(fp, "Combustivel necessario............ %.2f\n", rota->combustivel_necessario);
    fprintf(fp, "N passageiros..................... %u\n", rota->n_passageiros);
    fprintf(fp, "N carga........................... %u\n", rota->n_carga);
    //mostrar_nomes_tripulacao(rota->identificacao, rota, lista_aeronaves);
    fprintf(fp, "\n");
}

void listar_rotas(rotas_t *lista){
    while(lista){
        mostrar_rota(lista, stdout);
        lista = lista->prox;
    }
}

// listagens de rotas
void listagem_rotas_data(data_t data, rotas_t *lista_rotas){
    bool flag = false;
    while(lista_rotas){
        if(data.numero == lista_rotas->data.numero){
            mostrar_rota(lista_rotas, stdout);
            flag = true;
        }
        lista_rotas = lista_rotas->prox;
    }
    if(!flag)
        printf("Nenhuma rota encontrada.\n"); 
}

void listagem_rotas_intervalo_data(data_t inicio, data_t fim, rotas_t *lista_rotas){
    bool flag = false;
    while(lista_rotas){
        if(inicio.numero <= lista_rotas->data.numero && lista_rotas->data.numero <= fim.numero){
            mostrar_rota(lista_rotas, stdout);
            flag = true;
        }
        lista_rotas = lista_rotas->prox;
    }
    if(!flag)
        printf("Nenhuma rota encontrada.\n"); 
}

void listagem_rotas_destino(string destino, rotas_t *lista_rotas){
    bool flag = false;
    while(lista_rotas){
        if(!strcmp(lista_rotas->destino, destino)){
            mostrar_rota(lista_rotas, stdout);
            flag = true;
        }
        lista_rotas = lista_rotas->prox;
    }
    if(!flag)
        printf("Nenhuma rota encontrada.\n");    
}

void listagem_rotas_origem(string origem, rotas_t *lista_rotas){
        bool flag = false;
    while(lista_rotas){
        if(!strcmp(lista_rotas->origem, origem)){
            mostrar_rota(lista_rotas, stdout);
            flag = true;
        }
        lista_rotas = lista_rotas->prox;
    }
    if(!flag)
        printf("Nenhuma rota encontrada.\n");   
}

void listagem_rotas_numero_passageiros(int n_passageiros, rotas_t *lista_rotas){
    bool flag = false;
    while(lista_rotas){
        if(n_passageiros == lista_rotas->n_passageiros){
            mostrar_rota(lista_rotas, stdout);
            flag = true;
        }
        lista_rotas = lista_rotas->prox;
    }
    if(!flag)
        printf("Nenhuma rota encontrada.\n");   
}

/*int calculo_rotas_com_maior_n_pass(rotas_t **maiores_rotas, aeronaves_t *lista_aeronaves, rotas_t *lista_rotas){
    int k, maior;
    rotas_t *maior_rota = NULL, *rota = NULL;
    aeronaves_t *aeronave = NULL;

    for(aeronave = lista_aeronaves, k = 0; aeronave != NULL; aeronave = aeronave->prox, k++){
        maior = -1;

        for(rota = lista_rotas; rota!=NULL; rota = rota->prox){
            
            if(rota->codigo_da_aeronave == aeronave->codigo_aeronave){ // se a rota pertence à aeronave
                if(rota->n_passageiros >= maior){
                    maior_rota = rota;
                    maior = rota->n_passageiros;
                }
            }
        }

        if(!*maiores_rotas){
            *maiores_rotas = calloc(1, sizeof(rotas_t));
            *(*maiores_rotas) = *maior_rota;
        } else {
            *maiores_rotas = realloc(*maiores_rotas, sizeof(rotas_t)*(k+1));
            *(*maiores_rotas+k) = *maior_rota;
        }
    }

    return k;
}

void listagem_rotas_maior_n_passageiros(rotas_t *maiores_rotas, int k){
    for(int i = 0; i < k; i++){
        printf("Aeronave n%i (%u).......................................... Rota com maior numero de passageiros: %u (n = %i)\n", 
        i+1, (maiores_rotas+i)->codigo_da_aeronave, (maiores_rotas+i)->codigo_da_rota, (maiores_rotas+i)->n_passageiros);
    }
    free(maiores_rotas);
}

int calculo_rotas_com_menor_n_pass(rotas_t **menores_rotas, aeronaves_t *lista_aeronaves, rotas_t *lista_rotas){
    int k, menor;
    rotas_t *menor_rota = NULL, *rota = NULL;
    aeronaves_t *aeronave = NULL;

    for(aeronave = lista_aeronaves, k = 0; aeronave != NULL; aeronave = aeronave->prox, k++){
        menor = 999999;

        for(rota = lista_rotas; rota!=NULL; rota = rota->prox){
            
            if(rota->codigo_da_aeronave == aeronave->codigo_aeronave){ // se a rota pertence à aeronave
                if(rota->n_passageiros <= menor){
                    menor_rota = rota;
                    menor = rota->n_passageiros;
                }
            }
        }

        if(!*menores_rotas){
            *menores_rotas = calloc(1, sizeof(rotas_t));
            *(*menores_rotas) = *menor_rota;
        } else {
            *menores_rotas = realloc(*menores_rotas, sizeof(rotas_t)*(k+1));
            *(*menores_rotas+k) = *menor_rota;
        }
    }

    return k;
}

void listagem_rotas_menor_n_passageiros(rotas_t *menores_rotas, int k){
    for(int i = 0; i < k; i++){
        printf("Aeronave n%i (%u).......................................... Rota com maior numero de passageiros: %u (n = %i)\n", 
        i+1, (menores_rotas+i)->codigo_da_aeronave, (menores_rotas+i)->codigo_da_rota, (menores_rotas+i)->n_passageiros);
    }
    free(menores_rotas);
}*/

void mostrar_rota_maior_n_passageiros(rotas_t *lista_rotas){
    // cálculo da maior rota
    rotas_t *maior_rota = NULL;
    int maior_passageiros = 0;
    
    while(lista_rotas){
        if(lista_rotas->n_passageiros >= maior_passageiros){
            maior_passageiros = lista_rotas->n_passageiros;
            maior_rota = lista_rotas;
        }
        
        lista_rotas = lista_rotas->prox;

    }
    
    // mostra a maior rota
    mostrar_rota(maior_rota, stdout);

}

void mostrar_rota_menor_n_passageiros(rotas_t *lista_rotas){
    // cálculo da menor rota
    rotas_t *menor_rota = NULL;
    int menor_passageiros = 99999999;
    
    while(lista_rotas){
        if(lista_rotas->n_passageiros <= menor_passageiros && lista_rotas->n_passageiros != 0){ // diferente de 0 exclui as aeronaves de carga
            menor_passageiros = lista_rotas->n_passageiros;
            menor_rota = lista_rotas;
        }
        
        lista_rotas = lista_rotas->prox;

    }
    
    // mostra a menor rota
    mostrar_rota(menor_rota, stdout);
}
