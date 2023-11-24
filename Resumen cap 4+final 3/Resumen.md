# Resumen de capitulo 4 + final de 3
## The Stack ADT
El tipo de dato Abstracto Stack, se caracteriza por tener un funcionamiento de tipo LIFO o last in first out, lo que significa que el ultimo dato agregado es tambien el primer dato que tiene que salir,para esto se tienen diferentes opciones como push back y pop, ambas interactuando con la serie de datos en el mismo lugar, el final de la lista
## Applications
Algunos tipos de aplicaciones para un stack, es para el desarrollo de operaciones matematicas utilizando la notacion polaca inversa, de manera en que en un stack se juntan operadores aun no utilizados, esperando su turno para ejecutarse en orden.
## The Queue ADT
El tipo de dato abstracto fila, se caracteriza por tener un funcionamiento del tipo FIFO o first in first out, cuenta con funciones como enqueue y dequeue, las cuales agregan datos al final de la lista y borran datos de la lista al frente respectivamente
## Applications of Queues 115
Un posible ejemplo de aplicacion de un queue es la lista de tareas en una impresora, ya que las tareas se realizan de manera first come first served, tambien las filas de espera en sistemas de llamadas telefonicas, como cuando esperas a que te transfieran.

## Chapter 4 Trees 
4.1 Preliminaries 
Un arbol puede ser definido como una serie de nodos, que cuenta con un nodo raiz seguido de 0 a mas de 1 sub arbol no vacio, siendo la raiz r y los sub arboles de r considerados como sus hijos, cualquier nodo que origina de otro se considera hijo del que se origina.
4.1.1 Implementation of Trees
Una manera en la que se puede implementar primero una arbol, es con un formato de lista de nodos, que funciona tomando en cuenta el primer hijo del nodo en caso de tener uno y el siguiente hermano de un nodo en caso de tener uno, esto ya que seria demasiado mantener en cada nodo una direccion a cada uno de sus hijos.
4.1.2 Tree Traversals with an Application
En este capitulo se explora el uso de un arbol para imprimir una serie de directorios de un sistema operativo, y la manera en que se imprimiria, se muestran 2 maneras, la primera siendo la preorden en la cual se procesa el nodo antes de sus hijos y termina de esta manera:
![[Pasted image 20231030225732.png]]
y la segunda la post-orden la cual primero procesa los hijos antes de procesar al nodo inicial, tambien se menciona en este metodo la manera en como funciona size, regresando el tamaño de un archivo si es que no es un directorio, en el caso de serlo suma el espacio de el directorio recursivamente con el de todos sus hijos.
![[Pasted image 20231030230145.png]]

## Binary Trees
Los arboles binarios permiten solamente 2 hijos por nodo, lo cual hace a la estructura mas eficiente, en el peor de los casos funcionando como una lista simple
## Implementation
Como el arbol binario solo puede tener 2 hijos por nodo la estrategia de mantener punteros a cada uno de sus hijos se hace viable, con un puntero de izquierda y un puntero de derecha.
## An Example: Expression Trees
Se explora la idea de el uso de arboles para mas cosas que solo buscar, en este caso siendo una manera de representar operaciones matematicas y funcionando de una manera similar a la notacion polaca inversa, leyerndose de abajo para arriba y de derecha a izquierda, se leen datos y luego la operacion que les corresponde.
![[Pasted image 20231030230725.png]]
ademas se explica una manera de traspasar operaciones en la notacion polaca inversa directamente a un arbol de expresion, creando punteros con cada dato y uniendolos en otro con cada operador.
## The Search Tree ADT—Binary Search Trees
Los arboles de busqueda binaria son eficientes por su tiempo de ejecucion y la cantidad de recursos utilizada, funcionan organizando datos de manera que todo dato que se encuentre del lado izquierdo de un nodo es menor al dato de ese nodo y cualquier dato que se encuentre del lado derecho del nodo es mayor al dato del nodo.
## Contains
Contains busca comparando el dato que ingresas con los del nodo para encontrar su posible ubicacion, si llega al lugar buscado y encuentra el dato ahi, regresa verdadero, sin embargo si no lo encuentra regresa falso.
## FindMin and findMax 
Find min funciona viajando a traves de los nodos unicamente hacia la izquierda hasta llegar al limite de los nodos, de esta manera llegando al minimo y regresando el ultimo valor encontrado, el find max funciona de la misma manera pero simetricamente, es decir que avanza a la derecha y regresa el ultimo valor encontrado
## Insert
Para insertar un nuevo nodo se utiliza el mismo sistema de busqueda de contains sin embargo, al llegar al lugar ideal ingresa el dato como un nuevo nodo, a la izquierda o derecha del nodo hoja dependiendo del caso.
## Remove
remove funciona como contains pero si encuentra el nodo que se busca simplemente lo elimina, no hace nada si no se encuentra el nodo.
## Destructor and Copy Constructor
El destructor se encarga de recursivamente ir eliminando todos los hijos de los nodos hasta quedar en raiz y eliminarlo tambien, de esta manera recuperando todos los nodos utilizados previamente, copia utiliza clone para poder tomar una copia de Rhs y poder copiar sub arboles.
## Average-Case Analysis
Despues de varios casos analizados en los que se muestra lo teoricamente posible dentro de la eficiencia de un arbol, se menciona que en promedio queda en 0(logN)
y sigue siendo muy dificil obtener un arbol muy desbalanceado, pero se menciona una manera de que sea imposible llegar a tener un arbol desbalanceado, la cual funciona rebalanceando luego de cierto punto.
## AVL Trees
Los arboles binarios  AVL o Adelson-Velskii and Landis son arboles binarios de busqueda que mantienen una caracteristica de balance, la cual debe de ser simple de mantener y logra mantener la complejidad del arbol complero en 0(LogN) y la idea funciona con base en que la altura de los sub arboles izquierdos y derechos tengan la misma altura, sin embargo esta condicion es reducida en cuanto lo estricto que es, en vez de que solo puedan tener la misma altura, puere haber un margen de diferencia de 1, en el momento que se genera una diferencia de 2 se considera desbalanceado.
## Single Rotation
La rotacion simple es clave y mecanica principal para poder rebalancear los arboles AVL, funciona haciendo un reacomodo de 2 nodos y sus hijos para volver a tener un balance dependiendo de la direccion de el desbalanceo si se hace siguiendo las manecillas del reloj o de manera opuesta:![[Pasted image 20231030233136.png]]
En este caso,se intercambia k1 con k2 equilibrando las alturas, el hijo derecho de k1 se transforma en el izquierdo de k2
## Double Rotation
La doble rotacion ocurre cuando hay un desbalanceo en dos direcciones diferentes, en terminos simples es un nodo o sub arbol menor a su padre pero mayor a su abuelo o mayor a su padre pero menor a su abuelo:
![[Pasted image 20231030233433.png]]
en este ejemplo primero se intercambia con una rotacion simple k1 con k2, b transformandose en el hijo derecho de k1 y luego se hace otra rotacion simple de k2 con k3 para lograr el balance como se muestra en la parte derecha. 

## Splay Trees
Los Splay tree, funcionan con la idea de que cuando se accesa a un dato, es muy probable que se vuelva a acceder al mismo dato, por lo tanto se rota el dato buscado a la raiz del arbol para su facil acceso en una nueva ocasion, sin embargo puede tener problemas para mantenerse con bajo tiempo de ejecución, Este tipo de arboles no tiene restriccion de altura/profundidad.


## A Simple Idea (That Does Not Work)
El problema ocurre ya que al momento de rotar el dato a la raíz se alejan o profundizan otros datos en el arbol, llegando a estar a la misma altura que el dato rotado o incluso mas profundo.
![[Pasted image 20231108230415.png]]
## Splaying
Existe una manera de arreglar el problema, implica el uso de rotaciones dobles si el camino sigue la misma direccion en dos nodos, y una simple si cambia de dirección después de 2 nodos, esto no solo acerca el dato y lo rota hasta la raíz, sino que también reduce el tiempo de acceso de los otros datos que se encontraban en camino al dato buscado y balancea el arbol, nombra a estos dos casos como zig-zig y zig-zag.
![[Pasted image 20231108230521.png]]

## Tree Traversals (Revisited)
Vuelve a hablar de las maneras de avanzar en un arbol, siendo.
1.-El arbol izquierdo del nodo, el lado derecho del nodo y luego el nodo analizado.
2.-El nodo y luego los arboles de lado izquierdo a derecho.
3.-Por niveles de profundidad, utilizando un queue.
## B-Trees
En esta seccion se menciona la posibilidad de tener datos fuera del disco en uso, lo que agrega a consideración los accesos y guardados en el otro disco, para esto introduce el concepto de arboles m-arios, dicho de otra manera, en vez de ser binarios son de una cantidad determinada por ejemplo 5arios pueden tener de 3 a 5 hijos, y funcionan con llaves para decidir cual camino tomar.
Tienen que tener estas condiciones en mente:
![[Pasted image 20231108231708.png]]
Un ejemplo de esto:
![[Pasted image 20231108231739.png]]
## Sets
Los Sets existen en STL como un tipo de dato abstracto con tiempo de eficiencia logaritmico, funcionan de una manera similar a la de las listas y usan iteradores, sin embargo hacen uso de los pares, en caso de insertar, iterador y bool:
![[Pasted image 20231108232327.png]]
versiones de erase:
![[Pasted image 20231108232417.png]]
Y en vez de utilizar contains se usa:
![[Pasted image 20231108232645.png]]
## Maps
Los Maps también forman parte de STL y como característica importante es el uso del operador [], el cual funciona no solo para buscar datos sino agregarlos también.
![[Pasted image 20231108233416.png]]
## An Example That Uses Several Maps
En esta unidad utiliza a los mapas como una herramienta para encontrar las palabras derivadas de una palabra de cuatro letras, primero generando un mapa con palabras de cuatro letras, luego creando diferentes con segmentos de la palabra original como sus llaves para luego utilizarlas para organizar palabras que contienen ese fragmento de la palabra original y de esta manera reducir el tiempo en el que se logra la busqueda de palabras que pueden generarse a partir de la original con un cambio de letra.
![[Pasted image 20231108234332.png]]


Conclusión
La lección fue difícil en ciertos puntos, específicamente en los puntos en los que se explican las rotaciones,sin embargo al entenderlo por completo el aplicarlo y sus derivadas se hace trivial en su mayor parte y me sorprendió la manera en la que hablan del stack y sus aplicaciones, y la variedad de cosas que se pueden hacer con el, me gustaria repasar los M − 1 keys, un poco general de b-trees y la diferencia entre los dos simbolos de o notation, aunque si no me equivoco significan best case y worst case, tal vez casos de rotaciones largas en clase.

Fuentes 
[1]«ARBOLES GENERALES». https://ccia.ugr.es/~jfv/ed1/tedi/cdrom/docs/arb_gen.htm
[2]«Árboles binarios», _Estructuras de datos_, 10 de junio de 2014. https://hhmosquera.wordpress.com/arbolesbinarios/
[3]MrRocket99, «Arbol Avl de Insercion y Eliminacion y Ordenamiento», _YouTube_. 5 de julio de 2018. [En línea]. Disponible en: https://www.youtube.com/watch?v=UnhMzEaLDdw
[4]Rajinikanth, «Data Structures Tutorials - Splay tree with an example». http://www.btechsmartclass.com/data_structures/splay-trees.html
[5]GeeksforGeeks, «Set in C Standard Template Library STL», _GeeksforGeeks_, 23 de septiembre de 2023. https://www.geeksforgeeks.org/set-in-cpp-stl/
[6]GeeksforGeeks, «Map in C Standard Template Library STL», _GeeksforGeeks_, 30 de octubre de 2023. https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/