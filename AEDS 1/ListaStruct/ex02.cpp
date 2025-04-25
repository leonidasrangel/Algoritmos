#include <iostream>

using namespace std;

// Definindo a struct Retangulo
struct Retangulo {
    float largura;
    float altura;
};

// Função para calcular a área do retângulo
float calcularArea(Retangulo &r) {
    return r.largura * r.altura;
}

// Função para calcular o perímetro do retângulo
float calcularPerimetro(Retangulo &r) {
    return 2 * (r.largura + r.altura);
}

int main() {
    Retangulo retangulo;
    
    cout << "Digite a largura do retângulo: ";
    cin >> retangulo.largura;
    
    cout << "Digite a altura do retângulo: ";
    cin >> retangulo.altura;
    
    float area = calcularArea(retangulo);
    float perimetro = calcularPerimetro(retangulo);
    
    cout << "Área do retângulo: " << area << endl;
    cout << "Perímetro do retângulo: " << perimetro << endl;
    
    return 0;
}
