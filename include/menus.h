#ifndef MENUS_H
#define MENUS_H

#include <stdio.h>
#include <stdbool.h>

int menu(void);
int submenu_aeronave_ou_rota(char* str, bool plural);
int submenu_cadastrar_inicio_fim(char* str);
int submenu_localizar_aeronaves(void);
int submenu_localizar_rotas(void);
int submenu_exportar_dados(void);

#endif
