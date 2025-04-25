/*Faça um programa para que uma pessoa possa fazer três operações numa conta bancária na seguinte ordem:

1°. Fazer um deposito

2°. Fazer um saque

3°. Fazer outro deposito

Ao final seu programa deve informar o saldo desta conta.*/

#include<iostream>
using namespace std;

int main(){
        cout << "Dados bancarios" << endl;

        float deposito;

        cout << "Quanto deseja depositar em sua conta: " << endl;
        cin >> deposito;

        float saque;
        cout << "Quanto deseja sacar da sua conta: " << endl;
        cin >> saque;

        float outroDeposito;
        cout << "Quanto deseja depositar em sua conta: " << endl;
        cin >> outroDeposito;

        float saldo;
        saldo = deposito - saque + outroDeposito;

        cout << "Seu saldo atual: " << saldo << endl;


    return 0;
}