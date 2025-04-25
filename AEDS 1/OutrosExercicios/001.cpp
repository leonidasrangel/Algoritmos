/*Crie um programa que peça ao usuário que digite um 
número inteiro entre 1 e 7 e exiba o dia da semana correspondente. 
Se o usuário digitar um número fora desse intervalo, exiba uma mensagem de erro.*/

#include<iostream>
using namespace std;

void diaSemana(int dia){
    switch (dia){
    
    case 1: 
        cout <<"Segunda feira" ; 
        break;
    case 2: 
        cout <<"Terça-feira ";
    break;
    case 3:
        cout << "Quarta-feira" ;
    break;
    case 4: 
        cout << "Quinta-feira" ;
    break;
    case 5:
        cout << "Sexta-feira" ;
    break;
    case 6: 
        cout << "Sabado" ;
    break;

    default: 
        cout << "Domingo" << endl;
    
    break;
    
    }
}

int main(){
    int numeroDia = 0;

    cout << "Escolha um numero de 1 a 7: " << endl;
    cin >> numeroDia;

    diaSemana(numeroDia);
}