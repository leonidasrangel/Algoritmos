#include <iostream>
using namespace std;

void ParA (int a){
    if(a %2 ==0){
        cout << "O valor de A e par" <<endl;
    }else {
        cout << "O valor de A e impar" <<endl;
    }
}

void ParB (int b){
    if(b %2 ==0){
        cout << "O valor de B e par" <<endl;
    }else {
        cout << "O valor de B e impar" <<endl;
    }
}

int main (){
    int a = 0, b = 0;
    
    cout << "Digite o valor de A: ";
    cin >> a;
    cout << "Digite o valor de B: ";
    cin >> b;

    ParA(a);
    ParB(b);
    return 0;
}