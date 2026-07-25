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

/*
    Inserta un producto en un nodo que no está lleno.

    Si el nodo es hoja, el producto se inserta
    en la posición correspondiente.

    Si el nodo no es hoja, se continúa el proceso
    de inserción de forma recursiva.

    Limitación:
    Esta versión no contempla todos los casos de
    división múltiple que existen en un Árbol B.
*/
void ArbolB::insertarNoLleno(NodoB* nodo, Producto producto)
{
    int i = nodo->cantidadProductos - 1;

    if (nodo->esHoja)
    {
        while (i >= 0 && producto.id < nodo->productos[i].id)
        {
            nodo->productos[i + 1] = nodo->productos[i];
            i--;
        }

        nodo->productos[i + 1] = producto;
        nodo->cantidadProductos++;
    }
    else
    {
        while (i >= 0 && producto.id < nodo->productos[i].id)
        {
            i--;
        }

        i++;

        insertarNoLleno(nodo->hijos[i], producto);
    }
}
