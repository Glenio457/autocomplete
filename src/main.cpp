#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept> 

#include "../include/termo.h"
#include "../include/lista.h"
#include "../include/autocompletar.h"
#include "../include/carregar.h"

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