
# Capítulo1 
## Exponents
Son las potencias normalmente utilizadas en matemáticas y física, en este caso servirán para calcular complejidad.
![[Pasted image 20231004185910.png]]
## Logarithms
Logaritmos, funcionan de tal manera que el logaritmo del número que tiene es igual a la potencia que tiene que tener para llegar a su base, por defecto en programación se tomara la base como 2 por su lógica binaria.
![[Pasted image 20231004190025.png]]
## Series
Las series son sumatorias de una serie de términos determinada por valores asignados en el problema.
## Modular arithmetic
La aritmética modular se basa en que mod utiliza el residuo de una división, por ejemplo mod10 aplicado a 620 resultaría en 20.
## The P word
La palabra P hace alusión a Pruebas, esto siendo pruebas lógicas del problema matemático a tratar y de porque una solución funciona, existen 3 tipos principales mostrados por el libro, Prueba por Inducción en la cual se prueba el caso base para luego probar el caso base +1, si éste funciona se considera verdadero,  Prueba por contradicción, en la cual se trata de demostrar que una de las propiedades que se utilizarán es incorrecta y al probar que es correcta se crea la prueba necesaria,  y Prueba por contraejemplo, la cual es una manera de mostrar que algo no puede ser posiblemente correcto al mostrar otra cosa que contradice una propiedad unicersal
## Recursion
La recursión es utilizada para que ciertos problemas o funciones se llamen a si mismos para ser resueltos un caso de esto es el escribir un número uno por uno.
## Classes
Estos son Objetos que Guardan datos o funciones los cuales también son llamados Miembros los cuales pueden ser públicos o privados, esto determina si otras clases pueden acceder a esos datos.
## C++ Details
### Punteros

Los punteros son un tipo de dato en el cual se puede asignar una estancia de memoria, con lo cual se pueden hacer referencias a diferentes valores.

### L valores y R valores
Los l valores son los datos que solo se pueden encontrar en la parte izquierda del código mientras que los r valores son los que se encuentran del otro lado del igual, la derecha por lo estos no son datos asignados a un espacio de memoria por ejemplo constantes.

Existe el tipo de paso de variable en el cual se divide en 3, Por valor el cual genera una copia, por referencia el cual no genera una copia y puede modificar el dato al que está referenciando y por referencia constante en el cual solo se puede accesar la información sin embargo no se puede modificar.

Se pueden determinar parámetros los cuales Determinan el tipo de dato que se va a utilizar lo que puede ayudar a reducir errores en compilacion por asignación predeterminada.

Move ayuda a mover valores asignados a l valores, aunque por si mismo move no genera ningún movimiento, modifica la variable para que pueda ser intercambiada con otras.

### Los 5 Grandes

Éstos están conformados por los destructores los cuales se utilizan e invocan para liberar memoria que se desea recuperar en el programa, estos deben ser llamados manualmente luego de haber usado un new, ya que new no se elimina automáticamente, constructor de copia, que crea la función de copia que conocemos, por ejemplo a=5, el constructor de movimiento, el cual nos ayuda a establecer referencias, los asignadores de copia y de movimiento como su nombre lo menciona son utilizados para asignar valores, estos 5 pueden ser modificados, sin embargo al modificar uno es recomendado volver a establecer cada uno de ellos aunque exista la posibilidad de usar los determinados de igual manera por buenas prácticas.

Los arrays y strings son herramientas incluidas en c, siguen siendo útiles, sin embargo muchos de sus usos pueden ser reemplazados con las librerías de vector y string, las cuales son más fáciles de utilizar.


## Templates
Existen diferentes tipos de plantillas, de función y de clase, el primer tipo por ejemplo, puede utilizar comparable para poder comparar todo tipo de datos sin necesariamente establecerlo directamente, por esto plantilla, por ejemplo se podría comparar un int con otro o un string con otro, aún así tienen que expandirse para lograr esto lo cual puede generar code bloat.

El segundo tipo utiliza object, de esta manera puede utilizar distintos tipos como primitivos y clases para su funcionamiento, utilizando este mismo concepto, se pueden generar matrices.

## Matrices
Las matrices pueden ser generadas con una plantilla de vector usando object, para luego reemplazar con vector, de esta manera generando un vector de vectores, de los cuales se pueden acceder a sus datos, por ejemplo con la sintaxis m[i]  [j] (Columna y fila).  
![[Pasted image 20231004201812.png]]
### Conclusión:
Las únicas dudas que tuve entre algunas cosas fueron de los funcionamientos de los constructores, más que nada por la sintaxis no tanto por el proceso que ocure detrás de cámara, tuve dudas de como implementar un template, pero como este es santi del futuro tengo menos, y asumí que lo veríamos en algún momento, tal vez sea buena idea hacer algunos ejemplos de matrices, por un tiempo estuve muy confundido con los & porque solo estabamos acostumbrados a usar uno, en algun momento mi cerebro mezcló datos y no entendía que move era otro concepto, cosa que ya entiendo tiene otra funcionalidad.
Los r valores y l valores los tengo muy en claro, si acaso hablar de uno refiriendo a otro puede llegar a ser confuso.
### Referencias:
M. A. Weiss, _Data Structures & Algorithm Analysis in C++_. 2012. [En línea]. Disponible en: http://ci.nii.ac.jp/ncid/BA4445754X
«Sucesiones y series», _StudySmarter ES_. https://www.studysmarter.es/resumenes/matematicas/analisis-matematico/sucesiones-y-series/
Contributors to Wikimedia projects, «Mathematical Proof/Methods of Proof/Counterexamples», _Wikibooks, open books for an open world_, nov. 2017, [En línea]. Disponible en: https://en.wikibooks.org/wiki/Mathematical_Proof/Methods_of_Proof/Counterexamples#:~:text=A%20proof%20by%20counterexample%20is,that%20contradicts%20a%20universal%20statement.
«Exponente de una potencia - Diccionario de Matemáticas | Superprof», _Diccionario de Matemáticas | Superprof_. https://www.superprof.es/diccionario/matematicas/aritmetica/exponente-potencia.html#:~:text=Qu%C3%A9%20significa%20exponente%20de%20una%20potencia%20en%20Matem%C3%A1ticas&text=El%20exponente%20de%20una%20potencia,la%20base%20por%20s%C3%AD%20misma.&text=El%20exponente%20de%20la%20potencia,de%20la%20potencia%20es%205.
Cienciayt, «C Matrices - Cienciayt», _Cienciayt_, 30 de abril de 2020. https://cienciayt.com/programacion/c/c-matrices/