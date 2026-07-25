#ifndef NODOB_H
#define NODOB_H

#include "Producto.h"

/*
    Clase NodoB

    Representa un nodo de un Árbol B.

    Cada nodo puede almacenar varias claves (productos)
    y referencias a sus nodos hijos.

    Esta estructura servirá como base para implementar
    el Árbol B de SmartShop.

    Limitaciones:
    - No implementa eliminación.
    - La división de nodos será gestionada por la clase ArbolB.
*/

class NodoB
{
public:

    static const int ORDEN = 4;

    Producto productos[ORDEN - 1];
    NodoB* hijos[ORDEN];

    int cantidadProductos;
    bool esHoja;

    // Constructor
    NodoB(bool hoja)
    {
        esHoja = hoja;
        cantidadProductos = 0;

        for (int i = 0; i < ORDEN; i++)
        {
            hijos[i] = nullptr;
        }
    }
};

#endif
