# Lista Doble
```c++
//
// Created by santi on 11/2/2023.
//

#ifndef REVISIONCOMPLETA_DLLIST_H
#define REVISIONCOMPLETA_DLLIST_H
#include <iostream>
#include <utility>

template <typename Object>
class DLList{
private:
    struct Node  {
        Object data;
        Node *next;
        Node *prev;

        //Constructor de copia
        Node(const Object &d = Object{}, Node *n = nullptr, Node *p = nullptr)
                : data{d}, next{n}, prev{p} {}

        //Constructor de referncia
        Node(Object &&d, Node *n = nullptr, Node *p = nullptr)
                : data{std::move(d)}, next{n}, prev{p} {}
    };

public:
    class iterator{
    public:
        //constructor implicito, se establece nulo el puntero
        iterator() : current{nullptr} {}

        //Operador * para que se comporte como puntero
        Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        //Operador ++ hace que se pueda mover por la lista.
        iterator &operator++() {
            if(current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }

        iterator &operator--() {
            if(current)
                current = current->prev;
            else
                throw std::logic_error("Trying to decrease past the beginning.");
            return *this;
        }

        iterator operator--(int) {
            iterator old = *this;
            --(*this);
            return old;
        }

        iterator &operator+(int addition){

            for(int i = 0; i<addition;i++){
                ++(*this);
            }
            return  *this;
        }

        //Operadores para realizar comparaciones
        bool operator==(const iterator &rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }

    protected:
        //apunta al nodo al que estoy trabajando en ese momento
        Node *current;
        iterator(Node *p) : current{p} {}
        //la clase amigo de acceso a los atributos privados
        friend class DLList<Object>;

        Object & retrieve() const{
            return current->data;
        }
    };

public:
    //Define la dimension de la lista
    //Cuando se llame al constructor, ya tiene que estar una cabeza y una cola
    DLList() {
        init();
    }

    //Destructor de la lista
    //Primero borra el contenido y despues la cola y la cabeza
    ~DLList() {
        clear();
        delete head;
        delete tail;
    }

    //Sirve para meter el iterador al principio o al final
    iterator begin() { return {head->next}; }
    iterator end() { return {tail}; }

    //el tamaño de la lista, para que un iterador sepa cuanto debe recorrer
    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

    //Mientras no este vacia borra el objeto de en frente
    void clear() { while (!empty()) pop_front(); }

    //Si la lista esta vacia da un error, si no retorna el inicio
    Object &front() {
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }

    //funcion de push por copia
    void push_front(const Object &x) {
        insert(begin(), x);
    }
    //funcion de push por referencia
    void push_front(Object &&x) {
        insert(begin(), std::move(x));
    }

    void push_back(const Object &x) {
        insert(end(), x);
    }
    //funcion de push por referencia
    void push_back(Object &&x) {
        insert(end(), std::move(x));
    }

    //elimina el valo de en frente
    void pop_front() {
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }

    //Recibe un iterador, lee esa posicion e inserta un código en la posicion que le demos
    //este funciona por copia
    iterator insert(iterator itr, const Object &x) {
        Node *p = itr.current;
        theSize++;
        return {p->prev = p->prev->next = new Node{x, p, p->prev}};
    }

    //este funciona por referencia
    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        theSize++;
        return {p->prev = p->prev->next = new Node{std::move(x), p, p->prev}};
    }

    void insert(int pos, const Object &x) {
        insert(get_iterator(pos), x);
    }

    iterator get_iterator(int a)
    {
        iterator it = begin();
        for(int i = 0; i != a; ++i) {
            ++it;
        }
        return it;
    }

    //recibe un iterador y borra el dato en la posicion que le digamos
    iterator erase(iterator itr) {

        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node *p = itr.current;
        iterator returnValue(p->next);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;

        return returnValue;
    }

    void erase(int pos)
    {
        erase(get_iterator(pos));
    }

    //Getter para toda la lista
    void print() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }


protected:
    Node *head;
    Node *tail;
    int theSize;
    //init necesita acceso a los datos privados para inicializar una lista vacia
    void init() {
        head = new Node;
        tail = new Node;
        theSize = 0;

        head->next = tail;
        head->prev = nullptr;

        tail->prev = head;
        tail->next = nullptr;
    }


};
#endif //REVISIONCOMPLETA_DLLIST_H
```
La única complicación que tuvo la lista doblemente enlazada fue la que nos ayudó a resolver, fuera de eso no hubo nada en lo que yo considere me haya atorado en esta entrega, aqui se definen las funciones que utilizaremos con herencia para el stack y el queue y cuenta con una complejidad lineal.
# Lista Simple

```c++
//
// Created by santi on 11/2/2023.
//

#ifndef REVISIONCOMPLETA_SLLIST_H
#define REVISIONCOMPLETA_SLLIST_H
#include <iostream>
#include <utility>

template <typename Object>
class SLList {
private:
    //Cada Cuadrito
    struct Node  {
        Object data;
        Node *next;//Anya

        Node(const Object &d = Object{}, Node *n = nullptr)
                : data{d}, next{n} {}

        Node(Object &&d, Node *n = nullptr)
                : data{std::move(d)}, next{n} {}
    };

public:
    class iterator {
    public:
        iterator() : current{nullptr} {}

        Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        iterator &operator++() {
            if(current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const iterator &rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }

    private:
        Node *current;
        iterator(Node *p) : current{p} {}
        friend class SLList<Object>;
    };

public:
    SLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }

    ~SLList() {
        clear();
        delete head;
        delete tail;
    }

    iterator begin() { return {head->next}; }
    iterator end() { return {tail}; }

    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

    void clear() { while (!empty()) pop_front(); }

    Object &front() {
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }

    void push_front(const Object &x) { insert(begin(), x); }
    void push_front(Object &&x) { insert(begin(), std::move(x)); }

    void pop_front() {
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }

    iterator insert(iterator itr, const Object &x) {
        Node *p = itr.current;
        head->next = new Node{x, head->next};
        theSize++;
        return iterator(head->next);
    }

    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        head->next = new Node{std::move(x), head->next};
        theSize++;
        return iterator(head->next);
    }

    iterator erase(iterator itr) {
        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node *p = head;
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current;
        theSize--;
        return iterator(p->next);
    }

    void print() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

private:
    Node *head;
    Node *tail;
    int theSize;
    void init() {
        theSize = 0;
        head->next = tail;
    }
};

#endif //REVISIONCOMPLETA_SLLIST_H
```
En la lista simple solo se utilizan punteros hacia adelante sin la funcionalidad de regresar, tambien es lineal.

# Queue
```c++
#ifndef REVISIONCOMPLETA_QUEUE_H
#define REVISIONCOMPLETA_QUEUE_H


#include "DLList.h"

template<typename DataType>
class Queue : private DLList<DataType>{ //se accede para heredar de forma privada de la doble lista
public:
    Queue(){
    }

    ~Queue(){//se heredan destructores
        clear();
        delete DLList<DataType>::head;
        delete DLList<DataType>::tail;
    }

    void enqueue(DataType &data){//funcion para agregar dato a la lista, llama al push back original
        DLList<DataType>::push_back(data);
    }

    void enqueue(DataType &&data){//funcion pero con uso de referencia
        DLList<DataType>::push_back(data);
    }

    void dequeue(){//funcion de dequeue, aprovecha el pop front original
        DLList<DataType>::pop_front();
    }

    void print(){//funcion para imprimir, heredada de la lista doble
        DLList<DataType>::print();
    }

    void clear(){
        DLList<DataType>::clear();//borra todos los elementos
    }

    DataType front(){//muestra el valor al frente de la lista
        return DLList<DataType>::head->next->data;
    }
};

#endif //PROYECTO_SEGUNDO_PARCIAL_QUEUE_H
```
Queue funciona como una fila, una manera en que es llamado es FIFO (First in First Out), solamente puede hacer operaciones en 2 partes , al inicio y al final, al inicio puede hacer dequeue que quita el dato y al final puede hacer queue para agregar un dato, por estas razones tiene complejidad constante.
# Stack
```c++
#ifndef REVISIONCOMPLETA_STACK_H
#define REVISIONCOMPLETA_STACK_H
#include <iostream>
#include <cstdlib>
#include "DLList.h"

template <typename DataType>
class Stack : private DLList<DataType> {//se accede para heredar de forma privada de la doble lista
public:
    Stack() {
    }

    ~Stack(){//se heredan destructores
        clear();
        delete DLList<DataType>::head;
        delete DLList<DataType>::tail;
    }

    void push(DataType &data){//funcion push llamando a la funcion push front original
        DLList<DataType>::push_front(data);
    }
    void push(DataType &&data){//funcioon push con uso de referencia en el parametro
        DLList<DataType>::push_front(data);
    }

    void pop(){//funcion pop que llama la funcio pop fron del archivo original
        DLList<DataType>::pop_front();
    }

    void clear(){//llama al clear original
        DLList<DataType>::clear();
    }

    void print(){//llama al print original
        DLList<DataType>::print();
    }

    DataType top(){//regresa el primer dato de la lista o stack
        return DLList<DataType>::head->next->data;
    }
};

#endif //PROYECTO_SEGUNDO_PARCIAL_STACK_H
```

El stack solamente accede a un espacio de la lista, de una manera visual la parte superior de una pila (LIFO, Last in First out), por esto solo puede agregar, quitar y observar en el espacio mas alto, como todo ocurre en el mismo lugar el stack tiene complejidad constante.