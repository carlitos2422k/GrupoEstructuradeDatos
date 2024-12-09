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
    Nodo<T>* getCabeza(); 
    friend class Utils;
};

#endif // LISTA_CIRCULAR_DOBLE_H
