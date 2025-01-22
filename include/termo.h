#ifndef TERMO_H
#define TERMO_H

#include <string>

class Termo {
private:
    std::string nome;
    long peso;

public:
    Termo(const std::string& n, long p);

    std::string getNome() const;
    long getPeso() const;

    void print() const;

    static bool comparaPorPrefixo(const Termo& a, const Termo& b, const std::string& prefixo);
    static bool comparaPorPeso(const Termo& a, const Termo& b);
};

#endif