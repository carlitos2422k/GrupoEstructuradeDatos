#include "Parqueadero.h"

Parqueadero::Parqueadero(int _filas, int _columnas) : filas(_filas), columnas(_columnas) {
    matriz = new char*[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new char[columnas];
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = '-'; // Inicialmente todos los espacios están vacíos
        }
    }
}

Parqueadero::~Parqueadero() {
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void Parqueadero::mostrarParqueadero() {
    cout << "\nEstado del Parqueadero:\n";
    int idEspacio = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            // Mostrar el ID del espacio con su estado: 'X' si está ocupado, '-' si está libre
            cout << "[" << idEspacio << (matriz[i][j] == 'X' ? "X" : "-") << "] ";
            idEspacio++; // Incrementar el ID del espacio
        }
        cout << endl;
    }
}

void Parqueadero::ocuparEspacio(int idEspacio) {
    int fila = idEspacio / columnas;
    int columna = idEspacio % columnas;
    if (fila < filas && columna < columnas) {
        matriz[fila][columna] = 'X'; // Representar el espacio ocupado
    }
}

void Parqueadero::liberarEspacio(int idEspacio) {
    int fila = idEspacio / columnas;
    int columna = idEspacio % columnas;
    if (fila < filas && columna < columnas) {
        matriz[fila][columna] = '-'; // Representar el espacio libre
    }
}
