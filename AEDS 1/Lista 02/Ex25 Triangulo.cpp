#include <iostream>
using namespace std;

void angulo (float angulo1, float angulo2, float angulo3){
    float resultado = angulo1 + angulo2 + angulo3;
    if (resultado == 180){
        cout << "Sao validos, pois a soma de seus angulos e igual a 180 graus";
    } else {
        cout << "Nao sao validos";
    }
}

int main (){
    float Angulo1 = 0, Angulo2 = 0, Angulo3 = 0;
    cout<< "Digite o valor do Angulo 1: ";
    cin >> Angulo1;
    cout<< "Digite o valor do Angulo 2: ";
    cin >> Angulo2;
    cout<< "Digite o valor do Angulo 3: ";
    cin >> Angulo3;

    angulo(Angulo1, Angulo2, Angulo3);
    return 0;
}