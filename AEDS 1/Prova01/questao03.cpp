/*Utilizando a estrutura alternativa múltipla escolha (obrigatório o uso do 'switch(código){case'...}),
desenvolver um algoritmo para calcular e imprimir o novo salário de um funcionário. O algoritmo
deve solicitar o código e o salário atual do funcionário. Os códigos de funcionários são:
12 - Programador Jr; 17 - Analista de Sistemas; 23 - Gerente de Projetos.
O aumento será dado de acordo com as seguintes regras:
Programador Jr : Aumento de 10% se o sálario for menor que R$ 1,500.00 e 7% caso contrário.
Analista de Sistema - Aumento de 8% se o salário for menor que R$ 3,100.00 e 6% caso contrário.
Gerente de Projetos - Aumento de 5%
Se o código lido for diferente dos citados acima, imprima uma mensagem de erro.*/

#include <iostream>
using namespace std;
// Sub-rotina para calcular o novo salário do funcionário
double calcularNovoSalario(int codigo, double salarioAtual) {
    double novoSalario;
    switch (codigo) {
        case 12: // Programador Jr
            if (salarioAtual < 1500.00) {
                novoSalario = salarioAtual * 1.10; // Aumento de 10%
            } else {
                novoSalario = salarioAtual * 1.07; // Aumento de 7%
            }
            break;
        case 17: // Analista de Sistemas
            if (salarioAtual < 3100.00) {
                novoSalario = salarioAtual * 1.08; // Aumento de 8%
            } else {
                novoSalario = salarioAtual * 1.06; // Aumento de 6%
            }
            break;
        case 23: // Gerente de Projetos
            novoSalario = salarioAtual * 1.05; // Aumento de 5%
            break;
        default:
            cout << "Código de funcionário inválido!" << endl;
            return 0;
    }
    return novoSalario;
}
int main() {
    int codigo;
    double salarioAtual, novoSalario;
    // Solicitar o código do funcionário
    cout << "Digite o código do funcionário: ";
    cin >> codigo;
    // Solicitar o salário atual do funcionário
    cout << "Digite o salário atual do funcionário: ";
    cin >> salarioAtual;
    // Calcular o novo salário usando a sub-rotina
    novoSalario = calcularNovoSalario(codigo, salarioAtual);
    // Imprimir o novo salário no método main, se o código for válido
    if (novoSalario) {
        cout << "O novo salário do funcionário é: R$ " << novoSalario << endl;
    }
    return 0;
}
