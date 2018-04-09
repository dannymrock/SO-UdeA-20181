# Enlazando contra librerias externas

## Estamos en construccion - Disculpas por las molestias causadas

La libreria a emplear es [C algorithms](https://fragglet.github.io/c-algorithms/) de Simon Howard (https://github.com/fragglet). Para descargarla y descomprimirla se emplean el siguientes comandos:

```
wget https://github.com/fragglet/c-algorithms/archive/c-algorithms-1.2.0.zip
unzip c-algorithms-1.2.0.zip
```

Una vez descomprimio el proceso de compilacion e instalacion es el siguiente:

```
cd c-algorithms-1.2.0
./configure 
make
make check
sudo make install
```

El resultado es que se instalan los siguientes archivos cabeceras y librerias en las siguientes rutas:
* **Archivos cabecera (.h)**: /usr/local/include/libcalg-1.0/libcalg/

```
ls /usr/local/include/libcalg-1.0/libcalg/
```

* **Librerias (.so y .a)**: /usr/local/lib

```
ls /usr/local/lib/libcalg*
```

En el momento de hacer el enlazado con esta libreria para crear el ejecutable se usara la opcion: **-lcalg**

## A tener en cuenta

> Libraries have been installed in:
>    /usr/local/lib
> 
> If you ever happen to want to link against installed libraries
> in a given directory, LIBDIR, you must either use libtool, and
> specify the full pathname of the library, or use the `-LLIBDIR'
> flag during linking and do at least one of the following:
>    - add LIBDIR to the `LD_LIBRARY_PATH' environment variable
>      during execution
>    - add LIBDIR to the `LD_RUN_PATH' environment variable
>      during linking
>    - use the `-Wl,--rpath -Wl,LIBDIR' linker flag
>    - have your system administrator add LIBDIR to `/etc/ld.so.conf'
> 
> See any operating system documentation about shared libraries for
> more information, such as the ld(1) and ld.so(8) manual pages.


Asi teniendo en cuenta lo anterior y suponiendo que se tiene un archivo (**main.c**) que esta haciendo uso de las funciones propias de esta libreria tenemos que el comando seria:

```
gcc -I/usr/local/include/libcalg-1.0/libcalg/ -L/usr/local/lib/ main.c -lcalg -o myprogram.out
```

## Recursos adicionales
1. [Static and Dynamic Libraries | Set 1](https://www.geeksforgeeks.org/static-vs-dynamic-libraries/)
2. [Static and Dynamic Libraries | Set 2](https://www.geeksforgeeks.org/working-with-shared-libraries-set-2/)

