#ifndef EJ1ALT_H
#define EJ1ALT_H

#include <cstddef> // size_t

/*
    Crea una matriz dinámica de tamaño n x n y la llena con valores consecutivos.
    Parámetros:
        - n: Tamaño de la matriz (número de filas y columnas)
    Retorna:
        - Un puntero doble (int**) que apunta a la matriz creada
    Manejo de errores:
        - Si ocurre un error de asignación de memoria, lanza una excepción bad_alloc
*/
int** creatematrix(size_t n);

/*
    Imprime los valores de una matriz dinámica en orden inverso.
    Parámetros:
        - matrix: Puntero doble (int**) que apunta a la matriz
        - n: Tamaño de la matriz (número de filas y columnas)
*/
void printmatrix(int** matrix, size_t n);

/*
    Libera la memoria asignada para la matriz.
    Parámetros:
        - matrix: Puntero doble (int**) que apunta a la matriz
        - n: Tamaño de la matriz (número de filas y columnas)
    Info:
        - Libera cada fila de la matriz y luego el array de punteros
*/
void freematrix(int** matrix, size_t n);

#endif // EJ1ALT_H