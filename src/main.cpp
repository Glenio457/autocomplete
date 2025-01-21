#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <arquivo.txt> <numero>" << endl;
        return 1;
    }

    string nomeArquivo = argv[1];
    int numLinhas = stoi(argv[2]);

    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return 1;
    }

    string linha;
    int contador = 0;
    while (getline(arquivo, linha) && contador < numLinhas) {
        cout << linha << endl;
        contador++;
    }

    cout << "Número: " << numLinhas << endl;

    arquivo.close();
    return 0;
}