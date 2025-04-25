#include <iostream>
#include <cmath>

using namespace std;

struct Ponto2D {
    double x;
    double y;
    
};

double calcularDistancia(Ponto2D& p1, Ponto2D& p2) {
        double distanciaX = p1.x - p2.x;
        double distanciaY = p1.y - p2.y;
        return sqrt(distanciaX * distanciaX + distanciaY * distanciaY);
    }


int main() {
    Ponto2D ponto1;
    ponto1.x = 2.5;
    ponto1.y = 1.0;

    Ponto2D ponto2;
    ponto2.x = 5.0;
    ponto2.y = 3.0;

    double distancia = calcularDistancia(ponto1, ponto2);
    cout << "A distância entre os pontos é: " << distancia << endl;

    return 0;
}