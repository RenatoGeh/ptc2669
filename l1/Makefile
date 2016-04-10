CFLAGS = -ansi -pedantic -Wall -Wno-unused-result
DEBUG = false

ifeq ($(DEBUG), true)
	CFLAGS += -g
else
	CFLAGS += -O2
endif

FILE = lms

run: $(FILE).o $(DEPS)
	gcc $(FILE).c $(CFLAGS)

.PHONY: clean
clean:
	rm *.out *.gch *.o run

