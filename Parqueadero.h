#ifndef PARQUEADERO_H
#define PARQUEADERO_H

#include <iostream>
using namespace std;

class Parqueadero {
private:
    char** matriz;    // Matriz para representar el parqueadero
    int filas;        // Número de filas del parqueadero
    int columnas;     // Número de columnas del parqueadero

public:
    // Constructor y destructor
    Parqueadero(int _filas, int _columnas);
    ~Parqueadero();

    // Métodos
    void mostrarParqueadero();
    void ocuparEspacio(int idEspacio);
    void liberarEspacio(int idEspacio);
};

#endif // PARQUEADERO_H
