# Arbol AVL
```c++
//Los arboles binarios  AVL o Adelson-Velskii and Landis son arboles binarios de busqueda que mantienen una caracteristica de balance, la cual debe de ser simple de mantener y logra mantener la complejidad del arbol complero en 0(LogN) y la idea funciona con base en que la altura de los sub arboles izquierdos y derechos tengan la misma altura, sin embargo esta condicion es reducida en cuanto lo estricto que es, en vez de que solo puedan tener la misma altura, puere haber un margen de diferencia de 1, en el momento que se genera una diferencia de 2 se considera desbalanceado.
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<memory>

template <typename T>
class Node {
public:
    T data; //Informacion que se guarda en el nodo
    int height; //altura a l;a que se encuentra el nodo
    std::shared_ptr<Node<T>> left; // Puntero que apunta a la izquierda , inteligente porque puede apuntar a dos lugares
    std::shared_ptr<Node<T>> right;
//puntero que apunta  a la derecha
//constructor explicito con datos por default
    Node(T data) : data(data), height(1), left(nullptr), right(nullptr) {}
};

template <typename T>
class AVLTree {
public:
    std::shared_ptr<Node<T>> root;

    AVLTree(): root(nullptr) {}

    void add(T data) {
        root = insert(root, data);
    }//se utiliza para agregar un nodo y llama al insertar

    void remove(T data)  {
        root = deleteNode(root, data);
    }//elimina un nodo, llama a la funcion deleteNode

    void print() {
        if (root != nullptr) {
            print(root, 0);
        } else {
            std::cout << "The tree is empty." << std::endl;
        }//se utiliza para imprimir el arbol mientras no sea 
    }

private:
    void print(std::shared_ptr<Node<T>> node, int indent) {//funcion para imprimir, le puedes asignar indent y un puntero de nodo, mientras va avanzando recursivamente va imprimiendo con diferentes indents, ya que va sumandoles 8 en cada ciclo, teniendo como diferencia que en el lado izquierdo se imprime el indent primero
        if(node) {
            if(node->right) {//avanza a la derecha mientras haya nodo derecho
                print(node->right, indent + 8);
            }//marca el indent antes de imprimir un dato
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            if (node->right) {//imprime el lado derecho del arbol
                std::cout << " / (Right of " << node->data << ")\n" << std::setw(indent) << ' ';
            }
            std::cout << node->data << "\n" ;
            if (node->left) {//imprime el lado izquierdo del arbol
                std::cout << std::setw(indent) << ' ' << " \\ (Left of " << node->data << ")\n";
                print(node->left, indent + 8);
            }
        }
    }

    std::shared_ptr<Node<T>> newNode(T data) {
        return std::make_shared<Node<T>>(data);
    }
// Aqui da lugar la rotacion a la derecha 
    std::shared_ptr<Node<T>> rightRotate(std::shared_ptr<Node<T>> y) {
        std::shared_ptr<Node<T>> x = y->left;//se iguala x a la izquierda de y
        std::shared_ptr<Node<T>> T2 = x->right;//se iguala T2 a la derecha de x

        x->right = y;//se le asigna a la derecha de x y
        y->left = T2;//se asigna a la izquierda de y  t2 que es la antigua derecha de x

        y->height = max(height(y->left), height(y->right))+1;
        x->height = max(height(x->left), height(x->right))+1;//se aumenta la altura de y en la linea anterior y de x en esta

        return x;
    }
//Se hace la rotacion izquierda, que funciona como la anterior pero simetrica
    std::shared_ptr<Node<T>> leftRotate(std::shared_ptr<Node<T>> x) {
        std::shared_ptr<Node<T>> y = x->right;
        std::shared_ptr<Node<T>> T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;

        return y;
    }
//funcion para conseguir el balance en la cual se resta la altura de la derecha a la izquierda y se utiliza la diferencia para saber si hay un desbalance
    int getBalance(std::shared_ptr<Node<T>> N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }
//funcion para agregar un nodo al arbol 
    std::shared_ptr<Node<T>> insert(std::shared_ptr<Node<T>> node, T data) {
        if (node == nullptr)
            return (newNode(data));//se crea un nodo si estaba vacio

        if (data < node->data)//comienza la busqueda del lugar en donde se insertara el dato, en esta linea busca si avanza a la izquierda
            node->left = insert(node->left, data);
            //en este if se busca a la derecja
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;//es la creacion del nodo cuando encuentra su lugar

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);//funcion para obtener el balance llamando a get balance y dependiendo de el tipo de desbalanceo la rotacion que se hace

        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    std::shared_ptr<Node<T>> minValueNode(std::shared_ptr<Node<T>> node) {
        std::shared_ptr<Node<T>> current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    std::shared_ptr<Node<T>> deleteNode(std::shared_ptr<Node<T>> root, T data) {// se implementa la funcion de borrar nodo
        if (!root)
            return root;
//busca el dato para eliminarlo de la misma manera que insert
        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        }
        else if(data > root->data) {
            root->right = deleteNode(root->right, data);
        }
        else {
            if(!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            }
            else {
                std::shared_ptr<Node<T>> temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
                temp.reset();
            }
        }

        if(!root)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
//funcion para obtener balance y saber si usar una rotacion simple o doble 
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
//regresa la altura del nodo
    int height(std::shared_ptr<Node<T>> N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }
//Funciona para obtener el numero maximo entre 2
    int max(int a, int b) {
        return (a > b)? a : b;
    }
};

#endif /* AVL_TREE_H */
```
Lo unico con lo que realmente batalle fue al momento de leer la seccion de rotaciones, al inicio crei entenderlo bien, luego me perdi y lo volvi a entender, no es tan dificil realmente , solo el libro puede ser confuso,tambien juan nos explico que era lo del shared ptr