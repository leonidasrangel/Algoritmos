#include <iostream>
using namespace std;

void diaSemana (int semana){
    switch (semana){
        case 1:
            cout << "Domingo";
            break;
        case 2:
            cout << "Segunda";
            break;
        case 3:
            cout << "Terca";
            break;
        case 4:
            cout << "Quarta";
            break;
        case 5:
            cout << "Quinta";
            break;
        case 6:
            cout << "Sexta";
            break;
        case 7:
            cout << "Sabado";
            break;
        default:
            cout << "Numero Invalido";
    }
}

int main (){
    int semana = 0;
    cout << "Digite um dia da Semana: ";
    cin >> semana;
    diaSemana(semana);
    return 0;
}