# Manejo de archivos en C

## 1. Conceptualización

### 1.1. ¿Que son los archivos?

Un archivo es una colección de información almacenada en un dispositivo de memoria no volatil, usualmente el disco de un computador. Como la información no se pierde esta puede ser reutilizada una vez se ha guardado. 

### 1.2. ¿Para que se usan los archivos?

Los archivos son usados para almacenamiento permanente de grandes cantidades de datos ya que los datos almacenados en arreglos y variables solo existen temporalmente (Mientras el programa se ejecuta). A todo archivo le es asignado un nombre que es usado por el sistema operativo y por el usuario para propósitos de identificación.

## 2. Empleando C para el trabajo con archivos

### 2.1. Aspectos introductorios

Un concepto muy importante en C es el de **stream**. Un **stream** no es mas que una interfaz logica que permite el intercambio de datos entre una aplicacion y un archivo (en el sentido amplio de la palabra, se asocia no solo al disco duro sino que tambien puede hacer alusion a otros dispositivos como el teclado, la pantalla, etc.). Cuando se establece un intercambio de datos entre una aplicacion y un archivo se establece un buffer (flujo de bytes) que es intercambiado entre el dispositivo y la aplicación tal y como se muestra en la siguiente figura:

![fig1](./imagenes/file_IO.png)

**Figura 1**. C stream.

Tal y como se muestra en la figura 2, el intercambio de informacion entre el archivo y la aplicacion implica tres actividades:
1. **Abrir el archivo**: con esto se indica que se va a iniciar una transferencia de datos asi como el sentido en el cual se va a llevar a cabo.
2. **Procesar los datos**: en esta parte la aplicacion lleva a cabo el desarrollo de la logica como tal; esta puede implicar el procesamiento de informacion y el uso de instrucciones (lectura/escritura) para intercambio de datos entre el archivo y la aplicacion.
3. **Cerrar el archivo**: lo cual indica que se dara por terminada la transferencia de datos entre este y la aplicacion.

![fig2](./imagenes/procesando_archivos.png)

**Figura 2**. Trabajando con archivos. 

### 2.2. Usando archivos en C

A continuación se describiran la forma como se llevan a cabo cada una de las actividades previamente citadas:

#### 2.2.1. Abriendo el archivo

Abrir el archivo implica dos cosas:
1. Declarar un apuntador a ```FILE```
2. Hacer uso de la funcion ```fopen```

**Declarando un apuntador a FILE**

```FILE``` es una estructura definida en la libreria ```stdio.h``` (no olvidar incluir en el archivo fuente) para trabajar con archivos, de modo que el primer paso para empezar el proceso de trabajar con archivos consiste en la declaracion de un apuntador a este tipo de dato. La forma para esto es la siguiente:

```C
FILE *file_pointer_name,..;
```

Por ejemplo a continuacion se declaran dos apuntadores a FILE:

```C
FILE *ifp;
FILE *ofp;
```
**Abriendo un archivo**
Para abrir un archivo y asociarlo con un stream se usa la funcion ```fopen()``` cuyo prototipo se muestra a continuacion:

```C
FILE *fopen(const char *fname, const char *mode);
```

**Donde**:
* **fname** esta asociado al nombre del archivo.
* **mode** opcion que indica a C si el archivo se va a leer, a escribir o a modificar entre otras. La siguiente tabla describe las opciones disponibles el modo.


| Modo  | Significado |
| ------------- | ------------- |
| r | Abre un archivo de texto para lectura  |
| w  | Abre un archivo de texto para escritura  |
| a  | Agrega contenido a un archivo de texto  |
| rb  | Abre un archivo binario para lectura  |
| wb  | Abre un archivo binario para escritura  |
| ab  | Agrega contenido a un archivo binario |
| r+  | Abre un archivo de texto para leer/escribir  |
| w+ | Crea un archivo de texto para leer/escribir   |
| a+ | Abre o crea un archivo de texto para leer/escribir  |
| r+b | Abre binario para leer/escribir  |
| w+b | Crea binario para leer/escribir  |
| a+b | Abre o crea binario para leer/escribir  |

Si el programa abre exitoramente el archivo, fopen() devuelve un apuntador a file pointer el cual puede ser empleado para aplicar otras funciones de I/O sobre el archivo asociado (como lo veremos despues). Por otro lado, si hay un error, el valor retornado sera un puntero nulo.

**Code snippets**

1. Crear un archivo de texto llamado **data.dat** y dejandolo listo para escribir

```C
#include <stdio.h>
#include <string.h>

...
// Abriendo el archivo
FILE *outFile;
inFile = open("data.dat","w");
// Este codigo continuara...
```

2. Abrir para leer un archivo llamado "lista.txt"

```C
#include <stdio.h>
#include <string.h>

...
// Abriendo el archivo
FILE *inFile;
inFile = open("lista.txt","r");
// Verificando que el archivo se haya abierto
if(inFile == NULL) {
  printf("No se puede abrir lista.txt\n");
  exit(1);
}
// Este codigo continuara...
```
Note que se chequeo el resultado de **fopen**. Esta función puede devolver NULL mas espeficicamente por cosas como:
* Usar un nombre de archivo invalido.
* Intentar abrir un archivo en un disco que no esta listo; por ejemplo, cuando el disco no esta formateado.
* Intentar abrir un archivo en un directorio inexistente o en un disco duro inexistente.
* Intentar abrir un archivo inexistente en modo **r**.

3. Abrir para leer un archivo. Su nombre debera ser pasado por teclado.

```C
#include <stdio.h>
#include <string.h>

...
// Abriendo el archivo
char filename[80];
FILE *fp;
printf("Entre el nombre del archivo que sera abierto: ");
gets(filename); 
fp = open(filename,"r");
// Verificando que el archivo se haya abierto
if(fp == NULL) {
  printf("Can not open %s\n", filename);
  exit(1);
}
// Este codigo continuara...
```

Como se puede ver en el código anteriormente mostrado, se empleo la funcion fgets() la cual es una funcion como scanf para entrada de datos desde el teclado. Para mas informacion sobre esta, puede consultar el siguiente [enlace](http://c.conclase.net/librerias/?ansifun=fgets).

4. Crear un archivo dentro del directorio **/home/vito.corleone**. El nombre del archivo sera pasado por teclado.

```C
#include <stdio.h>
#include <string.h>

...
// Abriendo el archivo
char path[] = "/home/vito.corleone/"
char filename[80];
char fullName[161]; 
FILE *fp;
printf("Entre el nombre del archivo que sera abierto: ");
gets(filename);
strcat(fullName, path);
strcat(fullName, filename);
fp = open(fullName,"w");
// Este codigo continuara...
```
Para obtener el nombre completo del archivo (ruta + nombre) se uso la función **strcat** que concatena dos cadenas de caracteres. Para mas informacion sobre esta puede consultar el siguiente [enlace](http://c.conclase.net/librerias/?ansifun=strcat)

#### 2.2.2. Cerrando el archivo el archivo
Despues de completarse el procesamiento de un archivo, este debe ser cerrado y para ello se emplea la funcion fclose(). El prototipo de la funcion fclose es el siguiente:

```C
int fclose(FILE *fp);
```

**Donde**:
* **fp** es el FILE pointer asociado con el stream.

La funcion anterior retorna 0 si el stream fue cerrado con exito o -1 si hay errores.

**Code snippets**

1. En el siguiente ejemplo se muestra como se cierra un archivo despues de que este ha sido abierto.

```C
#include <stdio.h>
#include <string.h>

...
// Abriendo el archivo
char fullName[] = "/home/vito.corleone/data.dat"
fout = open(fullName,"w");
// Este codigo continuara

...
// Cerrando el archivo
fclose(fout);
```

#### 2.2.3. Trabajando con archivos

C proporsiona varias funciones para leer y escribir archivos, la siguiente tabla muestra algunas de ellas:

| Modo  | Funciones |
| ------------- | ------------- |
| Lectura | fscanf, fgets, fgetc, fread |
| Escrirtura | fprintf, fputs, fputc, fwrite |

#### 2.2.3.1. Entrada y salida por caracteres

Para leer y escribir archivos de caracter en caracter se emplea las funciones **getc** y **putc** respectivamente. A continuación se hablará de cada una de estas

#### 2.2.3.1.1. Funcion putc
Permite escribir un unico caracter a un stream especifico. El prototipo de esta se muestra a continuacion:

```C
int putc(int ch, FILE *fp);
```

**Donde**:
* **ch** es el caracter que sera escrito.
* **fp** es el file pointer asociado al archivo despues de que este ha sido abierto mediante la funcion fopen.

La funcion retorna el caracter que se acabo de escribir si el proceso fue exitoso o EOF (constante simbolica definida en stdio.h cuyo valor es -1) si un error ocurre.

**Ejemplo**
1. Una cadena de ADN puede se representa mediante un alfabeto de 4 simbolos ('A', 'C', 'G' y 'T'). Hacer un programa que permita generar una archivo con una cadena de ADN cuyo tamaño y nombre sea ingresado por el usuario.

**Solucion**: En [write_caracter.c](./code/write_caracter.c) se encuentra la solucion de este programa. Por comodidad aqui tambien se pone:

```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generarCaracter(void);

int main() {
  srand(time(NULL)); // Inicializacion del generador
  char filename[80];
  int tam;
  char ch;
  FILE *outFile;
  printf("Ingrese el nombre de la cadena de ADN a generar: ");
  scanf("%[^\n]s",filename); // Formato para que la entrada pueda aceptar espacios
  printf("Ingrese el tamaño de la cadena: ");
  scanf("%d",&tam);
  outFile = fopen(filename,"w");
  for(int i = 0; i < tam; i++) {
    ch = generarCaracter(); // Generacion de la letra
    putc(ch,outFile);
  }
  putc('\0',outFile);
  fclose(outFile);
  exit(0);
}

char generarCaracter(void) {
  int randomNum = rand()%4; //Generando un aleatorio entre 0 y 3
  switch(randomNum) {
    case 0:
      return 'A';
    case 1:
      return 'G';
    case 2:
      return 'T';
    case 3:
      return 'C';
  }
}
```

#### 2.2.3.1.2. Funcion getc
Permite leer un unico caracter de un stream especifico. El prototipo de esta se muestra a continuacion:

```C
int getc(FILE *fp);
```

**Donde**:
* **fp** es el file pointer asociado al archivo despues de que este ha sido abierto mediante la funcion fopen.

La funcion retorna el caracter que fue leido **EOF** (-1) en caso de error.

**Ejemplo**
1. Hacer un programa que lea un archivo de texto caracter por caracter y lo imprima en pantalla.

**Solucion**: [read_caracter.c](./code/read_caracter.c) es el codigo solucion. Por comodidad se muestra este codigo a continuación:

```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Inicializacion del generador
  char filename[80];
  int tam;
  char ch;
  FILE *inputFile;
  printf("Ingrese el nombre de la cadena de ADN a generar: ");
  scanf("%[^\n]s",filename); // Formato para que la entrada pueda aceptar espacios
  inputFile = fopen(filename,"r");
  if (inputFile == NULL) {
    printf("Error al abrir el archivo %s\n", filename);
    exit(-1);
  }
  do {
    ch = getc(inputFile);
    printf("%c", ch);
  } while(ch != EOF);
  printf("\n");
  fclose(inputFile);
  exit(0);
}
```

2. Hacer un programa que abra un archivo que contiene una cadena de ADN y genere un archivo de salida con el numero de cada uno de los caracteres el alfabeto genetico ('A', 'G', 'G' y 'C') separados por espacio. El nombre del archivo sera **inventario_nombreArchivo**. Asi por ejemplo si se tiene un archivo con el siguiente nombre **secuencia.dat** con el siguiente contenido:

```
AGCTTTTCATTCT
```

La salida sera un archivo llamado **inventario_secuencia.dat** y su contenido será el siguiente:

```
2 1 7 2
```

**Solución**: En [read_write_caracter.c](./code/read_write_caracter.c) se muestra el codigo solución, por comodidad a continuación tambien aparece:

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char inFilename[80];
  char outFilename[80] = "inventario_";
  char cntS[10];
  int tam;
  char ch;
  int cnt[] = {0,0,0,0}; 
  FILE *inFile;
  FILE *outFile;
  int i, j;
  printf("Ingrese el nombre de la cadena de ADN a generar: ");
  scanf("%[^\n]s",inFilename); // Formato para que la entrada pueda aceptar espacios
  inFile = fopen(inFilename,"r");
  if (inFile == NULL) {
    printf("Error al abrir el archivo %s\n", inFilename);
    exit(-1);
  }
  do {
    ch = getc(inFile);
    if(ch == 'A') {
      cnt[0]++;
    }
    else if(ch == 'G') {
      cnt[1]++;
    }
    else if(ch == 'T') {
      cnt[2]++;
    }
    else if(ch == 'C') {
      cnt[3]++;
    }
  } while(ch != EOF);
  fclose(inFile);
  strcat(outFilename,inFilename);
  outFile = fopen(outFilename,"w");
  for(i = 0; i < 4; i++) {
    snprintf(cntS,10,"%d", cnt[i]);
    j = 0;
    while(cntS[j] != '\0') {
      putc(cntS[j],outFile);
      j++;
    }
    putc(' ',outFile);
  }
  putc('\0',outFile);
  fclose(outFile);
  exit(0);
}
```

Hay que resaltar que en el codigo anterior, hay algunas funciones que no se han visto pero que pueden ser consultadas en internet, a continuacion como [strcat](https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_73/rtref/strcat.htm) y [snprintf](https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_73/rtref/snprintf.htm). Lo animamos a que observe la descripcion y ejemplos de los enlaces y comprenda como se usan estos en el programa.

## X. Enlaces:
* http://c.conclase.net/librerias/
* https://www.ntu.edu.sg/home/ehchua/programming/index.html
* https://www.le.ac.uk/users/rjm1/cotter/index.htm
* https://pablohaya.com/2013/10/12/diferencia-entre-scanf-gets-y-fgets/
* http://www.dummies.com/programming/c/how-to-use-the-fgets-function-for-text-input-in-c-programming/
* https://www.programiz.com/c-programming

