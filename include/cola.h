#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <string>

using namespace std;

/*
    Clase Cola

    Esta clase implementa una cola desde cero utilizando un arreglo.

    Será utilizada para almacenar los productos pendientes por comprar.

    Limitación:
    La cola tiene un tamaño máximo de 100 elementos.
*/

class Cola
{
private:

    string datos[100];
    int frente;
    int fin;

public:

    // Constructor
    Cola();

    // Inserta un nuevo producto al final de la cola
    void enqueue(string producto);

    // Elimina el primer producto de la cola
    void dequeue();

    // Devuelve el primer producto de la cola
    string front();

    // Verifica si la cola está vacía
    bool isEmpty();

    // Muestra todos los productos pendientes
    void mostrar();
};

#endif
