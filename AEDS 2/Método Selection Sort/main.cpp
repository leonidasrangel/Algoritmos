#include <iostream>
using namespace std;

// Função que realiza o algoritmo de ordenação Selection Sort
void selectionSort(int arr[], int tamanho) {
    // Percorre cada elemento do array, exceto o último
    for (int i = 0; i < tamanho - 1; i++) {
        // Define o índice do menor elemento como o índice atual i
        int minIndex = i;

        // Percorre o restante do array para encontrar o menor elemento
        for (int j = i + 1; j < tamanho; j++) {
            // Se encontrar um elemento menor que o atual "minIndex", atualiza o "minIndex"
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Se o menor elemento não for o atual, troca os elementos
        if (minIndex != i) {
            // Realiza a troca de valores usando uma variável temporária
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    // Exemplo de array para ordenar
    int arr[] = {5, 3, 4, 1, 2};
    int tamanho = sizeof(arr) / sizeof(arr[0]); // Cálculo do número de elementos do array. 

    // Exibe o array antes da ordenação
    cout << "Array antes da ordenacao: ";
    for (int i = 0; i < tamanho; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Chama a função de ordenação
    selectionSort(arr, tamanho);

    // Exibe o array depois da ordenação
    cout << "Array depois da ordenacao: ";
    for (int i = 0; i < tamanho; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
