#include <iostream>
using namespace std;

float linearX (float a, float b, float c, float d, float e, float f){
    float x = (c*e - b*f) / (a*e - b*d);
    return x;
}

float linearY (float a, float b, float c, float d, float e, float f){
    float y = (a*f - c*d) / (a*e - b*d);
    return y;
}

int main (){
    float a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    
    cout << "Digite o valor de A: ";
    cin >> a;
    cout << "Digite o valor de B: ";
    cin >> b;
    cout << "Digite o valor de C: ";
    cin >> c;
    cout << "Digite o valor de D: ";
    cin >> d;
    cout << "Digite o valor de E: ";
    cin >> e;
    cout << "Digite o valor de F: ";
    cin >> f;

    float resultadoX = linearX(a,b,c,d,e,f);
    cout <<"O resultado de X: "<< resultadoX ;

    float resultadoY = linearY(a,b,c,d,e,f);
    cout <<"O resultado de Y " << resultadoY;
    return 0;
}