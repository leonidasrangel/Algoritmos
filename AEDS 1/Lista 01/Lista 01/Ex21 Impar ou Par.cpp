#include <iostream>
using namespace std;

void ImparPar (int numero){
    if (numero %2 == 0){
        cout << "O numero e par";
    }else {
        cout << "O numero e impar";
    }
}

int main (){
    int numero = 0;
    cout << "Informe um numero: ";
    cin >> numero;
    ImparPar(numero);
    return 0;
}