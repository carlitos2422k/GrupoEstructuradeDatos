#pragma once
#include <iostream>
#include <string>

template<typename T>
class Nodo {
private:
    T nombre;        // Nombre del dueño
    T apellido;      // Apellido del dueño
    T cedula;        // Cédula del dueño
    T celular;       // Celular del dueño
    int idEspacio;   // ID del espacio de parqueo
    T placa;         // Placa del vehículo
    T marca;         // Marca del vehículo
    T color;         // Color del vehículo
    Nodo* siguiente; // Puntero al siguiente nodo
    Nodo* anterior;  // Puntero al nodo anterior

public:
    Nodo(T _nombre, T _apellido, T _cedula, T _celular, int _idEspacio, T _placa, T _marca, T _color);

    void setNombre(T _nombre);
    T getNombre();
    void setApellido(T _apellido);
    T getApellido();
    void setCedula(T _cedula);
    T getCedula();
    void setCelular(T _celular);
    T getCelular();
    void setIdEspacio(int _idEspacio);
    int getIdEspacio();
    void setPlaca(T _placa);
    T getPlaca();
    void setMarca(T _marca);
    T getMarca();
    void setColor(T _color);
    T getColor();

    void setSiguiente(Nodo* _siguiente);
    Nodo* getSiguiente();
    void setAnterior(Nodo* _anterior);
    Nodo* getAnterior();

    template<typename U> friend class Lista_Circular_Doble;
};
