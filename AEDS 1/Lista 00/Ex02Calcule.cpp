#include<iostream>
#include<math.h>
using namespace std;

float elevadoQuadrado(float a, float b, float c){
    float R = (a + b)*(a + b);
    float S = (b + c)*(b + c);
    float D = (R + S)/2;
    return D;
}
int main(){
    int a, b, c;

    cout << "Escreva o primeiro numero: " << endl;
    cin >> a;

    cout << "Escreva o segundo numero: " << endl;
    cin >> b;

    cout << "Escreva o terceiro numero: " << endl;
    cin >> c;

    cout << "Resultado: " << elevadoQuadrado(a, b, c) << endl;

    return 0;
}
