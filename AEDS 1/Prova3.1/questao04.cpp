#include <iostream>
#include <cmath>
using namespace std;

// Estrutura para armazenar um ponto 2D
struct Ponto2D {
    double x; // Coordenada x
    double y; // Coordenada y
};

// Estrutura para armazenar um quadrilátero
struct Quadrilatero {
    Ponto2D A, B, C, D; // Quatro pontos do quadrilátero
};

// Sub-rotina para calcular a distância entre dois pontos
double calcularDistancia(Ponto2D p1, Ponto2D p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); // Pitágoras
}

// Sub-rotina para calcular e imprimir o perímetro de um quadrilátero
void calcularPerimetro(Quadrilatero quad) {
    double perimetro = 0;
    perimetro += calcularDistancia(quad.A, quad.B);
    perimetro += calcularDistancia(quad.B, quad.C);
    perimetro += calcularDistancia(quad.C, quad.D);
    perimetro += calcularDistancia(quad.D, quad.A);
    cout << "Perímetro do quadrilátero: " << perimetro << endl;
}

// Sub-rotina para calcular o maior lado de um quadrilátero
double calcularMaiorLado(Quadrilatero quad) {
    double maiorLado = 0;
    
    // Calcula todas as distâncias entre os pontos do quadrilátero
    double ladoAB = calcularDistancia(quad.A, quad.B);
    double ladoBC = calcularDistancia(quad.B, quad.C);
    double ladoCD = calcularDistancia(quad.C, quad.D);
    double ladoDA = calcularDistancia(quad.D, quad.A);
    
    // Encontra o maior lado
    maiorLado = max(max(ladoAB, ladoBC), max(ladoCD, ladoDA));
    
    return maiorLado;
}

// Sub-rotina que imprime o maior lado entre dois quadriláteros
void maiorLadoEntreQuadrilateros(Quadrilatero quad1, Quadrilatero quad2) {
    double maiorLado1 = calcularMaiorLado(quad1);
    double maiorLado2 = calcularMaiorLado(quad2);
    
    // Compara os maiores lados de ambos os quadriláteros
    double maiorLado = max(maiorLado1, maiorLado2);
    
    cout << "Maior lado entre os dois quadriláteros: " << maiorLado << endl;
}

// Sub-rotina para inserir os valores dos pontos do quadrilátero
void inserirPontos(Quadrilatero &quad) {
    cout << "Digite as coordenadas de A (x y): ";
    cin >> quad.A.x >> quad.A.y;

    cout << "Digite as coordenadas de B (x y): ";
    cin >> quad.B.x >> quad.B.y;

    cout << "Digite as coordenadas de C (x y): ";
    cin >> quad.C.x >> quad.C.y;

    cout << "Digite as coordenadas de D (x y): ";
    cin >> quad.D.x >> quad.D.y;
}

int main() {
    // Definindo o primeiro quadrilátero
    Quadrilatero quad1;
    cout << "Insira os valores dos pontos do primeiro quadrilátero:\n";
    inserirPontos(quad1);

    // Definindo o segundo quadrilátero
    Quadrilatero quad2;
    cout << "Insira os valores dos pontos do segundo quadrilátero:\n";
    inserirPontos(quad2);

    // Calcula e exibe o maior lado entre os dois quadriláteros
    maiorLadoEntreQuadrilateros(quad1, quad2);

    return 0;
}
