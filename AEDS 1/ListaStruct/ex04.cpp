#include <iostream>

using namespace std;

// Definindo a struct Data
struct Data {
    int dia;
    int mes;
    int ano;
};

// Função para verificar se um ano é bissexto
bool eBissexto(int ano) {
    return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
}

// Função para verificar se a data é válida
bool dataValida(const Data &d) {
    // Verificar o mês
    if (d.mes < 1 || d.mes > 12) {
        return false;
    }
    
    // Verificar o dia
    int diasNoMes;
    switch (d.mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasNoMes = 31; // Janeiro, Março, Maio, Julho, Agosto, Outubro, Dezembro
            break;
        case 4: case 6: case 9: case 11:
            diasNoMes = 30; // Abril, Junho, Setembro, Novembro
            break;
        case 2:
            diasNoMes = eBissexto(d.ano) ? 29 : 28; // Fevereiro
            break;
        default:
            return false; // Mês inválido
    }
    
    return d.dia >= 1 && d.dia <= diasNoMes;
}

int main() {
    Data data;
    
    cout << "Digite o dia: ";
    cin >> data.dia;
    
    cout << "Digite o mês: ";
    cin >> data.mes;
    
    cout << "Digite o ano: ";
    cin >> data.ano;
    
    if (dataValida(data)) {
        cout << "A data é válida." << endl;
    } else {
        cout << "A data é inválida." << endl;
    }
    
    return 0;
}
