/*
    En la primera función, comencé usando string en lugar de char* ya que incluyendo la librería string
    resultaba mucho más sencillo, al contener funciones como size(), que facilitan el trabajo.
    Además, string maneja automáticamente la gestión de la memoria, lo que reduce las probabilidades de
    errores como leaks de memoria o acceder a indices "out of range". Que si usara char* debería hacerlo
    manualmente.

    En la segunda función, usé char* y constexpr para que el compilador pueda evaluar la función en tiempo
    de compilación. El marcar la función como constexpr, le dice al compilador que puede evaluar la
    función en tiempo de compilación si los argumentos son constantes. Además, al usar char* en lugar de
    string, se evita la sobrecarga de la librería string, lo que puede hacer que la
    función sea más rápida.

    El programa mide el tiempo que toma cada función para realizar la comparación y muestra los resultados.
    Al final se explican las ventajas y desventajas de cada enfoque.
*/

#include "Ej4.h"
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

bool compararEnEjecucion(const string& text1, const string& text2, size_t index) {
    if (text1.size() != text2.size()) { // Verificar si las cadenas tienen tamaños diferentes
        return false;
    }
    if (index == text1.size()) { // Caso base: se recorrieron todos los caracteres
        return true;
    }
    if (text1[index] != text2[index]) { // Comparar el caracter actual
        return false;
    }
    return compararEnEjecucion(text1, text2, index + 1); // Llamada recursiva al siguiente caracter
}

constexpr bool compararEnCompilacion(const char* text1, const char* text2, size_t index) {
    if (text1[index] == '\0' && text2[index] == '\0') { // Caso base: ambos punteros llegaron al final
        return true;
    }
    else if (text1[index] != text2[index]) { // Comparar el caracter actual
        return false;
    }
    else {
        return compararEnCompilacion(text1, text2, index + 1); // Llamada recursiva al siguiente caracter
    }
}

int main() {
    // Cadena de texto para la comparación 1
    string texto1 = "Las sombras bailan al ritmo del viento en la fría noche sin fin.";

    // Medir el tiempo de ejecución de compararEnEjecucion
    auto startTime1 = chrono::high_resolution_clock::now();
    bool sonIguales1 = compararEnEjecucion(texto1, texto1);
    auto endTime1 = chrono::high_resolution_clock::now();
    auto elapsedTime1 = chrono::duration_cast<chrono::nanoseconds>(endTime1 - startTime1);
    cout << "Mi proceso a medir tomó: " << elapsedTime1.count() << " nanosegundos (compararEnEjecucion)" << endl;

    // Cadena de texto para la comparación 2
    constexpr const char* texto2 = "Las sombras bailan al ritmo del viento en la fría noche sin fin.";

    // Medir el tiempo de ejecución de compararEnCompilacion
    auto startTime2 = chrono::high_resolution_clock::now();
    constexpr bool sonIguales2 = compararEnCompilacion(texto2, texto2);
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(endTime2 - startTime2);
    cout << "Mi proceso a medir tomó: " << elapsedTime2.count() << " nanosegundos (compararEnCompilacion)" << endl;

    return 0;
}

/*
    La diferencia en el tiempo de ejecución entre ambas funciones es que la primera función se ejecuta
    en tiempo de ejecución y la segunda función se ejecuta en tiempo de compilación. Por lo tanto,
    la segunda función es más rápida que la primera, y esto se puede ver en los resultados de la ejecución
    del programa.

    Pros y contras:
    - La función compararEnEjecucion es más flexible y fácil de usar gracias a string, pero se ejecuta
        en tiempo de ejecución, por lo que es más lenta.
    - La función compararEnCompilacion es más eficiente porque se evalúa en tiempo de compilación, pero
        requiere que las cadenas sean constantes y utiliza punteros char*, lo que es un poco más incómodo.
*/