#include "Lista_Circular_Doble.cpp" // Asegúrate de que esta clase maneje los nodos de parqueo
#include "Nodo.cpp"
#include "Validaciones.cpp"
#include <iostream>
#include <string>
#include <conio.h> 
#include <cstdlib>

using namespace std;

int main()
{
    // Inicializar la lista circular
    Lista_Circular_Doble<string> *lista_vehiculos = new Lista_Circular_Doble<string>();
    string nombre, apellido, placa, marca, color, celular, cedulaStr;
    long cedula;
    int idEspacio = 0;

    // Inicializar validaciones
    Validaciones<std::string> ingresar_string;
    Validaciones<long> ingresar_entero;

    // Opciones del menú
    string opciones[] = {
        "\033[36mInsertar vehiculo\033[0m",
        "Buscar vehiculo por placa",
        "Eliminar vehiculo",
        "Mostrar vehiculos",
        "Salida de vehiculo",
        "Salir"};
    const int num_opciones = 6;
    int seleccion = 0;

    // Ciclo principal del menú
    while (true)
    {
        system("cls");
        cout << "\033[35m*********** Sistema de Parqueadero ***********\033[0m" << endl;

        // Mostrar las opciones del menú
        for (int i = 0; i < num_opciones; ++i)
        {
            if (i == seleccion)
                cout << "-> " << opciones[i] << endl;
            else
                cout << "   " << opciones[i] << endl;
        }

        // Capturar entrada del usuario
        char tecla = _getch();

        // Navegación del menú
        if (tecla == 72) // Flecha arriba
        {
            seleccion = (seleccion - 1 + num_opciones) % num_opciones;
        }
        else if (tecla == 80) // Flecha abajo
        {
            seleccion = (seleccion + 1) % num_opciones;
        }
        else if (tecla == 13) // Enter
        {
            switch (seleccion)
            {
            case 0: // Insertar vehículo
                nombre = ingresar_string.ingresar("Ingrese el nombre del propietario: ", "string");
                cout << endl;
                apellido = ingresar_string.ingresar("Ingrese el apellido del propietario: ", "string");
                cout << endl;
                cedula = ingresar_entero.ingresar("Ingrese la cédula del propietario: ", "long");
                cout << endl;
                celular = ingresar_string.ingresar("Ingrese el celular del propietario: ", "string");
                cout << endl;
                placa = ingresar_string.ingresar("Ingrese la placa del vehiculo: ", "string");
                cout << endl;
                marca = ingresar_string.ingresar("Ingrese la marca del vehiculo: ", "string");
                cout << endl;
                color = ingresar_string.ingresar("Ingrese el color del vehiculo: ", "string");
                cout << endl;
                
                cedulaStr = to_string(cedula);
                lista_vehiculos->InsertarPorCabeza(nombre, apellido, cedulaStr, celular,idEspacio, placa, marca, color);
                cout << endl
                     << "Vehiculo ingresado correctamente." << endl;
                idEspacio++;
                system("pause");
                break;

            case 1: // Buscar vehículo por placa
                placa = ingresar_string.ingresar("Ingrese la placa del vehiculo: ", "string");
                lista_vehiculos->BuscarPorPlaca(placa);
                system("pause");
                break;

            case 2: // Eliminar vehículo
                placa = ingresar_string.ingresar("Ingrese la placa del vehiculo a eliminar: ", "string");
                lista_vehiculos->EliminarPorPlaca(placa);
                system("pause");
                break;

            case 3: // Mostrar vehículos
                lista_vehiculos->Mostrar();
                cout << endl;
                system("pause");
                break;

            case 4: // Salida de vehículo
                placa = ingresar_string.ingresar("Ingrese la placa del vehiculo que sale: ", "string");
                lista_vehiculos->EliminarPorPlaca(placa);
                cout << "Vehiculo ha salido correctamente." << endl;
                system("pause");
                break;

            case 5: // Salir
                cout << "Saliendo del programa..." << endl;
                delete lista_vehiculos; // Liberar memoria de la lista
                return 0;
            }
        }
    }
}
