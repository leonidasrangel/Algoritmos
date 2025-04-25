#include <iostream>

using namespace std;

// Definindo a struct TimeFutebol
struct TimeFutebol {
    string nome;
    string cidade;
    int quantidadeTitulos;

    // Função para exibir as informações do time de futebol
    void exibirInformacoes(){
        cout << "Nome do Time: " << nome << endl;
        cout << "Cidade: " << cidade << endl;
        cout << "Quantidade de Títulos: " << quantidadeTitulos << endl;
    }
};

int main() {
    TimeFutebol time;

    // Solicita as informações do time de futebol
    cout << "Digite o nome do time: ";
    getline(cin, time.nome);

    cout << "Digite a cidade do time: ";
    getline(cin, time.cidade);

    cout << "Digite a quantidade de títulos: ";
    cin >> time.quantidadeTitulos;

    // Exibe as informações do time de futebol
    time.exibirInformacoes();

    return 0;
}
