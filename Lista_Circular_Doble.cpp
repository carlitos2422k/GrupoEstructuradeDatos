#include "Lista_Circular_Doble.h"

template<typename T>
Lista_Circular_Doble<T>::Lista_Circular_Doble() : cabeza(nullptr) {}

template<typename T>
void Lista_Circular_Doble<T>::InsertarPorCabeza(T nombre, T apellido, T cedula, int idEspacio, T placa, T marca, T color, const std::string& fechaHora) {
    Nodo<T>* nuevo = new Nodo<T>(nombre, apellido, cedula, idEspacio, placa, marca, color,fechaHora);
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
void Lista_Circular_Doble<T>::InsertarPorCola(T nombre, T apellido, T cedula, int idEspacio, T placa, T marca, T color, const std::string& fechaHora) {
    Nodo<T>* nuevo = new Nodo<T>(nombre, apellido, cedula, idEspacio, placa, marca, color,fechaHora);
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
                  << ", Marca: " << aux->getMarca()
                  << ", Hora de parqueo: " << aux->getFechaHora() << std::endl;
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
            // Vaciar los datos del nodo (excepto el ID de espacio)
            aux->setNombre("");
            aux->setApellido("");
            aux->setCedula("");
            aux->setPlaca("");
            aux->setMarca("");
            aux->setColor("");
            aux->setFechaHora("");

            std::cout << "Datos del vehiculo con placa " << placa << " han sido vaciados." << std::endl;
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);

    std::cout << "No se encontró un nodo con la placa " << placa << "." << std::endl;
}

template<typename T>
void Lista_Circular_Doble<T>::InicializarLista(int totalEspacios) {
    for (int i = 0; i < totalEspacios; i++) {
        this->InsertarPorCola("", "", "", i, "", "", "","");
    }
    std::cout << "Lista inicializada con " << totalEspacios << " espacios vacíos.\n";
}

template<typename T>
void Lista_Circular_Doble<T>::ActualizarEspacio(T nombre, T apellido, T cedula, int idEspacio, T placa, T marca, T color, const std::string& fechaHora) {
    if (!cabeza) {
        std::cout << "La lista está vacía.\n";
        return;
    }

    Nodo<T>* aux = cabeza;
    do {
        if (aux->getIdEspacio() == idEspacio) {
            aux->setNombre(nombre);
            aux->setApellido(apellido);
            aux->setCedula(cedula);
            aux->setPlaca(placa);
            aux->setMarca(marca);
            aux->setColor(color);
            aux->setFechaHora(fechaHora);
            std::cout << "Espacio actualizado exitosamente.\n";
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);

    std::cout << "Error: Espacio no encontrado.\n";
}
template<typename T>
Nodo<T>* Lista_Circular_Doble<T>::getCabeza() {
    return cabeza;
}
