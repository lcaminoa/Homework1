# Homework 1  
## Lautaro Valentín Caminoa  

Este homework contiene cuatro ejercicios implementados en C++. A continuación, se detalla cómo compilar y ejecutar cada uno de ellos.

---

### Ejercicio 1  
**Descripción:**  
Este programa crea una matriz dinámica de tamaño `n x n`, la llena con valores consecutivos, la imprime en orden inverso y libera la memoria asignada.

**Archivos:**  
- `Ej1.cpp`  
- `Ej1.h`  

**Cómo compilar:**  
```
g++ -o Ej1 Ej1.cpp
```
Esto genera un ejecutable llamado `Ej1`

**Cómo ejecutar:**
```
./Ej1
```

---

### Ejercicio 2
**Descripción:**  
Este programa implementa un sistema de registro de logs en un archivo llamado `log.txt`. Permite registrar mensajes con diferentes niveles de severidad, errores con información adicional y accesos de usuarios.

**Archivos:**  
- `Ej2.cpp`
- `Ej2.h`

**Cómo compilar:**  
```
g++ -o Ej2 Ej2.cpp
```
Esto genera un ejecutable llamado `Ej2`

**Cómo ejecutar:**
```
./Ej2
```

---


### Ejercicio 3
**Descripción:**  
Este programa implementa una lista simplemente enlazada utilizando `std::unique_ptr`. Permite insertar y eliminar elementos en diferentes posiciones y muestra los elementos de la lista.

**Archivos:**  
- `Ej3.cpp`
- `Ej3.h`

**Cómo compilar:**  
```
g++ -std=c++14 -o Ej3 Ej3.cpp
```
Esto genera un ejecutable llamado `Ej3`

**Cómo ejecutar:**
```
./Ej3
```

---

### Ejercicio 4
**Descripción:**    
Este programa compara cadenas de texto utilizando dos enfoques:

1. En tiempo de ejecución, usando `std::string`.
2. En tiempo de compilación, usando `constexpr` y `char*`.

Además, mide el tiempo de ejecución de ambas funciones y muestra los resultados.

**Archivos:**  
- `Ej4.cpp`
- `Ej4.h`

**Cómo compilar:**  
```
g++ -std=c++14 -o Ej4 Ej4.cpp
```
Esto genera un ejecutable llamado `Ej4`

**Cómo ejecutar:**
```
./Ej4
```
