#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept> 
#include "../include/termo.h"
#include "../include/lista.h"
#include "../include/autocompletar.h"

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

int main(int argc, char* argv[]) {
    try {
        if (argc < 3) {
            throw std::runtime_error("Uso: ./programa <arquivo.txt> <numero k>");
        }

        std::string filename = argv[1];
        int k = std::stoi(argv[2]);

        if (k <= 0) {
            throw std::runtime_error("O valor de k deve ser um inteiro positivo.");
        }

        auto termos_vector = carregarTermos(filename);
        Autocompletar autocompletar(termos_vector);

        while (true) {
            std::string fragment;
            std::cout << "\nEntre com o termo a ser auto-completado: (digite \"sair\" para encerrar o programa): \n";
            std::getline(std::cin, fragment);

            if (fragment == "sair") {
                std::cout << "Encerrando o programa." << std::endl;
                break;
            }

            std::vector<Termo> matches = autocompletar.buscar(fragment);

            for (size_t i = 0; i < matches.size() && i < static_cast<size_t>(k); ++i) {
                matches[i].print();
            }

            if (matches.empty()) {
                std::cout << "Nenhum resultado encontrado." << std::endl;
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}