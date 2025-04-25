#include <iostream>
using namespace std;

float soma (float n1, float n2, float n3){
    float resultado;
    resultado = n1 + n2 + n3;
    return resultado; 
}

int main (){
    float n1 = 0;
    float n2 = 0;
    float n3 = 0;

    cout << "Digite o valor de n1: ";
    cin >> n1;
    cout << "Digite o valor de n2: ";
    cin >> n2;
    cout << "Digite o valor de n3: ";
    cin >> n3;  

    cout << "A soma e: " << soma(n1,n2,n3);
    return 0;
}