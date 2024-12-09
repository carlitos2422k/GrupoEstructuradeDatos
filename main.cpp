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
        "Salir"
    };

    int seleccion = 0;
    int numOpciones = 4;
    bool ejecutando = true;

    string nombre, apellido, placa, marca, color, celular, cedulaStr, fechaHoraActual;
    long cedula;
    int idEspacio = 0;

    while (ejecutando) {
        cedulaStr = "";
        placa= ""; 
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
                do{
                    idEspacio=ingresar_entero.ingresar("Ingrese en donde desea parquear (0-14): ", "entero");
                    cout << endl;
                    if (idEspacio < 0 || idEspacio >= filas * columnas) {
                        cout << "ID de espacio inválido. Ingrese nuevamente\n";
                    }
                    if (Utils::isSpaceOccupied(lista_vehiculos, idEspacio)); {
                        cout << "ID de espacio ocupado. Ingrese nuevamente\n";
                    }
                }
                while(idEspacio < 0 || idEspacio >= filas * columnas || !Utils::isSpaceOccupied(lista_vehiculos, idEspacio));

                cout << "Datos del vehículo:\n";
                nombre=ingresar_string.ingresar("Ingrese el nombre del propietario: ","string" );
                cout << endl;
                apellido=ingresar_string.ingresar("Ingrese el apellido del propietario: ", "string");
                cout << endl;
                while (!Utils::validateId(cedulaStr) || !Utils::isUniqueField(lista_vehiculos,cedulaStr,"cedula",-1)) {
                    cedula = ingresar_cedula.ingresar("Ingrese la cedula: ", "long");
                    cout << endl;
                    cedulaStr = std::to_string(cedula);

                    if (!Utils::validateId(cedulaStr)) {
                        cout << "Cedula invalida. Ingrese nuevamente." << endl;
                    }
                    if (!Utils::isUniqueField(lista_vehiculos,cedulaStr,"cedula",-1)) {
                        cout << "Cedula ya ingresada. Ingrese nuevamente." << endl;
                    }
                }
                cout << endl;
                while (!Utils::isUniqueField(lista_vehiculos,celular,"celular",-1))
                {
                celular=ingresar_string.ingresar("Ingrese el numero celular del propietario: ","string");
                cout << endl;
                if (!Utils::isUniqueField(lista_vehiculos,celular,"celular",-1)) {
                        cout << "Celular ya ingresada. Ingrese nuevamente." << endl;
                    }
                }
                while (!Utils::validarPlacaEcuador(placa) || !Utils::isUniqueField(lista_vehiculos,placa,"placa",-1))
                {
                    cout << "Ingrese la placa del vehiculo: ";
                    cout << endl;
                    cin >> placa;
                    if (!Utils::validarPlacaEcuador(placa)) {
                        cout << "Placa invalida. Ingrese nuevamente." << endl;
                    }
                    if (!Utils::isUniqueField(lista_vehiculos,placa,"placa",-1)) {
                        cout << "Placa ya ingresada. Ingrese nuevamente." << endl;
                    }

                }
                cout << endl;
                marca=ingresar_string.ingresar("Ingrese la marca del vehiculo: ", "string");
                cout << endl;
                color=ingresar_string.ingresar("Ingrese el color del vehiculo: ","string");
                cout << endl;
                fechaHoraActual = Utils::getCurrentDateTime();
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
            parqueadero->liberarEspacio(idEspacio);
            cout << "Vehículo eliminado y espacio liberado.\n";
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
