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

/*
    Divide un hijo cuando está lleno.

    El producto central asciende al padre y
    el nodo se divide en dos nodos hermanos.

    Esta implementación corresponde a un
    Árbol B de orden 4.

    No contempla la eliminación de claves.
*/
void ArbolB::dividirHijo(NodoB* padre, int indice, NodoB* hijo)
{
    // Crear el nuevo nodo que almacenará la mitad derecha
    NodoB* nuevo = new NodoB(hijo->esHoja);

    // El nuevo nodo recibirá una clave
    nuevo->cantidadProductos = 1;

    // Copiar la última clave del nodo lleno
    nuevo->productos[0] = hijo->productos[2];

    // Si no es hoja, mover también sus hijos
    if (!hijo->esHoja)
    {
        nuevo->hijos[0] = hijo->hijos[2];
        nuevo->hijos[1] = hijo->hijos[3];
    }

    // El nodo original conserva solo la primera clave
    hijo->cantidadProductos = 1;

    // Desplazar los hijos del padre para abrir espacio
    for (int j = padre->cantidadProductos; j >= indice + 1; j--)
    {
        padre->hijos[j + 1] = padre->hijos[j];
    }

    padre->hijos[indice + 1] = nuevo;

    // Desplazar las claves del padre
    for (int j = padre->cantidadProductos - 1; j >= indice; j--)
    {
        padre->productos[j + 1] = padre->productos[j];
    }

    // Promover la clave central al padre
    padre->productos[indice] = hijo->productos[1];

    padre->cantidadProductos++;
}
