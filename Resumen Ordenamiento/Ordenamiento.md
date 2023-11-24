# Métodos de ordenamiento

## Shellsort
Shell sort es descrito como un metodo de ordenamiento de incremento decreciente, primero se toma un incremento, el cual es determinado de diferentes maneras, el original siendo los incrementos de shell, los cuales no son los mas eficaces, pero pueden cambiar con diferentes resultados siendo uno de los mejores los de hibbard,el cual va comparando los datos entre 2 punteros separados por los incrementos diferentes, una vez termina el ciclo el incremento reduce su tamaño de tal manera que se hacen mas intercambios por cada pasada, sin embargo los datos grandes se mueven a la derecha y los datos pequeños se mueven a la izquierda generando asi una menor cantidad de movimientos total.
#### Complejidad espacial y Temporal  
El caso promedio de shellsort es de $nlog(n)^2$ el del peor caso es $n^2$ y el mejor caso es de $nlog(n)$ 
Su complejidad espacial es de $n$ porque no necesita espacio adicional mas que el temporal.
#### Ventajas y desventajas del algoritmo  
Su ventaja más grande diría yo que es que no es tan dificil de codificar y que no ocupa una gran cantidad de memoria para su funcionamiento.
#### En qué momento es útil 

## Mergesort
El mergesort Funciona para ordenar 2 listas ordenadas, pero puede ser utilizado recursivamente para ordenar cualquier cosa que no este ordenada, utilizando 2 punteros, cada uno al inicio de cada lista, luego se comparan los datos en los que se encuentran los punteros y se reintegra el elemento menor en una lista de mayor tamaño, luego se avanza el puntero de donde se sacó el dato, y se sigue el proceso de comparación hasta que se acaban los datos de uno de las listas y luego se suben todos los restantes de la ultima lista con datos.
#### Complejidad espacial y Temporal  
El caso promedio es de $nlogn$ el peor caso es $nlogn$ y el mejor es de $nlogn$ 
La complejidad Espacial es de $n^2$ porque necesita espacio para el arreglo auxiliar.
#### Ventajas y desventajas del algoritmo  
Tiene un buen tiempo de ejecución, sin embargo ocupa mucho más memoria que los anteriores, por lo tanto sirve cuando importa la eficiencia y no hay que preocuparse de recursos.
#### En qué momento es útil
Creo que uno de los mejores usos es cuando se tienen dos listas ya preciamente ordenadas ya que esto reduce el tiempo en que se ejecuta además de que es el caso más lógico 

## Quicksort
Quicksort funciona obteniendo un pivote de la siguiente manera, el primer termino mas el ultimo término sobre 2, se utiliza para determinar la posición del dato que se utilizará como pivote, luego se mueve el dato a la ultima posición para comenzar a ordenar los datos sin que pueda molestar, luego se establecen 2 punteros, los cuales se crean al inicio y al final-1 de la lista, el primer puntero ignora datos menores al pivote y el segundo puntero ignora datos mayores al pivote y avanzan en dirección uno al otro, se detienen en ciertos casos, el primer puntero al encontrar un dato mayor al pivote y el segundo puntero al encontrar un dato menor al pivote, si ambos se detienen, intercambian datos y siguen avanzando, si llegan a estar juntos el puntero izquierdo avanza un lugar y regresa el pivote enmedio del arreglo.
#### Complejidad espacial y Temporal  
Su caso promedio es de $nlogn$, su peor caso es de $n^2$ y su mejor caso es de $nlogn$ 
Su complejidad espacial es de n, ya que no requiere de espacio extra
#### Ventajas y desventajas del algoritmo 
El algoritmo es uno de los más rápidos en tiempos de ejecución además de que está preparado para resolver casos en los que se repite el dato del pivote, lo cual no genera un tiempo muy alto. 
#### En qué momento es útil
Es util específicamente con una cantidad mayor a 20 datos, ya que antes de ese punto el insertion sort es mejor para acomodar los datos, estos son algunas aplicaciones:
- Para ordenar una lista de números/nombres.
- Utilización antes de implementar una búsqueda binaria.
- Utilizado como el método de ordenamiento en tarjetas gráficas.
## Referencias
[1] M. A. Weiss, _Data Structures & Algorithm Analysis in C++_. 2012. [En línea]. Disponible en: http://ci.nii.ac.jp/ncid/BA4445754X
[2] H. Jindal, «Ordenamiento Shell», _Delft Stack_, 12 de octubre de 2023. https://www.delftstack.com/es/tutorial/algorithm/shell-sort/
[3] H. Jindal, «Ordenamiento por mezcla», _Delft Stack_, 12 de octubre de 2023. https://www.delftstack.com/es/tutorial/algorithm/merge-sort/
[4] H. Jindal, «Ordenamiento rápido», _Delft Stack_, 12 de octubre de 2023. https://www.delftstack.com/es/tutorial/algorithm/quick-sort/
[5] A. A. A. Alvarez, «Ventajas, desventajas y aplicaciones», _Quicksort_, 14 de octubre de 2017. https://quicksortweb.wordpress.com/2017/10/07/ventajas-desventajas-y-aplicaciones/
[6] 
[7] 