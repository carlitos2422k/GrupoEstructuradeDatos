#pragma once
#include <string>

template<typename T>
class Nodo {
private:
    T nombre;
    T apellido;
    T cedula;
    T celular;
    int idEspacio;
    T placa;
    T marca;
    T color;
    std::string fechaHora; // Campo para la fecha y hora

    Nodo* siguiente;
    Nodo* anterior;

public:
    Nodo(T, T, T, T, int, T, T, T,std::string);

    void setNombre(T);
    T getNombre();
    void setApellido(T);
    T getApellido();
    void setCedula(T);
    T getCedula();
    void setCelular(T);
    T getCelular();
    void setIdEspacio(int);
    int getIdEspacio();
    void setPlaca(T);
    T getPlaca();
    void setMarca(T);
    T getMarca();
    void setColor(T);
    T getColor();

    // Métodos para fecha y hora
    void setFechaHora(const std::string&);
    std::string getFechaHora() const;

    void setSiguiente(Nodo*);
    Nodo* getSiguiente();
    void setAnterior(Nodo*);
    Nodo* getAnterior();

    template<typename U> friend class Lista_Circular_Doble;
};
