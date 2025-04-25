/*Questão 1 (5 pontos)
a) Crie uma estrutura chamada Filme com os seguintes dados: título, gênero e valor diário da locação.

b) Crie uma estrutura chamada Cliente com os seguintes dados: código do cliente (inteiro), nome e endereço 
(endereço pode ser representado por um único vetor de char).

c) Depois, crie uma estrutura chamada Locacao contendo um cliente, um vetor de filmes (no máximo 5), o número de dias em atraso e o valor total da locação. 
Nesta estrutura, você deve usar as estruturas definidas em a) e b).*/

#include <iostream>
using namespace std;

// Estrutura Filme
struct Filme {
    char titulo[100];    // Armazena o título do filme
    char genero[50];     // Armazena o gênero do filme
    float valor_diario;  // Armazena o valor diário de locação do filme
};

// Estrutura Cliente
struct Cliente {
    int codigo;          // Código do cliente
    char nome[100];      // Nome do cliente
    char endereco[200];  // Endereço do cliente
};

// Estrutura Locação
struct Locacao {
    Cliente cliente;        // Contém os dados do cliente (do tipo Cliente)
    Filme filmes[5];        // Vetor que pode armazenar até 5 filmes (do tipo Filme)
    int dias_atraso;        // Número de dias que a locação está em atraso
    float valor_total;      // Valor total da locação, incluindo dias de atraso
};

int main() {
    Locacao locacao;  // Criando uma variável do tipo Locacao

    // Coletando os dados do cliente
    cout << "Digite o código do cliente: ";
    cin >> locacao.cliente.codigo;
    //cin.ignore();  // Limpa o buffer após a leitura de um número

    cout << "Digite o nome do cliente: ";
    cin.getline(locacao.cliente.nome, 100);  // Captura o nome do cliente

    cout << "Digite o endereço do cliente: ";
    cin.getline(locacao.cliente.endereco, 200);  // Captura o endereço do cliente

    // Coletando os dados dos filmes
    for (int i = 0; i < 5; ++i) {
        cout << "\nDigite o título do filme " << i + 1 << ": ";
        cin.getline(locacao.filmes[i].titulo, 100);  // Captura o título do filme

        cout << "Digite o gênero do filme " << i + 1 << ": ";
        cin.getline(locacao.filmes[i].genero, 50);  // Captura o gênero do filme

        cout << "Digite o valor diário da locação do filme " << i + 1 << ": ";
        cin >> locacao.filmes[i].valor_diario;
        //cin.ignore();  // Limpa o buffer após a leitura de um número
    }

    // Coletando o número de dias de atraso
    cout << "\nDigite o número de dias em atraso: ";
    cin >> locacao.dias_atraso;

    // Calculando o valor total da locação
    locacao.valor_total = 0;  // Inicializa o valor total como zero
    for (int i = 0; i < 5; ++i) {
        locacao.valor_total += locacao.filmes[i].valor_diario * (locacao.dias_atraso + 1);
    }

    // Exibindo o valor total da locação
    cout << "\nValor total da locação: " << locacao.valor_total << " reais" << endl;

    return 0;  // Fim do programa
}
