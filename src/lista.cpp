#include "../include/lista.h"
#include "../include/termo.h"
#include <iostream>

template <typename T>
void Lista<T>::inserir(const T& elemento) {
    elementos.push_back(elemento);
}

template <typename T>
size_t Lista<T>::tamanho() const {
    return elementos.size();
}

template <typename T>
void Lista<T>::imprimir() const {
    for (const auto& elemento : elementos) {
        elemento.print(); // Assume que T tem um método print()
    }
}

template <typename T>
T& Lista<T>::operator[](size_t indice) {
    if (indice >= elementos.size()) {
        throw std::out_of_range("Indice fora do intervalo.");
    }
    return elementos[indice];
}

template <typename T>
const T& Lista<T>::operator[](size_t indice) const {
    if (indice >= elementos.size()) {
        throw std::out_of_range("Indice fora do intervalo.");
    }
    return elementos[indice];
}

template <typename T>
std::vector<T> Lista<T>::getElementos() const {
    return elementos;
}

template <typename T>
void ListaOrdenada<T>::ordenarPorPeso() {
    std::sort(this->elementos.begin(), this->elementos.end(), T::comparaPorPeso);
}

template <typename T>
void ListaOrdenada<T>::ordenarPorPrefixo(const std::string& prefixo) {
    std::sort(this->elementos.begin(), this->elementos.end(), 
              [&prefixo](const T& a, const T& b) {
                  return T::comparaPorPrefixo(a, b, prefixo);
              });
}

// Explicit template instantiation
template class Lista<Termo>;
template class ListaOrdenada<Termo>;