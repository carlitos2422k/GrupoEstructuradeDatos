/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista circular cifrado               *
 * Autor:                          Carlos Perez                                        *
 * Fecha de creacion:              04/12/2024                                          *
 * Fecha de modificacion:          04/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "utils.h"
#include <vector>
#include <regex>
#include <chrono>
#include <ctime>

bool Utils::validateId(const std::string& idInput) {
    if (idInput.length() != 10) {
        return false;
    }

    long id = std::stol(idInput);  // Convierte el string a un número entero largo
    std::vector<long> digits(10);
    long remainder;
    long doubledDigit;
    long evenPositionSum = 0;
    long oddPositionSum = 0;
    long totalSum;
    long checkDigit;

    // Extraer los dígitos individuales del número
    for (int i = 9; i >= 0; --i) {
        digits[i] = id % 10;
        id /= 10;
    }

    // Procesar los dígitos en las posiciones pares
    for (int i = 0; i < 9; i += 2) {
        doubledDigit = digits[i] * 2;
        if (doubledDigit > 9) {
            doubledDigit -= 9;
        }
        evenPositionSum += doubledDigit;
    }

    // Procesar los dígitos en las posiciones impares
    for (int i = 1; i < 9; i += 2) {
        oddPositionSum += digits[i];
    }

    // Calcular la suma total y el dígito verificador
    totalSum = evenPositionSum + oddPositionSum;
    remainder = totalSum % 10;
    checkDigit = 10 - remainder;
    if (checkDigit == 10) {
        checkDigit = 0;
    }

    // Comparar el dígito verificador calculado con el último dígito
    return checkDigit == digits[9];
}

bool Utils::validateEmail(const std::string& emailInput) {
    // Usamos una expresión regular para validar el correo
    const std::regex pattern(
        R"((^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$))"
    );

    return std::regex_match(emailInput, pattern);
}
void Utils::modifyCharInString(std::string& str, char target, int offset) {
    for (char& c : str) {
        if (c == target) {
            c = static_cast<char>(c + offset); // Incrementa el ASCII solo si coincide
        }
    }
}
bool Utils::validarPlacaEcuador(const std::string& placa) {
    std::regex regexParticular("^[A-Z]{3}-[0-9]{4}$");
    std::regex regexMoto("^[A-Z]{3}-[0-9]{3}$");

    if (std::regex_match(placa, regexParticular) || std::regex_match(placa, regexMoto)) {
        return true;
    }
    return false;
}
void Utils::mostrarMenu(const std::string opciones[], int numOpciones, int seleccion) {
    system("cls");
    std::cout << "\033[35m*********** Sistema de Parqueadero ***********\033[0m\n";
    for (int i = 0; i < numOpciones; ++i) {
        if (i == seleccion) {
            std::cout << "\033[32m > " << opciones[i] << " <\033[0m\n"; // Resaltar la opción seleccionada
        } else {
            std::cout << "   " << opciones[i] << "\n";
        }
    }
}

// Definición de la función getCurrentDateTime
std::string Utils::getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::string timeStr = std::ctime(&now_time_t);
    timeStr.pop_back(); // Eliminar el salto de línea final de ctime
    return timeStr;
}

// Validar unicidad de un campo en la lista
bool Utils::isUniqueField(Lista_Circular_Doble<std::string>* lista, const std::string& campo, const std::string& tipo,int id) {
    Nodo<std::string>* actual = lista->cabeza;
    if (!actual) return true;

    do {
        if ((tipo == "cedula" && actual->getCedula() == campo) ||
            (tipo == "placa" && actual->getPlaca() == campo) ||
            (tipo == "celular" && actual->getCelular() == campo)||
            (tipo== "id" && actual->getIdEspacio() == id)) {
            return false;
        }
        actual = actual->getSiguiente();
    } while (actual != lista->cabeza);

    return true;
}
bool Utils::isSpaceOccupied(Lista_Circular_Doble<std::string>* lista, int idEspacio) {
    Nodo<std::string>* actual = lista->getCabeza();
    if (!actual) return true; // Si la lista está vacía, el espacio no está ocupado.

    do {
        if (actual->getIdEspacio() == idEspacio) {
            // Verificar si todos los campos están llenos.
            if (actual->getCedula() != "" &&
                actual->getPlaca() != "" &&
                actual->getCelular() != "") {
                return false; // El espacio está ocupado.
            } else {
                return true; // El espacio está disponible.
            }
        }
        actual = actual->getSiguiente();
    } while (actual != lista->getCabeza());

    return true; // No se encontró el idEspacio en la lista.
}