# Macros
CC = gcc
CFLAGS = -g -Wall -std=c18
SOURCE = Conversion.c TablasDeConversion.c
OBJ = Conversion.o TablasDeConversion.o
BIN = output

#Reglas make all | make clean

#Compila crea un objeto, lo limpia y crea un ejecutable
all: $(BIN)
	
$(BIN):$(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) 

#Limpia el archivo ejecutable
clean:
	$(RM) $(BIN) $(OBJ)



