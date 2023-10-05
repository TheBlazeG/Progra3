```c++
**

#ifndef SLLLIST_H

#define SLLLIST_H

  

#include <iostream>

#include <utility>

  

template <typename Object>//Se declara que se va a utilizar un template y los object serán reemplazados por una clase o un tipo de dato

class SLList {

private:  //se enlistan los miembros privados

    //Cada Cuadrito

    struct Node  {

        Object data;

        Node *next;//Anya

  

        Node(const Object &d = Object{}, Node *n = nullptr) //se establece el constructor de un nodo default y de copia, para agregar datos o que esté vacío

            : data{d}, next{n} {}

  

        Node(Object &&d, Node *n = nullptr)

            : data{std::move(d)}, next{n} {}

    };//se establece el constructor de move 

  

public:

    class iterator { //se comienza a establecer la clase del iterador

    public:

        iterator() : current{nullptr} {}//constructor default

  

        Object &operator*() {//se utiliza para ver la información del puntero si el puntero es nulo, da un error lógico

            if(current == nullptr)

                throw std::logic_error("Trying to dereference a null pointer.");

            return current->data;

        }

  

        iterator &operator++() {//se utiliza para avanzar a la siguiente posición del iterador, si está en la orilla arroja un error de lógica

            if(current)

                current = current->next;

            else

                throw std::logic_error("Trying to increment past the end.");

            return *this;

        }

  

        iterator operator++(int) {//se utiliza para determinar el momento en que se usa el ++ por su posición

            iterator old = *this;

            ++(*this);

            return old;

        }

  

        bool operator==(const iterator &rhs) const {//se establece el operador ==, regresa verdadero si son iguales y falso si son diferentes

            return current == rhs.current;

        }

  

        bool operator!=(const iterator &rhs) const {//es como el operador anterior pero al inverso

            return !(*this == rhs);

        }

  

    private://miembros privados

        Node *current; //puntero

        iterator(Node *p) : current{p} {} //constructor

        friend class SLList<Object>; //se establece como amigo a la clase slllist

    };

  

public:

    SLList() : head(new Node()), tail(new Node()), theSize(0) {

        head->next = tail;

    }//constructor default de lista

  

    ~SLList() {

        clear();

        delete head;

        delete tail;

    }//destructor de lista, destruye el inicio el final y los datos de enmedio

  

    iterator begin() { return {head->next}; }//funciona para obtener el inicio de la lista

    iterator end() { return {tail}; }//funciona para obtener el final

  

    int size() const { return theSize; }//se usa para obtener el tamaño de la lista

    bool empty() const { return size() == 0; }//compara el tamaño de la lista y regresa verdadero si está vacío y falso si no

  

    void clear() { while (!empty()) pop_front(); }//se utiliza mientras no esté vacía o hasta que esté vacía

  

    Object &front() {

        if(empty())

            throw std::logic_error("List is empty.");

        return *begin();

    }//da el dato inicial, a menos que no haya alguno

  

    void push_front(const Object &x) { insert(begin(), x); }//se utiliza para poner un objeto al inicio con copia

    void push_front(Object &&x) { insert(begin(), std::move(x)); }//este funciona igual al anterior pero con referencia

  

    void pop_front() {

        if(empty())

            throw std::logic_error("List is empty.");

        erase(begin());

    }//se utiliza para borrar el dato inicial a menos que no haya uno

  

    iterator insert(iterator itr, const Object &x) {

        Node *p = itr.current;

        head->next = new Node{x, head->next};

        theSize++;

        return iterator(head->next);//se usa para insertar un dato a donde apunta el iterador

    }

  

    iterator insert(iterator itr, Object &&x) {

        Node *p = itr.current;

        head->next = new Node{std::move(x), head->next};

        theSize++;

        return iterator(head->next);

    }//se usa para mover un dato a donde apunta el iterador

  

    iterator erase(iterator itr) {

        if (itr == end())

            throw std::logic_error("Cannot erase at end iterator");

        Node *p = head;

        while (p->next != itr.current) p = p->next;

        p->next = itr.current->next;

        delete itr.current;

        theSize--;

        return iterator(p->next);

    }//se utiliza para borrar el dato en donde apunta el iterador

  

    void printList() {

        iterator itr = begin();

        while (itr != end()) {

            std::cout << *itr << " ";

            ++itr;

        }

        std::cout << std::endl;//se imprime el primer termino de la lista y luego avanza el iterador hasta el final repitiendo cíclicamente

    }

  

private://miembros privados como el inicio, fin de la lista y tamaño además de la inicialización de lista

    Node *head;

    Node *tail;

    int theSize;

    void init() {

        theSize = 0;

        head->next = tail;

    }

};

  

#endif

**
```
Me gustaría repasar el código para unas preguntas en los nodos con por ejemplo con las flechitas, aunque se mas o menos como funcionan me gustaría estar seguro, además de eso la duda de cual de los dos es ++x y x++ 