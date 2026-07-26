#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>

using namespace std;

/*
    Clase Grafo

    Representa un grafo no dirigido utilizando
    una matriz de adyacencia.

    Permite agregar conexiones entre vértices
    y realizar un recorrido DFS.

    Limitación:
    El tamaño del grafo se define al crearlo
    y no cambia dinámicamente.
*/

class Grafo
{
private:
    int numVertices;
    vector<vector<int>> matriz;
    vector<string> nombres;

// Función auxiliar utilizada por el recorrido DFS.

    void DFSRecursivo(int vertice, vector<bool>& visitado);

public:
// Constructor del grafo.
    Grafo(int vertices);

    void agregarVertice(int indice, string nombre);
    void agregarArista(int origen, int destino);

    void mostrar();

    void DFS(int inicio);
};

#endif
