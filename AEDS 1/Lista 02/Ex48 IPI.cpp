#include <iostream>
using namespace std;

float ipi (float codigo1, float valor1, float quantidade1,float codigo2, float valor2, float quantidade2){
    float resultado = 0;
    float final = 0;
    resultado = (valor1 * quantidade1) + (valor2 * quantidade2);
    final = resultado * ((resultado / 100) + 1);
    return final;
}

int main (){
    float codigo1 = 0, valor1 = 0, quantidade1 = 0, codigo2 = 0, valor2 = 0, quantidade2 = 0;

    cout << "Digite o codigo da Peca 1: ";
    cin >> codigo1;
    cout << "Digite o valor da Peca 1: ";
    cin >> valor1;
    cout << "Digie a quantidade da Peca 1: ";
    cin >> quantidade1;

    cout << "Digite o codigo da Peca 2: ";
    cin >> codigo2;
    cout << "Digite o valor da Peca 2: ";
    cin >> valor2;
    cout << "Digie a quantidade da Peca 2: ";
    cin >> quantidade2;

    float IpiFinal = ipi(codigo1,valor1,quantidade1,codigo2,valor2,quantidade2);
    cout <<"O resultado do IPI e: " << IpiFinal <<endl;
    return 0;
}