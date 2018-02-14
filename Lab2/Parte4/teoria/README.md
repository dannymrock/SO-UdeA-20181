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

```C
struct Book  {
   int  book_id;
   char title[50]; 
   char author[40]; 
   int pages;
   float price;
} book1, book2, book3;
```



2. Listando el tipo de la estructura seguida por las variables correspondientes en cualquier lugar del programa antes de utilizarlas, así, asumiendo que la estructura está declarada. Por ejemplo ([codigo](https://goo.gl/18uq3R)):

```C
struct Book  {
   int  book_id;
   char title[50]; 
   char author[40]; 
   int pages;
   float price;
}; 

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
### 2.3. Inicializacion de variables tipo struct

Al igual que para el caso de las variables simples, las estructuras pueden tener valores iniciales una vez se declaran. Como estas con estructuras compuestas, lo que se hace para inicializar estas, es inicializar miembro por miembro. A continuacion se describen las dos formas de llevar a cabo esto:

#### 2.3.1. Usando una lista de inicialización
Esta es similar a la empleada para los arrays, y lo que se hace es inicializar cada miembro de la estructura con el correspondiente valor inicial asociado. Cada valor inicial es separado por coma (,). Veamos.

**Ejemplo** 
Iniciar la estructura Cancion con la siguiente informacion asociada a una cancion de [Billie Holiday](https://es.wikipedia.org/wiki/Billie_Holiday). A continuacion se muestra el codigo:

```C
struct Cancion {
  char titulo[64];
  char artista[32];
  char compositor[32];
  short duracion;
  char URL[100];
};

// Inicializacion de la variable (sadSong) tipo struct Cancion 
struct Cancion sadSong = {
                            "Strange fruit",
                            "Billie Holiday",
                            "Abel Meeropol",
                             164,
                            "http://bit.ly/1mU1gBT"
                         };

```

#### 2.3.2. Inicialización específica de cada uno de los miembros
Básicamente, consiste en la designación de cada uno de los miembros siguiendo la siguiente forma.

```C
.miembro = valor; // designador
```

**Ejemplo** 
Realizar la misma inicilizacion del caso anterior, pero en este caso emplear la inicializacion especifica de miembros.

```C
struct Cancion {
  char titulo[64];
  char artista[32];
  char compositor[32];
  short duracion;
  char URL[100];
};

// Inicializacion de la variable (sadSong) tipo struct Cancion 
struct Cancion sadSong = {
                            .titulo = "Strange fruit",
                            .artista" = Billie Holiday",
                            .compositor = "Abel Meeropol",
                            .duracion = 164,
                            .URL = "http://bit.ly/1mU1gBT"
                         };

```

#### 2.3.3. Caso en el que no se inicializan todos lo miembros
Ya sea que se emplee una u otra de las formas anteriormente mencionadas, es posible inicializar parcialmente una variable tipo estructura, para ello, basta con no pasar todos los elementos que puede contener la lista de inicialización. A continuación se muestra un ejemplo:

**Ejemplo**
Crear dos variables tipo struct Cancion, estas variables no tendran todos los parametros inicialidos:

```C
struct Cancion {
  char titulo[64];
  char artista[32];
  char compositor[32];
  short duracion;
  char URL[100];
};

struct Cancion song1 = {"Mi cerebro esta boca abajo"};
struct Cancion song2 = { 
                         .titulo = "Noches de Hungria",
                         .compositor = "Julio Jaramillo",
                         .duracion = 127
};
```

### 2.4. Empleo de la palabra clave typedef para crear alias (tocayos)
La palabra reservada ```typedef``` permite a un programador crear un sinónimo de un tipo de dato definido por el usuario o de un tipo ya existente. La sintaxis para usar esta palabra clave es la siguiente:

```C
tipo_dato typedef nombre_alias;
```

**Ejemplo**
Dada la siguiente declaracion de variables:

```C
double alto, ancho;
```

Teniendo en cuenta que **alto** y **ancho** son medidas de longitud, podemos crear un alias para una variable tipo double llamado **longitud** y el efecto será el mismo que el del caso anterior, el código para el caso sera el siguiente:

```C
typedef double longitud;
longitud alto, ancho;
```

**Ejemplo**
La mayor ventaja del uso de esta palabra clave se ve con las estructuras. A continuación se muestra el resultado:

1. Cree dos variables tipo Punto2D llamadas P1 y P2 con valores (2,3) y (-1,6). No emplee typedef


```C
// Declaracion de las estructura
struct Punto2D {
  float x;
  float y;
};


// Declaracion de variables
struct Punto2D P1 = {
                      2,
                      3
                    };

struct Punto2D P2 = {
                      .x = -1,
                      .y = 6
                    };
```


2. Realice lo mismo que en el punto anterior, pero esta vez haga uso de la palabra clave **typedef** para crear un alias son **struct Punto2d** llamado **Punto2D**. 


```C
// Declaracion de las estructura
struct Punto2D {
  float x;
  float y;
};

// Creacion del alias
struct Punto2D Punto2D;

// Declaracion de variables (Note que ya no es necesario el struct Punto2D gracias al alias)
Punto2D P1 = {
                      2,
                      3
                    };

Punto2D P2 = {
                      .x = -1,
                      .y = 6
                    };
```

### 2.5. Manipulando estructuras
Por manipulacion de la estructuras (dentro de este contexto) nos queremos referir al acceso a los miembros de esta, tal y como sucede cuando se accede a los miembros de un objeto en el caso de la POO. Para el caso de las estructuras en particulas, existen dos formas de acceder:
* Empleando el operador punto (.)
* Emplenando el operador flecha (->)

#### 2.5.1 Usando el operador punto (.)
Usado cuando se definen variables del tipo de la estructura. Básicamente tiene la siguiente sintaxis:

```C
<nombre_variable_estructura>.<nombre_miembro> = datos;
```
**Ejemplos**
1. Crear dos puntos P1 y P2. Luego de su declaracion inicialicelos con los siguientes valores: (1,1) y (10,3).

```
// Declaracion de las estructura
struct Punto2D {
  ...
};

// Creacion del alias
struct Punto2D Punto2D;

// Declaracion de los puntos
Punto2D P1, P2;

// Manipulacion (acceso a los miembros)
P1.x = 1;
P1.y = 1;
P2.x = 10, P2.y = 3;
```

2. Crear una estructura asociada a un libro y porteriormente declarar dos libros con la siguiente informacion.



```
// Declaracion de las estructura
struct Punto2D {
  ...
};

// Creacion del alias
struct Punto2D Punto2D;

// Declaracion de los puntos
Punto2D P1, P2;

// Manipulacion (acceso a los miembros)
P1.x = 1;
P1.y = 1;
P2.x = 10, P2.y = 3;
```



### 2.5. Estructuras anidadas




