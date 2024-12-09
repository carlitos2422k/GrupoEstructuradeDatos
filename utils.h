/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista circular cifrado               *
 * Autor:                          Carlos Perez                                        *
 * Fecha de creacion:              04/12/2024                                          *
 * Fecha de modificacion:          04/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#ifndef UTILS_H
#define UTILS_H
#include "Lista_Circular_Doble.h"
#include <string>
#include <iostream>
#include <chrono>


class Utils {
public:
    static bool validateId(const std::string& idInput);
    static bool validateEmail(const std::string& emailInput);
    static void modifyCharInString(std::string& str, char target, int offset);
    static bool validarPlacaEcuador(const std::string& placa);
    static void mostrarMenu(const std::string opciones[], int numOpciones, int seleccion);
    static std::string getCurrentDateTime();
    static bool isUniqueField(Lista_Circular_Doble<std::string>* lista, const std::string& campo, const std::string& tipo, int id);
    static bool isSpaceOccupied(Lista_Circular_Doble<std::string>* lista, int idEspacio);
};

#endif // UTILS_H
