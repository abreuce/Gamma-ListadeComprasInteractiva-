# Manual de Usuario - SmartShop

## Introducción

SmartShop es una aplicación desarrollada en C++ que permite demostrar el funcionamiento de diversas estructuras de datos mediante un sistema sencillo de gestión de productos.

---

# Requisitos

Para ejecutar el programa se necesita:

- Compilador compatible con C++11 o superior.
- g++ (GNU Compiler Collection).
- Sistema operativo Windows, Linux o macOS.

---

# Compilación

Desde la carpeta raíz del proyecto ejecutar:

```bash
g++ src/*.cpp -Iinclude -o SmartShop
```

---

# Ejecución

En Linux o Codespaces:

```bash
./SmartShop
```

En Windows:

```bash
SmartShop.exe
```

---

# Funcionalidades del programa

Durante la ejecución el programa demuestra el funcionamiento de las siguientes estructuras de datos:

## Pila

Permite registrar acciones y mostrar el historial siguiendo la política LIFO (Last In, First Out).

Operaciones realizadas:

- Insertar acciones.
- Mostrar historial.
- Consultar la última acción.
- Eliminar una acción.

---

## Cola

Permite administrar pedidos pendientes utilizando la política FIFO (First In, First Out).

Operaciones realizadas:

- Agregar pedidos.
- Mostrar pedidos.
- Consultar el primer pedido.
- Atender un pedido.

---

## Lista Enlazada

Permite administrar un inventario de productos.

Operaciones realizadas:

- Insertar productos.
- Buscar por ID.
- Eliminar productos.
- Mostrar inventario.

---

## Tabla Hash

Permite almacenar productos utilizando una función hash.

Operaciones realizadas:

- Insertar productos.
- Buscar productos.
- Mostrar la tabla hash.

---

## Grafo

Representa relaciones entre productos mediante una matriz de adyacencia.

Operaciones realizadas:

- Crear vértices.
- Crear conexiones.
- Mostrar relaciones.
- Ejecutar recorrido DFS.

---

# Ejemplo de ejecución

Al ejecutar el programa se muestran ejemplos del funcionamiento de cada estructura de datos implementada.

No es necesario ingresar datos por teclado, ya que la demostración es automática.

---

# Observaciones

Este proyecto tiene fines académicos y busca demostrar la implementación de diferentes estructuras de datos estudiadas durante la asignatura.
