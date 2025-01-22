#ifndef LISTA_H
#define LISTA_H

#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>

template <typename T>
class Lista {
protected:
    std::vector<T> elementos;

public:
    void inserir(const T& elemento);
    size_t tamanho() const;
    void imprimir() const;
    T& operator[](size_t indice);
    const T& operator[](size_t indice) const;
    std::vector<T> getElementos() const;
};

template <typename T>
class ListaOrdenada : public Lista<T> {
public:
    void ordenarPorPeso();
    void ordenarPorPrefixo(const std::string& prefixo);
};

#endif