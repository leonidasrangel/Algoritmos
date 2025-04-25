#include <iostream>

using namespace std;

// Definindo a struct Vetor
struct Vetor {
    float x, y, z;

    // Método para calcular o produto escalar entre dois vetores
    float produtoEscalar(const Vetor& v) const {
        return (x * v.x) + (y * v.y) + (z * v.z);
    }
};

int main() {
    Vetor v1, v2;

    // Solicita as coordenadas do primeiro vetor
    cout << "Digite as coordenadas do vetor v1 (x, y, z):" << endl;
    cin >> v1.x >> v1.y >> v1.z;

    // Solicita as coordenadas do segundo vetor
    cout << "Digite as coordenadas do vetor v2 (x, y, z):" << endl;
    cin >> v2.x >> v2.y >> v2.z;

    // Calcula e exibe o produto escalar
    float resultado = v1.produtoEscalar(v2);
    cout << "O produto escalar entre v1 e v2 é: " << resultado << endl;

    return 0;
}
