#include <iostream>
using namespace std;

void ordenarCrescente(float &a, float &b, float &c) {
    if (a > b) {
        float temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        float temp = a;
        a = c;
        c = temp;
    }
    if (b > c) {
        float temp = b;
        b = c;
        c = temp;
    }
}

void ordenarDecrescente(float &a, float &b, float &c) {
    if (a < b) {
        float temp = a;
        a = b;
        b = temp;
    }
    if (a < c) {
        float temp = a;
        a = c;
        c = temp;
    }
    if (b < c) {
        float temp = b;
        b = c;
        c = temp;
    }
}

void colocarMaiorNoMeio(float &a, float &b, float &c) {
    if (a > b) {
        float temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        float temp = a;
        a = c;
        c = temp;
    }
    if (b > c) {
        float temp = b;
        b = c;
        c = temp;
    }
}

int main() {
    int i;
    float a, b, c;

    cout << "Digite o valor de i: ";
    cin >> i;
    cout << "Digite os valores de a, b, c: ";
    cin >> a >> b >> c;

    if (i == 1) {
        ordenarCrescente(a, b, c);
        cout << "Valores em ordem crescente: " << a << ", " << b << ", " << c << endl;
    } else if (i == 2) {
        ordenarDecrescente(a, b, c);
        cout << "Valores em ordem decrescente: " << a << ", " << b << ", " << c << endl;
    } else if (i == 3) {
        colocarMaiorNoMeio(a, b, c);
        cout << "Valores com o maior no meio: " << a << ", " << b << ", " << c << endl;
    } else {
        cout << "Valor de i inválido." << endl;
    }
    return 0;
}
