#include <iostream>
using namespace std;

void Multiplos (int n1, int n2){
    if (n1 % n2 == 0 || n2 % n1 == 0){
        cout << "Sao Multiplos" <<endl;
    } else {
        cout <<"Nao sao multiplos" <<endl;
    }
}

int main (){
    int n1 = 0, n2 = 0;
    cout << "Digite o primeiro valor: ";
    cin >> n1;
    cout << "Digite o segundo valor: ";
    cin >> n2; 

    Multiplos(n1,n2);
    return 0;
}