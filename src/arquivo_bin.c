#include "../include/arquivo_bin.h"
#include "../include/cadastros.h"

void salvar_dados_arq_bin_aeronaves(aeronaves_t *lista, string nome_arq){
    FILE *fp_arquivo = NULL;
    
    fp_arquivo = fopen(nome_arq, "wb");

    if (!fp_arquivo)
        printf("Erro ao tentar abrir arquivo bin %s.\n", nome_arq);

    while (lista){
        fwrite(lista, sizeof(aeronaves_t), 1, fp_arquivo);
        lista = lista->prox;
    }

    fclose(fp_arquivo);
}

void ler_dados_arq_bin_aeronaves(string nome_arq, aeronaves_t **lista){
    FILE *fp_arquivo = NULL;
    aeronaves_t *aeronave = NULL;
    
    fp_arquivo = fopen(nome_arq, "rb");

    while(!feof(fp_arquivo)){
        aeronave = calloc(1, sizeof(aeronaves_t));
        fread(aeronave, sizeof(aeronaves_t), 1, fp_arquivo);
        aeronave->prox = NULL;

        if(!feof(fp_arquivo)) // vai inserindo enquanto o ponteiro não aponta para EOF
            inserir_aeronave_pelo_fim(aeronave, lista);
        else
            free(aeronave); // apaga o EOF da lista
        
    }

    fclose(fp_arquivo);

}

void salvar_dados_arq_bin_rotas(rotas_t *lista, string nome_arq){
    FILE *fp_arquivo = NULL;

    fp_arquivo = fopen(nome_arq, "wb");

    if (!fp_arquivo)
        printf("Erro ao tentar abrir arquivo bin %s.\n", nome_arq);

    while(lista){
        fwrite(lista, sizeof(rotas_t), 1, fp_arquivo);
        lista = lista->prox;
    }

    fclose(fp_arquivo);

}

void ler_dados_arq_bin_rotas(string nome_arq, rotas_t **lista){
    FILE *fp_arquivo = NULL;
    rotas_t *rota = NULL;

    fp_arquivo = fopen(nome_arq, "rb");

    while(!feof(fp_arquivo)){
        rota = calloc(1, sizeof(rotas_t));
        fread(rota, sizeof(rotas_t), 1, fp_arquivo);
        rota->prox = NULL;

        if (!feof(fp_arquivo))
            inserir_rota_pelo_fim(rota, lista);
        else
            free(rota);
    }

    fclose(fp_arquivo);
    
}
