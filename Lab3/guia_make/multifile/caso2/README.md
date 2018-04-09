# Ejemplo multiarchivo

## Informacion general

**Organizacion de los archivos**: 
* **headers**:  
  - funciones.h
* **sources**:
  - funciones.c
  - funciones.h
  
## Casos de compilacion ##  
  
Se asume que la compilacion de los archivos se realiza en   
**Caso 1**:

```
# Generando los archivos objeto
gcc -I./headers -Wall -c ./sources/funciones.c
gcc -I./headers -Wall -c ./sources/main.c
# Generando el ejecutable
gcc -Wall funciones.o main.o -o example_multi1.out
```

* **Comando de ejecucion**:

```
./example_multi1.out
```

## a
