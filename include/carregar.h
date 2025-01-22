#ifndef CARREGAR_H
#define CARREGAR_H

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>

#include "../include/termo.h"

std::vector<Termo> carregarTermos(const std::string& filename) {
    std::vector<Termo> termos;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo: " + filename);
    }

    std::string linha;
    while (std::getline(file, linha)) {
        size_t tabPos = linha.find('\t');
        if (tabPos != std::string::npos) {
            try {
                long peso = std::stoull(linha.substr(0, tabPos));
                std::string nome = linha.substr(tabPos + 1);
                termos.push_back(Termo(nome, peso));
            } catch (const std::exception& e) {
                std::cerr << "Erro ao processar linha: " << linha << " - " << e.what() << std::endl;
            }
        } else {
            std::cerr << "Linha ignorada, formato inválido: " << linha << std::endl;
        }
    }

    file.close();
    return termos;
}

#endif