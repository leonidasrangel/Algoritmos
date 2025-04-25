#include <iostream>
using namespace std;

void valorN (float valor){
    
    if (valor < 0){
        cout <<"O resultado e negativo";
    } else {
        cout << "O resultado e positivo";
    }
}

int main (){
    float valor = 0;
    cout<<"Digite um valor: ";
    cin >> valor;
    
    valorN(valor);
    return 0;
}