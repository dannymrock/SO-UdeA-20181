# Estructuras en C

## 1. Conceptualizacion

Anteriormente vimos que los **arrays** esta una coleccion de datos de un mismo tipo agrupados bajo un mismo nombre. C, pese a no ser un lenguaje de programacion orientado a objetos maneja un tipo de dato compuesto conocido como **estructura**. En si, una estructura es lo mas cercano a la definición que conocemos de **clase** en los lenguajes de programación, la unica diferencia respecto a las clases (sin hablar en el sentido estricto de la palabra), es que una estructura es como una clase con miembros pero sin metodos.

La mayor ventaja de estas, es que permiten la creacion de **nuevos tipos de datos**, liberando al programador de tener que restringirse 
al uso de los tipos de datos tipicos ofrecidos por el lenguaje como tal (int, double, float, etc.) lo cual hace posible organizar datos complicados, particularmente en largos programas.

Una **estructura**, es una coleccion de uno o más tipos de datos denominados **miembros**, cada uno de los cuales (como se dijo antes) puede ser de un tipo diferente. 

## 2. Trabajando con estructuras

### 2.1. Declaración de una estructura

La declaración de una estructura tiene la siguiente sintaxis:

```C
struct nombre-estructura {
  tipo_1 miembro_1;
  tipo_2 miembro_2;
  tipo_3 miembro_3;
  ...
  tipo_N miembro_N;
};
```

**Tip**: se reocomienda que los nombres de estructuras empicen con mayuscula.

**Ejemplos**

1. Definir una estructura asociada a un punto en el plano cartesiano.

```C
struct Punto2D {
  float x;
  float y;
};
```

2. Definir una estructura asociada a una fecha.

```C
struct Date {
  unsigned year;
  unsigned month;
  unsigned day;
};
```

3. Definir una estructura asociada a una hora.

```C
struct Tiempo {
  unsigned int hr;
  unsigned int min;
  unsigned int sec;
};
```
4. Definir una estructura asociada a un album musical

```C
struct Album {
  char titulo[64];
  char artista[32];
  char genero[32];
  char *canciones;
};
```

5. Definir una estructura asociada a una cancion.

```C
struct Cancion {
  char titulo[64];
  char artista[32];
  char compositor[32];
  short duracion;
  struct fecha f_publicacion;
};
```

6. Definir una estructura asociada a una cancion.

```C
struct Book  {
   int  book_id;
   char title[50]; 
   char author[40]; 
   int pages;
   float price;
};

```

### 2.2. Definición de variables tipo struct
Las variables de estructuras se pueden definir de dos formas:
1. Listándolas inmediatamente después de la llave de cierre de la llave de cierre de la declaración de la estructura, algo como esto. Por ejemplo ([codigo](https://goo.gl/BKZ4tR)):

```
struct Book  {
   int  book_id;
   char title[50]; 
   char author[40]; 
   int pages;
   float price;
} book1, book2, book3;
```



2. Listando el tipo de la estructura seguida por las variables correspondientes en cualquier lugar del programa antes de utilizarlas, así, asumiendo que la estructura está declarada. Por ejemplo ([codigo](https://goo.gl/18uq3R)):

```
struct Book  {
   int  book_id;
   char title[50]; 
   char author[40]; 
   int pages;
   float price;
} 

struct Book book1, book2;
```

FIGURAs - LA MISMA PARA AMBOS EJEMPLOS 

Adicionalmente, los conceptos aplicados para los tipos de datos simples aplican para estructuras tambien; esto es, es posible crear variables normales, arrays, matrices y apuntadores de estructuras entre otros. Veamos:

**Ejemplo**:
Empleando la estructura tipo Punto2D crear las siguientes variables:
* Dos variables llamadas p1 y p2 (local).
* Un array de 3 elementos llamado vP (local).
* Un apuntador llamado *ptrP que apunte a p[1] (global).
* Una matrix de 2x2 llamada mP (global).

La [solución](https://goo.gl/kqGmJz) se muestra a continuación:

```C
struct Punto2D {
  float x;
  float y;
};

struct Punto2D vP[3];
struct Punto2D mP[2][2];
int main() {
  // Los datos tipo Punto2D seran locales
  struct Punto2D p1, p2;  
  struct Punto2D *ptrP = &vP[1];  
  return 0;
}
```

