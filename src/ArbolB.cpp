#include "../include/ArbolB.h"

/*
    Constructor del Árbol B.

    Inicializa el árbol sin nodos.
*/
ArbolB::ArbolB()
{
    raiz = nullptr;
}

/*
    Muestra todos los productos almacenados
    en el Árbol B.
*/
void ArbolB::mostrar()
{
    if (raiz == nullptr)
    {
        cout << "El Árbol B está vacío." << endl;
        return;
    }

    mostrarRecursivo(raiz);
}

/*
    Recorre el árbol de forma recursiva
    mostrando los productos almacenados.
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

        cout << "ID: " << nodo->productos[i].id
             << " | Nombre: " << nodo->productos[i].nombre
             << " | Cantidad: " << nodo->productos[i].cantidad
             << endl;
    }

    if (!nodo->esHoja)
    {
        mostrarRecursivo(nodo->hijos[i]);
    }
}
