/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre Sistema de Gestión de Parqueo        *
 * Autor:                          Danna Andrade, Carlos Perez, Samaniego Jefferson    *
 * Fecha de creacion:              02/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#ifndef UTILS_H
#define UTILS_H
#include "Lista_Circular_Doble.h"
#include <string>
#include <iostream>
#include <chrono>
#include <vector>

class Utils {
public:
    static bool validateId(const std::string& idInput);
    static bool validateEmail(const std::string& emailInput);
    static void modifyCharInString(std::string& str, char target, int offset);
    static bool validarPlacaEcuador(const std::string& placa);
    static void mostrarMenu(const std::string opciones[], int numOpciones, int seleccion);
    static void mostrarMenuManual(const std::string opciones[], int numOpciones, int seleccion);
    static void mostrarMenuCifrar(const std::string opciones[], int numOpciones, int seleccion);
    static void mostrarMenuCampoCifrar(const std::string opciones[], int numOpciones, int seleccion);
    static bool isUniqueField(Lista_Circular_Doble<std::string>* lista, const std::string& campo, const std::string& tipo, int id);
    static bool isSpaceOccupied(Lista_Circular_Doble<std::string>* lista, int idEspacio);
    static std::string getCurrentDateTime();
    template <typename T>
    static std::vector<Nodo<T>*> FiltrarAutosPorHora(const Lista_Circular_Doble<T>& lista, const std::string& horaInicio, const std::string& horaFin);
    
    static bool EsFechaDeHoy(const std::string& fechaHora);

};

#endif // UTILS_H
