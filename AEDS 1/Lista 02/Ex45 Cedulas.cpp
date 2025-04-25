#include <iostream>
using namespace std;

void dinheiro(int quantidade) {
    int cedulas100 = 0;
    int cedulas50 = 0;
    int cedulas20 = 0;
    int cedulas10 = 0;
    int cedulas5 = 0;
    int cedulas1 = 0;

    if (quantidade >= 100) {
        cedulas100 = quantidade / 100;
        cout << "Você tem " << cedulas100 << " notas de 100 reais" << endl;
        quantidade = quantidade % 100;
    }
    if (quantidade >= 50) {
        cedulas50 = quantidade / 50;
        cout << "Você tem " << cedulas50 << " notas de 50 reais" << endl;
        quantidade = quantidade % 50;
    }
    if (quantidade >= 20) {
        cedulas20 = quantidade / 20;
        cout << "Você tem " << cedulas20 << " notas de 20 reais" << endl;
        quantidade = quantidade % 20;
    }
    if (quantidade >= 10) {
        cedulas10 = quantidade / 10;
        cout << "Você tem " << cedulas10 << " notas de 10 reais" << endl;
        quantidade = quantidade % 10;
    }
    if (quantidade >= 5) {
        cedulas5 = quantidade / 5;
        cout << "Você tem " << cedulas5 << " notas de 5 reais" << endl;
        quantidade = quantidade % 5;
    }
    if (quantidade >= 1) {
        cedulas1 = quantidade;
        cout << "Você tem " << cedulas1 << " notas de 1 real" << endl;
    }
}

int main() {
    int quantidade = 0;
    cout << "Digite a quantidade de dinheiro: ";
    cin >> quantidade;

    dinheiro(quantidade);
    return 0;
}
