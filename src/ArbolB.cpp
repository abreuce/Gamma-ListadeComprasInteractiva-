#include "../include/ArbolB.h"

/*
    Constructor del Árbol B.

    Inicialmente el árbol está vacío,
    por lo que la raíz apunta a nullptr.
*/
ArbolB::ArbolB()
{
    raiz = nullptr;
}

/*
    Recorre el árbol en orden mostrando
    todos los productos almacenados.
*/
void ArbolB::mostrar()
{
    if (raiz == nullptr)
    {
        cout << "El árbol está vacío." << endl;
        return;
    }

    mostrarRecursivo(raiz);
}

/*
    Recorre recursivamente el árbol
    mostrando cada producto.
*/
void ArbolB::mostrarRecursivo(NodoB* nodo)
{
    if (nodo == nullptr)
    {
        return;
    }

    int i;

    for (i = 0; i < nodo->cantidadProductos; i++)
    {
        if (!nodo->esHoja)
        {
            mostrarRecursivo(nodo->hijos[i]);
        }

        cout << "ID: " << nodo->productos[i].getId()
             << " | Nombre: " << nodo->productos[i].getNombre()
             << " | Precio: " << nodo->productos[i].getPrecio()
             << endl;
    }

    if (!nodo->esHoja)
    {
        mostrarRecursivo(nodo->hijos[i]);
    }
}
