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
    double distancia = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    cout << "Distância entre (" << p1.x << ", " << p1.y << ") e ("
         << p2.x << ", " << p2.y << ") é: " << distancia << endl;
    return distancia;
}

// Sub-rotina para calcular e imprimir o perímetro de um quadrilátero
void calcularPerimetro(Quadrilatero quad) {
    double perimetro = 0;
    double ladoAB = calcularDistancia(quad.A, quad.B);
    double ladoBC = calcularDistancia(quad.B, quad.C);
    double ladoCD = calcularDistancia(quad.C, quad.D);
    double ladoDA = calcularDistancia(quad.D, quad.A);
    
    perimetro = ladoAB + ladoBC + ladoCD + ladoDA;
    cout << "Perímetro do quadrilátero: " << perimetro << endl;
}

// Sub-rotina para calcular o maior lado de um quadrilátero
double calcularMaiorLado(Quadrilatero quad) {
    double ladoAB = calcularDistancia(quad.A, quad.B);
    double ladoBC = calcularDistancia(quad.B, quad.C);
    double ladoCD = calcularDistancia(quad.C, quad.D);
    double ladoDA = calcularDistancia(quad.D, quad.A);
    
    double maiorLado = max(max(ladoAB, ladoBC), max(ladoCD, ladoDA));
    cout << "Maior lado do quadrilátero: " << maiorLado << endl;
    
    return maiorLado;
}

// Sub-rotina que imprime o maior lado entre dois quadriláteros
void maiorLadoEntreQuadrilateros(Quadrilatero quad1, Quadrilatero quad2) {
    double maiorLado1 = calcularMaiorLado(quad1);
    double maiorLado2 = calcularMaiorLado(quad2);
    
    double maiorLado = max(maiorLado1, maiorLado2);
    cout << "Maior lado entre os dois quadriláteros: " << maiorLado << endl;
}

int main() {
    // Definindo o primeiro quadrilátero
    Quadrilatero quad1 = {
        {3, 3}, {5, 2}, {0, 1}, {5, 0}
    };

    // Definindo o segundo quadrilátero
    Quadrilatero quad2 = {
        {4, 4}, {5, 2}, {0, 0}, {5, 0}
    };

    // Calcula e exibe o perímetro do primeiro quadrilátero
    cout << "Perímetro do primeiro quadrilátero:" << endl;
    calcularPerimetro(quad1);

    // Calcula e exibe o perímetro do segundo quadrilátero
    cout << "Perímetro do segundo quadrilátero:" << endl;
    calcularPerimetro(quad2);

    // Calcula e exibe o maior lado entre os dois quadriláteros
    maiorLadoEntreQuadrilateros(quad1, quad2);

    return 0;
}
