#include "termo.h" 
#include <algorithm> 

Termo::Termo() : termo(""), peso(0) {}

Termo::Termo(std::string termo, long peso) : termo(termo), peso(peso) {}

int Termo::compararPeloPeso(const Termo& T1, const Termo& T2) {
    if (T1.peso > T2.peso) return 1;
    if (T1.peso < T2.peso) return -1;
    return 0;
}

int Termo::compararPeloPrefixo(const Termo& T1, const Termo& T2, int r) {
    std::string prefixo1 = T1.termo.substr(0, std::min((int)T1.termo.length(), r));
    std::string prefixo2 = T2.termo.substr(0, std::min((int)T2.termo.length(), r));

    if (prefixo1 < prefixo2) return -1;
    if (prefixo1 > prefixo2) return 1;
    return 0;
}

bool Termo::operator<(const Termo& T2) const {
    return termo < T2.termo;
}

std::ostream& operator<<(std::ostream& out, const Termo& t) {
    out << "(" << t.termo << ", " << t.peso << ")";
    return out;
}