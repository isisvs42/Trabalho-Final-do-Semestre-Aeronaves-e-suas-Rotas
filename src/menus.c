#include "../include/menus.h"
#include "../include/uteis.h"

// menu e submenus
int menu(){
    limpar_terminal();
    int opc;
    printf("1. Cadastrar;\n");
    printf("2. Localizar;\n");
    printf("3. Listar tudo;\n");
    printf("4. Apagar aeronave;\n");
    printf("5. Exportar dados;\n");
    printf("6. Percentual de Voos por Destino em Intervalo de Datas;\n");
    printf("7. Percentual de Voos Realizado por Aeronave;\n");
    printf("8. Quantidade de Vezes que uma Aeronave entrou em Manutencao;\n");
    printf("9. Consumo Total de Combustivel em Intervalo de Datas;\n");
    printf("0. Sair do programa.\n");
    printf("::::::: ");
    scanf("%d", &opc);
    getchar();

    return opc;
}

int submenu_cadastros(){
    limpar_terminal();
    int opc;
    printf("1. Cadastrar aeronave;\n");
    printf("2. Cadastrar rota;\n");
    printf("0. Voltar.\n");
    printf("::::::: ");
    scanf("%d", &opc);
    getchar();
    return opc;
}

int submenu_cadastrar_inicio_fim(char* a_r){
    limpar_terminal();
    int opc;
    printf("1. Cadastrar %s pelo inicio;\n", a_r);
    printf("2. Cadastrar %s pelo fim;\n", a_r);
    printf("0. Voltar.\n");
    printf("::::::: ");
    scanf("%d", &opc);
    getchar();
    return opc;  
}

int submenu_localizar(){
    limpar_terminal();
    int opc;
    printf("1. Localizar aeronaves;\n");
    printf("2. Localizar rotas;\n");
    printf("0. Voltar.\n");
    printf("::::::: ");
    scanf("%d", &opc);
    getchar();
    return opc;
}

int submenu_localizar_aeronaves(){
    limpar_terminal();
    int opc;
    printf("1. Listagem de Aeronaves por Prefixo;\n");
    printf("2. Listagem de Aeronaves por Fabricante;\n");
    printf("3. Listagem de Aeronaves por Tipo;\n");
    printf("4. Listagem de Aeronaves por Modelo;\n");
    printf("5. Listagem de Aeronaves por Ano de Fabricacao;\n");
    printf("6. Listagem de Aeronaves por Situacao;\n");
    printf("0. Voltar.\n");
    printf("::::::: ");
    scanf("%d", &opc);
    getchar();
    return opc;
}

int submenu_localizar_rotas(){
    limpar_terminal();
    int opc;
    printf("1. Listagem de Rotas por Data;\n");
    printf("2. Listagem de Rotas em Intervalo de Datas;\n");
    printf("3. Listagem de Rotas por Destino;\n");
    printf("4. Listagem de Rotas por Origem;\n");
    printf("5. Listagem de Rotas por Numero de Passageiros;\n");
    printf("6. Mostrar Rota com Maior Numero de Passageiros;\n");
    printf("7. Mostrar Rota com Menor Numero de Passageiros;\n");
    printf("0. Voltar.\n");
    printf("::::::: ");
    scanf("%d", &opc);
    getchar();
    return opc;
}

int submenu_listar_tudo(){
    limpar_terminal();
    int opc;
    printf("1. Listar Todas as Aeronaves Cadastradas;\n");
    printf("2. Listar Todas as Rotas Cadastradas;\n");
    printf("0. Voltar.\n");
    printf("::::::: ");
    scanf("%d", &opc);
    getchar();
    return opc;
}

int submenu_exportar_dados(){
    limpar_terminal();
    int opc;
    printf("1. Exportar dados para arquivo txt;\n");
    printf("2. Exportar dados para planilha Excel (csv);\n");
    printf("3. Exportar para HTMl;\n");
    printf("0. Voltar.\n");
    printf("::::::: ");
    scanf("%d", &opc);
    getchar();
    return opc;
}

int submenu_exportar_quais_dados(){
    limpar_terminal();
    int opc;
    printf("1. Exportar AERONAVES;\n");
    printf("2. Exportar ROTAS;\n");
    printf("0. Voltar.\n");
    printf("::::::: ");
    scanf("%d", &opc);
    getchar();
    return opc;
}

