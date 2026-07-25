#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>

using namespace std;

/*
    Clase Producto

    Representa un producto dentro de SmartShop.

    Será utilizada por las listas enlazadas, árboles,
    hashing y grafos durante el desarrollo del proyecto.

    Limitación:
    No valida si los datos ingresados son correctos.
*/

class Producto
{
public:

    int id;
    string nombre;
    int cantidad;

    // Constructor por defecto
    Producto();

    // Constructor con parámetros
    Producto(int id, string nombre, int cantidad);
};

#endif
