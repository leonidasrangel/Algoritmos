#include <iostream>
#include <math.h>
using namespace std;

void calculaDelta (float a, float b, float c){
    float delta = (b*b - 4.0 * c *a);
    if (delta >=0){
        float x1 = (-b + sqrt(delta)) / (2.0*a);
        float x2 = (-b - sqrt(delta)) / (2.0*a);
        cout << "Raizes da equacao X1: " << x1 << " X2: " << x2 <<endl; 
    } else {
        cout << "Nao existem raizes " <<endl;
    }
}

int main (){
    float a = 0, b = 0, c = 0;

    cout << " Calcula raizes da equacao 2 grau\n F(x) = a.x² + b.x + c" <<endl;

    cout <<"Digite um valor para A: ";
    cin >> a;
    cout << "Digite um valor para B: ";
    cin >> b;
    cout << "Digite um valor para C: ";
    cin >> c;

    calculaDelta(a,b,c);
    return 0;
}