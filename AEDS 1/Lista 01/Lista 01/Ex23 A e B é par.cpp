#include <iostream>
using namespace std;

void soma (int a, int b){
    int valor = a + b;
    if (valor %2 == 0){
        cout << "O valor das Variaveis A e B sao pares " <<endl;
    } else {
        cout << "O valor das Variaveis A e B sao impares" <<endl;
    }
}

int main (){
    int a = 0, b = 0;
    cout << "Digite o valor de A: ";
    cin >> a;
    cout << "Digite o valor de B: ";
    cin >> b;
    soma(a,b); 
    return 0;
}