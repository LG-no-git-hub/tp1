CC = gcc
CFLAGS = -I.
OBJS = main.o pokemon.o pokelista.o treinador.o centro.o

programa: $(OBJS)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	del /f /q *.o programa.exe

## Para compilar, digite no terminal "make -f makefile"
## Para limpar os arquivos .o, digite no terminal "make clean"
