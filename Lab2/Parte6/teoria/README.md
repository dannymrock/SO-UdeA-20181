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



#### 2.2.2. Cerrando el archivo el archivo
Despues de completarse el procesamiento de un archivo, este debe ser cerrado y para ello se emplea la funcion fclose(). El prototipo de la funcion fclose es el siguiente:

```C
int fclose(FILE *fp);
```

**Donde**:
* **fp** es el FILE pointer asociado con el stream.

La funcion anterior retorna 0 si el stream fue cerrado con exito o -1 si hay errores.


**Code snippets**
1. Abrir para leer un archivo llamado "lista.txt"


## X. Enlaces:
* http://c.conclase.net/librerias/
* https://www.ntu.edu.sg/home/ehchua/programming/index.html
* https://www.le.ac.uk/users/rjm1/cotter/index.htm
