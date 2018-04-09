# makefile

deault: exe

main.o: main.c gerga.h
	gcc main.c -c -I.

gerga.o: gerga.c gerga.h
	gcc gerga.c -c -I.

exe: main.o gerga.o
	gcc *.o -o exe 

clean:
	rm *.o exe
