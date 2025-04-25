/*Crie uma sub-rotina que receba como parâmetros dois valores de números reais (valores e percentuais)
e seu tamanho (assuma que os dois vetores têm o mesmo tamanho). A sub-rotina deve inicialmente imprimir
a soma dos elementos do vetor valores. Depois, cada posição do vetor percentuais deve receber a razão
entre o elemento de mesma posição no vetor valores e a soma calculada. Por fim, o procedimento deve 
imprimir quantos elementos do vetor percentuais tem valor superior a um décimo.*/

#include <iostream>
#include <vector>
using namespace std;

void calculaPercentuais(const vector<double>& valores, vector<double>& percentuais, int tamanho) {
    // Calcula a soma dos elementos do vetor valores
    double soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += valores[i];
    }

    // Imprime a soma dos elementos do vetor valores
    cout << "Soma dos elementos do vetor valores: " << soma << endl;

    // Atualiza o vetor percentuais com a razão entre cada elemento de valores e a soma calculada
    for(int i = 0; i < tamanho; i++) {
        percentuais[i] = valores[i] / soma;
    }

    // Conta e imprime quantos elementos do vetor percentuais são superiores a um décimo
    int contador = 0;
    for(int i = 0; i < tamanho; i++) {
        if(percentuais[i] > 0.1) {
            contador++;
        }
    }

    cout << "Quantidade de elementos do vetor percentuais superiores a um décimo: " << contador << endl;
}

int main() {
    // Vetores de exemplo
    vector<double> valores = {2.0, 5.0, 3.0, 7.0, 8.0};
    vector<double> percentuais(valores.size());

    // Chama a sub-rotina passando os vetores e seu tamanho
    calculaPercentuais(valores, percentuais, valores.size());

    // Imprime o vetor percentuais atualizado
    cout << "Vetor percentuais atualizado: ";
    for(double p : percentuais) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
