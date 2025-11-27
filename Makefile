# pasta onde ficam os arquivos .c
# pasta para colocar os arquivos .o (objetos)
# nome do programa final (executável)

CC = gcc
SRC = ./src
OBJS = ./objs
TARGET = trabalho_2
LIMPAR = rm

all: objetos
	$(CC) $(OBJS)/apagar.o $(OBJS)/arquivo_bin.o $(OBJS)/cadastros.o $(OBJS)/exportar_txt.o $(OBJS)/listagens.o $(OBJS)/menus.o $(OBJS)/uteis.o $(OBJS)/trabalho_2.o -o $(TARGET)

objetos:
	$(CC) -c $(SRC)/apagar.c -o $(OBJS)/apagar.o
	$(CC) -c $(SRC)/arquivo_bin.c -o $(OBJS)/arquivo_bin.o
	$(CC) -c $(SRC)/cadastros.c -o $(OBJS)/cadastros.o
	$(CC) -c $(SRC)/exportar_txt.c -o $(OBJS)/exportar_txt.o
	$(CC) -c $(SRC)/listagens.c -o $(OBJS)/listagens.o
	$(CC) -c $(SRC)/menus.c -o $(OBJS)/menus.o
	$(CC) -c $(SRC)/uteis.c -o $(OBJS)/uteis.o
	$(CC) -c ./trabalho_2.c -o $(OBJS)/trabalho_2.o

clear:
	$(LIMPAR) $(OBJS)/*.o
	$(LIMPAR) $(TARGET)
