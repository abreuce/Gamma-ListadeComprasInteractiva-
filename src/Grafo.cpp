#include "../include/Grafo.h"
#include <iostream>

using namespace std;

// Constructor
Grafo::Grafo(int vertices)
{
    numVertices = vertices;

    matriz.resize(vertices, vector<int>(vertices, 0));
    nombres.resize(vertices);
}

// Agregar nombre a un vértice
void Grafo::agregarVertice(int indice, string nombre)
{
    if (indice >= 0 && indice < numVertices)
    {
        nombres[indice] = nombre;
    }
}

// Agregar una conexión entre dos vértices
void Grafo::agregarArista(int origen, int destino)
{
    if (origen >= 0 && origen < numVertices &&
        destino >= 0 && destino < numVertices)
    {
        matriz[origen][destino] = 1;
        matriz[destino][origen] = 1;
    }
}

// Mostrar la matriz de adyacencia
void Grafo::mostrar()
{
    cout << "\n===== GRAFO =====" << endl;

    for (int i = 0; i < numVertices; i++)
    {
        cout << nombres[i] << ": ";

        for (int j = 0; j < numVertices; j++)
        {
            if (matriz[i][j] == 1)
            {
                cout << nombres[j] << " ";
            }
        }

        cout << endl;
    }
}

// DFS recursivo
void Grafo::DFSRecursivo(int vertice, vector<bool>& visitado)
{
    visitado[vertice] = true;

    cout << nombres[vertice] << " ";

    for (int i = 0; i < numVertices; i++)
    {
        if (matriz[vertice][i] == 1 && !visitado[i])
        {
            DFSRecursivo(i, visitado);
        }
    }
}

// Iniciar recorrido DFS
void Grafo::DFS(int inicio)
{
    vector<bool> visitado(numVertices, false);

    cout << "\nRecorrido DFS: ";

    DFSRecursivo(inicio, visitado);

    cout << endl;
}
