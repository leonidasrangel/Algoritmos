/*Escrever um algoritmo que tenha como entrada um valor 'n' inteiro e que calcule a seguinte expressão:
R = n^1 +  n^2 + n^3 + ... + n^(n-2) + n^(n-1) + n
Se a entrada 'n' for zero ou negativo, imprimir uma mensagem de erro. Ao final, imprimir
o valor de R. (Obrigatório o uso do 'for')*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    long long R = 0; // Utilizando long long para suportar números grandes

    // Solicitar o valor de 'n'
    cout << "Digite um valor inteiro positivo para 'n': ";
    cin >> n;

    // Verificar se 'n' é zero ou negativo
    if (n <= 0) {
        cout << "Erro: O valor de 'n' deve ser positivo." << endl;
        return 1; // Termina o programa com código de erro
    }

    // Calcular a expressão R usando um loop for
    for (int i = 1; i <= n; i++) {
        R += pow(n, i);
    }

    // Imprimir o valor de R
    cout << "O valor de R é: " << R << endl;

    return 0;
}
