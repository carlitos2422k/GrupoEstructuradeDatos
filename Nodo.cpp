#include "Nodo.h"

template<typename T>
Nodo<T>::Nodo(T _nombre, T _apellido, T _cedula, T _celular, int _idEspacio, T _placa, T _marca, T _color) {
    nombre = _nombre;
    apellido = _apellido;
    cedula = _cedula;
    celular = _celular;
    idEspacio = _idEspacio;
    placa = _placa;
    marca = _marca;
    color = _color;
    siguiente = nullptr;
    anterior = nullptr;
}

template<typename T>
void Nodo<T>::setNombre(T _nombre) {
    nombre = _nombre;
}

template<typename T>
T Nodo<T>::getNombre() {
    return nombre;
}

template<typename T>
void Nodo<T>::setApellido(T _apellido) {
    apellido = _apellido;
}

template<typename T>
T Nodo<T>::getApellido() {
    return apellido;
}

template<typename T>
void Nodo<T>::setCedula(T _cedula) {
    cedula = _cedula;
}

template<typename T>
T Nodo<T>::getCedula() {
    return cedula;
}

template<typename T>
void Nodo<T>::setCelular(T _celular) {
    celular = _celular;
}

template<typename T>
T Nodo<T>::getCelular() {
    return celular;
}

template<typename T>
void Nodo<T>::setIdEspacio(int _idEspacio) {
    idEspacio = _idEspacio;
}

template<typename T>
int Nodo<T>::getIdEspacio() {
    return idEspacio;
}

template<typename T>
void Nodo<T>::setPlaca(T _placa) {
    placa = _placa;
}

template<typename T>
T Nodo<T>::getPlaca() {
    return placa;
}

template<typename T>
void Nodo<T>::setMarca(T _marca) {
    marca = _marca;
}

template<typename T>
T Nodo<T>::getMarca() {
    return marca;
}

template<typename T>
void Nodo<T>::setColor(T _color) {
    color = _color;
}

template<typename T>
T Nodo<T>::getColor() {
    return color;
}

template<typename T>
void Nodo<T>::setSiguiente(Nodo* _siguiente) {
    siguiente = _siguiente;
}

template<typename T>
Nodo<T>* Nodo<T>::getSiguiente() {
    return siguiente;
}

template<typename T>
void Nodo<T>::setAnterior(Nodo* _anterior) {
    anterior = _anterior;
}

template<typename T>
Nodo<T>* Nodo<T>::getAnterior() {
    return anterior;
}
