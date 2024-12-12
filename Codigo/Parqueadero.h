/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre Sistema de Gestión de Parqueo        *
 * Autor:                          Danna Andrade, Carlos Perez, Samaniego Jefferson    *
 * Fecha de creacion:              02/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
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
