#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include "Producto.h"

/*
    Clase HashTable

    Implementa una tabla hash para almacenar productos
    utilizando el identificador (ID) como clave.

    La estructura utiliza un vector de listas enlazadas
    para resolver colisiones mediante encadenamiento separado.

    Limitaciones:
    - El tamaño de la tabla es fijo (10 posiciones).
    - La función hash utiliza el operador módulo.
*/

class HashTable
{
private:
    static const int TAM = 10;
    std::vector<std::list<Producto>> tabla;

// Calcula la posición donde se almacenará un producto
// utilizando su identificador.

    int funcionHash(int id);

public:

// Constructor de la tabla hash.

    HashTable();

// Inserta un producto dentro de la tabla hash.

    void insertar(const Producto& producto);

// Busca un producto utilizando su ID.

    Producto* buscar(int id);

// Muestra el contenido completo de la tabla hash.
    void mostrar();
};

#endif
