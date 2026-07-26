#include <iostream>
#include "../include/Pila.h"
#include "../include/Cola.h"
#include "../include/ListaEnlazada.h"
#include "../include/HashTable.h"
#include "../include/Grafo.h"

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

    cout << "\n===== HASHING =====" << endl;

HashTable hash;

// Insertar productos
hash.insertar(Producto(1, "Teclado", 15));
hash.insertar(Producto(2, "Mouse", 30));
hash.insertar(Producto(3, "Monitor", 8));

// Mostrar la tabla
hash.mostrar();

// Buscar un producto
Producto* encontradoHash = hash.buscar(2);

if (encontradoHash != nullptr)
{
    cout << "\nProducto encontrado en Hash:" << endl;
    cout << "ID: " << encontradoHash->id << endl;
    cout << "Nombre: " << encontradoHash->nombre << endl;
    cout << "Cantidad: " << encontradoHash->cantidad << endl;
}
else
{
    cout << "\nProducto no encontrado." << endl;
}

cout << "\n===== GRAFOS =====" << endl;

Grafo grafo(3);

// Agregar vértices
grafo.agregarVertice(0, "Teclado");
grafo.agregarVertice(1, "Mouse");
grafo.agregarVertice(2, "Monitor");

// Crear conexiones
grafo.agregarArista(0, 1);
grafo.agregarArista(0, 2);

// Mostrar el grafo
grafo.mostrar();

// Recorrido DFS
grafo.DFS(0);
    
    return 0;
}
