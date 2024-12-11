#include "Lista_Circular_Doble.h"
#include <algorithm>
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
        std::cout << "\033[31mNombre: \033[0m" << aux->getNombre()
                  << "\033[31m, Apellido: \033[0m" << aux->getApellido()
                  << "\033[31m, ID Espacio: \033[0m" << aux->getIdEspacio()
                  << "\033[31m, Placa: \033[0m" << aux->getPlaca()
                  << "\033[31m, Marca: \033[0m" << aux->getMarca()
                  << "\033[31m, Hora de parqueo: \033[0m" << aux->getFechaHora() << std::endl;
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

template <typename T>
std::string Lista_Circular_Doble<T>::cifrarString(const std::string& texto, int desplazamiento) {
    std::string resultado = texto;

    for (char& c : resultado) {
        c += desplazamiento; // Desplazar el caracter por el valor de clave
    }

    return resultado;
}

template <typename T>
void Lista_Circular_Doble<T>::cifrarCampoDeNodo(int idNodo, const std::string& campo, int desplazamiento) {
    if (!cabeza) {
        std::cout << "La lista está vacía.\n";
        return;
    }

    Nodo<T>* aux = cabeza;
    do {
        if (aux->getIdEspacio() == idNodo) {
            if (campo == "nombre") {
                std::string nombre= aux->getNombre();
                aux->setNombre(cifrarString(nombre, desplazamiento));
            } else if (campo == "apellido") {
                std::string apellido = aux->getApellido();
                aux->setApellido(cifrarString(apellido, desplazamiento));
            } else if (campo == "cedula") {
                std::string cedula=aux->getCedula();
                aux->setCedula(cifrarString(cedula, desplazamiento));
            } else if (campo == "placa") {
                std::string placa = aux->getPlaca();
                aux->setPlaca(cifrarString(placa, desplazamiento));
            } else if (campo == "marca") {
                std::string marca=aux->getMarca();
                aux->setMarca(cifrarString(marca, desplazamiento));
            } else if (campo == "color") {
                std::string color=aux->getColor();
                aux->setColor(cifrarString(color, desplazamiento));
            } else if (campo == "fecha") {
                std::string fecha=aux->getFechaHora();
                aux->setFechaHora(cifrarString(fecha, desplazamiento));
            } else {
                std::cout << "Campo desconocido: " << campo << ".\n";
                return;
            }
            std::cout << "Campo " << campo << " cifrado en el nodo con ID " << idNodo << ".\n";
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);

    std::cout << "Nodo con ID " << idNodo << " no encontrado.\n";
}

// Cifrar un campo en todos los nodos
template <typename T>
void Lista_Circular_Doble<T>::cifrarCampoEnTodos(int idNodo, int desplazamiento) {
    if (!cabeza) {
        std::cout << "La lista está vacía.\n";
        return;
    }


    Nodo<T>* aux = cabeza;
    do {
        if (aux->getIdEspacio() == idNodo) {
            
                std::string nombre= aux->getNombre();
                aux->setNombre(cifrarString(nombre, desplazamiento));
                std::string apellido = aux->getApellido();
                aux->setApellido(cifrarString(apellido, desplazamiento));
                std::string cedula=aux->getCedula();
                aux->setCedula(cifrarString(cedula, desplazamiento));
                std::string placa = aux->getPlaca();
                aux->setPlaca(cifrarString(placa, desplazamiento));
                std::string marca=aux->getMarca();
                aux->setMarca(cifrarString(marca, desplazamiento));
                std::string color=aux->getColor();
                aux->setColor(cifrarString(color, desplazamiento));
                std::string fecha=aux->getFechaHora();
                aux->setFechaHora(cifrarString(fecha, desplazamiento));
            }
        aux = aux->getSiguiente();
        }
    while (aux != cabeza);
    std::cout << "Cifrado correctamente";
}
