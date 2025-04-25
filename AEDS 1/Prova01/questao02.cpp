/*Utilizando a estrutura de alternativa múltipla escolha (obrigatório o uso do 'switch(código){case'...})
desenvolver um algoritmo para calcular e imprimir o novo preço dos refrigerantes de determinada marca. 
O algoritmo deve solicitar o código do refrigerante e o preço antigo. Código 'L' para refrigentante de laranja,
'C' para refrigerante de cola e 'U' para refrigerante de uva. Em uma sub-rotina separada, explique ao usuário o que os códigos significam, chame-a no main.
O cálculo do novo preço será feito em outra sub-rotina do seguinte modo: refrigerante de laranja terá um aumento
de 10%. Refrigerante de cola terá um aumento de 8%. Refrigerante de uva terá um aumento de 5%. O valor do novo preço
deve ser obrigatoriamente impresso no método main.
Se o código lido for diferente dos citados acima, imprima uma mensagem de erro.*/
#include <iostream>
using namespace std;
// Sub-rotina para explicar ao usuário o que os códigos significam
void explicarCodigos() {
    cout << "Códigos dos refrigerantes:" << endl;
    cout << "'L' - Refrigerante de Laranja" << endl;
    cout << "'C' - Refrigerante de Cola" << endl;
    cout << "'U' - Refrigerante de Uva" << endl;
}
// Sub-rotina para calcular o novo preço do refrigerante
double calcularNovoPreco(char codigo, double precoAntigo) {
    double novoPreco;
    switch (codigo) {
        case 'L':
            novoPreco = precoAntigo * 1.10; // Aumento de 10%
            break;
        case 'C':
            novoPreco = precoAntigo * 1.08; // Aumento de 8%
            break;
        case 'U':
            novoPreco = precoAntigo * 1.05; // Aumento de 5%
            break;
        default:
            cout << "Código de refrigerante inválido!" << endl;
            return -1;
    }
    return novoPreco;
}
int main() {
    char codigo;
    double precoAntigo, novoPreco;
    // Explicar os códigos ao usuário
    explicarCodigos();
    // Solicitar o código do refrigerante
    cout << "Digite o código do refrigerante: ";
    cin >> codigo;
    // Solicitar o preço antigo do refrigerante
    cout << "Digite o preço antigo do refrigerante: ";
    cin >> precoAntigo;
    // Calcular o novo preço usando a sub-rotina
    novoPreco = calcularNovoPreco(codigo, precoAntigo);
    // Imprimir o novo preço no método main, se o código for válido
    
    cout << "O novo preço do refrigerante é: " << novoPreco << endl;   
    return 0;
}
