/*Desenvolver um algoritmo que faça a leitura de 3 numeros reais no main e, numa sub-rotina a parte, informe
se existem três valores iguais ou dois valores iguais. Caso contrário, ou seja, se forem todos diferentes, informar se estes
números estão em ordem crescente, decrescente ou se estão fora de ordem.*/

#include <iostream>
using namespace std;

// Sub-rotina para verificar os números e imprimir as informações desejadas
void verificarNumeros(double a, double b, double c) {
    if (a == b && b == c) {
        cout << "Os três valores são iguais." << endl;
    } else if (a == b || a == c || b == c) {
        cout << "Dois dos valores são iguais." << endl;
    } else {
        if (a < b && b < c) {
            cout << "Os valores estão em ordem crescente." << endl;
        } else if (a > b && b > c) {
            cout << "Os valores estão em ordem decrescente." << endl;
        } else {
            cout << "Os valores estão fora de ordem." << endl;
        }
    }
}

int main() {
    double num1, num2, num3;

    // Leitura de 3 números reais
    cout << "Digite o primeiro número: ";
    cin >> num1;
    cout << "Digite o segundo número: ";
    cin >> num2;
    cout << "Digite o terceiro número: ";
    cin >> num3;

    // Chama a sub-rotina para verificar os números
    verificarNumeros(num1, num2, num3);

    return 0;
}
