/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre Sistema de Gestión de Parqueo        *
 * Autor:                          Danna Andrade, Carlos Perez, Samaniego Jefferson    *
 * Fecha de creacion:              02/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#ifndef LISTA_CIRCULAR_DOBLE_H
#define LISTA_CIRCULAR_DOBLE_H

#include "Nodo.h"
#include <iostream>

template<typename T>
class Lista_Circular_Doble {
private:
    Nodo<T>* cabeza;

public:
    Lista_Circular_Doble();
    void InsertarPorCabeza(T nombre, T apellido, T cedula, int idEspacio, T placa, T marca, T color,const std::string& fechaHora);
    void InsertarPorCola(T nombre, T apellido, T cedula, int idEspacio, T placa, T marca, T color,const std::string& fechaHora);
    void Mostrar();
    void BuscarPorPlaca(T placa);
    void EliminarPorPlaca(T placa);
    void InicializarLista(int totalEspacios);
    void ActualizarEspacio(T nombre, T apellido, T cedula, int idEspacio, T placa, T marca, T color,const std::string& fechaHora); 
    void cifrarCampoDeNodo(int idNodo, const std::string& campo, int desplazamiento);
    void cifrarCampoEnTodos(int idNodo, int desplazamiento);
    std::string cifrarString(const std::string& texto, int desplazamiento);
    Nodo<T>* getCabeza(); 
    void BuscarPorRangoDeHora(const std::string& horaInicio, const std::string& horaFin);
    friend class Utils;
};

#endif // LISTA_CIRCULAR_DOBLE_H
