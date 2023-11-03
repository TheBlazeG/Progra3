# Resumen de capitulo 4 + final de 3
3.6 The Stack ADT
El tipo de dato Abstracto Stack, se caracteriza por tener un funcionamiento de tipo LIFO o last in first out, lo que significa que el ultimo dato agregado es tambien el primer dato que tiene que salir,para esto se tienen diferentes opciones como push back y pop, ambas interactuando con la serie de datos en el mismo lugar, el final de la lista
3.6.3 Applications
Algunos tipos de aplicaciones para un stack, es para el desarrollo de operaciones matematicas utilizando la notacion polaca inversa, de manera en que en un stack se juntan operadores aun no utilizados, esperando su turno para ejecutarse en orden.
3.7 The Queue ADT
El tipo de dato abstracto fila, se caracteriza por tener un funcionamiento del tipo FIFO o first in first out, cuenta con funciones como enqueue y dequeue, las cuales agregan datos al final de la lista y borran datos de la lista al frente respectivamente
3.7.3 Applications of Queues 115
Un posible ejemplo de aplicacion de un queue es la lista de tareas en una impresora, ya que las tareas se realizan de manera first come first served, tambien las filas de espera en sistemas de llamadas telefonicas, como cuando esperas a que te transfieran.

Chapter 4 Trees 
4.1 Preliminaries 
Un arbol puede ser definido como una serie de nodos, que cuenta con un nodo raiz seguido de 0 a mas de 1 sub arbol no vacio, siendo la raiz r y los sub arboles de r considerados como sus hijos, cualquier nodo que origina de otro se considera hijo del que se origina.
4.1.1 Implementation of Trees
Una manera en la que se puede implementar primero una arbol, es con un formato de lista de nodos, que funciona tomando en cuenta el primer hijo del nodo en caso de tener uno y el siguiente hermano de un nodo en caso de tener uno, esto ya que seria demasiado mantener en cada nodo una direccion a cada uno de sus hijos.
4.1.2 Tree Traversals with an Application
En este capitulo se explora el uso de un arbol para imprimir una serie de directorios de un sistema operativo, y la manera en que se imprimiria, se muestran 2 maneras, la primera siendo la preorden en la cual se procesa el nodo antes de sus hijos y termina de esta manera:
![[Pasted image 20231030225732.png]]
y la segunda la post-orden la cual primero procesa los hijos antes de procesar al nodo inicial, tambien se menciona en este metodo la manera en como funciona size, regresando el tamaño de un archivo si es que no es un directorio, en el caso de serlo suma el espacio de el directorio recursivamente con el de todos sus hijos.
![[Pasted image 20231030230145.png]]

4.2 Binary Trees
Los arboles binarios permiten solamente 2 hijos por nodo, lo cual hace a la estructura mas eficiente, en el peor de los casos funcionando como una lista simple
4.2.1 Implementation
Como el arbol binario solo puede tener 2 hijos por nodo la estrategia de mantener punteros a cada uno de sus hijos se hace viable, con un puntero de izquierda y un puntero de derecha.
4.2.2 An Example: Expression Trees
Se explora la idea de el uso de arboles para mas cosas que solo buscar, en este caso siendo una manera de representar operaciones matematicas y funcionando de una manera similar a la notacion polaca inversa, leyerndose de abajo para arriba y de derecha a izquierda, se leen datos y luego la operacion que les corresponde.
![[Pasted image 20231030230725.png]]
ademas se explica una manera de traspasar operaciones en la notacion polaca inversa directamente a un arbol de expresion, creando punteros con cada dato y uniendolos en otro con cada operador.
4.3 The Search Tree ADT—Binary Search Trees
Los arboles de busqueda binaria son eficientes por su tiempo de ejecucion y la cantidad de recursos utilizada, funcionan organizando datos de manera que todo dato que se encuentre del lado izquierdo de un nodo es menor al dato de ese nodo y cualquier dato que se encuentre del lado derecho del nodo es mayor al dato del nodo.
4.3.1 contains
Contains busca comparando el dato que ingresas con los del nodo para encontrar su posible ubicacion, si llega al lugar buscado y encuentra el dato ahi, regresa verdadero, sin embargo si no lo encuentra regresa falso.
4.3.2 findMin and findMax 
Find min funciona viajando a traves de los nodos unicamente hacia la izquierda hasta llegar al limite de los nodos, de esta manera llegando al minimo y regresando el ultimo valor encontrado, el find max funciona de la misma manera pero simetricamente, es decir que avanza a la derecha y regresa el ultimo valor encontrado
4.3.3 insert
Para insertar un nuevo nodo se utiliza el mismo sistema de busqueda de contains sin embargo, al llegar al lugar ideal ingresa el dato como un nuevo nodo, a la izquierda o derecha del nodo hoja dependiendo del caso.
4.3.4 remove
remove funciona como contains pero si encuentra el nodo que se busca simplemente lo elimina, no hace nada si no se encuentra el nodo.
4.3.5 Destructor and Copy Constructor
El destructor se encarga de recursivamente ir eliminando todos los hijos de los nodos hasta quedar en raiz y eliminarlo tambien, de esta manera recuperando todos los nodos utilizados previamente, copia utiliza clone para poder tomar una copia de Rhs y poder copiar sub arboles.
4.3.6 Average-Case Analysis
Despues de varios casos analizados en los que se muestra lo teoricamente posible dentro de la eficiencia de un arbol, se menciona que en promedio queda en 0(logN)
y sigue siendo muy dificil obtener un arbol muy desbalanceado, pero se menciona una manera de que sea imposible llegar a tener un arbol desbalanceado, la cual funciona rebalanceando luego de cierto punto.
4.4 AVL Trees
Los arboles binarios  AVL o Adelson-Velskii and Landis son arboles binarios de busqueda que mantienen una caracteristica de balance, la cual debe de ser simple de mantener y logra mantener la complejidad del arbol complero en 0(LogN) y la idea funciona con base en que la altura de los sub arboles izquierdos y derechos tengan la misma altura, sin embargo esta condicion es reducida en cuanto lo estricto que es, en vez de que solo puedan tener la misma altura, puere haber un margen de diferencia de 1, en el momento que se genera una diferencia de 2 se considera desbalanceado.
4.4.1 Single Rotation
La rotacion simple es clave y mecanica principal para poder rebalancear los arboles AVL, funciona haciendo un reacomodo de 2 nodos y sus hijos para volver a tener un balance dependiendo de la direccion de el desbalanceo si se hace siguiendo las manecillas del reloj o de manera opuesta:![[Pasted image 20231030233136.png]]
En este caso,se intercambia k1 con k2 equilibrando las alturas, el hijo derecho de k1 se transforma en el izquierdo de k2
4.4.2 Double Rotation
La doble rotacion ocurre cuando hay un desbalanceo en dos direcciones diferentes, en terminos simples es un nodo o sub arbol menor a su padre pero mayor a su abuelo o mayor a su padre pero menor a su abuelo:
![[Pasted image 20231030233433.png]]
en este ejemplo primero se intercambia con una rotacion simple k1 con k2, b transformandose en el hijo derecho de k1 y luego se hace otra rotacion simple de k2 con k3 para lograr el balance como se muestra en la parte derecha. 

Conclusión

Fuentes 
[1]«ARBOLES GENERALES». https://ccia.ugr.es/~jfv/ed1/tedi/cdrom/docs/arb_gen.htm
[2]«Árboles binarios», _Estructuras de datos_, 10 de junio de 2014. https://hhmosquera.wordpress.com/arbolesbinarios/
[3]MrRocket99, «Arbol Avl de Insercion y Eliminacion y Ordenamiento», _YouTube_. 5 de julio de 2018. [En línea]. Disponible en: https://www.youtube.com/watch?v=UnhMzEaLDdw
[4]
[5]