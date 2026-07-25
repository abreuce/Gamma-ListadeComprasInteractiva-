#ifndef ARBOLB_H
#define ARBOLB_H

#include <iostream>
#include "NodoB.h"

using namespace std;

/*
    Clase ArbolB

    Implementa un Árbol B de orden 3 para organizar
    productos utilizando el ID como clave principal.

    Operaciones disponibles:
    - Insertar productos.
    - Mostrar el contenido del árbol.

    Casos no contemplados:
    - No implementa eliminación.
    - No realiza fusión de nodos.
    - Solo permite inserciones.
*/

class ArbolB
{
private:

    NodoB* raiz;

    // Recorre el árbol mostrando los productos
    void mostrarRecursivo(NodoB* nodo);

    // Divide un nodo cuando alcanza su capacidad máxima
    void dividirHijo(NodoB* padre, int indice, NodoB* hijo);

    // Inserta un producto en un nodo que no está lleno
    void insertarNoLleno(NodoB* nodo, Producto producto);

public:

    // Constructor
    ArbolB();

    // Inserta un producto en el árbol
    void insertar(Producto producto);

    // Muestra el contenido del árbol
    void mostrar();
};

#endif
