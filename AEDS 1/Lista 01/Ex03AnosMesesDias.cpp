#include<iostream>
#include<math.h>
using namespace std;

float idadeEmDias(float a, float m, float d){
    float anos = a * 365;
    float meses = m * 30;
    float dia = d; 
    float resultado = anos + meses + dia;
    return resultado;
}

int main(){
    int n1, n2, n3;

    cout << "Informe quantos anos: " << endl;
    cin >> n1;

    cout << "Informe quantos meses: " << endl;
    cin >> n2;

    cout << "Infome quantos dias: " << endl;
    cin >> n3;

    cout << "Voce possui " << idadeEmDias(n1, n2, n3) << " dias de vida!" << endl; 

    return 0;
}