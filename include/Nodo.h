#ifndef NODO_H
#define NODO_H

#include "Producto.h"

/*
    Clase Nodo

    Representa un nodo de la lista enlazada.

    Cada nodo almacena un producto y un apuntador
    al siguiente nodo de la lista.

    Limitación:
    Solo permite enlazar un nodo siguiente
    (lista simplemente enlazada).
*/

class Nodo
{
public:

    Producto producto;
    Nodo* siguiente;

    // Constructor
    Nodo(Producto producto)
    {
        this->producto = producto;
        siguiente = nullptr;
    }
};

#endif
