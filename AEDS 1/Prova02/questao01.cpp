/*Indique a saída impressa  pelo programa a seguir. Procure escrever
a saída da forma mais idêntica possível à que seria impressa na tela do computador.*/
#include<iostream> 
using namespace std;

int func(int vet[], int a, int b){
    int i, x = vet[b];
    if( x <= 1)
    return 0;

    for (i = 1; vet[a] > x; i++){
        cout << "i=" << i << "=" << x << endl;
        x = x * vet[b];
    }
    cout << "i=" << i << "=" << x << endl;
    return i;
}
int main(){
    int r,v[5] = {3, 7, 1, 9, 2};

    cout << "Resultado 1: ";
    r = func (v, 1, 4);
    cout << r << "\nResultado 2: ";
    r = func (v, 4, 2);
    cout << r << endl;
    return 0;
}

/*
1. Declaração do vetor 'v' e chamada da função func:
int r, v[5] = {3, 7, 1, 9, 2};

2. Primeira chamada de função func(v, 1, 4):
a = 1, b = 4
x = vet[b] = vet[4] = 2
vet[a] = vet[1] = 7
Como x <= 1 é false, não retorna 0. Vai para o loop:
for (i = 1; vet[a] > x; i++) {
    cout << "i=" << i << "=" << x << endl;
    x = x * vet[b];
}
Iteração 1:
i = 1, x = 2, vet[a] = 7
Imprime: i=1=2
x = 2 * 2 = 4

Iteração 2:
i = 2, x = 4, vet[a] = 7
Imprime: i=2=4
x = 4 * 2 = 8

Iteração 3:
i = 3, x = 8, vet[a] = 7
Condição vet[a] > x (7 > 8) é false
Imprime: i=3=8
Retorna i = 3.

3. Segunda chamada de função func(v, 4, 2):

a = 4, b = 2
x = vet[b] = vet[2] = 1
vet[a] = vet[4] = 2
Como x <= 1 é true, retorna 0 sem imprimir nada.

Saída do programa:
Resultado 1: i=1=2
i=2=4
i=3=8
3
Resultado 2: 0


*/