#include <iostream>
using namespace std;

float energia (float quantidade){
    if (quantidade >= 250){
        quantidade = (quantidade * 1.50) * 1.20;
    } else if (quantidade >= 200){
        quantidade = (quantidade * 1.20) * 1.20;
    } else if (quantidade >= 100){
        quantidade = (quantidade * 0.75) * 1.20;
    } else {
        quantidade = (quantidade * 0.50) * 1.20;
    }
    return quantidade;
}

int main (){
    float quantidade = 0;
    cout << "Digite o valor da sua conta: ";
    cin >> quantidade;
    cout << "Vc esta pagando " << energia(quantidade) << " de energia" <<endl;
    return 0;
}