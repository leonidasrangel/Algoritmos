#include <iostream>
using namespace std;

float media (int opcao, float n1, float n2, float n3){
    if(opcao == 1){
        float resultado = (n1 + n2 + n3) / 3;
        return resultado;
    } else if (opcao == 2){
        float resultado = ((n1*3) + (n2*3) + (n3*4)) / (3 + 3 + 4);
        return resultado;
    } else if (opcao == 3){
        float resultado = (3) / ((1/n1) + (1/n2) + (1/n3));
        return resultado;
    } else {
        cout <<"Opcao invalida";
        return 0;
    }
}

int main (){
    int opcao = 0;
    float n1 = 0, n2 = 0,n3 = 0;
    cout << "Digite uma opcao: \n1.Aritmetica \n2.Ponderada(3,3,4) \n4.Harmonica";
    cin >> opcao;

    cout << "Digite o valor de N1: ";
    cin >> n1;
    cout << "Digite o valor de N2: ";
    cin >> n2;
    cout << "Digite o valor de N3: ";
    cin >> n3;

    float resultado = media(opcao,n1,n2,n3);
    cout << "Sua media e: " << resultado; 
    return 0;
}