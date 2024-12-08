#include "Lista_Circular_Doble.cpp" // Asegúrate de que esta clase maneje los nodos de parqueo
#include "Lista_Circular_Doble.h"
#include "Nodo.cpp"
#include "Validaciones.cpp"
#include "Parqueadero.cpp"
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include "utils.cpp"
using namespace std;

int main() {
    int filas = 5, columnas = 5;
    Parqueadero* parqueadero = new Parqueadero(filas, columnas);
    Lista_Circular_Doble<string>* lista_vehiculos = new Lista_Circular_Doble<string>();
    lista_vehiculos->InicializarLista(filas * columnas);
    Validaciones<std::string> ingresar_string;
    Validaciones<long> ingresar_cedula;
    Validaciones<int> ingresar_entero;
    string opciones[] = {
        "Insertar vehiculo",
        "Eliminar vehiculo",
        "Mostrar vehiculos",
        "Manual de usuario",
        "Salir"
    };
    string opciones_manual[] = {
        "1. Insertar Vehiculo",
        "2. Eliminar Vehiculo",
        "3. Mostrar Vehiculos",
        "4. Salir del Manual"
                };
    int seleccion = 0;
    int numOpciones = 5;
    bool ejecutando = true;
    const int num_opciones_manual = 4;
    int opcion_manual = 0;

    string nombre, apellido, placa, marca, color, cedulaStr, fechaHoraActual;
    long cedula;
    int idEspacio = 0;

    while (ejecutando) {
        cedulaStr = "";
        placa = "";
        Utils::mostrarMenu(opciones, numOpciones, seleccion);
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
                do {
                    idEspacio = ingresar_entero.ingresar("Ingrese en donde desea parquear (0-14): ", "entero");
                    cout << endl;
                    if (idEspacio < 0 || idEspacio >= filas * columnas) {
                        cout << "ID de espacio inválido. Ingrese nuevamente\n";
                    } else if (!Utils::isSpaceOccupied(lista_vehiculos, idEspacio)) {
                        cout << "ID de espacio ocupado. Ingrese nuevamente\n";
                    }
                } while (idEspacio < 0 || idEspacio >= filas * columnas || !Utils::isSpaceOccupied(lista_vehiculos, idEspacio));

                cout << "Datos del vehículo:\n";
                nombre = ingresar_string.ingresar("Ingrese el nombre del propietario: ", "string");
                cout << endl;
                apellido = ingresar_string.ingresar("Ingrese el apellido del propietario: ", "string");
                cout << endl;
                while (!Utils::validateId(cedulaStr) || !Utils::isUniqueField(lista_vehiculos, cedulaStr, "cedula", -1)) {
                    cedula = ingresar_cedula.ingresar("Ingrese la cédula: ", "long");
                    cout << endl;
                    cedulaStr = std::to_string(cedula);

                    if (!Utils::validateId(cedulaStr)) {
                        cout << "Cédula inválida. Ingrese nuevamente." << endl;
                    }
                    if (!Utils::isUniqueField(lista_vehiculos, cedulaStr, "cedula", -1)) {
                        cout << "Cédula ya ingresada. Ingrese nuevamente." << endl;
                    }
                }
                cout << endl;
                while (!Utils::validarPlacaEcuador(placa) || !Utils::isUniqueField(lista_vehiculos, placa, "placa", -1)) {
                    cout << "Ingrese la placa del vehículo: ";
                    cout << endl;
                    cin >> placa;
                    if (!Utils::validarPlacaEcuador(placa)) {
                        cout << "Placa inválida. Ingrese nuevamente." << endl;
                    }
                    if (!Utils::isUniqueField(lista_vehiculos, placa, "placa", -1)) {
                        cout << "Placa ya ingresada. Ingrese nuevamente." << endl;
                    }
                }
                cout << endl;
                marca = ingresar_string.ingresar("Ingrese la marca del vehículo: ", "string");
                cout << endl;
                color = ingresar_string.ingresar("Ingrese el color del vehículo: ", "string");
                cout << endl;
                fechaHoraActual = Utils::getCurrentDateTime();
                cout << endl;
                lista_vehiculos->ActualizarEspacio(nombre, apellido, cedulaStr, idEspacio, placa, marca, color, fechaHoraActual);
                parqueadero->ocuparEspacio(idEspacio);
                cout << "Vehículo ingresado correctamente en el espacio " << idEspacio << endl;
                system("pause");
                break;

            case 1: // Eliminar vehículo
            placa="";
            cout << "Ingrese la placa del vehiculo a eliminar: ";
            cin >> placa;
            lista_vehiculos->EliminarPorPlaca(placa);
            parqueadero->liberarEspacio(idEspacio);
            cout << "Vehículo eliminado y espacio liberado.\n";
            system("pause");
                break;

            case 2: // Mostrar vehículos
                lista_vehiculos->Mostrar();
                system("pause");
                break;

            case 3: // Manual de usuario
                while (true) {
                    system("cls");
                    cout << "\033[34m**** Manual de Usuario ****\033[0m" << endl;

                    for (int i = 0; i < num_opciones_manual; ++i) {
                        if (i == opcion_manual)
                            cout << "-> " << opciones_manual[i] << endl;
                        else
                            cout << "   " << opciones_manual[i] << endl;
                    }

                    char tecla_manual = _getch();
                    if (tecla_manual == 72)
                        opcion_manual = (opcion_manual - 1 + num_opciones_manual) % num_opciones_manual;
                    else if (tecla_manual == 80)
                        opcion_manual = (opcion_manual + 1) % num_opciones_manual;
                    else if (tecla_manual == 13) {
                        switch (opcion_manual) {
                        case 0:
                            cout << "Para insertar un vehiculo:\n";
                            cout << "- Elija un espacio libre en el parqueadero.\n";
                            cout << "- Ingrese los datos solicitados (nombre, cedula, placa, etc.).\n";
                            cout << "*Ejemplo:*\n";
                            cout << "Nombre: Juan\nApellido: Perez\nCedula: 1723456789\n";
                            cout << "Celular: 0987654321\nPlaca: ABC-1234\nMarca: Toyota\nColor: Rojo\n";
                            cout << "El sistema validara los datos y registrara el vehiculo.\n";
                            system("pause");
                            break;
                        case 1:
                            cout << "Para eliminar un vehiculo:\n";
                            cout << "- Ingrese la placa del vehiculo que desea eliminar.\n";
                            cout << "*Ejemplo:*\n";
                            cout << "Placa: ABC-1234\n";
                            cout << "El sistema eliminara el registro y liberara el espacio correspondiente.\n";
                            system("pause");
                            break;
                        case 2:
                            cout << "Para mostrar los vehiculos:\n";
                            cout << "- Seleccione esta opcion para listar los vehiculos registrados.\n";
                            cout << "*Ejemplo de salida:*\n";
                            cout << "Espacio 1: Juan Perez - Cedula: 1723456789 - Placa: ABC-1234 - Toyota Rojo\n";
                            system("pause");
                            break;
                        case 3:
                            break;
                        }
                        if (opcion_manual == 3) break;
                    }
                }
                break;

            case 4: // Salir
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
