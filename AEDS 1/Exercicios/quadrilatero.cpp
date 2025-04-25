#include <iostream>
#include <cmath>
using namespace std;

// Estrutura Ponto2D
struct Ponto2D {
    double x;
    double y;
};

// Estrutura Quadrilatero
struct Quadrilatero {
    Ponto2D A;
    Ponto2D B;
    Ponto2D C;
    Ponto2D D;
};

// Função que calcula a distância entre dois pontos
double calcularDistancia(Ponto2D p1, Ponto2D p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Função que calcula o perímetro do quadrilátero
void calcularPerimetro(Quadrilatero q) {
    double AB = calcularDistancia(q.A, q.B);
    double BC = calcularDistancia(q.B, q.C);
    double CD = calcularDistancia(q.C, q.D);
    double DA = calcularDistancia(q.D, q.A);
    
    double perimetro = AB + BC + CD + DA;
    cout << "Perímetro: " << perimetro << endl;
}

// Função que retorna o maior lado do quadrilátero
double maiorLado(Quadrilatero q) {
    double AB = calcularDistancia(q.A, q.B);
    double BC = calcularDistancia(q.B, q.C);
    double CD = calcularDistancia(q.C, q.D);
    double DA = calcularDistancia(q.D, q.A);
    
    return max(max(AB, BC), max(CD, DA));
}

// Função que imprime o maior lado entre dois quadriláteros
void maiorLadoEntreQuadrilateros(Quadrilatero q1, Quadrilatero q2) {
    double maiorQ1 = maiorLado(q1);
    double maiorQ2 = maiorLado(q2);
    
    cout << "Maior lado entre os dois quadriláteros: " << max(maiorQ1, maiorQ2) << endl;
}

int main() {
    // Pontos do primeiro quadrilátero
    Quadrilatero q1 = {{3, 3}, {5, 2}, {0, 1}, {5, 0}};
    
    // Pontos do segundo quadrilátero
    Quadrilatero q2 = {{4, 4}, {5, 2}, {0, 0}, {5, 0}};
    
    // Chama a função que imprime o maior lado entre os dois quadriláteros
    maiorLadoEntreQuadrilateros(q1, q2);
    
    return 0;
}
