#include "Lista_Circular_Doble.h"
#include <iostream>
using namespace std;

template<typename T>
Lista_Circular_Doble<T>::Lista_Circular_Doble() {
    cabeza = nullptr;
}

template<typename T>
void Lista_Circular_Doble<T>::InsertarPorCabeza(T nombre, T apellido, int idEspacio, T placa, T marca) {
    Nodo<T>* nuevo = new Nodo<T>(nombre, apellido, idEspacio, placa, marca);
    if (cabeza == nullptr) {
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
void Lista_Circular_Doble<T>::InsertarPorCola(T nombre, T apellido, int idEspacio, T placa, T marca) {
    Nodo<T>* nuevo = new Nodo<T>(nombre, apellido, idEspacio, placa, marca);
    if (cabeza == nullptr) {
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
void Lista_Circular_Doble<T>::Mostrar() {
    if (cabeza == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Nodo<T>* aux = cabeza;
    do {
        cout << "Nombre: " << aux->getNombre()
             << ", Apellido: " << aux->getApellido()
             << ", ID Espacio: " << aux->getIdEspacio()
             << ", Placa: " << aux->getPlaca()
             << ", Marca: " << aux->getMarca() << endl;
        aux = aux->getSiguiente();
    } while (aux != cabeza);
}

template<typename T>
void Lista_Circular_Doble<T>::BuscarPorPlaca(T placa) {
    if (cabeza == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Nodo<T>* aux = cabeza;
    do {
        if (aux->getPlaca() == placa) {
            cout << "Registro encontrado: " << endl
                 << "Nombre: " << aux->getNombre()
                 << ", Apellido: " << aux->getApellido()
                 << ", ID Espacio: " << aux->getIdEspacio()
                 << ", Placa: " << aux->getPlaca()
                 << ", Marca: " << aux->getMarca() << endl;
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);
    cout << "Placa " << placa << " no encontrada." << endl;
}

template<typename T>
void Lista_Circular_Doble<T>::EliminarPorPlaca(T placa) {
    if (cabeza == nullptr) {
        cout << "La lista está vacía." << endl;
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
            cout << "Nodo con placa " << placa << " eliminado correctamente." << endl;
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);
    cout << "Placa " << placa << " no encontrada." << endl;
}
template<typename T>
void Lista_Circular_Doble<T>::InsertarEnPosicion(T nombre, T apellido, int idEspacio, T placa, T marca, int posicion) {
    if (cabeza == nullptr) {
        cout << "La lista está vacía. Insertando en la posición 0." << endl;
        InsertarPorCabeza(nombre, apellido, idEspacio, placa, marca);
        return;
    }

    Nodo<T>* nuevo = new Nodo<T>(nombre, apellido, idEspacio, placa, marca);
    Nodo<T>* aux = cabeza;

    // Verificar si ya existe un nodo con el mismo idEspacio
    do {
        if (aux->getIdEspacio() == posicion) {
            cout << "Error: El espacio con ID " << posicion << " ya está ocupado." << endl;
            delete nuevo;
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);

    aux = cabeza;
    int contador = 0;

    // Encontrar la posición deseada
    do {
        if (contador == posicion) {
            Nodo<T>* anterior = aux->getAnterior();
            anterior->setSiguiente(nuevo);
            nuevo->setAnterior(anterior);
            nuevo->setSiguiente(aux);
            aux->setAnterior(nuevo);

            // Si se inserta en la posición 0, se actualiza la cabeza
            if (posicion == 0) {
                cabeza = nuevo;
            }
            cout << "Nodo insertado en la posición " << posicion << "." << endl;
            return;
        }
        aux = aux->getSiguiente();
        contador++;
    } while (aux != cabeza);

    cout << "Error: La posición " << posicion << " es inválida o está fuera de los límites de la lista." << endl;
    delete nuevo;
}
