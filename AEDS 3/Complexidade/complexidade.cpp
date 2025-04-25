//Complexidade

#include <iostream>
using namespace std;

int maiorSomaSubvetor(int sales_data[], int n) {
    int maior_soma = sales_data[0];

    for (int i = 0; i < n; i++) { // Início do subvetor
        for (int j = i; j < n; j++) { // Fim do subvetor
            int soma_atual = 0;
            for (int k = i; k <= j; k++) { // Soma do subvetor de i até j
                soma_atual += sales_data[k];
            }

            if (soma_atual > maior_soma) {
                maior_soma = soma_atual;
            }
        }
    }

    return maior_soma;
}

int main() {
    int vendas[] = {4, -5, 8, -4, 3, 4};
    int tamanho = sizeof(vendas) / sizeof(vendas[0]);

    int resultado = maiorSomaSubvetor(vendas, tamanho);
    cout << "Maior soma de subvetor: " << resultado << endl;

    return 0;
}
