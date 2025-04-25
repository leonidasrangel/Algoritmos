#include <iostream>
using namespace std;

float Carro (float valor){
    valor = (valor * 1.28) * 1.45;
    return valor;
}

int main (){
    float valor;
    cout << "Digite o valor do Carro: ";
    cin >> valor;

    float resultado = Carro(valor);
    cout <<"O valor final do carro e: " << resultado <<endl;
    return 0;
}