#include <iostream>
using namespace std;

int media (int n1, int n2, int n3){
    int resultado = (n1 + n2 + +n3) / 3;
    cout << resultado <<endl;
    if (resultado >= 6){
        cout << "Aluno Aprovado" <<endl;
    } else {
        cout << "Aluno Reprovado" <<endl;
    }
    return resultado;
}

int main (){
    int n1 = 0, n2 = 0, n3 = 0;
    cout << "Digite o valor da primeira nota: ";
    cin >> n1;
    cout << "Digite o valor da segunda nota: ";
    cin >> n2;
    cout << "Digite o valor da terceira nota: ";
    cin >> n3;

    media(n1,n2,n3);
    return 0;
}