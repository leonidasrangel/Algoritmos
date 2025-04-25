#include <iostream>
using namespace std;

int triplo (int n){
    int resultado;
    resultado = n * n * n;
    return resultado;
}

int quadruplo (int n){
    int resultado;
    resultado = n * n * n * n;
    return resultado;
}

int main () {
    int numero = 0;
    cout << "Digite um numero: ";
    cin >> numero;

    cout << "O triplo desse numero e: " << triplo(numero) <<endl;
    cout << "O Quadruplo desse numero e: " << quadruplo(numero) <<endl;
    return 0;
}