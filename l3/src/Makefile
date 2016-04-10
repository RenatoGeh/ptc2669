CFLAGS = -ansi -pedantic -Wall -Wno-unused-result
LIBS = -lm
DEBUG = false

ifeq ($(DEBUG), true)
	CFLAGS += -g
else
	CFLAGS += -O2
endif

DEPS = neuron.o nnet.o utils.o

all: run

run: main.o $(DEPS)
	gcc $^ -o $@ $(LIBS)

main.o: main.c
	gcc -c $(CFLAGS) $^

utils.o: utils.c utils.h
	gcc -c $(CFLAGS) $^

neuron.o: neuron.c neuron.h
	gcc -c $(CFLAGS) $^

nnet.o: nnet.c nnet.h
	gcc -c $(CFLAGS) $^

.PHONY: clean
clean:
	rm *.out *.gch *.o run

