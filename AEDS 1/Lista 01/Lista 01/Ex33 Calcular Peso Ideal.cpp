#include <iostream>
using namespace std;

void peso(char opcao, float altura){
    if (opcao == 'h'){
        float p = (72.7 * altura) - 58;
        cout << "Seu peso ideal e:" << p <<endl;
    } else if (opcao == 'm'){
        float p = (62.1 * altura) - 44.7;
        cout << "Sua peso ideal e:" << p <<endl;
    } else {
        cout << "Opcao Invalida" <<endl;
    }
}

int main (){
    char opcao = 0;
    float altura = 0;

    cout << "Vc e Home (H) ou Mulher(M):";
    cin >> opcao;

    cout << "Digite sua altura em Metros:";
    cin >> altura;

    peso(opcao,altura);
    return 0;
}