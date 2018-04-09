# makefile para generar el ejecutable exe

INCLUDES = -I./includes
EJECUTABLE = myexe
VPATH = includes
LIBRERIES = -lm


default: $(EJECUTABLE)

saludos.o: saludos.c saludos.h
	gcc $(INCLUDES) saludos.c -c

matematicas.o: matematicas.c matematicas.h
	gcc $(INCLUDES) matematicas.c -c

main.o: main.c saludos.h matematicas.h
	gcc $(INCLUDES) main.c -c

$(EJECUTABLE): saludos.o main.o matematicas.o
	gcc *.o -o $@ $(LIBRERIES)

clean:
	rm *.o exe
