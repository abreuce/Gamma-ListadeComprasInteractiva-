#include <iostream>
#include "../include/Pila.h"
#include "../include/Cola.h"

using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "          SMARTSHOP" << endl;
    cout << " Lista de Compras Interactiva" << endl;
    cout << " Proyecto de Estructuras de Datos" << endl;
    cout << "==========================================" << endl;

    // ===========================
    // Prueba de la Pila
    // ===========================

    Pila historial;

    historial.push("Agregar Leche");
    historial.push("Agregar Pan");
    historial.push("Eliminar Azucar");

    cout << "\n===== PRUEBA DE PILA =====" << endl;
    historial.mostrar();

    cout << "\nUltima accion: " << historial.peek() << endl;

    historial.pop();

    cout << "\nDespues de hacer pop():" << endl;
    historial.mostrar();

    // ===========================
    // Prueba de la Cola
    // ===========================

    Cola compras;

    compras.enqueue("Leche");
    compras.enqueue("Pan");
    compras.enqueue("Arroz");

    cout << "\n===== PRUEBA DE COLA =====" << endl;
    compras.mostrar();

    cout << "\nPrimer producto: " << compras.front() << endl;

    compras.dequeue();

    cout << "\nDespues de hacer dequeue():" << endl;
    compras.mostrar();

    return 0;
}
