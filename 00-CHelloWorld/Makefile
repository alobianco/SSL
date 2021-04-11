# Macros
CC = gcc
CFLAGS = -g -Wall -O2 -std=c18
SOURCE = hello.c 
OBJ = hello.o
BIN = hello

#Reglas make all | make clean

#Compila crea un objeto y un ejecutable
all: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

#Limpia el archivo objeto y el ejecutable
clean:
	$(RM) $(OBJ) $(BIN)



