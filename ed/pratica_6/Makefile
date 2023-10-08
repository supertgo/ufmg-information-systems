CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/graph.o
HDRS = $(INC)/linked_list.hpp $(INC)/graph.hpp
CFLAGS = -Wall -g -c -I$(INC) -std=c++11
EXE = $(BIN)/pa6.out

all: run

run: $(EXE)
	$(EXE) -k

$(BIN)/pa6.out: $(OBJS)
	$(CC) -g -o $(BIN)/pa6.out $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out
