# Ejemplo multiarchivo

## Informacion general

* **Archivos**: 
  - main.c
  - funciones.c
  - funciones.h
  
## Casos de compilacion ##  
  
**Caso 1**:

```
# Generando los archivos objeto
gcc -Wall -c funciones.c
gcc -Wall -c main.c
# Generando el ejecutable
gcc -Wall funciones.o main.o -o example_multi1.out
```

**Caso 2**: Aca se usara la opcion -I

```
# Generando los archivos objeto
gcc -I. -Wall -c funciones.c
gcc -I. -Wall -c main.c
# Generando el ejecutable
gcc -Wall funciones.o main.o -o example_multi1.out
```

**Caso 3**: Usando comodines (Ya sea que se use o no la opcion -I)

```
# Generando los archivos objeto
gcc -I. -Wall *.c -c 
# Generando el ejecutable
gcc -Wall *.o -o example_multi1.out
```

* **Comando de ejecucion**:

```
./example_multi1.out
```
