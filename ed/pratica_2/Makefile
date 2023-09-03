CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/fib.o $(OBJ)/fat.o $(OBJ)/timeed.o
HDRS = $(INC)/fat.h $(INC)/fib.h $(INC)/timeed.h 
CFLAGS = -pg -Wall -g -c -I$(INC)

EXE = $(BIN)/main

run: $(EXE)
	$(EXE) -b -r 5
	$(EXE) -b -i 5
	$(EXE) -f -r 5
	$(EXE) -f -i 5

gprof: $(BIN)/main
	$(EXE) -b -r 36
	gprof $(EXE) gmon.out > /tmp/fib_gprof.txt

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/timeed.o: $(HDRS) $(SRC)/timeed.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/timeed.o $(SRC)/timeed.cpp

$(OBJ)/fat.o: $(HDRS) $(SRC)/fat.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fat.o $(SRC)/fat.cpp

$(OBJ)/fib.o: $(HDRS) $(SRC)/fib.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fib.o $(SRC)/fib.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
