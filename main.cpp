#include "Lista_Circular_Doble.cpp" // Asegúrate de que esta clase maneje los nodos de parqueo
#include "Nodo.cpp"
#include "Validaciones.cpp"
#include "Parqueadero.cpp"
#include <iostream>
#include <string>
#include <conio.h> 
#include <cstdlib>
#include <chrono>
#include <ctime>
using namespace std;


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
std::string getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::string timeStr = std::ctime(&now_time_t);
    timeStr.pop_back(); // Elimina el salto de línea
    return timeStr;
}
int main() {
    int filas = 5, columnas = 5;
    Parqueadero* parqueadero = new Parqueadero(filas, columnas);
    Lista_Circular_Doble<string>* lista_vehiculos = new Lista_Circular_Doble<string>();
    lista_vehiculos->InicializarLista(filas * columnas);
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

    string nombre, apellido, placa, marca, color, celular, cedulaStr, fechaHoraActual;
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
                cout << "Ingrese el ID del espacio (0-14): ";
                cin >> idEspacio;
                if (idEspacio < 0 || idEspacio >= filas * columnas) {
                    cout << "ID de espacio inválido.\n";
                    break;
                }
                cout << "Datos del vehículo:\n";
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
                fechaHoraActual = getCurrentDateTime();
                cout << endl;
                lista_vehiculos->ActualizarEspacio(nombre, apellido, cedulaStr, celular, idEspacio, placa, marca, color, fechaHoraActual);
                parqueadero->ocuparEspacio(idEspacio);
                cout << "Vehículo ingresado correctamente en el espacio " << idEspacio << endl;
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
