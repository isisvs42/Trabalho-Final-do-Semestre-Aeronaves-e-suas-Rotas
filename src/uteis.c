#include "../include/uteis.h"

// úteis
void pressione_enter(){
    printf("\nPressione ENTER para continuar... ");
    getchar();
}

void limpar_terminal(){
    system("clear");
}

void retirar_enter(char* str){
    *(str + strlen(str)-1) = '\0';
}

void formatar_maiusculo(char *str){
    for(int i = 0; i < strlen(str); i++)
        *(str+i) = toupper(*(str+i));
}
