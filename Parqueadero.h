#ifndef PARQUEADERO_H
#define PARQUEADERO_H

#include <iostream>
#include <cmath>  // Para operaciones matemáticas como sqrt()
using namespace std;

class Parqueadero {
private:
    char** matriz;    // Matriz para representar el parqueadero
    int filas;        // Número de filas del parqueadero
    int columnas;     // Número de columnas del parqueadero
    int totalEspacios; // Total de espacios en el parqueadero
    int radio; // Radio del parqueadero circular

public:
    // Constructor y destructor
    Parqueadero(int _filas, int _columnas);
    ~Parqueadero();

    // Métodos
    void mostrarParqueadero();
    void ocuparEspacio(int idEspacio);
    void liberarEspacio(int idEspacio);
    void asignarIdEspacios();
};

#endif // PARQUEADERO_H
