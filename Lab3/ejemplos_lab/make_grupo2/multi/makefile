# makefile para generar el ejecutable exe

default: exe

saludos.o: saludos.c saludos.h
	gcc -I. saludos.c -c


main.o: main.c saludos.h
	gcc -I. main.c -c

exe: saludos.o main.o
	gcc *.o -o exe 

clean:
	rm *.o exe
