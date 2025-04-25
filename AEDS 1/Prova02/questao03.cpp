/*Crie uma sub-rotina que receba como parâmetros dois vetores de números reais e seus tamanhos
(assuma que dois vetores podem ter tamanhos diferentes). Divida por 2 todos os elementos do primeiro
vetor. Depois, calcule a média do segundo vetor. Divida os novos valores do primeiro vetor pela média
já calculada do segundo (perceba que estamos continuamente substituindo os valores do primeiro vetor).
Imprima os elementos do primeiro vetor que possuem valores maiores que média calculada anteriormente.*/

#include <iostream>
#include <vector>
using namespace std;

void processarVetores(vector<double>& vetor1, const vector<double>& vetor2) {
    int tamanho1 = vetor1.size();
    int tamanho2 = vetor2.size();

    // Dividir todos os elementos do primeiro vetor por 2
    for(int i = 0; i < tamanho1; i++) {
        vetor1[i] /= 2;
    }

    // Calcular a média do segundo vetor
    double soma2 = 0;
    for(int i = 0; i < tamanho2; i++) {
        soma2 += vetor2[i];
    }
    double media2 = soma2 / tamanho2;

    // Dividir os novos valores do primeiro vetor pela média do segundo vetor
    for(int i = 0; i < tamanho1; i++) {
        vetor1[i] /= media2;
    }

    // Imprimir os elementos do primeiro vetor que são maiores que a média calculada
    cout << "Elementos do primeiro vetor maiores que a média do segundo vetor (" << media2 << "). ";
    for(int i = 0; i < tamanho1; i++) {
        if(vetor1[i] > media2) {
            cout << vetor1[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    // Vetores de exemplo
    vector<double> vetor1 = {4.0, 8.0, 6.0, 10.0};
    vector<double> vetor2 = {3.0, 5.0, 7.0, 9.0, 11.0};

    // Chama a sub-rotina passando os vetores
    processarVetores(vetor1, vetor2);

    return 0;
}
