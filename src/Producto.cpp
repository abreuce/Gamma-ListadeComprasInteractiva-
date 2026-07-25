#include "../include/Producto.h"

/*
    Constructor vacío.
*/
Producto::Producto()
{
    id = 0;
    nombre = "";
    cantidad = 0;
}

/*
    Constructor con parámetros.

    Limitación:
    No verifica si los datos son válidos.
*/
Producto::Producto(int id, string nombre, int cantidad)
{
    this->id = id;
    this->nombre = nombre;
    this->cantidad = cantidad;
}
