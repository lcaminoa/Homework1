#ifndef EJ3_H
#define EJ3_H

#include <memory>

struct Node {
    int value;
    std::unique_ptr<Node> next;
};

struct List {
    std::unique_ptr<Node> head;
    int size;
};

/*
    Crea un nuevo nodo con el valor dado.
    Parámetros:
        - value: Valor del nodo a agregar
    Retorna:
        - Un unique pointer (unique_ptr<Node>) al nodo creado
*/
std::unique_ptr<Node> create_node(int value);

/*
    Inserta un nodo al inicio de la lista.
    Parámetros:
        - list: Unique pointer a la lista
        - value: Valor del nodo a agregar
*/
void push_front(std::unique_ptr<List>& list, int value);

/*
    Inserta un nodo al final de la lista.
    Parámetros:
        - list: Unique pointer a la lista
        - value: Valor del nodo a agregar
*/
void push_back(std::unique_ptr<List>& list, int value);

/*
    Inserta un nodo en una posición específica de la lista.
    Parámetros:
        - list: Unique pointer a la lista
        - value: Valor del nodo a agregar
        - position: Posición donde se insertará el nodo
*/
void insert(std::unique_ptr<List>& list, int value, int position);

/*
    Elimina un nodo de una posición específica de la lista.
    Si la posición es mayor que el tamaño de la lista, se elimina el último nodo.

    Parámetros:
        - list: Unique pointer a la lista
        - position: Posición del nodo a eliminar
*/
void erase(std::unique_ptr<List>& list, int position);

/*
    Imprime los valores de la lista enlazada.
    Parámetros:
        - list: Unique pointer a la lista
*/
void print_list(const std::unique_ptr<List>& list);

#endif // EJ3_H