#pragma once
#include "Nodo.h"

template<typename T>
class Lista_Circular_Doble {
private:
    Nodo<T>* cabeza;

public:
    Lista_Circular_Doble();
    void InsertarPorCabeza(T,T,T,T,int, T,T,T);
    void InsertarPorCola(T,T,T,T,int, T,T,T);
    void Mostrar();
    void BuscarPorPlaca(T);
    void EliminarPorPlaca(T);
    void InsertarEnPosicion(T,T,T,T,int, T,T,T);
};
