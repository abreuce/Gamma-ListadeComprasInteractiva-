#include "../include/ListaEnlazada.h"

/*
    Constructor

    Inicializa la lista vacía.
*/
ListaEnlazada::ListaEnlazada()
{
    cabeza = nullptr;
}

/*
    Inserta un nuevo producto al final de la lista.

    Limitación:
    No verifica si existen productos con el mismo ID.
*/
void ListaEnlazada::insertar(Producto producto)
{
    Nodo* nuevo = new Nodo(producto);

    if (cabeza == nullptr)
    {
        cabeza = nuevo;
        return;
    }

    Nodo* actual = cabeza;

    while (actual->siguiente != nullptr)
    {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
}

/*
    Elimina un producto utilizando su ID.

    Limitación:
    Solo elimina la primera coincidencia encontrada.
*/
void ListaEnlazada::eliminar(int id)
{
    if (cabeza == nullptr)
    {
        return;
    }

    if (cabeza->producto.id == id)
    {
        Nodo* aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
        return;
    }

    Nodo* actual = cabeza;

    while (actual->siguiente != nullptr &&
           actual->siguiente->producto.id != id)
    {
        actual = actual->siguiente;
    }

    if (actual->siguiente != nullptr)
    {
        Nodo* aux = actual->siguiente;
        actual->siguiente = aux->siguiente;
        delete aux;
    }
}

/*
    Busca un producto mediante su ID.

    Limitación:
    La búsqueda es secuencial y puede ser lenta
    en listas muy grandes.
*/
Nodo* ListaEnlazada::buscar(int id)
{
    Nodo* actual = cabeza;

    while (actual != nullptr)
    {
        if (actual->producto.id == id)
        {
            return actual;
        }

        actual = actual->siguiente;
    }

    return nullptr;
}

/*
    Recorre toda la lista mostrando los productos.

    Limitación:
    Solo muestra la información almacenada,
    no permite modificar los datos.
*/
void ListaEnlazada::mostrar()
{
    if (cabeza == nullptr)
    {
        cout << "La lista esta vacia." << endl;
        return;
    }

    Nodo* actual = cabeza;

    cout << "\n===== LISTA DE PRODUCTOS =====\n";

    while (actual != nullptr)
    {
        cout << "ID: " << actual->producto.id << endl;
        cout << "Nombre: " << actual->producto.nombre << endl;
        cout << "Cantidad: " << actual->producto.cantidad << endl;
        cout << "-----------------------------" << endl;

        actual = actual->siguiente;
    }
}
