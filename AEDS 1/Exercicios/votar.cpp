#include<iostream>
using namespace std;

void votar(int idade){
    if(idade >= 16){
        cout <<"Pode votar.";
    }else{
        cout <<"Nao pode votar.";
    }
    
}
int main(){
    float anos;
    cout <<"Informe sua idade: ";
    cin >> anos;

    votar(anos);
}