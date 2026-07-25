#include "../include/Cola.h"

/*
    Constructor

    Inicializa la cola vacía.
*/
Cola::Cola()
{
    frente = 0;
    fin = -1;
}

/*
    Inserta un nuevo producto al final de la cola.

    Limitación:
    La cola admite un máximo de 100 elementos.
*/
void Cola::enqueue(string producto)
{
    if (fin < 99)
    {
        fin++;
        datos[fin] = producto;
    }
    else
    {
        cout << "La cola esta llena." << endl;
    }
}

/*
    Elimina el primer producto de la cola.

    Limitación:
    No puede eliminar elementos si la cola está vacía.
*/
void Cola::dequeue()
{
    if (!isEmpty())
    {
        frente++;
    }
    else
    {
        cout << "La cola esta vacia." << endl;
    }
}

/*
    Devuelve el primer elemento de la cola.
*/
string Cola::front()
{
    if (!isEmpty())
    {
        return datos[frente];
    }

    return "";
}

/*
    Verifica si la cola está vacía.
*/
bool Cola::isEmpty()
{
    return frente > fin;
}

/*
    Muestra todos los productos pendientes.
*/
void Cola::mostrar()
{
    if (isEmpty())
    {
        cout << "La cola esta vacia." << endl;
        return;
    }

    cout << "\n===== PRODUCTOS PENDIENTES =====\n";

    for (int i = frente; i <= fin; i++)
    {
        cout << "- " << datos[i] << endl;
    }
}
