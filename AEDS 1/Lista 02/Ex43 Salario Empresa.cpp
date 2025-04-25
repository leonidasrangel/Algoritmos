#include <iostrem>
using namespace std;

void emprego (int cargo, float salario){

    switch (cargo){
        case 101:
            cout << "Gerente" <<endl;
            cout <<"Seu salario e: " << salario <<endl;
            cout <<"Seu novo salario e: " << salario * 1.10 <<endl;
            cout <<"Seu aumento foi de: " << salario * 0.10 <<endl;
        break;

        case 102:
            cout << "Engenheiro" <<endl;
            cout <<"Seu salario e: " << salario <<endl;
            cout <<"Seu novo salario e: " << salario * 1.20 <<endl;
            cout <<"Seu aumento foi de: " << salario * 0.20 <<endl;
        break;

        case 103:
            cout << "Tecnico" <<endl;
            cout <<"Seu salario e: " << salario <<endl;
            cout <<"Seu novo salario e: " << salario * 1.30 <<endl;
            cout <<"Seu aumento foi de: " << salario * 0.30 <<endl;
        break;

        default:
            cout << "Seu Cargo não esta na tabela então vc recebera 40% de aumento" <<endl;
            cout <<"Seu salario e: " << salario <<endl;
            cout <<"Seu novo salario e: " << salario * 1.40 <<endl;
            cout <<"Seu aumento foi de: " << salario * 0.40 <<endl;

    }
}

int main (){
    int cargo = 0;
    float salario = 0;
    cout <<"Digite o seu codigo: ";
    cin >> cargo;
    cout <<"Digite seu salario: ";
    cin >> salario;
    emprego(cargo,salario);
    return 0;
}