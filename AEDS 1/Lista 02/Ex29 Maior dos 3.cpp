#include <iostream>
using namespace std;

float maior(float n1, float n2, float n3){
    if (n1 > n2 && n1 > n3){
        return n1;
    } if (n2 > n3 && n2 > n1){
        return n2;
    } else {
        return n3;
    }
}

int main (){
    float n1 = 0, n2 = 0, n3 = 0;
    cout << "Digite o valor do primeiro numero: ";
    cin >> n1;
    cout << "Digite o valor do segundo numero: ";
    cin >> n2;
    cout << "Digite o valor do terceiro numero: ";
    cin >> n3;
    
    float maiorNumero = maior(n1,n2,n3);

    cout <<"O maior entre eles e: " << maiorNumero <<endl;
    return 0;
}