CC=gcc
CFLAGS=-Wall -I src
LDFLAGS=-ll
EXEC=tpcas
SRC=src
BIN=bin
OBJ=obj

all: $(BIN)/$(EXEC)

bin:
	mkdir -p bin

obj:
	mkdir -p obj

$(BIN)/$(EXEC): $(OBJ)/tree.o $(OBJ)/$(EXEC).o  $(OBJ)/$(EXEC).yy.o | bin
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ)/$(EXEC).o: $(OBJ)/$(EXEC).c $(OBJ)/$(EXEC).h $(OBJ)/$(EXEC).tab.h | obj
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJ)/$(EXEC).yy.o: $(OBJ)/$(EXEC).yy.c $(OBJ)/$(EXEC).h | obj
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJ)/$(EXEC).c $(OBJ)/$(EXEC).h $(OBJ)/$(EXEC).tab.h: $(SRC)/$(EXEC).y | obj
	bison -d -o $(OBJ)/$(EXEC).c $(SRC)/$(EXEC).y

$(OBJ)/$(EXEC).yy.c: $(SRC)/$(EXEC).lex | obj
	flex -o $@ $(SRC)/$(EXEC).lex

$(OBJ)/tree.o: $(SRC)/tree.c $(SRC)/tree.h | obj
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f bin/*
	rm -f obj/*