#include "Lista_Circular_Doble.cpp" // Asegúrate de que esta clase maneje los nodos de parqueo
#include "Nodo.cpp"
#include "Validaciones.cpp"
#include <iostream>
#include <string>
#include <conio.h> 
#include <cstdlib>

using namespace std;

class Parqueadero {
private:
    char** matriz;
    int filas;
    int columnas;

public:
    Parqueadero(int _filas, int _columnas) : filas(_filas), columnas(_columnas) {
        matriz = new char*[filas];
        for (int i = 0; i < filas; ++i) {
            matriz[i] = new char[columnas];
            for (int j = 0; j < columnas; ++j) {
                matriz[i][j] = '-';
            }
        }
    }

    ~Parqueadero() {
        for (int i = 0; i < filas; ++i) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }

    void mostrarParqueadero() {
        cout << "\nEstado del Parqueadero:\n";
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    void ocuparEspacio(int idEspacio) {
        int fila = idEspacio / columnas;
        int columna = idEspacio % columnas;
        if (fila < filas && columna < columnas) {
            matriz[fila][columna] = 'X';
        }
    }

    void liberarEspacio(int idEspacio) {
        int fila = idEspacio / columnas;
        int columna = idEspacio % columnas;
        if (fila < filas && columna < columnas) {
            matriz[fila][columna] = '-';
        }
    }
};

void mostrarMenu(const string opciones[], int numOpciones, int seleccion) {
    system("cls");
    cout << "\033[35m*********** Sistema de Parqueadero ***********\033[0m\n";
    for (int i = 0; i < numOpciones; ++i) {
        if (i == seleccion) {
            cout << "\033[32m > " << opciones[i] << " <\033[0m\n"; // Resaltar la opción seleccionada
        } else {
            cout << "   " << opciones[i] << "\n";
        }
    }
}

int main() {
    int filas = 5, columnas = 5;
    Parqueadero* parqueadero = new Parqueadero(filas, columnas);
    Lista_Circular_Doble<string>* lista_vehiculos = new Lista_Circular_Doble<string>();
    Validaciones<std::string> ingresar_string;
    Validaciones<long> ingresar_cedula;
    string opciones[] = {
        "Insertar vehiculo",
        "Eliminar vehiculo",
        "Mostrar vehiculos",
        "Salir"
    };

    int seleccion = 0;
    int numOpciones = 4;
    bool ejecutando = true;

    string nombre, apellido, placa, marca, color, celular, cedulaStr;
    long cedula;
    int idEspacio = 0;

    while (ejecutando) {
        mostrarMenu(opciones, numOpciones, seleccion);
        parqueadero->mostrarParqueadero();

        char tecla = _getch(); // Captura la tecla
        switch (tecla) {
        case 72: // Flecha hacia arriba
            seleccion = (seleccion - 1 + numOpciones) % numOpciones;
            break;
        case 80: // Flecha hacia abajo
            seleccion = (seleccion + 1) % numOpciones;
            break;
        case 13: // Enter
            switch (seleccion) {
            case 0: // Insertar vehículo
                nombre=ingresar_string.ingresar("Ingrese el nombre del propietario: ","string" );
                cout << endl;
                apellido=ingresar_string.ingresar("Ingrese el apellido del propietario: ", "string");
                cout << endl;
                cedula=ingresar_cedula.ingresar("Ingrese la cedula del propietario: ","long");
                cout << endl;
                celular=ingresar_string.ingresar("Ingrese el numero celular del propietario: ","string");
                cout << endl;
                cout << "Ingrese la placa del vehiculo: ";
                getline(cin, placa);
                cout << endl;
                marca=ingresar_string.ingresar("Ingrese la marca del vehiculo: ", "string");
                cout << endl;
                color=ingresar_string.ingresar("Ingrese el color del vehiculo: ","string");
                cout << endl;
                cedulaStr = to_string(cedula);
                cout << endl;
                lista_vehiculos->InsertarPorCabeza(nombre, apellido, cedulaStr, celular, idEspacio, placa, marca, color);
                parqueadero->ocuparEspacio(idEspacio);
                cout << "Vehículo ingresado correctamente en el espacio " << idEspacio << endl;
                idEspacio++;
                system("pause");
                break;

            case 1: // Eliminar vehículo
                cout << "Ingrese la placa del vehiculo a eliminar: ";
                cin >> placa;
                lista_vehiculos->EliminarPorPlaca(placa);
                cout << "Ingrese el ID del espacio a liberar: ";
                int idEliminar;
                cin >> idEliminar;
                parqueadero->liberarEspacio(idEliminar);
                cout << "Vehiculo eliminado y espacio liberado.\n";
                system("pause");
                break;

            case 2: // Mostrar vehículos
                lista_vehiculos->Mostrar();
                system("pause");
                break;

            case 3: // Salir
                ejecutando = false;
                break;
            }
            break;

        default:
            break;
        }
    }

    delete parqueadero;
    delete lista_vehiculos;
    cout << "Saliendo del programa..." << endl;
    return 0;
}
