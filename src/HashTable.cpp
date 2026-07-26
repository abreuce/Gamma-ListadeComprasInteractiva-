#include "../include/HashTable.h"
#include <iostream>

using namespace std;

// Constructor
HashTable::HashTable()
{
    tabla.resize(TAM);
}

// Función hash
int HashTable::funcionHash(int id)
{
    return id % TAM;
}

// Insertar un producto
void HashTable::insertar(const Producto& producto)
{
    int indice = funcionHash(producto.getId());
    tabla[indice].push_back(producto);
}

// Buscar un producto por ID
Producto* HashTable::buscar(int id)
{
    int indice = funcionHash(id);

    for (auto& producto : tabla[indice])
    {
        if (producto.getId() == id)
        {
            return &producto;
        }
    }

    return nullptr;
}

// Mostrar toda la tabla
void HashTable::mostrar()
{
    cout << "\n===== TABLA HASH =====\n";

    for (int i = 0; i < TAM; i++)
    {
        cout << "[" << i << "] ";

        if (tabla[i].empty())
        {
            cout << "Vacio";
        }
        else
        {
            for (const auto& producto : tabla[i])
            {
                cout << producto.getNombre()
                     << "(ID:" << producto.getId() << ") ";
            }
        }

        cout << endl;
    }
}
