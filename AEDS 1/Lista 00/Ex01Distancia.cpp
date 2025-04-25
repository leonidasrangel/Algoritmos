/*Construa um algoritmo que, tendo como dados de entrada 
dois pontos quaisquer no plano, P(x1, y1) e P(x2, y2), 
escreva a distância entre eles. A fórmula que efetua tal cálculo é:*/
#include<iostream>
#include<math.h>
using namespace std;

float distanciaPontos(float x1, float y1, float x2, float y2){
    float x = (x2 - x1)*(x2 - x1);
    float y = (y2 - y1)*(y2 - y1);
    float distancia = sqrt(x + y);
    return distancia;
}
int main(){
    float n1, n2, n3, n4;

    cout << "Escreva um numero;" << endl;
    cin >> n1;
    cout << "Escreva um numero;" << endl;
    cin >> n2;
    cout << "Escreva um numero;" << endl;
    cin >> n3;
    cout << "Escreva um numero;" << endl;
    cin >> n4;

    cout << "Resultado: " << distanciaPontos(n1, n2, n3, n4) << endl;


    return 0;
}