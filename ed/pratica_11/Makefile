CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/indice.o $(OBJ)/set.o $(OBJ)/avl.o
HDRS = $(INC)/set.h $(INC)/avl.h $(INC)/node.h
CFLAGS = -Wall -g -c -I $(INC) -std=c++11
EXE = $(BIN)/pa11.out

all: run

run: $(EXE)

$(EXE): $(OBJS)
	$(CC) -g -o $(EXE) $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out
