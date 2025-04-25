#include<iostream>
#include<locale.h>
using namespace std;

void cnh(int idade){
    if(idade >= 18){
        cout << "Você pode tirar carteira.";
    }else{
        cout << "Idade insuficiente.";
    }

}

int main(){
    setlocale(LC_ALL, "Portuguese");
    float anos = 0;
    cout <<"Informe sua idade:";
    cin >> anos;

    cnh(anos);

    return 0;
}
