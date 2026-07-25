#include "../include/ArbolBinario.h"

/*
    Constructor

    Inicializa el árbol vacío.
*/
ArbolBinario::ArbolBinario()
{
    raiz = nullptr;
}

/*
    Inserta un producto en el árbol.

    La inserción se realiza utilizando el ID
    como criterio de ordenamiento.
*/
void ArbolBinario::insertar(Producto producto)
{
    raiz = insertarRecursivo(raiz, producto);
}

/*
    Inserción recursiva.

    Si el árbol está vacío, crea un nuevo nodo.
    Si el ID es menor, continúa por la izquierda.
    Si el ID es mayor, continúa por la derecha.

    Limitación:
    No inserta productos con IDs duplicados.
*/
NodoArbol* ArbolBinario::insertarRecursivo(NodoArbol* nodo, Producto producto)
{
    if (nodo == nullptr)
    {
        return new NodoArbol(producto);
    }

    if (producto.id < nodo->producto.id)
    {
        nodo->izquierdo = insertarRecursivo(nodo->izquierdo, producto);
    }
    else if (producto.id > nodo->producto.id)
    {
        nodo->derecho = insertarRecursivo(nodo->derecho, producto);
    }

    return nodo;
}

/*
    Busca un producto mediante su ID.
*/
NodoArbol* ArbolBinario::buscar(int id)
{
    return buscarRecursivo(raiz, id);
}

/*
    Búsqueda recursiva.

    Recorre el árbol comparando el ID buscado
    con el ID almacenado en cada nodo.

    Limitación:
    Retorna únicamente la primera coincidencia.
*/
NodoArbol* ArbolBinario::buscarRecursivo(NodoArbol* nodo, int id)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }

    if (id == nodo->producto.id)
    {
        return nodo;
    }

    if (id < nodo->producto.id)
    {
        return buscarRecursivo(nodo->izquierdo, id);
    }

    return buscarRecursivo(nodo->derecho, id);
}

/*
    Muestra los productos ordenados por ID
    utilizando un recorrido InOrden.
*/
void ArbolBinario::inOrden()
{
    if (raiz == nullptr)
    {
        cout << "El árbol está vacío." << endl;
        return;
    }

    cout << "\n===== ÁRBOL BINARIO (InOrden) =====\n";

    inOrdenRecursivo(raiz);
}

/*
    Recorrido InOrden.

    Visita:
    1. Subárbol izquierdo.
    2. Nodo actual.
    3. Subárbol derecho.

    Casos no contemplados:
    No modifica la estructura del árbol;
    únicamente muestra su contenido.
*/
void ArbolBinario::inOrdenRecursivo(NodoArbol* nodo)
{
    if (nodo == nullptr)
    {
        return;
    }

    inOrdenRecursivo(nodo->izquierdo);

    cout << "ID: " << nodo->producto.id << endl;
    cout << "Nombre: " << nodo->producto.nombre << endl;
    cout << "Cantidad: " << nodo->producto.cantidad << endl;
    cout << "-----------------------------" << endl;

    inOrdenRecursivo(nodo->derecho);
}
