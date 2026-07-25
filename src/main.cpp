#include <iostream>
#include "../include/Pila.h"
#include "../include/Cola.h"
#include "../include/ListaEnlazada.h"
#include "../include/ArbolBinario.h"

using namespace std;

int main()
{
    // ==========================
    // DEMOSTRACIÓN DE PILA
    // ==========================

    cout << "===== PILA =====" << endl;

    Pila historial;

    historial.push("Agregar teclado");
    historial.push("Agregar mouse");
    historial.push("Eliminar monitor");

    historial.mostrar();

    cout << "\nUltima accion: " << historial.peek() << endl;

    historial.pop();

    cout << "\nDespues de eliminar la ultima accion:\n";
    historial.mostrar();


    // ==========================
    // DEMOSTRACIÓN DE COLA
    // ==========================

    cout << "\n===== COLA =====" << endl;

    Cola compras;

    compras.enqueue("Pedido #1");
    compras.enqueue("Pedido #2");
    compras.enqueue("Pedido #3");

    compras.mostrar();

    cout << "\nPrimer pedido: " << compras.front() << endl;

    compras.dequeue();

    cout << "\nDespues de atender un pedido:\n";
    compras.mostrar();


    // ==========================
    // DEMOSTRACIÓN DE LISTA ENLAZADA
    // ==========================

    cout << "\n===== LISTA ENLAZADA =====" << endl;

    ListaEnlazada inventario;

    inventario.insertar(Producto(1, "Teclado", 15));
    inventario.insertar(Producto(2, "Mouse", 30));
    inventario.insertar(Producto(3, "Monitor", 8));

    cout << "\nInventario inicial:\n";
    inventario.mostrar();

    Nodo* encontrado = inventario.buscar(2);

    if (encontrado != nullptr)
    {
        cout << "\nProducto encontrado:\n";
        cout << "ID: " << encontrado->producto.id << endl;
        cout << "Nombre: " << encontrado->producto.nombre << endl;
        cout << "Cantidad: " << encontrado->producto.cantidad << endl;
    }
    else
    {
        cout << "\nProducto no encontrado." << endl;
    }

    inventario.eliminar(2);

    cout << "\nInventario despues de eliminar el producto con ID 2:\n";
    inventario.mostrar();

// ==========================
// DEMOSTRACIÓN DE ÁRBOL BINARIO
// ==========================

cout << "\n===== ÁRBOL BINARIO =====" << endl;

ArbolBinario arbol;

// Insertar productos
arbol.insertar(Producto(5, "Laptop", 10));
arbol.insertar(Producto(2, "Mouse", 25));
arbol.insertar(Producto(8, "Monitor", 12));
arbol.insertar(Producto(1, "Teclado", 18));
arbol.insertar(Producto(3, "Audifonos", 20));

cout << "\nRecorrido InOrden:\n";
arbol.inOrden();

NodoArbol* encontradoArbol = arbol.buscar(3);

if (encontradoArbol != nullptr)
{
    cout << "\nProducto encontrado en el árbol:\n";
    cout << "ID: " << encontradoArbol->producto.id << endl;
    cout << "Nombre: " << encontradoArbol->producto.nombre << endl;
    cout << "Cantidad: " << encontradoArbol->producto.cantidad << endl;
}
else
{
    cout << "\nProducto no encontrado." << endl;
}    
    
    return 0;
}
