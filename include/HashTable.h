#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include "Producto.h"

class HashTable
{
private:
    static const int TAM = 10;
    std::vector<std::list<Producto>> tabla;

    int funcionHash(int id);

public:
    HashTable();

    void insertar(const Producto& producto);
    Producto* buscar(int id);
    void mostrar();
};

#endif
