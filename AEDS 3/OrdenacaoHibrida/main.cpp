#include <iostream> 
using namespace std; 

void ordenacaoHibrida(int vetor[], int n) {
    int inicio = 0, fim = n - 1; // Define os índices de início (0) e fim (n-1) do vetor

    while (inicio < fim) { // Loop enquanto o índice de início for menor que o de fim
        // Parte do Selection Sort: encontra o menor elemento no intervalo [inicio, fim]
        int minIndex = inicio; // Assume que o menor elemento está no índice de início
        for (int j = inicio + 1; j <= fim; j++) { // Percorre o vetor do próximo elemento até o fim
            if (vetor[j] < vetor[minIndex]) { // Se o elemento atual for menor que o menor conhecido
                minIndex = j; // Atualiza o índice do menor elemento
            }
        }
        if (minIndex != inicio) { // Se o menor elemento não está no início
            swap(vetor[inicio], vetor[minIndex]); // Troca o elemento do início com o menor encontrado
        }

        // Parte do Bubble Sort: empurra o maior elemento para o final do intervalo
        for (int j = inicio; j < fim; j++) { // Percorre o vetor do início até o penúltimo elemento do intervalo
            if (vetor[j] > vetor[j + 1]) { // Se o elemento atual for maior que o próximo
                swap(vetor[j], vetor[j + 1]); // Troca os elementos para colocar o maior à direita
            }
        }

        // Atualiza os limites do intervalo
        inicio++; // Incrementa o início, pois o menor elemento já está posicionado
        fim--; // Decrementa o fim, pois o maior elemento já está posicionado
    }
}

// Função auxiliar para imprimir o vetor
void imprimirVetor(int vetor[], int n) { // Recebe o vetor e seu tamanho
    for (int i = 0; i < n; i++) { // Loop para percorrer todos os elementos do vetor
        cout << vetor[i] << " "; // Imprime cada elemento 
    }
    cout << endl; 
}

int main() {
    int vetor[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(vetor) / sizeof(vetor[0]); // Calcula o tamanho do vetor (número de elementos)

    cout << "Vetor original: "; 
    imprimirVetor(vetor, n);

    ordenacaoHibrida(vetor, n); 

    cout << "Vetor ordenado: "; 
    imprimirVetor(vetor, n); 

    return 0;
}