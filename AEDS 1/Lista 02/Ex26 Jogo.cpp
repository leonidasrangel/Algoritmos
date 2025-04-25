#include <iostream>
using namespace std;

int tempoDeJogo(int inicio, int fim){       
    if(fim > inicio) {
        return fim - inicio;
    }else{
        int tantoQueFalta = 24 - inicio;
        return tantoQueFalta + fim;
    }    
}

int main(){
    float inicio = 0, fim = 0;

    cout << "Informe o horario que o jogo comecou: ";
    cin >> inicio;
    cout << "Informe o horario que o jogo acabou: ";
    cin >> fim;
    
    cout << "O jogo durou: " << tempoDeJogo(inicio, fim) <<"h";
    return 0;
}