# Macros
CC = gcc
CFLAGS = -g -Wall -O2 -std=c18
SOURCE = hello.c 
OBJ = hello.o
BIN = output

#Reglas make all | make clean

#Compila crea un objeto, lo limpia y crea un ejecutable
all: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)
	$(RM) $(OBJ)

#Limpia el archivo ejecutable
clean:
	$(RM) $(BIN)



