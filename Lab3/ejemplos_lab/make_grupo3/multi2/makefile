# makefile

VPATH = includes
CC = gcc
INCLUDES = -I./includes
EJECUTABLE = exe

deault: $(EJECUTABLE)

main.o: main.c gerga.h matematicas.h
	$(CC) main.c -c $(INCLUDES)

gerga.o: gerga.c gerga.h
	$(CC) gerga.c -c $(INCLUDES)

matematicas.o: matematicas.c matematicas.h
	$(CC) $< -c $(INCLUDES)

$(EJECUTABLE): main.o gerga.o matematicas.o 
	$(CC) $^ -o $@ -lm

clean:
	rm *.o $(EJECUTABLE)
