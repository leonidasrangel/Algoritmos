#include <iostream>
using namespace std;

void carteira(int idade){
    int tempo = (18 - idade);
    if (idade >= 18){
        cout << "Vc pode tirar sua carteira" <<endl;
    } else {
        cout <<"Vc nao tem idade prara tirar carteira" <<endl;        
        cout << "Faltam " << tempo << " anos para vc poder tirar a sua carteira" <<endl;
    }
}

int main (){
    int idade = 0;
    cout << "Digite sua idade: ";
    cin >> idade;

    carteira(idade);
    return 0;
}