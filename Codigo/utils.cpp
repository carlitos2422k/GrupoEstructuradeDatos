/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre Sistema de Gestión de Parqueo        *
 * Autor:                          Danna Andrade, Carlos Perez, Samaniego Jefferson    *
 * Fecha de creacion:              02/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "utils.h"
#include <iostream>
#include <vector>
#include <regex>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
bool Utils::validateId(const std::string& idInput) {
    if (idInput.length() != 10) {
        return false;
    }

    long id = std::stol(idInput);  
    std::vector<long> digits(10);
    long remainder;
    long doubledDigit;
    long evenPositionSum = 0;
    long oddPositionSum = 0;
    long totalSum;
    long checkDigit;

    
    for (int i = 9; i >= 0; --i) {
        digits[i] = id % 10;
        id /= 10;
    }

    
    for (int i = 0; i < 9; i += 2) {
        doubledDigit = digits[i] * 2;
        if (doubledDigit > 9) {
            doubledDigit -= 9;
        }
        evenPositionSum += doubledDigit;
    }

    
    for (int i = 1; i < 9; i += 2) {
        oddPositionSum += digits[i];
    }

  
    totalSum = evenPositionSum + oddPositionSum;
    remainder = totalSum % 10;
    checkDigit = 10 - remainder;
    if (checkDigit == 10) {
        checkDigit = 0;
    }

    
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
   
    std::regex regexParticular("^[A-CEG-IK-UX-Z][A-Z]{2}-[0-9]{4}$");
    std::regex regexMoto("^[A-CEG-IK-UX-Z][A-Z]{2}-[0-9]{3}$");

   
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
bool Utils::isUniqueField(Lista_Circular_Doble<std::string>* lista, const std::string& campo, const std::string& tipo,int id) {
    Nodo<std::string>* actual = lista->cabeza;
    if (!actual) return true;

    do {
        if ((tipo == "cedula" && actual->getCedula() == campo) ||
            (tipo == "placa" && actual->getPlaca() == campo) ||
            (tipo== "id" && actual->getIdEspacio() == id)) {
            return false;
        }
        actual = actual->getSiguiente();
    } while (actual != lista->cabeza);

    return true;
}

bool Utils::isSpaceOccupied(Lista_Circular_Doble<std::string>* lista, int idEspacio) {
    Nodo<std::string>* actual = lista->getCabeza();
    if (!actual) return true; 

    do {
        if (actual->getIdEspacio() == idEspacio) {
            
            if (actual->getCedula() != "" &&
                actual->getPlaca() != "") {
                return false; 
            } else {
                return true; 
            }
        }
        actual = actual->getSiguiente();
    } while (actual != lista->getCabeza());

    return true; 
}


std::string Utils::getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::string timeStr = std::ctime(&now_time_t);
    timeStr.pop_back(); 
    return timeStr;
}

