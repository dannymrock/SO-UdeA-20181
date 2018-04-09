# Utilidad Make (En construccion...)

## Aspectos introductorios

Los makefiles son archivos de texto que permiten la automatización de tareas (normalmente de compilación y enlazado). Estos son interpretados y ejecutados por un programa llamado make. La unidad de construcción básica en un makefile se conoce como regla y su forma básica se muestra a continuación:

```
Target: lista de prerrequisitos
<TAB> comandos de construccion
```
**Donde**:
* **Línea de dependencia**: Consiste en el target y la lista de prerrequisitos separados por comas. El target suele ser el resultado de la ejecución de los comandos de construcción. Normalmente, cuando este es invocado retorna un archivo objeto o un ejecutable, sin embargo, también existen casos en los cuales no se retorna nada limitando la tarea asociada solo a la ejecución de un conjunto de comandos. Por otro lado, la lista de prerrequisitos son las dependencias que deben ser satisfechas para poder ejecutar los comandos de construcción cuando un target es invocado. Las dependencias no solo son archivos también pueden ser otros target en el makefile.
* **Línea de dependencia**: Consiste en el target y la lista de prerrequisitos separados por comas. El target suele ser el resultado de la ejecución de los comandos de construcción. Normalmente, cuando este es invocado retorna un archivo objeto o un ejecutable, sin embargo, también existen casos en los cuales no se retorna nada limitando la tarea asociada solo a la ejecución de un conjunto de comandos. Por otro lado, la lista de prerrequisitos son las dependencias que deben ser satisfechas para poder ejecutar los comandos de construcción cuando un target es invocado. Las dependencias no solo son archivos también pueden ser otros target en el makefile.

## Enlaces de interes
1. [GCC and Make Compiling, Linking and Building C/C++ Applications](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)
2. [C++ TUTORIAL - MAKE &CMAKE](http://www.bogotobogo.com/cplusplus/make.php)
3. [Unix Makefile Tutorial](https://www.tutorialspoint.com/makefile/index.htm)
4. [GNU make](http://iie.fing.edu.uy/~vagonbar/gcc-make/make.htm)
5. [Manual GNU make](https://www.gnu.org/software/make/manual/make.html)
6. [A Simple Makefile Tutorial](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)
7. [Using make and writing Makefiles](https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html)
8. [A Simple Makefile](https://www.gnu.org/software/make/manual/html_node/Simple-Makefile.html)
9. [
An Introduction to GCC - for the GNU compilers gcc and g++](http://www.network-theory.co.uk/docs/gccintro/gccintro_16.html)
10. [Makefile template for shared library](https://gist.github.com/xuhdev/1873316)
