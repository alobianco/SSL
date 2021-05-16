##DD-FasesErrores

###1- PREPROCESADOR

    a) Tipear hello2.c:
        Ver archivo hello2.c

    b) Preprocesar hello2.c:
        <p><b>Para preprocesar el hello2.c -> gcc -E hello2.c > hello2.i</b>
            Al abrir el hello2.i vemos que el preprocesador toma el #include <stdio.h> copia todas las declaraciones de funciones del stdio.h y las pega en la parte superior de nuestro hello.i
            Tambien reemplaza los comentarios escritos en el hello2.c por un espacio.</p>

    c) Tipear hello3.c:
        Ver archivo hello3.c

    d) Investivar e indicar la semantica de la primera linea de hello3.c:
        La primera linea del hello3.c se declara una funcion llamada printf, los datos que recibe y los que devuelve, pero no nos explica como funciona

    e) Preprocesar hello3.c:
        <p><b>Para preprocesar el hello3.c -> gcc -E hello3.c > hello3.i</b>
            Aparecen comentarios especificos del preprocesador, fuera de eso no hay diferencias entre el hello3.c y hello3.i

###2- COMPILACIÓN

    a) Compilar hello3.i y generar hello3.s:
        Para realizar esto -> gcc -S hello3.i
        Nos mostrara los siguientes errores (No warnings):
            hello3.c:5:5: error: expected declaration or statement at end of input

    b) Corregir los errores del punto anterior en un hello4.c:
        Se crea un hello4.c corrigiendo esos errores -> Ver hello4.c
        Se genera el hello4.s Para eso:
            <b>gcc -S hello4.c -> Se crea hello4.s en Assembler</b>

    c) Objetivo del codigo hello4.s:
        Toma nuestro main y como esta lo "traduce" a Assembler. Crea un programa con la misma funcion de nuestro programa en C, asignar un valor a la variable entera i y llamar la funcion prontf.
        Esto no nos dice que el programa funcione, solo traduce lo escrito en C a Assembler
    
    d) Ensamblar el hello4.s:
       <b> Para eso as -o hello4.o hello4.s  </b>

###3- VINCULACIÓN

    a) Vincular hello4.o con la biblioteca estandar:
        <b>Para eso corremos: ld -o hello4 hello4.o </b>
            Vemos que nos tira diferentes errores al momento de enlazar, no reconoce 'prontf' ni 'main' que aparecen en el codigo de Assembler.
    
    b) Crear hello5.c con los problemas solucionados:
        Se crea el hello5.c -> Ver hello5.c
        Se cambia la funcion prontf por printf, ya que tenemos la declaracion escrita previamente y al ser parte de la biblioteca estandar de C, el compilador la reconoce.
        No es necesario el <stdio.h> ya que tenemos la declaracion escrita en el hello5.c

    c) Ejecutar el hello5:
        Al ejecutar, lo que se muestra por pantalla es: " La respuesta es 4200688 " 
        Ese numero, esta tomando el %d que tenemos en el printf, al no pasar ninguna variable, tiene un comportamiento indefinido y su valor desborda, al compilar con -Wall nos muestra los warnings de la compilacion y como solucionarlos. 

###4- CORRECIÓN DE BUG

    a) Crear hello6.c con las correciones y compilar:
        Se agrega la variable i anteriormente creada dentro del printf. De esta manera el %d encuentra una variable de donde sacar el valor a mostrar por pantalla.
        El mensaje por pantalla es: "La respuesta es 42".

###5- REMOCIÓN DE PROTOTIPO