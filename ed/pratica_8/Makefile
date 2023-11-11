CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/unionFind.o
HDRS = $(INC)/unionFind.hpp
CFLAGS = -Wall -g -c -I$(INC) -std=c++11
EXE = $(BIN)/pa8.out

all: run

run: $(EXE)

$(EXE): $(OBJS)
	$(CC) -g -o $(EXE) $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out
