#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa analisamem
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2021-10-30 - arquivo criado
# 		: 2023-09-08 - fixaddr adicionado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm 
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/pilhaindexada.o $(OBJ)/analisamem.o
TOBJS = $(OBJ)/pilhaindexada.o $(OBJ)/testepilhaindexada.o
HDRS = $(INC)/pilhaindexada.h $(INC)/msgassert.h
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/analisamem

TEST = $(BIN)/testepilhaindexada

all: test use

use: $(EXE)
	if test -d /tmp/out; then rm -rf /tmp/out; fi
	mkdir /tmp/out
	mkdir /tmp/out/teste
	# fixaddr/fixaddr.csh teste/multlog.out /tmp/out
	# $(EXE) -i /tmp/out/teste/multlog.out.fixed -p /tmp/out/mult
	fixaddr/fixaddr.csh teste/somalog.out /tmp/out
	$(EXE) -i /tmp/out/teste/somalog.out.fixed -p /tmp/out/soma
	fixaddr/fixaddr.csh teste/normalog.out /tmp/out
	$(EXE) -i /tmp/out/teste/normalog.out.fixed -p /tmp/out/norma
	fixaddr/fixaddr.csh teste/internolog.out /tmp/out
	$(EXE) -i /tmp/out/teste/internolog.out.fixed -p /tmp/out/interno
	# fixaddr/fixaddr.csh teste/soma1M.out /tmp/out
	# $(EXE) -i /tmp/out/teste/soma1M.out.fixed -p /tmp/out/soma1M
	gnuplot /tmp/out/*.gp
	ls /tmp/out/

test: $(TEST)
	$(BIN)/testepilhaindexada

bin: $(EXE) $(TEST)

$(BIN)/testepilhaindexada: $(TOBJS)
	$(CC) -g -o $(BIN)/testepilhaindexada $(TOBJS) $(LIBS)

$(BIN)/analisamem: $(OBJS)
	$(CC) -g -o $(BIN)/analisamem $(OBJS) $(LIBS)

$(OBJ)/analisamem.o: $(HDRS) $(SRC)/analisamem.c
	$(CC) $(CFLAGS) -o $(OBJ)/analisamem.o $(SRC)/analisamem.c 

$(OBJ)/testepilhaindexada.o: $(HDRS) $(SRC)/testepilhaindexada.c
	$(CC) $(CFLAGS) -o $(OBJ)/testepilhaindexada.o $(SRC)/testepilhaindexada.c 

$(OBJ)/pilhaindexada.o: $(HDRS) $(SRC)/pilhaindexada.c
	$(CC) $(CFLAGS) -o $(OBJ)/pilhaindexada.o $(SRC)/pilhaindexada.c 

clean:
	rm -f $(EXE) $(TEST) $(OBJS)  $(TOBJS)
