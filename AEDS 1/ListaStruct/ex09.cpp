#include <iostream>
#include <cmath> // Para a função sqrt
using namespace std;
// Definindo a struct Triangulo
struct Triangulo {
    // Estrutura para armazenar um ponto
    struct Ponto {
        float x;
        float y;
    } A, B, C;

    // Método para calcular a área do triângulo
    float calcularArea() const {
        // Fórmula da área do triângulo usando a fórmula determinante
        return fabs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
    }
};
int main() {
    Triangulo tri;
    // Solicita as coordenadas dos pontos
    cout << "Digite as coordenadas do ponto A:" << endl;
    cout << "x: ";
    cin >> tri.A.x;
    cout << "y: ";
    cin >> tri.A.y;

    cout << "Digite as coordenadas do ponto B:" << endl;
    cout << "x: ";
    cin >> tri.B.x;
    cout << "y: ";
    cin >> tri.B.y;

    cout << "Digite as coordenadas do ponto C:" << endl;
    cout << "x: ";
    cin >> tri.C.x;
    cout << "y: ";
    cin >> tri.C.y;

    // Calcula e exibe a área do triângulo
    float area = tri.calcularArea();
    cout << "A área do triângulo é: " << area << endl;

    return 0;
}
