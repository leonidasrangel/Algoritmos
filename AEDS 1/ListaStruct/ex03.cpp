#include <iostream>
#include <string>

using namespace std;

// Definindo a struct Aluno
struct Aluno {
    int matricula;
    string nome;
    float notas[5]; // Supondo que o aluno tenha até 5 notas
};

// Função para preencher as notas de um aluno
void preencherNotas(Aluno &a) {
    cout << "Digite o nome do aluno: ";
    cin >> a.nome; // Leitura do nome

    cout << "Digite a matrícula do aluno: ";
    cin >> a.matricula; // Leitura da matrícula
    
    cout << "Digite as notas do aluno: " << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Nota " << (i + 1) << ": ";
        cin >> a.notas[i]; // Leitura das notas
    }
}

// Função para calcular a média das notas
float calcularMedia(const Aluno &a) {
    float soma = 0;
    for (int i = 0; i < 5; ++i) {
        soma += a.notas[i];
    }
    return soma / 5;
}

int main() {
    Aluno aluno;
    
    preencherNotas(aluno);
    
    float media = calcularMedia(aluno);
    
    cout << "Nome do aluno: " << aluno.nome << endl;
    cout << "Matrícula do aluno: " << aluno.matricula << endl;
    cout << "Média das notas: " << media << endl;
    
    return 0;
}
