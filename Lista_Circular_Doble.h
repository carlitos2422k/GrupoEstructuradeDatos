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
    void InsertarPorCabeza(T nombre, T apellido, T cedula, T celular, int idEspacio, T placa, T marca, T color);
    void InsertarPorCola(T nombre, T apellido, T cedula, T celular, int idEspacio, T placa, T marca, T color);
    void InsertarEnPosicion(T nombre, T apellido, T cedula, T celular, int idEspacio, T placa, T marca, T color, int posicion);
    void Mostrar();
    void BuscarPorPlaca(T placa);
    void EliminarPorPlaca(T placa);
};

#endif // LISTA_CIRCULAR_DOBLE_H
