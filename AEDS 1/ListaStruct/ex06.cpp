#include <iostream>
#include <string>

using namespace std;

struct Livro {
    string titulo;
    string autor;
    int anoPublicacao;    
};

void exibirInformacoes(Livro &livro) {
        cout << "Livro: " << livro.titulo << endl;
        cout << "Autor: " << livro.autor << endl;
        cout << "Ano de Publicação: " << livro.anoPublicacao << endl;
}

int main() {
    Livro livro;
    livro.titulo = "Dom Casmurro";
    livro.autor = "Machado de Assis";
    livro.anoPublicacao = 1899;

    exibirInformacoes(livro);

    return 0;
}