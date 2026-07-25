#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <iostream>
#include "NodoArbol.h"

using namespace std;

/*
    Clase ArbolBinario

    Implementa un Árbol Binario de Búsqueda (BST)
    para almacenar productos utilizando el ID como
    criterio de ordenamiento.

    Operaciones disponibles:
    - Insertar productos.
    - Buscar productos.
    - Mostrar los productos mediante recorrido InOrden.

    Casos no contemplados:
    - No permite eliminar nodos.
    - No realiza balanceo automático.
    - No valida IDs duplicados.
    - El balanceo será implementado posteriormente
      mediante un Árbol AVL.
*/

class ArbolBinario
{
private:

    NodoArbol* raiz;

    // Inserción recursiva
    NodoArbol* insertarRecursivo(NodoArbol* nodo, Producto producto);

    // Búsqueda recursiva
    NodoArbol* buscarRecursivo(NodoArbol* nodo, int id);

    // Recorrido InOrden
    void inOrdenRecursivo(NodoArbol* nodo);

public:

    // Constructor
    ArbolBinario();

    // Inserta un producto
    void insertar(Producto producto);

    // Busca un producto por ID
    NodoArbol* buscar(int id);

    // Muestra el árbol en orden
    void inOrden();
};

#endif
