#include <iostream>
using namespace std;

float imc (float peso, float altura){
    float resultado = (peso) / (altura * altura);
    cout << "Seu IMC e: " << resultado <<endl;
    return resultado;
}

void classificacao (float resultado){
    if (resultado >= 40){
        cout << "Obesidade grau III (mórbida)";
    } else if (resultado >= 35){
        cout << "Obesidade grau II (severa)";
    } else if (resultado >=30){
        cout << "Obesidade grau I";
    } else if (resultado >= 25){
        cout << "Sobrepeso";
    } else if (resultado >= 18.5){
        cout << "Saudável";
    } else if (resultado >= 17){
        cout << "Magreza leve";
    } else if (resultado >= 16){
        cout << "Magreza moderada";
    } else {
        cout << "Magreza grave";
    }
}

int main (){
    float peso = 0, altura = 0;

    cout << "Digite seu peso: ";
    cin >> peso;
    cout << "Digite sua altura: ";
    cin >> altura;

    float resultado = imc(peso,altura);
    classificacao (resultado);
    return 0;
}