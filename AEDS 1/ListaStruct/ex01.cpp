#include <iostream>

using namespace std;

// Definindo a struct Pessoa
struct Pessoa {
    char nome[100];
    int idade;
    float altura;
};

// Função para preencher os dados de uma pessoa
void preencherPessoa(Pessoa &p) {
    cout << "Digite o nome: ";
    cin >> p.nome; // Leitura do nome com cin

    cout << "Digite a idade: ";
    cin >> p.idade;
    
    cout << "Digite a altura (em metros): ";
    cin >> p.altura;
}

// Função para exibir os dados de uma pessoa
void exibirPessoa(const Pessoa &p) {
    cout << "Nome: " << p.nome << endl;
    cout << "Idade: " << p.idade << endl;
    cout << "Altura: " << p.altura << " metros" << endl;
}

int main() {
    Pessoa pessoa;
    
    preencherPessoa(pessoa);
    exibirPessoa(pessoa);
    
    return 0;
}
