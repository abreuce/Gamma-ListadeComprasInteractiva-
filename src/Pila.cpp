#include "../include/Pila.h"

/*
    Constructor

    Inicializa la pila vacía.
*/
Pila::Pila()
{
    cima = -1;
}

/*
    Inserta una nueva acción en la pila

    Limitación:
    La pila solo admite hasta 100 elementos.
*/
void Pila::push(string accion)
{
    if (cima < 99)
    {
        cima++;
        datos[cima] = accion;
    }
    else
    {
        cout << "La pila esta llena." << endl;
    }
}

/*
    Elimina la última acción registrada.

    Limitación:
    No puede eliminar elementos si la pila está vacía.
*/
void Pila::pop()
{
    if (!isEmpty())
    {
        cima--;
    }
    else
    {
        cout << "La pila esta vacia." << endl;
    }
}

/*
    Devuelve el elemento ubicado en la cima.

    Limitación:
    Si la pila está vacía devuelve una cadena vacía.
*/
string Pila::peek()
{
    if (!isEmpty())
    {
        return datos[cima];
    }

    return "";
}

/*
    Indica si la pila está vacía.
*/
bool Pila::isEmpty()
{
    return cima == -1;
}

/*
    Muestra todas las acciones almacenadas.

    Limitación:
    Si la pila está vacía solo muestra un mensaje
    indicando que no existen acciones registradas.
*/
void Pila::mostrar()
{
    if (isEmpty())
    {
        cout << "La pila esta vacia." << endl;
        return;
    }

    cout << "\n===== HISTORIAL DE ACCIONES =====\n";

    for (int i = cima; i >= 0; i--)
    {
        cout << "- " << datos[i] << endl;
    }
}
