CC = gcc
CFLAGS = -I.
OBJS = main.o pokemon.o pokelista.o treinador.o centro.o

test: $(OBJS)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -f *.o test

## Para compilar, escreva "make -f makefile"