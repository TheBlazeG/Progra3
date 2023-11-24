
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