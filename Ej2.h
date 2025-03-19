#ifndef EJ2_H
#define EJ2_H

#include <string>

enum NivelSeveridad {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

/*
    Registra un mensaje en el archivo de log con un nivel de severidad.
    Parámetros:
        - mensaje: Mensaje a registrar
        - nivel: Nivel de severidad del mensaje (DEBUG, INFO, WARNING, ERROR, CRITICAL)
*/
void logMessage(const std::string& mensaje, NivelSeveridad nivel);

/*
    Registra un mensaje de error en el archivo de log con información adicional.
    Parámetros:
        - mensaje_de_error: Mensaje de error a registrar
        - archivo: Nombre del archivo donde ocurrió el error
        - linea_codigo: Línea de código donde ocurrió el error
*/
void logMessage(const std::string& mensaje_de_error, const std::string& archivo, const int linea_codigo);

/*
    Función que registra un mensaje relacionado con accesos de usuarios en el archivo de log.
    Parámetros:
        - mensaje_acceso: Mensaje de acceso a escribir en el archivo de log
        - nombre_usuario: Nombre del usuario que intentó acceder
*/
void logMessage(const std::string& mensaje_acceso, const std::string& nombre_usuario);

#endif // EJ2_H