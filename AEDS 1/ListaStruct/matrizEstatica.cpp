#include <iostream>

using namespace std;

// Função para preencher uma matriz estática 3x3 com valores
void preencherMatriz(int matriz[3][3]) {
    cout << "Digite os valores da matriz 3x3:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

// Função para imprimir uma matriz estática 3x3
void imprimirMatriz(const int matriz[3][3]) {
    cout << "Matriz 3x3:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriz[3][3]; // Matriz estática 3x3

    // Preenche e imprime a matriz
    preencherMatriz(matriz);
    imprimirMatriz(matriz);

    return 0;
}
