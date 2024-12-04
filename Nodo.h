#pragma once
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Nodo {
private:
    T nombre;       // Nombre del dueño
    T apellido;     // Apellido del dueño
    int idEspacio;  // ID del espacio de parqueo
    T placa;        // Placa del vehículo
    T marca;        // Marca del vehículo
    Nodo* siguiente; // Puntero al siguiente nodo
    Nodo* anterior;  // Puntero al nodo anterior

public:
    Nodo(T, T, int, T, T);
    void setNombre(T);
    T getNombre();
    void setApellido(T);
    T getApellido();
    void setIdEspacio(int);
    int getIdEspacio();
    void setPlaca(T);
    T getPlaca();
    void setMarca(T);
    T getMarca();
    void setSiguiente(Nodo*);
    Nodo* getSiguiente();
    void setAnterior(Nodo*);
    Nodo* getAnterior();

    template<typename U> friend class Lista_Circular_Doble;
};
