#include "../include/autocompletar.h"
#include <algorithm>
#include <string>

Autocompletar::Autocompletar(const std::vector<Termo>& t) : termos(t) {
    std::sort(termos.begin(), termos.end(), [](const Termo& a, const Termo& b) {
        return a.getNome() < b.getNome();
    });
}

std::vector<Termo> Autocompletar::buscar(const std::string& prefixo) const {
    std::vector<Termo> resultados;

    auto it_inicio = std::lower_bound(termos.begin(), termos.end(), prefixo, [](const Termo& termo, const std::string& prefixo) {
        return termo.getNome().compare(0, prefixo.length(), prefixo) < 0;
    });

    if (it_inicio != termos.end()) {
        auto it_fim = std::upper_bound(it_inicio, termos.end(), prefixo, [](const std::string& prefixo, const Termo& termo) {
            return prefixo.compare(0, prefixo.length(), termo.getNome(), 0, prefixo.length()) < 0;
        });

        resultados.assign(it_inicio, it_fim);

        std::sort(resultados.begin(), resultados.end(), Termo::comparaPorPeso);
    }

    return resultados;
}