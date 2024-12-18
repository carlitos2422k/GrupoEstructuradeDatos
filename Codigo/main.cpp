/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre Sistema de Gestión de Parqueo        *
 * Autor:                          Danna Andrade, Carlos Perez, Samaniego Jefferson    *
 * Fecha de creacion:              02/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "Lista_Circular_Doble.cpp" 
#include "Nodo.cpp"
#include "Validaciones.cpp"
#include "Parqueadero.cpp"
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <vector>
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
        "1. Insertar vehiculo",
        "2. Eliminar vehiculo",
        "3. Mostrar vehiculos por hora",
        "4. Manual de usuario",
        "5. Cifrar",
        "6. Salir"
    };
    string opciones_manual[] = {
        "1. Insertar Vehiculo",
        "2. Eliminar Vehiculo",
        "3. Mostrar Vehiculos",
        "4. Salir del Manual"
                };
    string opciones_cifrar[]={
        "1. Cifrar todos los datos",
        "2. Cifrar campo especifico",
        "3. Regresar"
    };
    string opciones_cifrar_campo[]={
        "1. Cifrar Nombre",
        "2. Cifrar Apellido",
        "3. Cifrar Cedula",
        "4. Cifrar Placa",
        "5. Cifrar Marca",
        "6. Cifrar Color",
        "7. Cifrar Fecha",
        "8. Regresar"
    };
    string opciones_mostrar[] = {
        "1. Mostrar todos los vehiculos",
        "2. Buscar vehiculos por rango de hora",
        "3. Regresar"
        };
    int seleccion = 0;
    int numOpciones = 6;
    const int numOpcionesCifrar=3;
    const int numOpcionesCifrarCampo=8;
    bool ejecutando = true;
    const int num_opciones_manual = 4;
    int opcion_manual = 0;
    int opcion_cifrado = 0;
    int opcion_campocifrado = 0;
    int opcion_mostrar=0;
    string nombre, apellido, placa, marca, color, cedulaStr, fechaHoraActual;
    long cedula;
    int idEspacio = 0;
    int espacio;
    std::string horaInicio="";
    std::string horaFin="";

    while (ejecutando) {
        espacio=0;
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
                        cout << "ID de espacio invalido. Ingrese nuevamente\n";
                    } else if (!Utils::isSpaceOccupied(lista_vehiculos, idEspacio)) {
                        cout << "ID de espacio ocupado. Ingrese nuevamente\n";
                    }
                } while (idEspacio < 0 || idEspacio >= filas * columnas || !Utils::isSpaceOccupied(lista_vehiculos, idEspacio));

                cout << "Datos del vehiculo:\n";
                nombre = ingresar_string.ingresar("Ingrese el nombre del propietario: ", "string");
                cout << endl;
                apellido = ingresar_string.ingresar("Ingrese el apellido del propietario: ", "string");
                cout << endl;
                while (!Utils::validateId(cedulaStr) || !Utils::isUniqueField(lista_vehiculos, cedulaStr, "cedula", -1)) {
                    cedula = ingresar_cedula.ingresar("Ingrese la cedula: ", "long");
                    cout << endl;
                    cedulaStr = std::to_string(cedula);

                    if (!Utils::validateId(cedulaStr)) {
                        cout << "Cedula invalida. Ingrese nuevamente." << endl;
                    }
                    if (!Utils::isUniqueField(lista_vehiculos, cedulaStr, "cedula", -1)) {
                        cout << "Cedula ya ingresada. Ingrese nuevamente." << endl;
                    }
                }
                cout << endl;
                while (!Utils::validarPlacaEcuador(placa) || !Utils::isUniqueField(lista_vehiculos, placa, "placa", -1)) {
                    cout << "Ingrese la placa del vehiculo: ";
                    cout << endl;
                    cin >> placa;
                    if (!Utils::validarPlacaEcuador(placa)) {
                        cout << "Placa invalida. Ingrese nuevamente." << endl;
                    }
                    if (!Utils::isUniqueField(lista_vehiculos, placa, "placa", -1)) {
                        cout << "Placa ya ingresada. Ingrese nuevamente." << endl;
                    }
                }
                cout << endl;
                marca = ingresar_string.ingresar("Ingrese la marca del vehiculo: ", "string");
                cout << endl;
                color = ingresar_string.ingresar("Ingrese el color del vehiculo: ", "string");
                cout << endl;
                fechaHoraActual = Utils::getCurrentDateTime();
                cout << endl;
                lista_vehiculos->ActualizarEspacio(nombre, apellido, cedulaStr, idEspacio, placa, marca, color, fechaHoraActual);
                parqueadero->ocuparEspacio(idEspacio);
                cout << "Vehiculo ingresado correctamente en el espacio " << idEspacio << endl;
                system("pause");
                break;

            case 1: // Eliminar vehículo
            placa="";
            cout << "Ingrese la placa del vehiculo a eliminar: ";
            cin >> placa;
            lista_vehiculos->EliminarPorPlaca(placa);
            parqueadero->liberarEspacio(idEspacio);
            system("pause");
                break;
    case 2: // Mostrar vehículos
    while (true) {
        system("cls");
        cout << "\033[34m**** Mostrar Vehiculos ****\033[0m" << endl;
        // Mostrar opciones
        for (int i = 0; i < 3; ++i) {
            if (i == opcion_mostrar) {
                cout << "-> " << opciones_mostrar[i] << endl;
            } else {
                cout << "   " << opciones_mostrar[i] << endl;
            }
        }

        char tecla_mostrar = _getch(); // Capturar entrada del usuario
        if (tecla_mostrar == 72) { // Flecha hacia arriba
            opcion_mostrar = (opcion_mostrar - 1 + 3) % 3;
        } else if (tecla_mostrar == 80) { // Flecha hacia abajo
            opcion_mostrar = (opcion_mostrar + 1) % 3;
        } else if (tecla_mostrar == 13) { // Enter
            switch (opcion_mostrar) {
                case 0: // Mostrar todos los vehículos
                    lista_vehiculos->Mostrar();
                    system("pause");
                    break;

                case 1: // Buscar por rango de hora
                    system("cls");
                    cout << "Ingrese la hora de inicio (HH:MM:SS): ";
                    cin >> horaInicio;
                    cout << "Ingrese la hora de fin (HH:MM:SS): ";
                    cin >> horaFin;
                    lista_vehiculos->BuscarPorRangoDeHora(horaInicio, horaFin);
                    system("pause");
                    break;

                case 2: // Regresar
                break;
            }
            if (opcion_mostrar == 2) break;
        }
    }
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
            case 4: // Cifrar
                while (true) {
                    system("cls");
                    cout << "\033[34m**** Cifrado ****\033[0m" << endl;

                    for (int i = 0; i < numOpcionesCifrar; ++i) {
                        if (i == opcion_cifrado)
                            cout << "-> " << opciones_cifrar[i] << endl;
                        else
                            cout << "   " << opciones_cifrar[i] << endl;
                    }
                    parqueadero->mostrarParqueadero();
                    char tecla_manualcifrado = _getch();
                    if (tecla_manualcifrado == 72)
                        opcion_cifrado = (opcion_cifrado - 1 + numOpcionesCifrar) % numOpcionesCifrar;
                    else if (tecla_manualcifrado == 80)
                        opcion_cifrado = (opcion_cifrado + 1) % numOpcionesCifrar;
                    else if (tecla_manualcifrado == 13) {
                        switch (opcion_cifrado) {
                        case 0:
                                espacio = ingresar_entero.ingresar("Ingrese el espacio de parqueo a cifrar: ","entero");
                                cout << endl;
                                if (espacio < 0 || espacio >= filas * columnas) {
                                    cout << "ID de espacio invalido. Ingrese nuevamente\n";
                                    cout << endl;
                                    system("pause");
                                    break;
                                }
                                else if (Utils::isSpaceOccupied(lista_vehiculos,espacio)){
                                    cout << "El espacio de parqueo esta vacio intente nuevamente";
                                    cout << endl;
                                    system("pause");
                                    break;
                                }
                            
                            lista_vehiculos->cifrarCampoEnTodos(espacio,5);
                            system("pause");
                            break;
                        case 1:
                                espacio = ingresar_entero.ingresar("Ingrese el espacio de parqueo a cifrar: ","entero");
                                cout << endl;
                                if (espacio < 0 || espacio >= filas * columnas) {
                                    cout << "ID de espacio invalido. Ingrese nuevamente\n";
                                    cout << endl;
                                    system("pause");
                                    break;
                                }
                                else if (Utils::isSpaceOccupied(lista_vehiculos,espacio)){
                                    cout << "El espacio de parqueo esta vacio intente nuevamente";
                                    cout << endl;
                                    system("pause");
                                    break;
                                }
                        while (true) {
                        system("cls");
                        cout << "\033[34m**** Cifrar campo ****\033[0m" << endl;

                        for (int i = 0; i < numOpcionesCifrarCampo; ++i) {
                            if (i == opcion_campocifrado)
                                cout << "-> " << opciones_cifrar_campo[i] << endl;
                            else
                                cout << "   " << opciones_cifrar_campo[i] << endl;
                        }
                        parqueadero->mostrarParqueadero();
                        char tecla_manual = _getch();
                        if (tecla_manual == 72)
                            opcion_campocifrado = (opcion_campocifrado - 1 + numOpcionesCifrarCampo) % numOpcionesCifrarCampo;
                        else if (tecla_manual == 80)
                            opcion_campocifrado = (opcion_campocifrado + 1) % numOpcionesCifrarCampo;
                        else if (tecla_manual == 13) {
                        switch (opcion_campocifrado) {
                                    case 0:
                                        lista_vehiculos->cifrarCampoDeNodo(espacio,"nombre",5);
                                        system("pause");
                                        break;
                                    case 1:
                                        lista_vehiculos->cifrarCampoDeNodo(espacio,"apellido",5);
                                        system("pause");
                                        break;
                                    case 2:
                                        lista_vehiculos->cifrarCampoDeNodo(espacio,"cedula",5);
                                        system("pause");
                                        break;
                                    case 3:
                                        lista_vehiculos->cifrarCampoDeNodo(espacio,"placa",5);
                                        system("pause");
                                        break;
                                    case 4:
                                        lista_vehiculos->cifrarCampoDeNodo(espacio,"marca",5);
                                        system("pause");
                                        break;
                                    case 5:
                                        lista_vehiculos->cifrarCampoDeNodo(espacio,"color",5);
                                        system("pause");
                                        break;
                                    case 6:
                                        lista_vehiculos->cifrarCampoDeNodo(espacio,"fecha",5);
                                        system("pause");
                                        break;
                                    case 7:
                                        break;
                                    }
                                    if (opcion_campocifrado == 7) break;
                                }
                            }
                            break;
                            system("pause");
                            break;
                        case 2:
                            break;
                        }
                        if (opcion_cifrado == 2) break;
                    }
                }
                break;
            case 5: // Salir
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
