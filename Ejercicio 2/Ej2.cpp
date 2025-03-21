/*
    Este programa implementa un sistema de registro de logs en un archivo llamado log.txt
    Permite registrar mensajes con diferentes niveles de severidad (DEBUG, INFO, WARNING, ERROR, CRITICAL),
    mensajes de error con información adicional (archivo y línea de código), y accesos de usuarios.
    Además, maneja excepciones en tiempo de ejecución y registra los errores en el archivo de log. El
    programa asegura que los mensajes se escriban correctamente en el archivo y maneja errores al abrir el
    archivo de log.
*/

#include "Ej2.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void logMessage(const string& mensaje, NivelSeveridad nivel) {
    ofstream logFile("log.txt", ios::app); // Abrir el archivo en modo append
    if (!logFile.is_open()) { // Verificar si no hubo errores al abrir
        cerr << "No se pudo abrir el archivo de log." << endl;
        return;
    }

    // Escribir el mensaje con el nivel de severidad correspondiente
    switch (nivel) {
        case DEBUG:
            logFile << "[DEBUG] " << mensaje << endl;
            break;
        case INFO:
            logFile << "[INFO] " << mensaje << endl;
            break;
        case WARNING:
            logFile << "[WARNING] " << mensaje << endl;
            break;
        case ERROR:
            logFile << "[ERROR] " << mensaje << endl;
            break;
        case CRITICAL:
            logFile << "[CRITICAL] " << mensaje << endl;
            break;
        default:
            logFile << "[UNKNOWN] " << mensaje << endl;
            break;
    }

    logFile.close(); // Cerrar el archivo
}

void logMessage(const string& mensaje_de_error, const string& archivo, const int linea_codigo) {
    ofstream logFile("log.txt", ios::app); // Abrir el archivo en modo append
    if (!logFile.is_open()) { // Verificar si no hubo errores al abrir
        cerr << "No se pudo abrir el archivo de log." << endl;
        return;
    }

    // Escribir el mensaje de error con información adicional
    logFile << "[ERROR] " << mensaje_de_error << " (Archivo: " << archivo << ", línea: " << linea_codigo << ")" << endl;

    logFile.close(); // Cerrar el archivo
}

void logMessage(const string& mensaje_acceso, const string& nombre_usuario) {
    ofstream logFile("log.txt", ios::app); // Abrir el archivo en modo append
    if (!logFile.is_open()) { // Verificar si no hubo errores al abrir
        cerr << "No se pudo abrir el archivo de log." << endl;
        return;
    }

    // Escribir el mensaje de acceso con el nombre del usuario
    logFile << "[SECURITY] " << mensaje_acceso << " (Usuario: " << nombre_usuario << ")" << endl;

    logFile.close(); // Cerrar el archivo
}

int main() {
    // Registrar mensajes con diferentes niveles de severidad
    logMessage("Mensaje de depuración.", DEBUG);
    logMessage("Mensaje informativo.", INFO);
    logMessage("Mensaje de advertencia.", WARNING);
    logMessage("Mensaje de error.", ERROR);
    logMessage("Mensaje crítico.", CRITICAL);

    // Registrar un mensaje de error con info adicional
    logMessage("Error en la conexión a la base de datos.", "main.cpp", 42);

    // Registrar mensajes de accesos de usuarios
    logMessage("Access Granted", "User1");
    logMessage("Acces Denied", "User2");

    // Manejar excepciones en tiempo de ejecución
    try {
        throw runtime_error("Se produjo un error desconocido."); // Lanzar una excepción
    } catch (exception& e) {
        logMessage(e.what(), __FILE__, __LINE__); // Registrar el error en el archivo de log
        cerr << "Se capturó un error en runtime.\nSaliendo del programa..." << endl;
        return 1; // Salir del programa con un código de error
    }

    cout << "Los mensajes de log fueron escritos correctamente en log.txt" << endl;

    return 0;
}