/*Algoritmo deve executar o que se pede até que o FLAG de parada zero seja fornecido como entrada.
O objetivo do algoritmo é contar a quantidade de números maiores que zero e a quantidade de 
números menores que zero. Ao final, informe a quantidade de números positivos e números negativos lidos.*/

#include <iostream>
using namespace std;

int main() {
    int numero = 0;
    int positivos = 0;
    int negativos = 0;

    // Solicitar números até que o usuário forneça o flag de parada (zero)
    cout << "Digite números inteiros (digite zero para parar): " << endl;
    while (true) {
        cin >> numero;

        // Verificar se o flag de parada foi fornecido
        if (numero == 0) {
            break;
        }

        // Contar números positivos e negativos
        if (numero > 0) {
            positivos++;
        } else if (numero < 0) {
            negativos++;
        }
    }

    // Imprimir as quantidades de números positivos e negativos
    cout << "Quantidade de números positivos: " << positivos << endl;
    cout << "Quantidade de números negativos: " << negativos << endl;

    return 0;
}
