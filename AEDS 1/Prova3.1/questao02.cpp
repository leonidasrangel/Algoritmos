#include <iostream>
using namespace std;

// Sub-rotina que conta os elementos positivos nas linhas ímpares
int contarPositivosLinhasImpares(int matriz[10][10]) {
    int contador = 0;

    // Percorrendo as linhas ímpares da matriz (índices 1, 3, 5, ...)
    for (int i = 1; i < 10; i += 2) {  // Começando em 1 e avançando de 2 em 2
        for (int j = 0; j < 10; ++j) {
            if (matriz[i][j] > 0) {  // Verifica se o elemento é positivo
                contador++;  // Incrementa o contador
            }
        }
    }

    return contador;  // Retorna a quantidade de elementos positivos
}

int main() {
    // Exemplo de matriz 50x50
    int matriz[10][10];

    // Preenchendo a matriz com valores de exemplo
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << "Digite o valor para matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Chamando a sub-rotina e exibindo o resultado
    int quantidadePositivos = contarPositivosLinhasImpares(matriz);
    cout << "\nQuantidade de elementos positivos nas linhas ímpares: " << quantidadePositivos << endl;

    return 0;
}
