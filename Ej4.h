#ifndef EJ4_H
#define EJ4_H

#include <string>

/*
    Compara dos cadenas de texto en tiempo de ejecución.
    Usa string para manejar las cadenas de texto.
    Parámetros:
        - text1: Primera cadena de texto a comparar
        - text2: Segunda cadena de texto a comparar
        - index: Índice actual de la comparación (por default, 0)
    Retorna:
        - true si las cadenas son iguales, false en caso contrario
*/
bool compararEnEjecucion(const std::string& text1, const std::string& text2, size_t index = 0);

/*
    Compara dos cadenas de texto en tiempo de compilación.
    Usa constexpr para permitir la evaluación en tiempo de compilación.
    Parámetros:
        - text1: Primera cadena de texto a comparar (char*)
        - text2: Segunda cadena de texto a comparar (char*)
        - index: Índice actual de la comparación (por default, 0)
    Retorna:
        - true si las cadenas son iguales, false en caso contrario
*/
constexpr bool compararEnCompilacion(const char* text1, const char* text2, size_t index = 0);

#endif // EJ4_H