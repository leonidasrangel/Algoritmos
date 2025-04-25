//Faça um programa que peça ao usuário dois números e informe a subtração entre eles.
#include<iostream>
using namespace std;

float subtracao(float a, float b){
    float sub = a - b;
    return sub;

}
int main(){
    float n1;
    float n2;

    cout << "Informe um numero:" << endl;
    cin >> n1;

    cout << "Informe mais um numero:" << endl;
    cin >> n2;

    cout << "Resultado da subtracao:" << subtracao(n1, n2) << endl;

    return 0;
}