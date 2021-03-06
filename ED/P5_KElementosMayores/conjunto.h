#pragma once

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <algorithm> // std::binary_search
#include <fstream>

template <class T>
class set {
public:
    set(size_t tam = TAM_INICIAL); // constructor
    set(set<T> const& other); // constructor por copia
    set<T>& operator=(set<T> const& other); // operador de asignación
    ~set(); // destructor
    void insert(T e);
    bool contains(T e) const;
    void erase(T e);
    bool empty() const;
    size_t size() const;
    T min() const;
    void erase_min();
    T* begin();
    T* end();

private:
    const static size_t TAM_INICIAL = 8;
    size_t contador;
    size_t capacidad;
    T* datos;
    void amplia();
    void libera();
    void copia(set<T> const& other);

    class comp {
    public:
        bool operator()(T const& e1, T const& e2) {
            return e1 > e2;
        }
    };
};

template <class T>
set<T>::set(size_t tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() {
    libera();
}

template <class T>
void set<T>::libera() {
    delete[] datos;
}

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
    copia(other);
}

/** Operador de asignación */
template <class T>
set<T>& set<T>::operator=(set<T> const& other) {
    if (this != &other) {
        libera();
        copia(other);
    }
    return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) {
    capacidad = other.capacidad;
    contador = other.contador;
    datos = new T[capacidad];
    for (size_t i = 0; i < contador; ++i)
        datos[i] = other.datos[i];
}

template <class T>
void set<T>::insert(T e) {
    if (!contains(e)) {
        if (contador == capacidad)
            amplia();
        datos[contador] = e;
        ++contador;
        for (int i = contador - 1; i > 0 && datos[i] > datos[i - 1]; --i) {
            std::swap(datos[i], datos[i - 1]);
        }
    }
}

template <class T>
bool set<T>::contains(T e) const {
    return std::binary_search(datos, datos + contador, e, comp());
}

template <class T>
void set<T>::amplia() {
    T* nuevos = new T[2 * capacidad];
    for (size_t i = 0; i < capacidad; ++i)
        nuevos[i] = std::move(datos[i]);
    delete[] datos;
    datos = nuevos;
    capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {
    size_t i = 0;
    while (i < contador && datos[i] != e)
        ++i;
    if (i < contador) {
        datos[i] = datos[contador - 1];
        --contador;
    }
    else
        throw std::domain_error("El elemento no esta");
}


template <class T>
bool set<T>::empty() const {
    return contador == 0;
}

template <class T>
size_t set<T>::size() const {
    return contador;
}

template <class T>
T set<T>::min() const {
    if (empty()) throw std::domain_error("El vector esta vacio");
    return datos[contador - 1];
}

template <class T>
void set<T>::erase_min() {
    if (empty()) throw std::domain_error("El vector esta vacio");
    --contador;
}

template <class T>
T* set<T>::begin() {
    return datos;
}

template <class T>
T* set<T>::end() {
    return datos + contador;
}