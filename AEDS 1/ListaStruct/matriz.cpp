#include <iostream>
using namespace std;
// Função para criar uma matriz dinâmica
float** criarMatriz(int linhas, int colunas) {
    // Aloca o array de ponteiros para as linhas
    float** matriz = new float*[linhas];   
    // Aloca o array para cada linha
    for (int i = 0; i < linhas; ++i) {
        matriz[i] = new float[colunas];
    }   
    return matriz;
}
// Função para preencher a matriz com valores
void preencherMatriz(float** matriz, int linhas, int colunas) {
    cout << "Digite os valores da matriz:" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}
// Função para imprimir a matriz
void imprimirMatriz(float** matriz, int linhas, int colunas) {
    cout << "Matriz:" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int linhas, colunas;
    cout << "Digite o número de linhas: ";
    cin >> linhas;
    cout << "Digite o número de colunas: ";
    cin >> colunas;
    float** matriz = criarMatriz(linhas, colunas);
    preencherMatriz(matriz, linhas, colunas);
    imprimirMatriz(matriz, linhas, colunas);
    return 0;
}
