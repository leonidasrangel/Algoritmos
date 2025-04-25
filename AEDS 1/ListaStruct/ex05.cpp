#include <iostream>
#include <cmath> // Para a função M_PI, que fornece o valor de pi

using namespace std;

// Definindo a struct Circulo
struct Circulo {
    float raio;
};

// Função para calcular a área do círculo
float calcularArea(const Circulo &c) {
    return M_PI * c.raio * c.raio;
}

// Função para calcular o perímetro do círculo
float calcularPerimetro(const Circulo &c) {
    return 2 * M_PI * c.raio;
}

int main() {
    Circulo circulo;
    
    cout << "Digite o raio do círculo: ";
    cin >> circulo.raio;
    
    float area = calcularArea(circulo);
    float perimetro = calcularPerimetro(circulo);
    
    cout << "Área do círculo: " << area << endl;
    cout << "Perímetro do círculo: " << perimetro << endl;
    
    return 0;
}
