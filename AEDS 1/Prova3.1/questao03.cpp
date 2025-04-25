#include <iostream>
using namespace std;

// Sub-rotina que conta os elementos positivos nas linhas ímpares
int contarPositivosLinhasImpares(int** matriz, int linhas, int colunas) {
    int contador = 0;

    // Percorrendo as linhas ímpares da matriz (índices 1, 3, 5, ...)
    for (int i = 1; i < linhas; i += 2) {  // Começando em 1 e avançando de 2 em 2
        for (int j = 0; j < colunas; ++j) {
            if (matriz[i][j] > 0) {  // Verifica se o elemento é positivo
                contador++;  // Incrementa o contador
            }
        }
    }

    return contador;  // Retorna a quantidade de elementos positivos
}

int main() {
    int linhas, colunas;

    // Solicita o tamanho da matriz ao usuário
    cout << "Digite o número de linhas da matriz: ";
    cin >> linhas;
    cout << "Digite o número de colunas da matriz: ";
    cin >> colunas;

    // Alocação dinâmica da matriz
    int** matriz = new int*[linhas];
    for (int i = 0; i < linhas; ++i) {
        matriz[i] = new int[colunas];
    }

    // Preenchendo a matriz com valores de exemplo
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cout << "Digite o valor para matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Chamando a sub-rotina e exibindo o resultado
    int quantidadePositivos = contarPositivosLinhasImpares(matriz, linhas, colunas);
    cout << "\nQuantidade de elementos positivos nas linhas ímpares: " << quantidadePositivos << endl;

    // Liberando a memória alocada
    for (int i = 0; i < linhas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
