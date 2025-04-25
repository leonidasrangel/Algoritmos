#include <iostram>
using namespace std;

float media (float credito){
    float valor = 0;
    if(credito > 600){
        valor = credito * 0.40;
    } else if (credito > 400){
        valor = credito * 0.30;
    } else if (credito > 200){
        valor = credito * 0.20;
    } else {
        valor = credito;
    }
    return valor;
}

int main (){
    float credito = 0;
    cout <<"Digite seu saldo medio: ";
    cin >> credito;
    cout << "Vc tem " << media(credito) << " de credito";
    return 0;
}