#include <iostream>
using namespace std;

float MediaPonderada (float n1, float n2, float n3){
    float resultado = (n1*2) + (n2*3) + (n3*5) / (2+3+5);
    return resultado;
}

int main (){
    float n1 = 0, n2 = 0, n3 = 0;
    cout << "Digite o valor da primeira nota: ";
    cin >> n1;
    cout << "Digite o valor da segunda nota: ";
    cin >> n2;
    cout << "Digite o valor da terceira nota: ";
    cin >> n3;

    float media = MediaPonderada(n1,n2,n3);
    cout << "A media do alune e:" << media <<endl;

    return 0;
}