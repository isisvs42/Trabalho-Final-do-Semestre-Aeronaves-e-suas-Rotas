CC = gcc          
SRC = ./src           # pasta onde ficam os arquivos .c
OBJS = ./objs         # pasta para colocar os arquivos .o (objetos)
TARGET = trabalho_2   # nome do programa final (executável)
LIMPAR = rm

OBJS_LIST = $(OBJS)/apagar.o $(OBJS)/arquivo_bin.o $(OBJS)/cadastros.o $(OBJS)/exportar_txt.o $(OBJS)/listagens.o $(OBJS)/menus.o $(OBJS)/uteis.o $(OBJS)/trabalho_2.o

all: objetos
	$(CC) $(OBJS_LIST) -o $(TARGET)

objetos:
	$(CC) -c ./$(SRC)/apagar.c -o $(OBJS)/apagar.o
	$(CC) -c ./$(SRC)/arquivo_bin.c -o $(OBJS)/arquivo_bin.o
	$(CC) -c ./$(SRC)/cadastros.c -o $(OBJS)/cadastros.o
	$(CC) -c ./$(SRC)/exportar_txt.c -o $(OBJS)/exportar_txt.o
	$(CC) -c ./$(SRC)/listagens.c -o $(OBJS)/listagens.o
	$(CC) -c ./$(SRC)/menus.c -o $(OBJS)/menus.o
	$(CC) -c ./$(SRC)/uteis.c -o $(OBJS)/uteis.o
	$(CC) -c ./$(SRC)/trabalho_2.c -o $(OBJS)/trabalho_2.o

clear:
	$(LIMPAR) $(OBJS)/*.o
	$(LIMPAR) $(TARGET)
