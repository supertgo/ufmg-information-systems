CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o
HDRS =
CFLAGS = -Wall -g -c -I$(INC) -std=c++11
EXE = $(BIN)/pa9.out

all: run

run: $(EXE)
	$(EXE) -z 73735 -s 13 -a rs

$(EXE): $(OBJS)
	$(CC) -g -o $(EXE) $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out
