/*
    Este programa implementa una lista simplemente enlazada usando smart pointers (unique_ptr).
    Permite realizar operaciones como insertar elementos al inicio, al final o en una posición específica,
    eliminar elementos de una posición específica y mostrar los elementos de la lista.
    Al usar unique_ptr, la memoria se maneja automaticamente, evitando leaks de memoria. El programa también
    maneja casos como índices inválidos o posiciones fuera del rango de la lista.
*/

#include "Ej3.h"
#include <iostream>
#include <memory>

using namespace std;

unique_ptr<Node> create_node(int value) {
    auto new_node = make_unique<Node>(); // Crear un nuevo nodo
    new_node->value = value; // Asignar el valor al nodo
    return new_node; // Devolver el unique pointer al nodo
}

void push_front(unique_ptr<List>& list, int value) {
    auto new_node = create_node(value); // Crear un nuevo nodo
    new_node->next = std::move(list->head); // Apuntar el nuevo nodo al head de la lista
    list->head = std::move(new_node); // Actualizar el inicio de la lista
    list->size++; // Incrementar el tamaño de la lista
}

void push_back(unique_ptr<List>& list, int value) {
    auto new_node = create_node(value); // Crear un nuevo nodo
    if (!list->head) { // Si la lista está vacía
        list->head = std::move(new_node); // El nuevo nodo se convierte en el inicio de la lista
        list->size++;
        return;
    }

    auto temp = list->head.get(); // Obtener un raw pointer al nodo actual
    while (temp->next) { // Recorrer la lista hasta el último nodo
        temp = temp->next.get();
    }
    temp->next = std::move(new_node); // Insertar el nuevo nodo al final
    list->size++; // Incrementar el tamaño de la lista
}

void insert(unique_ptr<List>& list, int value, int position) {
    if (position < 0) { // Ver si la posición es negativa
        cout << "Posición inválida." << endl;
        return;
    }

    if (position == 0) { // Insertar al inicio si la posición es 0
        push_front(list, value);
        return;
    }

    auto temp = list->head.get(); // Obtener un raw pointer al nodo actual
    int index = 0;

    while (temp->next && index < position - 1) { // Recorrer la lista hasta la posición deseada
        temp = temp->next.get();
        index++;
    }

    if (temp->next && index == position - 1) { // Insertar en la posición dada
        auto new_node = create_node(value);
        new_node->next = std::move(temp->next);
        temp->next = std::move(new_node);
        list->size++;
    }
    else { // Si la posición es mayor que el tamaño de la lista, insertar al final
        cout << "Posición mayor que el largo de la lista. Se insertó al final." << endl;
        push_back(list, value);
    }
}

void erase(unique_ptr<List>& list, int position) {
    if (position < 0) { // Ver si la posición es negativa
        cout << "Posición inválida." << endl;
        return;
    }
    if (position >= list->size) { // Si la posición es mayor que el tamaño de la lista
        cout << "Posición mayor que el largo de la lista. Se eliminó el último nodo." << endl;
        position = list->size - 1;
    }

    if (!list->head) return; // Si la lista está vacía, no hacer nada

    if (position == 0) { // Eliminar el primer nodo
        list->head = std::move(list->head->next);
        list->size--;
        return;
    }

    auto temp = list->head.get(); // Obtener un raw pointer al nodo actual
    int index = 0;

    while (temp->next && index < position - 1) { // Recorrer la lista hasta la posición deseada
        temp = temp->next.get();
        index++;
    }

    temp->next = std::move(temp->next->next); // Eliminar el nodo en la posición dada
    list->size--;
}

void print_list(const unique_ptr<List>& list) {
    auto temp = list->head.get(); // Obtener un raw pointer al nodo actual
    while (temp) { // Recorrer la lista e imprimir los valores
        cout << temp->value << " -> ";
        temp = temp->next.get();
    }
    cout << "null" << endl; // El final de la lista
}

int main() {
    unique_ptr<List> list = make_unique<List>(); // Crear una lista vacía
    list->size = 0;

    cout << "Lista después de 2 push front: ";
    push_front(list, 10);
    push_front(list, 20);
    print_list(list);

    cout << "Lista después de 1 push back: ";
    push_back(list, 30);
    print_list(list);

    cout << "Lista después de insertar 25 en el indice 2: ";
    insert(list, 25, 2);
    print_list(list);

    cout << "Lista después de insertar 5 en el indice 0: ";
    insert(list, 5, 0);
    print_list(list);

    cout << "Lista después de insertar 35 en el indice 10: ";
    insert(list, 35, 10);
    print_list(list);

    cout << "Lista después de borrar el indice 0: ";
    erase(list, 0);
    print_list(list);

    cout << "Lista después de borrar el indice 2: ";
    erase(list, 2);
    print_list(list);

    cout << "Lista después de borrar el indice 10: ";
    erase(list, 10);
    print_list(list);

    // Insertar y borrar con posiciones negativas
    cout << "Lista después de insertar y eliminar con posiciones negativas: " << endl;
    insert(list, 40, -1);
    erase(list, -1);

    cout << "Lista final: ";
    print_list(list);

    return 0;
}