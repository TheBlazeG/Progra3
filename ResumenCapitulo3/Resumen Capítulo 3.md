## Abstract Data Types (ADTs)
Los tipos de datos abstractos son un grupo de objetos los cuales cuentan con una serie de operaciones en específico, objetos como listas, sets y gráficas pueden ser tipos de datos abstractos, de la misma que existen otros en la programación como los enteros dobles o booleanos y cuentan con operaciones como "add, remove, size, contains pushback" entre otros.

Aunque estos tipos cuentan con estas operaciones no hay nada que nos diga que operaciones tienen que funcionar con nuestros datos implementados, podríamos crear nuestras propias listas que por alguna razón no tuvieran compatibilidad para remover datos.
![[Pasted image 20231005224820.png]]
## The List ADT
Cuando tenemos una lista la forma que comúnmente se usa, es de múltiples datos con un orden, una manera de observarlo, es con letras y números representando sus lugares respectivos en la lista, a1,a2,a3,a4,a5,a6,a7, a1 siendo el primer dato de la lista y a7 el último de la misma, también observando el número del último dato de la lista podemos conseguir el tamalo de la lista, en este caso siendo 7, las listas tienen operaciones que son comunmente asociadas con ellas como printList (la cual imprime la lista), makeEmpty (la cual la vacía) tipos de buscadores los cuales pueden ser definidos de diferentes maneras por el programador, como utilizarlos para buscar cierto dato en la lista o en cierto lugar de la lista.

## Simple Array Implementation of Lists 
Una manera simple de implementar una lista, sin embargo este tipo de lista está limitado de diferentes maneras, una por ejemplo siendo la inserción de datos, la cual funciona de buena manera si solo se van a agregar datos al final de el arreglo, ya que no es necesario desplazar de ninguna manera, solo se agregan, el problema viene cuando se necesitan agregar datos a lo largo de el arreglo, entre más cerca al inicio más datos se mueven, haciendolo poco eficiente, para estos casos es mejor usar una lista enlazada.

## Simple Linked Lists
La lista enlazada funciona de una manera en la que los datos tienen que estar guardados de una manera no contigua, ya que si se tuviera que agregar un dato se tendría que desplazar todo lo demás.

Existen 2 tipos de listas enlazadas:
### Simple
En la lista enlazada simple se mantiene un puntero en al dato al cual se le asigna la posición del siguiente elemento en la lista, formando una cadena de a dónde avanzar para seguir con la lista, de esta manera se implementan nuevas formas de agregar y quitar datos en una lista, al borrar un dato de la lista lo único necesario es reemplazar la ubicación del puntero que se quiere eliminar y asignarsela al anterior al borrado.
![[Pasted image 20231005195153.png]]
Gracias a los punteros es más fácil agregar datos y borrar datos de la lista, incluso al final, mientras se mantenga un puntero, sin embargo para encontrarlos con metodos de búsqueda puede que se tengan problemas pues solo se avanza hacia adelante pero no puedes regresar en el camino,
por lo tanto es menos eficiente que el arreglo, pero esto tiene una solución, la lista doble enlazada.
![[Pasted image 20231005195215.png]]
### Doble
Una lista enlazada doble tiene eso mismo, dos punteros, uno asignado al frente y uno asignado al final, de esta manera el avanzar y regresar dentro de la lista se vuelve más eficiente, y los únicos cambios que se hacen al agregar y borrar datos, es el borrado y asignado del puntero extra que tienen los datos.
## Vector and list in the STL
Existen dos implementaciones de lista que sobresalen, siendo estas el vector y la lista, teniendo diferentes ventajas cada una, el vector es indexable en tiempo constante por ejemplo pero el agregar datos a un vector puede ser costoso, además de que si al final del vector no hay espacio se duplica el espacio a utilizar con el fin de no tener que aumentar el espacio o aumentarlo la cantidad menor de veces, para esto puede ayudar el tener un estimado de datos que se utilizarán ya que se puede establecer una cantidad de espacios en el vector.

La lista doble enlazada o **List** no es indexada con la misma facilidad pero el agregar y quitar datos es más eficiente y barato que con los vectores, para ambos los algoritmos de búsqueda son eficientes.

Ambos tipos de listas son templates los cuales pueden albergar cualquier tipo de dato y comparten ciertos métodos como lo son size, el cual regresa el tamaño de la lista, clear el cual borra todos los elementos de la lista, empty la cual regresa un booleano(verdadero si está vacía y falso si contiene datos).

Tienen maneras de agregar, quitar datos y obtenerlos, push_back agrega un objeto al final de la lista, pop back **quita** un dato de la lista, front muestra el dato de al frente de la lista, vack muestra el último dato de la lista.

Por la eficiencia de agregar datos en cualquier parte de la lista, esta cuenta con métodos exclusivos, como push_front el cual agrega un dato al inicio de la lista, o pop front el cual borra el primer elemento de la lista.

De la misma manera vector tiene sus ventajas y propios métodos, como el operador [], el cual se utiliza para obtener el dato indexado en la posición escrita dentro de el, at el cual hace algo parecido pero con bounds checking, capacity, el cuál muestra la capacidad interna del vector, reserve, con el cuál puedes asignar una capacidad nueva previamente mencionada útil si se tiene un estimado.

## Iterators
Los iteradores son muestran la posición de un dato y se encuentran anidados dentro de cada dato en la lista,existen varias maneras de conseguir un iterador, como son begin y end, consiguiendo el inicio y el final respectivamente, aunque end muestra un iterador fuera del espacio, lo cual es raro a menos que tomes en cuenta usos como en un while o for, en los cuales se avanza hasta llegar a el, de esta manera por ejemplo, imprimiendo todos los datos de la lista, existen diferentes métdos que se pueden utilizar con iteradores:

itr++ y ++itr: avanza el iterador a la siguiente posición, y ambas maneras de escribirlo se admiten

/* itr(ignorar el / en todos los ejemplos, sin el no se puede escribir el simbolo o combinación): regresa una referencia al objeto guardado en la locación del iterador, se puede ambos no y modificar el dato accesado

itr1=/=itr2: regresa verdadero si ambos son iguales y falso si son diferentes

itr!=itr2 regresa verdadero si son diferentes y falso si son iguales
próximo se encuentra un ejemplo de print
![[Pasted image 20231005204537.png]]

existen operaciones las cuales utilizan un iterador las cuales pueden ser insert y erase, la primera para insertar un dato en la posición del iterador, erase borrando o un dato, o un rango de datos desde un iterador a otro.

![[Pasted image 20231005231537.png]]
## Using erase on a List
En el momento que se utiliza erase en una lista, este actua para eliminar todos los elementos de una lista, se posiciona el elemento al inicio de la lista, se borra el elemento y se avanza en el iterador hasta que llegue al final, de esta manera borrando todo.

## Const_iterators
Los iteradores cuentan con la posibilidad de ser constantes, esto ya que se puede acceder al objeto mismo con ellos, si no se quiere permitir un cambio a los datos, se establece como constante, de esta manera ninguna parte del cógido podría modificarlo, evitando alteración de datos importantes, cuando se trata de asignar datos a un iterador constante da un error  de compilador y es facil detectar líneas de código ilegales, se puede utilizar auto para que el programa mismo deduce si necesita un iterador o un iterador constante.

Existe una función que permite escribir de otras maneras, como por ejemplo begin(c) en vez de c.begin() para lugares donde begin es miembro.
## Implementation of vector
Una de las ventajas de vector es que puede ser copiado y también se pueden recuperar sus recursos gracias a su destructor.

Algunas propiedades de arreglos son que es un puntero asignado a un bloque de memoria, y el tamaño lo mantiene el programador aparte,puedes dar un bloque de memoria utilizando new pero tendría que borrarse con delete, y no se puede cambiar el tamaño del arreglo, se puede copiar a otro mas grande y borrar el anterior, de esta manera recuperando el bloque antiguo.

El vector cuenta con estas características:
* Mantiene un arreglo primitivo
* Implementa los 5 grandes para conseguir funciones como copias y destructores para recuperar memoria
* Obtiene la posibilidad de aumentar el tamaño obteniendo un bloque de memoria mayor
* Agrega el uso de operador [] 
* Agrega rutinas para agregar y quitar datos como pop, push,back y reserve.
* Da soporte a tipos anidados como los iteradores e iteradores constantes
## Implementation of list
**List** refiere al tipo de lista enlazada doble, la cual tiene punteros en ambas orillas de cada dato y la lista siendo el inicial y el final fijados en nullptr.

Dentro de la lista se necesitan incluir 4 tipos de clases:
* La lista misma.
* Los nodos que contienen los datos y punteros de proximos y previos datos.
* El iterador constante que permite uso de operadores como =, doble =, != y ++
* El iterador el cual tiene la noción de la posición igual que el constante, pero este muestra referencia al dato, se puede utilizar en cualquier lugar que uno constante se use, pero no viceversa.

Existen los nodos sentinelas, normalmente siendo header y tail, los cuales ayudan para evitar casos especiales como al remover un dato, ya que normalmente se necesita accessar al dato anterior al borrar uno, y sería un caso especial si ocurriera al inicio sin el nodo sentinela header.
![[Pasted image 20231005214101.png]]
Se muestra una lista vacía, solo conteniendo los nodos sentinela.

Funciones como erase borran los datos que contiene la lista comenzando por los que están entre header y tail y borrándolos al final.

Se puede declarar a otra clase como amigo, esto se puede utilizar para que la lista sea capaz de acceder a miembros no publicos de una clase como la de los iteradores constantes.

Gracias a los iteradores, se puede borrar un dato con ellos, adelante una imagen del proceso, representando con p el nodo al que hace referencia el iterador.
![[Pasted image 20231005214534.png]]

## Conclusión
Lo más confuso sigue siendo la sintaxis, puede costar algo de tiempo pero cuando lo entiendes se vuelve más tranquilo, me gustaría ver algunos usos de bound checking el cual se menciona en el método at, para mi la lógica sigue siendo de los aspectos más comprensibles que hay, el asociar cada parte con el código es donde se puede encontrar más complejidad, me gusta este acercamiento que se tiene con el libro, ya que habla específicamente de cosas como tiempo y eficiencia cosas que antes no nos mencionaban tanto, es verdad que tiene grado de complejidad entender el lenguaje como dice gibrán pero entiendo que para el ritmo que tenemos sea normal no entender cosas y también terminarlas entendiendo por contexto es una parte grande de mi aprendizaje, por lo tanto puede que al inicio no entienda conceptos pero con el tiempo los aprenda por una especie de "osmosis".

## Referencias
GeeksforGeeks, «Abstract data types», _GeeksforGeeks_, sep. 2023, [En línea]. Disponible en: https://www.geeksforgeeks.org/abstract-data-types/
Wikipedia contributors, «Bounds checking», _Wikipedia_, feb. 2023, [En línea]. Disponible en: https://en.wikipedia.org/wiki/Bounds_checking
EcuRed, «Iteradores (Programación) - ECURed». https://www.ecured.cu/Iteradores_(Programaci%C3%B3n)
«Patrón de diseño “Iterador”». https://thewhitecode.com/blog/0109