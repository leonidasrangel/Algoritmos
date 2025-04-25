#include <iostream>
using namespace std;

float funcao (float x){
    float resultado;
    resultado = x*x + 2*x -3;
    return resultado;
}

int main () {
    float x = 0;
    cout << "Digite um valor de x Para a Funcao F(X) = X*X + 2*X - 3: ";
    cin >> x;

    cout << "O valor e: " << funcao(x);
    return 0;
}