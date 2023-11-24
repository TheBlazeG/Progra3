# Métodos de ordenamiento

## Shellsort
Shell sort es descrito como un metodo de ordenamiento de incremento decreciente, primero se toma un incremento, el cual es determinado de diferentes maneras, el original siendo los incrementos de shell, los cuales no son los mas eficaces, pero pueden cambiar con diferentes resultados siendo uno de los mejores los de hibbard,el cual va comparando los datos entre 2 punteros separados por los incrementos diferentes, una vez termina el ciclo el incremento reduce su tamaño de tal manera que se hacen mas intercambios por cada pasada, sin embargo los datos grandes se mueven a la derecha y los datos pequeños se mueven a la izquierda generando asi una menor cantidad de movimientos total.
#### Complejidad espacial y Temporal  
El caso promedio de shellsort es de $nlog(n)^2$ el del peor caso es $n^2$ y el mejor caso es de $nlog(n)$ 
Su complejidad espacial es de $1$ porque no necesita espacio adicional mas que el temporal.
#### Ventajas y desventajas del algoritmo  
Su ventaja más grande diría yo que es que no es tan dificil de codificar y que no ocupa una gran cantidad de memoria para su funcionamiento.
#### En qué momento es útil 
El shellsort, no considero es tan util como los demas, ya que su eficiencia no es muy alta, sin embargo podria ser utilizado en sistemas donde no se tiene mucha memoria.

```c
#include <bits/stdc++.h>
using namespace std;
void shellSort(int arr[], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i += 1) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
        arr[j] = arr[j - gap];
      arr[j] = temp;
    }
  }
}
int main() {
  int n = 8;
  int arr[8] = {9, 8, 3, 7, 5, 6, 4, 1};
  cout << "Input arr: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  shellSort(arr, n);  // Sort elements in ascending order
  cout << "Output arr: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
```

## Mergesort
El mergesort Funciona para ordenar 2 listas ordenadas, pero puede ser utilizado recursivamente para ordenar cualquier cosa que no este ordenada, utilizando 2 punteros, cada uno al inicio de cada lista, luego se comparan los datos en los que se encuentran los punteros y se reintegra el elemento menor en una lista de mayor tamaño, luego se avanza el puntero de donde se sacó el dato, y se sigue el proceso de comparación hasta que se acaban los datos de uno de las listas y luego se suben todos los restantes de la ultima lista con datos.
#### Complejidad espacial y Temporal  
El caso promedio es de $nlogn$ el peor caso es $nlogn$ y el mejor es de $nlogn$ 
La complejidad Espacial es de $n^2$ porque necesita espacio para el arreglo auxiliar.
#### Ventajas y desventajas del algoritmo  
Tiene un buen tiempo de ejecución, sin embargo ocupa mucho más memoria que los anteriores, por lo tanto sirve cuando importa la eficiencia y no hay que preocuparse de recursos.
#### En qué momento es útil
Creo que uno de los mejores usos es cuando se tienen dos listas ya preciamente ordenadas ya que esto reduce el tiempo en que se ejecuta además de que es el caso más lógico 

codigo ejemplo
```c
#include <iostream>
using namespace std;

void merge(int arr[], int beg, int mid, int end) {
  int output[end - beg + 1];
  int i = beg, j = mid + 1, k = 0;
  // add smaller of both elements to the output
  while (i <= mid && j <= end) {
    if (arr[i] <= arr[j]) {
      output[k] = arr[i];
      k += 1;
      i += 1;
    } else {
      output[k] = arr[j];
      k += 1;
      j += 1;
    }
  }
  // remaining elements from first array
  while (i <= mid) {
    output[k] = arr[i];
    k += 1;
    i += 1;
  }
  // remaining elements from the second array
  while (j <= end) {
    output[k] = arr[j];
    k += 1;
    j += 1;
  }
  // copy output to the original array
  for (i = beg; i <= end; i += 1) {
    arr[i] = output[i - beg];
  }
}

void mergeSort(int arr[], int beg, int end) {
  if (beg < end) {
    int mid = (beg + end) / 2;
    // divide and conquer
    mergeSort(arr, beg, mid);      // divide : first half
    mergeSort(arr, mid + 1, end);  // divide: second half
    merge(arr, beg, mid, end);     // conquer
  }
}
int main() {
  int n = 6;
  int arr[6] = {5, 3, 4, 2, 1, 6};
  cout << "Input array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  mergeSort(arr, 0, n - 1);  // Sort elements in ascending order
  cout << "Output array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
```
## Heapsort
El heapsort hace uso de una estructura de datos llamada heap, esto es una pequeña descripción de chat gpt:
"Un heap es una estructura de datos especializada basada en árboles que satisface la propiedad de heap. En un max heap, para cada nodo `i` que no sea la raíz, el valor de `i` es menor o igual al valor de su padre. En un min heap, para cada nodo `i` que no sea la raíz, el valor de `i` es mayor o igual al valor de su padre."[6]
Para este metodo de ordenamiento se crea un max heap con el arreglo, y luego el termino del origen se envia al final del arreglo, el proceso se repite con cada vez menos datos hasta llegar a tener el arreglo completamente acomodado.
#### Complejidad espacial y Temporal  
la complejidad de todos los casos esta dada por $nlogn$ y su complejidad espacial es de 1 porque solo necesita espacio temporal
#### Ventajas y desventajas del algoritmo  
La ventaja que tiene es su tiempo de ejecucion mas su consumo de espacio bajo solo siendo comparable con shell pero este gana en eficiencia.

#### En qué momento es útil
Al momento de necesitar procesar cantidades gigantes de datos, de esta manera no se necesitaria espacio extra en caso de estar usando la mayoria con los datos.

Codigo ejemplo 
```c
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
  int parent = i;
  int leftChild = 2 * i + 1;
  int rightChild = 2 * i + 2;

  if (leftChild < n && arr[leftChild] > arr[parent]) parent = leftChild;

  if (rightChild < n && arr[rightChild] > arr[parent]) parent = rightChild;

  if (parent != i) {
    swap(arr[i], arr[parent]);
    heapify(arr, n, parent);
  }
}

void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main() {
  int n = 6;
  int arr[6] = {5, 3, 4, 2, 1, 6};
  cout << "Input array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  heapSort(arr, n);  // Sort elements in ascending order
  cout << "Output array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
```
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
codigo ejemplo
```c
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int beg, int end) {
  // Select the last element as pivot element
  int pivot = arr[end];
  int i = (beg - 1);
  // Move smaller elements to left side and larger on right side
  for (int j = beg; j < end; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1],
       arr[end]);  // Move pivot element to its right position in array
  return (i + 1);
}

void quickSort(int arr[], int beg, int end) {
  if (beg < end) {
    int pi = partition(arr, beg, end);
    quickSort(arr, beg,
              pi - 1);  // Recursive Sort element on left side of partition
    quickSort(arr, pi + 1,
              end);  // Recursive Sort element on right side of partition
  }
}
int main() {
  int n = 6;
  int arr[6] = {5, 3, 4, 2, 1, 6};
  cout << "Input array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  quickSort(arr, 0, n - 1);  // Sort elements in ascending order
  cout << "Output array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
```
# Opinión Crítica 
Tengo un mejor entendimiento de los metodos de ordenamiento y de sus usos, ventajas y desventajas, con ayudas visuales me fue aun mas facil de entender, lo único que me gustaría agregar es que las comprobaciones matemáticas me confundieron en muchos momentos.

## Referencias
[1] M. A. Weiss, _Data Structures & Algorithm Analysis in C++_. 2012. [En línea]. Disponible en: http://ci.nii.ac.jp/ncid/BA4445754X
[2] H. Jindal, «Ordenamiento Shell», _Delft Stack_, 12 de octubre de 2023. https://www.delftstack.com/es/tutorial/algorithm/shell-sort/
[3] H. Jindal, «Ordenamiento por mezcla», _Delft Stack_, 12 de octubre de 2023. https://www.delftstack.com/es/tutorial/algorithm/merge-sort/
[4] H. Jindal, «Ordenamiento rápido», _Delft Stack_, 12 de octubre de 2023. https://www.delftstack.com/es/tutorial/algorithm/quick-sort/
[5] A. A. A. Alvarez, «Ventajas, desventajas y aplicaciones», _Quicksort_, 14 de octubre de 2017. https://quicksortweb.wordpress.com/2017/10/07/ventajas-desventajas-y-aplicaciones/
[6] https://chat.openai.com/ ,«Que es un heap?»,24 de noviembre de 2023. https://chat.openai.com/
[7] H. Jindal, «Ordenamiento por montículos», _Delft Stack_, 12 de octubre de 2023. https://www.delftstack.com/es/tutorial/algorithm/heap-sort/
[8]V. Singh, «Big O notation : time complexity of an algorithm», 6 de febrero de 2021. https://www.linkedin.com/pulse/big-o-notation-time-complexity-algorithm-vikas-kumar/