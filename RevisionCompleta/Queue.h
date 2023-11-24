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