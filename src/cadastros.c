#include "../include/tipos.h"
#include "../include/cadastros.h"
#include "../include/uteis.h"
#include <string.h>
#include <ctype.h>

// cadastro de aeronave
aeronaves_t *localizar_aeronave_por_codigo(unsigned int codigo_aeronave, aeronaves_t *lista_aeronaves){
    // versão recursiva

    //      DEFINITIVAMENTE NÃO ACHEI
    if(!lista_aeronaves) return NULL;

    //      ACHEI
    if(codigo_aeronave == lista_aeronaves->codigo_aeronave) return lista_aeronaves;

    //      AINDA NÃO ACHEI
    return localizar_aeronave_por_codigo(codigo_aeronave, lista_aeronaves->prox);

    /* versão iterativa
        while (lista_aeronaves){
        if (codigo_aeronave == lista_aeronaves->codigo_aeronave)
            return lista_aeronaves;
        lista_aeronaves = lista_aeronaves->prox;
    }
    return NULL;*/
}

aeronaves_t *nova_aeronave(unsigned int codigo_aeronave){
    aeronaves_t *aeronave = NULL;

    aeronave = calloc(1, sizeof(aeronaves_t));

    aeronave->codigo_aeronave = codigo_aeronave;

    registrar_fabricante(aeronave); // passo o endereço de onde está a aeronave na heap

    printf("Modelo: ");
    fgets(aeronave->modelo, T_STRING, stdin);
    retirar_enter(aeronave->modelo);
    formatar_maiusculo(aeronave->modelo);

    printf("Prefixo: ");
    fgets(aeronave->prefixo, T_STRING, stdin);
    retirar_enter(aeronave->prefixo);
    formatar_maiusculo(aeronave->prefixo);

    printf("Ano de fabricacao: ");
    scanf("%u", &aeronave->ano_de_fabricacao);
    getchar();

    registrar_tipo(aeronave);

    aeronave->situacao = 1;
    aeronave->vezes_que_entrou_em_manutenção = 0;
    registrar_situacao(aeronave);

    printf("Tripulacao necessaria: ");
    scanf("%i", &aeronave->tripulacao_necessaria);
    getchar();

    aeronave->prox = NULL;

    printf("Aeronave registrada. Pressione enter para continuar...\n");
    getchar();

    return aeronave; // retorna o endereço de todos os dados dessa nova aeronave que foram guardados na heap
}

void registrar_fabricante(aeronaves_t *aeronave){
    fabricantes_t fabricante;
    do {
        printf("--------- Fabricantes possíveis ---------\n");
        printf("1. Airbus;\n");
        printf("2. Boeing;\n");
        printf("3. Embraer;\n");
        printf("-----------------------------------------\n");
        printf("Fabricante: ");
        scanf("%i", &fabricante);
        getchar();
    } while(fabricante < 1 || fabricante > 3);

    aeronave->fabricante = fabricante;
}

void registrar_tipo(aeronaves_t *aeronave){
    tipos_t tipo;
    do {
        printf("Tipo (1 = de carga/2 = de passageiros): ");
        scanf("%i", &tipo);
        getchar();
        switch (tipo) {
            case 1:
                aeronave->n_passageiros_max = 0;
                break;
            case 2:
                printf("Capacidade de passageiros: ");
                scanf("%i", &aeronave->n_passageiros_max);
                break;
            
            default:
                printf("Isso nao eh uma opcao.");
        }
    } while(tipo < 1 || tipo > 2);

    aeronave->tipo = tipo;
}

void registrar_situacao(aeronaves_t *aeronave){
    situacao_t situacao;
    do {
        printf("Situacao (1 = em operacao/2 = em manutencao): ");
        scanf("%i", &situacao);
        getchar();

        if(situacao == 2 && aeronave->situacao == 1)
            aeronave->vezes_que_entrou_em_manutenção++;

        if(situacao < 1 || situacao > 2)
            printf("Isso nao eh uma opcao.\n");
        
    } while(situacao < 1 || situacao > 2);

    aeronave->situacao = situacao;
}

void inserir_aeronave_pelo_inicio(aeronaves_t *aeronave, aeronaves_t **end_lista_aeronaves){
    if(*end_lista_aeronaves) // se a lista NÃO estiver vazia
        aeronave->prox = *end_lista_aeronaves; // o próximo da aeronave inserida é a antiga primeira aeronave

    *end_lista_aeronaves = aeronave; // o ponteiro lista_aeronaves aponta para a nova aeronave
}

void inserir_aeronave_pelo_fim(aeronaves_t *aeronave, aeronaves_t **end_lista_aeronaves){
    aeronaves_t *ultima_aeronave = NULL;
    ultima_aeronave = localizar_ultima_aeronave(*end_lista_aeronaves);

    if (ultima_aeronave) // se existe uma última aeronave
        ultima_aeronave->prox = aeronave; // a seguinte passa a ser a nova aeronave registrada

    else // não tem uma última aeronave; a lista está vazia
        *end_lista_aeronaves = aeronave;
}

aeronaves_t* localizar_ultima_aeronave(aeronaves_t *lista_aeronaves){
    while (lista_aeronaves){
        if(!lista_aeronaves->prox) // se o próximo da aeronave é NULL
            return lista_aeronaves; // então ela é a última da lista

        lista_aeronaves = lista_aeronaves->prox;
    }
    return NULL;
}

// cadastro de rotas
rotas_t *nova_rota(aeronaves_t* aeronave, unsigned int codigo_rota, bool carga){
    rotas_t *rota = NULL;

    rota = calloc(1, sizeof(rotas_t));

    rota->codigo_da_aeronave = aeronave->codigo_aeronave;
    rota->codigo_da_rota = codigo_rota;
    rota->n_tripulacao = aeronave->tripulacao_necessaria;
    
    printf("Data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &rota->data.dia, &rota->data.mes, &rota->data.ano);
    getchar();
    rota->data.numero = rota->data.ano*10000 + rota->data.mes*100 + rota->data.dia;

    printf("Hora (hh:mm): ");
    scanf("%d:%d", &rota->hora.horas, &rota->hora.minutos);
    getchar();

    printf("Origem: ");
    fgets(rota->origem, T_STRING, stdin);
    retirar_enter(rota->origem);
    formatar_maiusculo(rota->origem);

    printf("Destino: ");
    fgets(rota->destino, T_STRING, stdin);
    retirar_enter(rota->destino);
    formatar_maiusculo(rota->destino);

    printf("Tempo estimado de voo (em h): ");
    scanf("%u", &rota->tempo_estimado_de_voo);
    getchar();

    printf("Combustivel necessario (em L): ");
    scanf("%f", &rota->combustivel_necessario);
    getchar();

    if(carga){ // se é de carga 
        printf("Quantidade de carga (em kg): ");
        scanf("%u", &rota->n_carga);
        getchar();
        rota->n_passageiros = 0; // nada de passageiros

    } else { 
        do {
            printf("Quantidade de passageiros: ");
            scanf("%u", &rota->n_passageiros);
            getchar();
            if(rota->n_passageiros > aeronave->n_passageiros_max){
                printf("Nao eh possivel a aeronave ter %i passageiros. O maximo eh %i\n", rota->n_passageiros, aeronave->n_passageiros_max);
                printf("Tente de novo...\n");
            }
        } while(rota->n_passageiros > aeronave->n_passageiros_max);
        rota->n_carga = 0; // nada de carga
    }

    registrar_nomes_tripulacao(rota, rota->n_tripulacao);

    printf("Rota registrada. Pressione enter para continuar...\n");
    getchar();

    rota->prox = NULL;

    return rota;
}

void registrar_nomes_tripulacao(rotas_t* rota, int n_tripulacao){
    string nome;

    printf("--> Estaremos agora registrando os nomes da tripulacao.\n");
    pressione_enter();

    for(int i = 0; i < n_tripulacao; i++){
        printf("Digite o nome do membro n%i: ", i+1);
        fgets(nome, T_STRING, stdin);
        retirar_enter(nome);
        formatar_maiusculo(nome);
        strcpy(rota->nomes_tripulacao[i], nome);
    }
}

rotas_t *localizar_rota_por_codigo(unsigned int codigo_rota, rotas_t *lista_rotas){
    // versão recursiva

    //      DEFINITIVAMENTE NÃO ACHEI
    if(!lista_rotas) return NULL;

    //      ACHEI
    if(codigo_rota == lista_rotas->codigo_da_rota) return lista_rotas;

    //      AINDA NÃO ACHEI
    return localizar_rota_por_codigo(codigo_rota, lista_rotas->prox);
    
    
    /* versão iterativa
        while(lista_rotas){
        if(lista_rotas->codigo_da_rota == codigo_rota)
            return lista_rotas;

        lista_rotas = lista_rotas->prox;
    }
    return NULL;*/
}

bool eh_carga(aeronaves_t *aeronave){
    if(aeronave->tipo == 1)
        return true;
    return false;
}

bool esta_operando(aeronaves_t *aeronave){
    if(aeronave->situacao == 1)
        return true;
    return false;
}

void inserir_rota_pelo_inicio(rotas_t *rota, rotas_t **end_lista_rotas){
    if(*end_lista_rotas)
        rota->prox = *end_lista_rotas;

    *end_lista_rotas = rota;
}

void inserir_rota_pelo_fim(rotas_t *rota, rotas_t **end_lista_rotas){
    rotas_t *ultima_rota = NULL;
    ultima_rota = localizar_ultima_rota(*end_lista_rotas);

    if (ultima_rota) 
       ultima_rota->prox = rota;

    else
        *end_lista_rotas = rota;
}

rotas_t* localizar_ultima_rota(rotas_t *lista_rotas){
    while (lista_rotas){
        if(!lista_rotas->prox) 
            return lista_rotas;

        lista_rotas = lista_rotas->prox;
    }
    return NULL;
}
