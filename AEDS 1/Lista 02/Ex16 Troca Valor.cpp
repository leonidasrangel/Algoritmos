#include <iostream>
using namespace std;

void troca (float A, float B){
    if (A < B){
        cout << " O valor de A: " << B;
        cout << " O valor de B :" << A;
    } else {
        cout << " O valor de A:" << A;
        cout << " O valor de B:" << B;
    }
}

int main (){
    float A = 0;
    float B = 0;
    cout << "Digite o valor de A: " << endl;
    cin >> A;
    cout << "Digite o valor de B " << endl;
    cin >> B;
    
    troca(A,B);
    return 0;
}