#include <iostream>
using namespace std;

void TipoIdade (int idade){
    if (idade >= 18){
        cout <<"Adulto";
    } else if (idade >= 14){
        cout <<"Juvenil B";
    } else if (idade >= 11){
        cout <<"Juvenil A";
    } else if (idade >= 8){
        cout <<"Infantil B";
    } else if (idade >= 5){
        cout <<"Infantil A";
    } else {
        cout <<"Crianca";
    }
}

int main (){
    int idade = 0;
    cout <<"Digite sua idade: ";
    cin >> idade;

    TipoIdade(idade);
    return 0;
}