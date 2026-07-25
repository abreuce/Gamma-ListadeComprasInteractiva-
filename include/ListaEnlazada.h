#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>
#include "Nodo.h"

using namespace std;

/*
    Clase ListaEnlazada

    Administra los productos de SmartShop mediante
    una lista simplemente enlazada.

    Operaciones disponibles:
    - Insertar
    - Eliminar
    - Buscar
    - Mostrar

    Limitación:
    No soporta búsqueda binaria debido a que
    los elementos no se encuentran indexados.
*/

class ListaEnlazada
{
private:

    Nodo* cabeza;

public:

    // Constructor
    ListaEnlazada();

    // Inserta un producto al final de la lista
    void insertar(Producto producto);

    // Elimina un producto por su ID
    void eliminar(int id);

    // Busca un producto por su ID
    Nodo* buscar(int id);

    // Recorre toda la lista mostrando los productos
    void mostrar();
};

#endif
