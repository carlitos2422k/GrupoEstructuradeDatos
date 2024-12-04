#include "Lista_Circular_Doble.h"

template<typename T>
Lista_Circular_Doble<T>::Lista_Circular_Doble() : cabeza(nullptr) {}

template<typename T>
void Lista_Circular_Doble<T>::InsertarPorCabeza(T nombre, T apellido, T cedula, T celular, int idEspacio, T placa, T marca, T color) {
    Nodo<T>* nuevo = new Nodo<T>(nombre, apellido, cedula, celular, idEspacio, placa, marca, color);
    if (!cabeza) {
        cabeza = nuevo;
        cabeza->setSiguiente(cabeza);
        cabeza->setAnterior(cabeza);
    } else {
        Nodo<T>* ultimo = cabeza->getAnterior();
        nuevo->setSiguiente(cabeza);
        nuevo->setAnterior(ultimo);
        ultimo->setSiguiente(nuevo);
        cabeza->setAnterior(nuevo);
        cabeza = nuevo;
    }
}

template<typename T>
void Lista_Circular_Doble<T>::InsertarPorCola(T nombre, T apellido, T cedula, T celular, int idEspacio, T placa, T marca, T color) {
    Nodo<T>* nuevo = new Nodo<T>(nombre, apellido, cedula, celular, idEspacio, placa, marca, color);
    if (!cabeza) {
        cabeza = nuevo;
        cabeza->setSiguiente(cabeza);
        cabeza->setAnterior(cabeza);
    } else {
        Nodo<T>* ultimo = cabeza->getAnterior();
        nuevo->setSiguiente(cabeza);
        nuevo->setAnterior(ultimo);
        ultimo->setSiguiente(nuevo);
        cabeza->setAnterior(nuevo);
    }
}

template<typename T>
void Lista_Circular_Doble<T>::InsertarEnPosicion(T nombre, T apellido, T cedula, T celular, int idEspacio, T placa, T marca, T color, int posicion) {
    Nodo<T>* nuevo = new Nodo<T>(nombre, apellido, cedula, celular, idEspacio, placa, marca, color);
    if (!cabeza) {
        InsertarPorCabeza(nombre, apellido, cedula, celular, idEspacio, placa, marca, color);
        return;
    }

    Nodo<T>* aux = cabeza;
    int contador = 0;

    do {
        if (contador == posicion) {
            Nodo<T>* anterior = aux->getAnterior();
            nuevo->setSiguiente(aux);
            nuevo->setAnterior(anterior);
            anterior->setSiguiente(nuevo);
            aux->setAnterior(nuevo);

            if (posicion == 0) {
                cabeza = nuevo;
            }
            std::cout << "Nodo insertado en la posición " << posicion << "." << std::endl;
            return;
        }
        aux = aux->getSiguiente();
        contador++;
    } while (aux != cabeza);

    std::cout << "Error: Posición fuera de los límites." << std::endl;
    delete nuevo;
}

template<typename T>
void Lista_Circular_Doble<T>::Mostrar() {
    if (!cabeza) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo<T>* aux = cabeza;
    do {
        std::cout << "Nombre: " << aux->getNombre()
                  << ", Apellido: " << aux->getApellido()
                  << ", ID Espacio: " << aux->getIdEspacio()
                  << ", Placa: " << aux->getPlaca()
                  << ", Marca: " << aux->getMarca() << std::endl;
        aux = aux->getSiguiente();
    } while (aux != cabeza);
}

template<typename T>
void Lista_Circular_Doble<T>::BuscarPorPlaca(T placa) {
    if (!cabeza) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo<T>* aux = cabeza;
    do {
        if (aux->getPlaca() == placa) {
            std::cout << "Registro encontrado: " << aux->getPlaca() << std::endl;
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);

    std::cout << "Placa no encontrada." << std::endl;
}

template<typename T>
void Lista_Circular_Doble<T>::EliminarPorPlaca(T placa) {
    if (!cabeza) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo<T>* aux = cabeza;
    do {
        if (aux->getPlaca() == placa) {
            Nodo<T>* anterior = aux->getAnterior();
            Nodo<T>* siguiente = aux->getSiguiente();

            anterior->setSiguiente(siguiente);
            siguiente->setAnterior(anterior);

            if (aux == cabeza) {
                cabeza = (aux == siguiente) ? nullptr : siguiente;
            }
            delete aux;
            std::cout << "Nodo eliminado con placa: " << placa << "." << std::endl;
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);

    std::cout << "No se encontró un nodo con la placa " << placa << "." << std::endl;
}
