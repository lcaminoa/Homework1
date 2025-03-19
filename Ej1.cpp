/*
    Este programa crea una matriz dinámica de tamaño n x n, la llena con valores consecutivos
    empezando desde 1, la imprime en orden inverso (de atrás para adelante) y después libera la memoria.
    El programa usa manejo de excepciones para capturar errores de asignación de memoria y asegura que
    no haya leaks de memoria al liberar.
*/

#include "Ej1.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int** creatematrix(size_t n) {
    try {
        int** matrix = new int*[n]; // Crear un array de punteros para las filas
        int valor = 1; // Valor inicial que irá aumentando en cada celda
        for (size_t i = 0; i < n; i++) {
            matrix[i] = new int[n]; // Crear un array para cada fila
            for (size_t j = 0; j < n; j++) {
                matrix[i][j] = valor++; // Asignar valores consecutivos a cada celda
            }
        }
        return matrix; // Retornar el puntero a la matriz
    }
    catch (bad_alloc& e) {
        // Capturar errores de asignación de memoria y mostrar un mensaje de error
        cerr << "Error al reservar memoria para la matriz: " << e.what() << endl;
        throw; // Relanzar la excepción para que se maneje en otro lugar
    }
}

void printmatrix(int** matrix, size_t n) {
    for (int i = n * n - 1; i >= 0; i--) { // Iterar desde la última celda hasta la primera
        int fila = i / n; // Calcular la fila
        int columna = i % n; // Calcular la columna
        cout << "M[" << fila << "][" << columna << "] = " << matrix[fila][columna] << endl;
    }
}

void freematrix(int** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i]; // Liberar cada fila
    }
    delete[] matrix; // Liberar el array de punteros
}

int main(void) {
    size_t n;
    cout << "Ingrese un entero positivo mayor a uno: ";
    cin >> n;

    if (n <= 1) {
        // Validar que el tamaño de la matriz sea mayor a 1
        cout << "El valor debe ser mayor a uno." << endl;
        return 1;
    }

    // Crear la matriz, imprimirla y liberar la memoria
    int** matrix = creatematrix(n);
    printmatrix(matrix, n);
    freematrix(matrix, n);

    return 0; // Mostrar que el programa terminó correctamente
}