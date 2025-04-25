#include <iostream>
#include <cmath>
using namespace std;

// Estrutura para armazenar as coordenadas de um ponto 2D
struct Ponto2D {
    float x, y;

    // Construtor para facilitar a inicialização
    Ponto2D(float _x = 0, float _y = 0) {
        x = _x;
        y = _y;
    }
};

// Estrutura para representar um quadrilátero usando quatro pontos
struct Quadrilatero {
    Ponto2D A, B, C, D;

    // Construtor para facilitar a inicialização
    Quadrilatero(Ponto2D _A, Ponto2D _B, Ponto2D _C, Ponto2D _D) {
        A = _A;
        B = _B;
        C = _C;
        D = _D;
    }
};

// Sub-rotina que calcula a distância entre dois pontos 2D
float calcularDistancia(Ponto2D p1, Ponto2D p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Sub-rotina que calcula e imprime o perímetro de um quadrilátero
void calcularPerimetro(Quadrilatero quad) {
    float perimetro = calcularDistancia(quad.A, quad.B) +
                      calcularDistancia(quad.B, quad.C) +
                      calcularDistancia(quad.C, quad.D) +
                      calcularDistancia(quad.D, quad.A);
    cout << "Perimetro do quadrilatero: " << perimetro << endl;
}

// Sub-rotina que retorna o valor do maior lado de um quadrilátero
float maiorLado(Quadrilatero quad) {
    float ladoAB = calcularDistancia(quad.A, quad.B);
    float ladoBC = calcularDistancia(quad.B, quad.C);
    float ladoCD = calcularDistancia(quad.C, quad.D);
    float ladoDA = calcularDistancia(quad.D, quad.A);

    // Retorna o maior dos quatro lados
    return max(max(ladoAB, ladoBC), max(ladoCD, ladoDA));
}

// Sub-rotina que recebe dois quadriláteros e imprime o maior lado entre eles
void maiorLadoEntreQuadrilateros(Quadrilatero quad1, Quadrilatero quad2) {
    float maiorLadoQuad1 = maiorLado(quad1);
    float maiorLadoQuad2 = maiorLado(quad2);
    float maiorLadoEntreAmbos = max(maiorLadoQuad1, maiorLadoQuad2);

    cout << "O maior lado entre os dois quadrilateros e: " << maiorLadoEntreAmbos << endl;
}

int main() {
    // Definição dos pontos do primeiro quadrilátero
    Ponto2D A1(3, 3), B1(5, 2), C1(0, 1), D1(5, 0);
    Quadrilatero quad1(A1, B1, C1, D1);

    // Definição dos pontos do segundo quadrilátero
    Ponto2D A2(4, 4), B2(5, 2), C2(0, 0), D2(5, 0);
    Quadrilatero quad2(A2, B2, C2, D2);

    // Calcula e exibe o perímetro dos quadriláteros
    cout << "Para o primeiro quadrilatero:" << endl;
    calcularPerimetro(quad1);

    cout << "Para o segundo quadrilatero:" << endl;
    calcularPerimetro(quad2);
    
    // Chama a sub-rotina para encontrar o maior lado entre os dois quadriláteros
    maiorLadoEntreQuadrilateros(quad1, quad2);

    return 0;
}