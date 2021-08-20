# AED2-Homework-1
## Tarea Extraclase #1
Instituto Tecnológico de Costa Rica

Área Académica Ingeniería en Computadores

Algoritmos y Estructuras de Datos II (CE 2103)

Segundo Semestre 2021

### Objetivo General
- Aplicar  el concepto de gestión de memoria desde la perspectiva de la codificación del software.
### Objetivos Específicos
- Utilizar punteros para la implementación de estructuras de datos lineales y jerárquicas.
- Investigar y desarrollar una aplicación en el lenguaje de programación C++.
- Investigar acerca de programación orientada a objetos en C++.

### Descripción de la tarea
Dado    un archivo que contiene una gran cantidad de números enterosseparados por coma. 
Para ordenar el archivo el estudiante debe implementar alguno de los siguientes algoritmos de ordenamiento: 
quick sort, insertion sort ó selection sort. Se debe suponer que el computador en el que se ejecuta el programa 
tiene una memoria máxima de 12 KB por lo que el programa no podrá tener más de 6 páginas de 1 KB (256 enteros) 
en memoria y deberá ejecutar el algoritmo de ordenamiento bajo esta restricción. Para los algoritmos, 
la paginación debe ser transparente, es decir su código no debe ser modificado de tal forma que refleje lo que ocurre detrás de escena. 
El estudiante deberá implementar una clase PagedArrayque sobrecargue el operador [ ], 
de esta forma el algoritmo simplemente pedirá entradas del arreglo, y la clase PagedArrayse encargará de buscar 
la página correspondiente, reemplazando alguna de las que ya estaban cargadas. El estudiante deberá investigar 
e implementar algún algoritmo de reemplazo.

El programa se ejecutará de la siguiente forma:

<paged-sort -i <archivo> -a -  o <archivo_resultado>>

Cuando el programa se ejecute, copia el contenido de archivoa archivo_resultadoy aplica el algoritmo de 
ordenamiento (QS   para Quicksort, IS   para insertion sort o SS   para selection sort) sobre el archivo de resultado.
No puede generar ningún archivo intermedio.El código fuente debe ser documentado utilizando Doxygen
y debe manejarse en GitHub brindando acceso al profesor mediante el siguiente correo: ldnoguera@gmail.comAspectos 
operativos y evaluación
