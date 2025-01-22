#ifndef AUTOCOMPLETAR_H
#define AUTOCOMPLETAR_H

#include "termo.h"
#include <vector>
#include <string>

class Autocompletar {
private:
    std::vector<Termo> termos;

public:
    Autocompletar(const std::vector<Termo>& termos);
    std::vector<Termo> buscar(const std::string& prefixo);
};

#endif