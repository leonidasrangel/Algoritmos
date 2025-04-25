#include<iostream>
using namespace std;

float maior( float num1, float num2){
    float m;
    if(num1 >= num2){
        m = num1;
    }else{
        m = num2;
    }
    return m;
}

int main(){
    float x1 = 0;
    float x2 = 0;

    cout <<"Informe um numero:";
    cin >> x1;

    cout <<"Informe outro numero;";
    cin >> x2;

    cout <<"O maior numero: " << maior (x1,x2);
    return 0;
}