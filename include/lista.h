#ifndef LISTA_H
#define LISTA_H

#include <vector>

template <class T> 
    class lista{
        protected:
            std::vector<T> elementos;
        public:
            void inserir(const T& elemento);
            size_t tamanho() const;
            void imprimir() const;
};

template <class T>
class listaOrdenada : public lista<T>{
    public:
        void ordenar();
        void ordenar(bool (*comparador)(const T&, const T&));
};
#endif