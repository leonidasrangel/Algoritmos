//Faça um programa que peça ao usuário para inserir dois números reais e calcular o produto e a diferença entre eles, em seguida seu programa deve imprimir os resultados;
#include<iostream>
using namespace std;

int main(){

    float n1;
    float n2;

    cout << "Insira o primeiro numero: "  << endl;
    cin >> n1; 
    cout << "Insira o segundo numero: " << endl;
    cin >> n2; 

    float produto;
    produto = n1 * n2;  

    float diferenca;
    diferenca = n1 - n2;

    cout << "O produto dos numeros sao: " << produto << "." << endl;
    cout << "A diferenca dos numeros sao: " << diferenca << "." << endl;






    return 0;
}