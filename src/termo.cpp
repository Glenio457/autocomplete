#include <iostream>

#include "../include/termo.h"

Termo::Termo(const std::string& n, long p) : nome(n), peso(p) {}

std::string Termo::getNome() const { return nome; }
long Termo::getPeso() const { return peso; }

void Termo::print() const {
    std::cout << peso << "\t" << nome << "\n";
}

bool Termo::comparaPorPrefixo(const Termo& a, const Termo& b, const std::string& prefixo) {
    bool a_comeca = a.getNome().rfind(prefixo, 0) == 0;
    bool b_comeca = b.getNome().rfind(prefixo, 0) == 0;

    if (a_comeca && b_comeca) {
        return a.getNome() < b.getNome();
    } else {
        return a_comeca;
    }
}

bool Termo::comparaPorPeso(const Termo& a, const Termo& b) {
    return a.getPeso() > b.getPeso();
}