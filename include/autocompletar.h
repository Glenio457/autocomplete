#ifndef AUTOCOMPLETAR_H
#define AUTOCOMPLETAR_H

#include <string>
#include <vector>

#include "termo.h"

class Autocompletar {
private:
    std::vector<Termo> termos;

public:
    Autocompletar(const std::vector<Termo>& t);

    std::vector<Termo> buscar(const std::string& prefixo) const;
};

#endif 