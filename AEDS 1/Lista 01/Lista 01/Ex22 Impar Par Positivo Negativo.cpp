#include <iostream>
using namespace std;

void ImparPar (int numero){
    if (numero %2 == 0){
        cout << "O numero e par" <<endl;
    }else {
        cout << "O numero e impar" <<endl;
    }
}

void PositivoNegativo (int numero){
    if (numero > 0){
        cout << "O numnero e positivo" <<endl;
    } else {
        cout << "O numero e negativo" <<endl;
    }
}

int main (){
    int numero = 0;
    cout << "Informe um numero: ";
    cin >> numero;
    ImparPar(numero);
    PositivoNegativo(numero);
    return 0;
}