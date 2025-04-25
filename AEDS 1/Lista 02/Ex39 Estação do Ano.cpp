#include <iostream>
using namespace std;

void mes (int estacao){
    switch (estacao){
        case 1:
            cout << "Janeiro / Verao";
            break;
        case 2:
            cout << "Fevereiro / Verao";
            break;
        case 3:
            cout << "Marco / Outono";
            break;
        case 4:
            cout << "Abril / Outono";
            break;
        case 5:
            cout << "Maio / Outono";
            break;
        case 6:
            cout << "Junho / Inverno";
            break;
        case 7:
            cout << "Julho / Inverno";
            break;
        case 8:
            cout << "Agosto / Inverno";
            break;
        case 9:
            cout << "Setembro / Primavera";
            break;
        case 10:
            cout << "Outubro / Primavera";
            break;
        case 11:
            cout << "Novembro / Primavera";
            break;
        case 12:
            cout << "Dezembro / Verao";
            break;
        default :
            cout << "Numero Invalido";
    }
}

int main (){
    int estacao = 0;
    cout << "Digite um mes (numero): ";
    cin >> estacao;
    mes(estacao);
    return 0;
}