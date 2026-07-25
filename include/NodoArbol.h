#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "Producto.h"

/*
    Clase NodoArbol

    Representa un nodo de un Árbol Binario de Búsqueda (BST).

    Cada nodo almacena un producto y mantiene referencias
    hacia sus hijos izquierdo y derecho.

    Esta estructura será reutilizada posteriormente por el
    Árbol AVL.

    Limitación:
    No almacena información de balanceo. Esa característica
    será incorporada cuando se implemente el AVL.
*/

class NodoArbol
{
public:

    Producto producto;
    NodoArbol* izquierdo;
    NodoArbol* derecho;

    // Constructor
    NodoArbol(Producto producto)
    {
        this->producto = producto;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

#endif
