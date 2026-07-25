#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <string>

using namespace std;

/*
    Clase Pila

    Esta clase implementa una pila desde cero utilizando un arreglo
    Será utilizada para almacenar el historial de acciones realizadas
    por el usuario dentro de SmartShop.

    Limitación:
    La pila tiene un tamaño máximo de 100 elementos.
*/

class Pila
{
private:

    string datos[100];
    int cima;

public:

    // Constructor
    Pila();

    // Inserta una acción en la pila
    void push(string accion);

    // Elimina la última acción registrada
    void pop();

    // Devuelve la acción ubicada en la cima
    string peek();

    // Indica si la pila está vacía
    bool isEmpty();

    // Muestra el contenido de la pila
    void mostrar();
};

#endif
