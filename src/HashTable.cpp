#include "../include/HashTable.h"
#include <iostream>

using namespace std;

/*
    Constructor.

    Inicializa la tabla hash con un tamaño fijo
    de diez posiciones.
*/
HashTable::HashTable()
{
    tabla.resize(TAM);
}

/*
    Calcula el índice donde se almacenará el producto.

    La posición se obtiene aplicando la operación:

        ID % TAM

    Limitación:
    Pueden existir colisiones cuando diferentes IDs
    generan el mismo índice.
*/
int HashTable::funcionHash(int id)
{
    return id % TAM;
}

/*
    Inserta un producto dentro de la tabla hash.

    Si ocurre una colisión, el producto se almacena
    en la lista correspondiente al índice calculado.
*/
void HashTable::insertar(const Producto& producto)
{
    int indice = funcionHash(producto.id);
    tabla[indice].push_back(producto);
}

/*
    Busca un producto por su identificador.

    Devuelve un puntero al producto si existe.

    Limitación:
    Si el producto no está almacenado devuelve nullptr.
*/
Producto* HashTable::buscar(int id)
{
    int indice = funcionHash(id);

    for (auto& producto : tabla[indice])
    {
        if (producto.id == id)
        {
            return &producto;
        }
    }

    return nullptr;
}

/*
    Recorre toda la tabla hash y muestra
    el contenido almacenado en cada posición.
*/
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
                cout << producto.nombre
                     << " (ID:" << producto.id << ") ";
            }
        }

        cout << endl;
    }
}
