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

/*
    Divide un nodo hijo cuando alcanza
    el número máximo de productos.

    El producto central asciende al nodo padre
    y el nodo se divide en dos partes.

    Esta implementación es una versión básica
    para demostrar el funcionamiento de un Árbol B.

    Casos no contemplados:
    - Eliminación de claves.
    - Fusión de nodos.
*/
void ArbolB::dividirHijo(NodoB* padre, int indice, NodoB* hijo)
{
    NodoB* nuevo = new NodoB(hijo->esHoja);

    nuevo->cantidadProductos = 1;

    // Copiar la última clave al nuevo nodo
    nuevo->productos[0] = hijo->productos[2];

    // Si no es hoja, mover los hijos correspondientes
    if (!hijo->esHoja)
    {
        nuevo->hijos[0] = hijo->hijos[2];
        nuevo->hijos[1] = hijo->hijos[3];
    }

    // El nodo original conserva únicamente la primera clave
    hijo->cantidadProductos = 1;

    // Desplazar los hijos del padre
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

    // Promover la clave central
    padre->productos[indice] = hijo->productos[1];

    padre->cantidadProductos++;
}

/*
    Inserta un producto en el Árbol B.

    Si el árbol está vacío, crea la raíz.
    Si la raíz está llena, se divide antes de insertar.
*/
void ArbolB::insertar(Producto producto)
{
    // Si el árbol está vacío
    if (raiz == nullptr)
    {
        raiz = new NodoB(true);
        raiz->productos[0] = producto;
        raiz->cantidadProductos = 1;
        return;
    }

    // Si la raíz está llena
    if (raiz->cantidadProductos == NodoB::ORDEN - 1)
    {
        NodoB* nuevaRaiz = new NodoB(false);

        nuevaRaiz->hijos[0] = raiz;

        dividirHijo(nuevaRaiz, 0, raiz);

        int i = 0;

        if (producto.id > nuevaRaiz->productos[0].id)
        {
            i++;
        }

        insertarNoLleno(nuevaRaiz->hijos[i], producto);

        raiz = nuevaRaiz;
    }
    else
    {
        insertarNoLleno(raiz, producto);
    }
}
