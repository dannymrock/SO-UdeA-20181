# Ejemplo 2

## Compilacion con comandos

```
gcc -I./includes main.c -c
gcc -I./includes saludos.c -c
gcc -I./includes matematicas.c -c
gcc *.o -o main.out -lm
```

## Compilacion empleando el archivo make

```
make
```

## Ejecucion

```
./main.out
```
