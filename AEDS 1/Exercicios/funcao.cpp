/*Agora é sua vez, faça um programa que execute a seguinte função matemática:

$F(x) = 3x^3 - 8x^2 – 9x + 7*/

#include<iostream>
using namespace std;

int cubo(int x){

    int a = x*x*x;
    return a;
}
int quadrado(int x){
    int a = x*x;
    return a;
}
int letra(int x){
    int a = x;
    return a;
}

int main(){

    int valor = 3*cubo(2) - 8*quadrado(2) - 9*letra(2) + 7;
    cout << "O valor de F(2): " << valor << endl;





    return 0;
}