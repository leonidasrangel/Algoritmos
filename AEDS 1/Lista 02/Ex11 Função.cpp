#include <iostream>
using namespace std;

float funcao (float x, float y){
    float resultado;
    resultado = (x*x) + (y*y) - (6*x*y) - 1;
    return resultado;
}

int main (){
    float x = 0;
    float y = 0;

    cout <<"Funcao F(X,Y) = X2 + Y2 - 6XY" <<endl;
    cout <<"Digite o valor de X: ";
    cin >> x;
    cout <<"Digite o valor de Y: ";
    cin >> y;

    float resultado = funcao(x,y);
    cout <<"O reultado e:" << resultado << endl;
    return 0;
}