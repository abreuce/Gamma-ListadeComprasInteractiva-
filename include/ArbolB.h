#ifndef ARBOLB_H
#define ARBOLB_H

#include <iostream>
#include "NodoB.h"

using namespace std;

/*
    Clase ArbolB

    Implementación básica de un Árbol B de orden 4.

    Operaciones implementadas:
    - Insertar productos.
    - Mostrar productos.

    Casos no contemplados:
    - Eliminación.
    - Fusión de nodos.
    - Rebalanceo avanzado.
*/

class ArbolB
{
private:

    NodoB* raiz;

    void mostrarRecursivo(NodoB* nodo);

    void insertarNoLleno(NodoB* nodo, Producto producto);

    void dividirHijo(
        NodoB* padre,
        int indice,
        NodoB* hijo
    );

public:

    ArbolB();

    void insertar(Producto producto);

    void mostrar();
};

#endif
