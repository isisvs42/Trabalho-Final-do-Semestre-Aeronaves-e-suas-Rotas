#include "./include/apagar.h"
#include "./include/arquivo_bin.h"
#include "./include/cadastros.h"
#include "./include/exportar_dados.h"
#include "./include/listagens.h"
#include "./include/menus.h"
#include "./include/quantidades.h"
#include "./include/tipos.h"
#include "./include/uteis.h"

int main(){
    bool carga;
    string nome;
    data_t inicio, fim, data;
    fabricantes_t fabricante;
    situacao_t situacao;
    tipos_t tipo;
    unsigned int codigo_aeronave, codigo_rota;
    int opc_menu, opc_sub, opc_sub2, ano, numero, s_n;
    aeronaves_t *aeronave = NULL, *lista_aeronaves = NULL;
    rotas_t *rota = NULL, *lista_rotas = NULL;
    //rotas_t *maiores_rotas = NULL, *menores_rotas = NULL;

    ler_dados_arq_bin_aeronaves("aeronaves.bin", &lista_aeronaves);
    ler_dados_arq_bin_rotas("rotas.bin", &lista_rotas);

    do{
        opc_menu = menu();

        switch (opc_menu){

            case 0:
                salvar_dados_arq_bin_aeronaves(lista_aeronaves, "aeronaves.bin");
                salvar_dados_arq_bin_rotas(lista_rotas, "rotas.bin");
                printf("Encerrando programa...\n");
                pressione_enter();
                break;

            case 1: // CADASTRAR
                do {
                    opc_sub = submenu_cadastros();

                    switch (opc_sub) {

                        case 1: // CADASTRAR AERONAVE
                            do {
                                opc_sub2 = submenu_cadastrar_inicio_fim("AERONAVE");

                                switch (opc_sub2){
                                    case 1: // CADASTRAR AERONAVE PELO INICIO
                                        printf("Digite o codigo da aeronave: ");
                                        scanf("%u", &codigo_aeronave);
                                        getchar();
                                        aeronave = localizar_aeronave_por_codigo(codigo_aeronave, lista_aeronaves);
                                        if (!aeronave){ // se aeronave = NULL, ou seja, não foi registrada
                                            aeronave = nova_aeronave(codigo_aeronave);
                                            inserir_aeronave_pelo_inicio(aeronave, &lista_aeronaves);
                                        } else {
                                            printf("Aeronave ja foi registrada.\n");
                                            registrar_situacao(aeronave);
                                        }
                                        break;

                                    case 2: // CADASTRAR AERONAVE PELO FIM
                                        printf("Digite o codigo da aeronave: ");
                                        scanf("%u", &codigo_aeronave);
                                        getchar();
                                        aeronave = localizar_aeronave_por_codigo(codigo_aeronave, lista_aeronaves);
                                        if (!aeronave){ // se aeronave = NULL, ou seja, não foi registrada
                                            aeronave = nova_aeronave(codigo_aeronave);
                                            inserir_aeronave_pelo_fim(aeronave, &lista_aeronaves);
                                        } else {
                                            printf("Aeronave ja foi registrada.");
                                            registrar_situacao(aeronave);
                                        }
                                        break;

                                    case 0:
                                        printf("Voltando ao menu anterior...");
                                        pressione_enter();
                                        break;

                                    default:
                                        printf("Isso nao eh uma opcao;\n");
                                }
                            } while (opc_sub2);
                            break;
                        
                        case 2: // CADASTRAR ROTA
                            do {
                                opc_sub2 = submenu_cadastrar_inicio_fim("ROTA");

                                switch (opc_sub2){
                                    case 1: // CADASTRAR ROTA PELO INICIO
                                        printf("Digite o codigo da aeronave: ");
                                        scanf("%u", &codigo_aeronave);
                                        getchar();
                                        aeronave = localizar_aeronave_por_codigo(codigo_aeronave, lista_aeronaves);

                                        if (aeronave){ // se aeronave tem aeronave para relacionar à rota
                                            if(esta_operando(aeronave)){ // e não está em manutenção

                                                carga = eh_carga(aeronave);
                                                printf("Digite o codigo da rota: ");
                                                scanf("%u", &codigo_rota);
                                                getchar();
                                                rota = localizar_rota_por_codigo(codigo_rota, lista_rotas);

                                                if(!rota){ // se a rota não foi registrada
                                                    rota = nova_rota(codigo_aeronave, codigo_rota, carga);
                                                    inserir_rota_pelo_inicio(rota, &lista_rotas);
                                                } else {
                                                    printf("Esse codigo ja eh usado. Abortando insercao de rota...\n");
                                                    pressione_enter();
                                                }

                                            } else {
                                                printf("Essa aeronave esta em manutencao. Nao pode alocar rotas.\n");
                                                pressione_enter();
                                            }
                                        } else {
                                            printf("Aeronave inexistente.\n");
                                            pressione_enter();
                                        }

                                        break;

                                    case 2: // CADASTRAR ROTA PELO FIM
                                        printf("Digite o codigo da aeronave: ");
                                        scanf("%u", &codigo_aeronave);
                                        getchar();
                                        aeronave = localizar_aeronave_por_codigo(codigo_aeronave, lista_aeronaves);

                                        if (aeronave){ // se aeronave tem aeronave para relacionar à rota
                                            if(esta_operando(aeronave)){ // e não está em manutenção

                                                carga = eh_carga(aeronave);
                                                printf("Digite o codigo da rota: ");
                                                scanf("%u", &codigo_rota);
                                                getchar();
                                                rota = localizar_rota_por_codigo(codigo_rota, lista_rotas);

                                                if(!rota){ // se a rota não foi registrada
                                                    rota = nova_rota(codigo_aeronave, codigo_rota, carga);
                                                    inserir_rota_pelo_fim(rota, &lista_rotas);
                                                } else {
                                                    printf("Esse codigo ja eh usado. Abortando insercao de rota...\n");
                                                    pressione_enter();
                                                }

                                            } else {
                                                printf("Essa aeronave esta em manutencao. Nao pode alocar rotas.\n");
                                                pressione_enter();
                                            }
                                        } else {
                                            printf("Aeronave inexistente.\n");
                                            pressione_enter();
                                        }

                                        break;

                                    case 0:
                                        printf("Voltando ao menu anterior...");
                                        pressione_enter();
                                        break;

                                    default:
                                        printf("Isso nao eh uma opcao;\n");
                                }
                            } while (opc_sub2);
                            break;
                        
                        case 0:
                            printf("Voltando ao menu principal...");
                            pressione_enter();
                            break;

                        default:
                            printf("Isso nao eh uma opcao.\n");

                    }
                } while (opc_sub);
                break;

            case 2: // LOCALIZAR
                do {
                    opc_sub = submenu_localizar();

                    switch(opc_sub){
                        case 1: // LOCALIZAR AERONAVES
                            do {
                                opc_sub2 = submenu_localizar_aeronaves();

                                switch (opc_sub2){
                                    case 1: // prefixo
                                        printf("Digite o PREFIXO: ");
                                        fgets(nome, T_STRING, stdin);
                                        formatar_maiusculo(nome);
                                        retirar_enter(nome);
                                        listagem_aeronaves_prefixo(nome, lista_aeronaves);
                                        pressione_enter();
                                        break;

                                    case 2: // fabricante
                                        printf("Digite o FABRICANTE (1 - airbus/2 - boeing/ 3 - embraer): ");
                                        scanf("%i", &fabricante);
                                        getchar();
                                        listagem_aeronaves_fabricante(fabricante, lista_aeronaves);
                                        pressione_enter();
                                        break;

                                    case 3: // tipo
                                        printf("Digite o TIPO (1 = carga e 2 = passageiro): ");
                                        scanf("%i", &tipo);
                                        getchar();
                                        listagem_aeronaves_tipo(tipo, lista_aeronaves);
                                        pressione_enter();
                                        break;

                                    case 4: // modelo 
                                        printf("Digite o MODELO: ");
                                        fgets(nome, T_STRING, stdin);
                                        formatar_maiusculo(nome);
                                        retirar_enter(nome);
                                        listagem_aeronaves_modelo(nome, lista_aeronaves);
                                        pressione_enter();
                                        break;

                                    case 5: // ano de fabricacao
                                        printf("Digite o ANO DE FABRICACAO: ");
                                        scanf("%i", &ano);
                                        getchar();
                                        listagem_aeronaves_ano_fabricacao(ano, lista_aeronaves);
                                        pressione_enter();
                                        break;

                                    case 6: // situacao
                                        printf("Digite a SITUACAO (1 = em operacao/2 = em manutencao): ");
                                        scanf("%i", &situacao);
                                        getchar();
                                        listagem_aeronaves_situacao(situacao, lista_aeronaves);
                                        pressione_enter();
                                        break;

                                    case 0:
                                        printf("Voltando ao menu anterior...");
                                        pressione_enter();
                                        break;

                                    default:
                                        printf("Isso nao eh uma opcao.\n");
                                        pressione_enter();
                                }

                            } while (opc_sub2);
                            break;

                        case 2: // LOCALIZAR ROTAS
                            do {
                                opc_sub2 = submenu_localizar_rotas();
                                
                                switch (opc_sub2){
                                    case 1:
                                        printf("Digite uma DATA (dd/mm/aaaa): ");
                                        scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
                                        getchar();
                                        data.numero = data.ano*10000 + data.mes*100 + data.dia;

                                        listagem_rotas_data(data, lista_rotas);
                                        pressione_enter();
                                        break;

                                    case 2: // data
                                        printf("Digite uma DATA para o INICIO (dd/mm/aaaa): ");
                                        scanf("%d/%d/%d", &inicio.dia, &inicio.mes, &inicio.ano);
                                        getchar();
                                        inicio.numero = inicio.ano*10000 + inicio.mes*100 + inicio.dia;

                                        printf("Digite uma DATA para o FIM (dd/mm/aaaa): ");
                                        scanf("%d/%d/%d", &fim.dia, &fim.mes, &fim.ano);
                                        getchar();
                                        fim.numero = fim.ano*10000 + fim.mes*100 + fim.dia;

                                        listagem_rotas_intervalo_data(inicio, fim, lista_rotas);
                                        pressione_enter();

                                        break;

                                    case 3: // destino 
                                        printf("Digite um DESTINO: ");
                                        fgets(nome, T_STRING, stdin);
                                        retirar_enter(nome);
                                        formatar_maiusculo(nome);
                                        listagem_rotas_destino(nome, lista_rotas);
                                        pressione_enter();
                                        break;

                                    case 4: // origem
                                        printf("Digite um ORIGEM: ");
                                        fgets(nome, T_STRING, stdin);
                                        retirar_enter(nome);
                                        formatar_maiusculo(nome);
                                        listagem_rotas_origem(nome, lista_rotas);
                                        pressione_enter();
                                        break;

                                    case 5: // numero de passageiros
                                        printf("Digite um NUMERO DE PASSAGEIROS: ");
                                        scanf("%d", &numero);
                                        getchar();
                                        listagem_rotas_numero_passageiros(numero, lista_rotas);
                                        pressione_enter();
                                        break;

                                    case 6: // maior numero de passageiros
                                    
                                        /*numero = calculo_rotas_com_maior_n_pass(&maiores_rotas, lista_aeronaves, lista_rotas);
                                        listagem_rotas_maior_n_passageiros(maiores_rotas, numero);
                                        pressione_enter();*/

                                        mostrar_rota_maior_n_passageiros(lista_rotas);
                                        pressione_enter();

                                        break;

                                    case 7: // menor numero de passageiros

                                        /*numero = calculo_rotas_com_menor_n_pass(&menores_rotas, lista_aeronaves, lista_rotas);
                                        listagem_rotas_menor_n_passageiros(menores_rotas, numero);
                                        pressione_enter();*/

                                        mostrar_rota_menor_n_passageiros(lista_rotas);
                                        pressione_enter();

                                        break;

                                    case 0:
                                        printf("Voltando ao menu anterior...\n");
                                        pressione_enter();
                                    default:
                                }

                            } while (opc_sub2);
                            break;

                        case 0: 
                            printf("Voltando ao menu principal...\n");
                            pressione_enter();
                            break;
                        
                        default:
                            printf("Isso nao eh uma opcao\n");
                            break;
                    }
                } while (opc_sub);
                break;

            case 3: // LISTAR TUDO
                do {
                    opc_sub = submenu_listar_tudo();

                    switch(opc_sub){
                        case 1: // LISTAR TODAS AS AERONAVES
                            listar_aeronaves(lista_aeronaves);
                            pressione_enter();
                            break;

                        case 2: // LISTAR TODAS AS ROTAS
                            listar_rotas(lista_rotas);
                            pressione_enter();
                            break;

                        case 0:
                            printf("Voltando ao menu anterior.\n");
                            pressione_enter();
                            break;
                        
                        default:
                            printf("Isso nao eh uma opcao.\n");
                            pressione_enter();
                    }
                } while(opc_sub);
                break;

            case 4: // APAGAR AERONAVE
                listar_aeronaves(lista_aeronaves);
                printf("Digite o codigo da aeronave que deseja apagar: ");
                scanf("%u", &codigo_aeronave);
                do {
                    printf("Tem certeza que quer apagar aeronave %u (1 = sim/2 = nao)? ", codigo_aeronave);
                    scanf("%u", &s_n);
                } while (s_n < 1 || s_n > 2);
                pressione_enter();
                break;
            
            case 5: // EXPORTAR DADOS
                do {
                    opc_sub = submenu_exportar_dados();
                    
                    switch (opc_sub){
                        case 1: // ARQUIVO TXT
                            do {
                                opc_sub2 = submenu_exportar_quais_dados();
                                switch (opc_sub2){
                                    case 1: // exportar aeronaves
                                        printf("Digite um nome para o arquivo ser gerado (AERONAVES): ");
                                        fgets(nome, T_STRING, stdin);
                                        retirar_enter(nome);
                                        strcat(nome, ".txt");
                                        exportar_dados_arquivo_texto_aeronaves(nome, lista_aeronaves);
                                        pressione_enter();
                                        break;

                                    case 2: // exportar rotas
                                        printf("Digite um nome para o arquivo ser gerado (ROTAS): ");
                                        fgets(nome, T_STRING, stdin);
                                        retirar_enter(nome);
                                        strcat(nome, ".txt");
                                        exportar_dados_arquivo_texto_rotas(nome, lista_rotas);
                                        pressione_enter();
                                        break;

                                    case 0:
                                        printf("Voltando ao menu anterior...\n");
                                        pressione_enter();
                                        break;

                                    default:
                                        printf("Isso nao eh uma opcao.\n");
                                        pressione_enter();
                                }
                            } while (opc_sub2);
                            break;

                        case 2: // PLANILHA CSV
                            do {
                                opc_sub2 = submenu_exportar_quais_dados();
                                switch (opc_sub2){
                                    case 1: // exportar aeronaves
                                        printf("Digite um nome para o arquivo ser gerado (AERONAVES): ");
                                        fgets(nome, T_STRING, stdin);
                                        retirar_enter(nome);
                                        strcat(nome, ".csv");
                                        exportar_dados_arquivo_csv_aeronaves(nome, lista_aeronaves);
                                        pressione_enter();
                                        break;

                                    case 2: // exportar rotas
                                        printf("Digite um nome para o arquivo ser gerado (ROTAS): ");
                                        fgets(nome, T_STRING, stdin);
                                        retirar_enter(nome);
                                        strcat(nome, ".csv");
                                        exportar_dados_arquivo_csv_rotas(nome, lista_rotas);
                                        pressione_enter();
                                        break;

                                    case 0:
                                        printf("Voltando ao menu anterior...\n");
                                        pressione_enter();
                                        break;

                                    default:
                                        printf("Isso nao eh uma opcao.\n");
                                        pressione_enter();
                                }
                            } while (opc_sub2);
                            break;

                        case 3: // HTML
                            do {
                                opc_sub2 = submenu_exportar_quais_dados();
                                switch (opc_sub2){
                                    case 1: // exportar aeronaves
                                        printf("Digite um nome para o arquivo ser gerado (AERONAVES): ");
                                        fgets(nome, T_STRING, stdin);
                                        retirar_enter(nome);
                                        strcat(nome, ".html");
                                        exportar_dados_arquivo_html_aeronaves(nome, lista_aeronaves);
                                        pressione_enter();
                                        break;

                                    case 2: // exportar rotas
                                        printf("Digite um nome para o arquivo ser gerado (ROTAS): ");
                                        fgets(nome, T_STRING, stdin);
                                        retirar_enter(nome);
                                        strcat(nome, ".html");
                                        exportar_dados_arquivo_html_rotas(nome, lista_rotas);
                                        pressione_enter();
                                        break;

                                    case 0:
                                        printf("Voltando ao menu anterior...\n");
                                        pressione_enter();
                                        break;

                                    default:
                                        printf("Isso nao eh uma opcao.\n");
                                        pressione_enter();
                                }
                            } while (opc_sub2);
                            break;

                        case 0:
                            printf("Voltando ao menu principal...\n");
                            pressione_enter();
                            break;

                        default:
                            printf("Isso nao eh uma opcao\n");
                            pressione_enter();
                    }
                   

                } while (opc_sub);
                break;

            case 6: // PERCENTUAL DE VOOS POR DESTINO EM INTERVALO DE DATA
                printf("Digite uma DATA para o INICIO (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &inicio.dia, &inicio.mes, &inicio.ano);
                getchar();
                inicio.numero = inicio.ano*10000 + inicio.mes*100 + inicio.dia;

                printf("Digite uma DATA para o FIM (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &fim.dia, &fim.mes, &fim.ano);
                getchar();
                fim.numero = fim.ano*10000 + fim.mes*100 + fim.dia;

                percentual_de_voos_por_destino_em_intervalo_de_datas(inicio, fim, lista_rotas);
                pressione_enter();
                break;

            case 7: // PERCENTUAL DE VOOS REALIZADO POR AERONAVE
                percentual_de_voos_realizado_por_aeronave(lista_aeronaves, lista_rotas);
                pressione_enter();
                break;

            case 8: // QUANTIDADE DE VEZES QUE UMA AERONAVE ENTROU EM MANUTENÇÃO
                printf("Digite o código da aeronave para descobrir quantas vezes ela entrou em manutencao: ");
                scanf("%u", &codigo_aeronave);
                getchar();
                aeronave = localizar_aeronave_por_codigo(codigo_aeronave, lista_aeronaves);
                printf("Essa aeronave entrou em manutencao %i vezes.\n", aeronave->vezes_que_entrou_em_manutenção);
                pressione_enter();
                break;

            case 9: // CONSUMO TOTAL DE COMBUSTÍVEL EM INTERVALO DE DATAS
                printf("Digite uma DATA para o INICIO (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &inicio.dia, &inicio.mes, &inicio.ano);
                getchar();
                inicio.numero = inicio.ano*10000 + inicio.mes*100 + inicio.dia;

                printf("Digite uma DATA para o FIM (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &fim.dia, &fim.mes, &fim.ano);
                getchar();
                fim.numero = fim.ano*10000 + fim.mes*100 + fim.dia;

                consumo_total_de_combustivel_em_intervalo_de_datas(inicio, fim, lista_rotas);
                pressione_enter();
                break;

            default:
                printf("Isso nao eh uma opcao.\n");
                pressione_enter();

        }
    } while(opc_menu);

    return 0;
}
