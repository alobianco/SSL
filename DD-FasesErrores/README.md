## 02-FasesErrores

### 1- PREPROCESADOR

a) Tipear hello2.c:
         Ver archivo hello2.c

b) Preprocesar hello2.c:
        <p><strong>Para preprocesar el hello2.c -> gcc -E hello2.c > hello2.i</strong></p>
        Al abrir el hello2.i vemos que el preprocesador toma el #include <stdio.h> copia todas las declaraciones de funciones del stdio.h y las pega en la parte superior de nuestro hello.i
        Tambien reemplaza los comentarios escritos en el hello2.c por un espacio.

c) Tipear hello3.c:
        Ver archivo hello3.c

d) Investivar e indicar la semantica de la primera linea de hello3.c:
        La primera linea del hello3.c se declara una funcion llamada printf, los datos que recibe y los que devuelve, pero no nos explica como funciona

e) Preprocesar hello3.c:
            <p><strong>Para preprocesar el hello3.c -> gcc -E hello3.c > hello3.i</strong></p>
            Aparecen comentarios especificos del preprocesador, fuera de eso no hay diferencias entre el hello3.c y hello3.i

### 2- COMPILACIÓN

a) Compilar hello3.i y generar hello3.s:
        <p><strong>Para realizar esto -> gcc -S hello3.i</strong></p>
        Nos mostrara los siguientes errores (No warnings):
            hello3.c:5:5: error: expected declaration or statement at end of input

b) Corregir los errores del punto anterior en un hello4.c:
        Se crea un hello4.c corrigiendo esos errores -> Ver hello4.c
        Se genera el hello4.s Para eso:
            <p><strong>gcc -S hello4.c -> Se crea hello4.s en Assembler</strong></p>

c) Objetivo del codigo hello4.s:
        Toma nuestro main y como esta lo "traduce" a Assembler. Crea un programa con la misma funcion de nuestro programa en C, asignar un valor a la variable entera i y llamar la funcion prontf.
        Esto no nos dice que el programa funcione, solo traduce lo escrito en C a Assembler
    
d) Ensamblar el hello4.s:
       <p><strong> Para eso as -o hello4.o hello4.s  </strong></p>

### 3- VINCULACIÓN

a) Vincular hello4.o con la biblioteca estandar:
        <p><strong>Para eso corremos: ld -o hello4 hello4.o </strong></p>
            Vemos que nos tira diferentes errores al momento de enlazar, no reconoce 'prontf' ni 'main' que aparecen en el codigo de Assembler.
    
b) Crear hello5.c con los problemas solucionados:
        Se crea el hello5.c -> Ver hello5.c
        Se cambia la funcion prontf por printf, ya que tenemos la declaracion escrita previamente y al ser parte de la biblioteca estandar de C, el compilador la reconoce.
        No es necesario el <stdio.h> ya que tenemos la declaracion escrita en el hello5.c

c) Ejecutar el hello5:
        Al ejecutar, lo que se muestra por pantalla es: " La respuesta es 4200688 " 
        Ese numero, esta tomando el %d que tenemos en el printf, al no pasar ninguna variable, tiene un comportamiento indefinido y su valor desborda, al compilar con -Wall nos muestra los warnings de la compilacion y como solucionarlos. 

### 4- CORRECIÓN DE BUG

a) Crear hello6.c con las correciones y compilar:
        Se agrega la variable i anteriormente creada dentro del printf. De esta manera el %d encuentra una variable de donde sacar el valor a mostrar por pantalla.
        El mensaje por pantalla es: "La respuesta es 42".

### 5- REMOCIÓN DE PROTOTIPO

a) Se crea hello7.c -> Ver hello7.c Compila correctamente

b) hello7.c Compila y ejecuta correctamente a pesar de no incluir el header stdio.h.
        Esto funciona ya que en C hay prototipos de funciones implicitas, como printf, en C printf se define como -> int printf(); 
        Recordemos que el #include <stdio.h> no incluye la biblioteca, sino que pega los prototipos de las funciones que se encuentan en ella en nuestro programa a compilar.

### 6- COMPILACIÓN SEPARADA: CONTRATOS Y MÓDULOS

a) Se crea studio1.c -> Ver studio1.c

b) Investigar como lograr que compilen juntos estos archivos .c:
    Para lograr que puedan generan un ejecutable entre ellos, debemos incluir uno en el otro, eso lo solucionamos con un #include "studio1.c" -> Compilamos con gcc -o hello8 hello8.c y para correr ./hello8
    Vemos que muestra correctamente el mensaje.
    Al incluir el studio1.c lo que hacemos es incluir en el Preprocesado el codigo que se encuenta en studio1.c que nos trae la definicion de prontf.

c) Eliminar o agregar elementos a la invocacion de prontf:
    Agregar:  "prontf ("La respuesta es %d\n", i, h);"
        error: too many arguments to function 'prontf'
         El compilador nos dice que no estamos invocando a la funcion prontf de manera correcta, no estamos utilizando la declaracion utilizada. No se puede compilar
    Eliminar: "prontf ("La respuesta es %d\n");"
        error: too few arguments to function 'prontf'
            Al igual que agregando un parametro el compilador nos dice que estamos utilizando de manera incorrecta la declaracion de prontf, esperamos 2 parametros y solo enviamos 1 o ninguno. No se puede compilar

d) Creamos studio.h -> hello9.c -> studio2.c
        Vemos que al compilar, agregando al compilador la instruccion -Wall no nos envia ningun error ni ningun warning, al agregar el #include <stdio.h> 
        printf nos deja enviar menos argumentos de lo que pide, lo cual trae problemas al ejecutar el programa, distintos overflows son posibles.



## Bibliotecas

### ¿Qué son?
        Las bibliotecas son cierto tipo de archivos que se puede importar dentro de nuestro programa. Estos archivos contienen las especificaciones de funciones construidas previamente, por ejemplo leer el teclado o mostrar algo por pantalla.
        Ayudan a la programacion haciendola mas facil sin tener que codear funciones conocidas una y otra vez.
### ¿Se pueden distribuir?
        Las bibliotecas son archivos que pueden ser locales o externos, hay muchas librerias conocidas, como por ejemplo stdio, math, string. Todas estas fueron creadas anteriormente y nosotros las podemos utilizar, esto demuestra que se pueden distribuir
### ¿Son Portables?
        Las mismas son portables, ya que para utilizarlas solo tenemos que incluir el archivo de cabecera en nuestro programa, de la forma #include <stdio.h> (En el caso de la biblioteca estandar de C) Tambien se puede incluir un archivo header que este en la misma ruta que nuestro programa C de la siguiente forma #include "nombrebiblioteca.h"
### ¿Cuales son sus ventajas y desventajas?
        Las ventajas de las mismas son poder tomar codigo ya escrito para agilizar los tiempos de programacion. No tener que hacer lo mismo una y otra vez.
        La cantidad de funciones en las bibliotecas de C son gigantes, desde imprimir en pantalla, funciones matematicas, hasta manejo de memoria y manejo de cadenas.
        Las desventajas pueden ser que hay ciertas funciones que no tiene un limite estipulado, causando problemas al ejecutar, por ejemplo printf. Si se deja un dato sin enviar del prototipo vamos a poner compilar igual y esto trae problemas en la ejecucion. Lo mismo con funciones de manejo de strings, no toman en cuenta el fin de la cadena, hay funciones creadas que no son del todo confiables.
        A si mismo el manejo de errores de algunas funciones, como las matematicas.