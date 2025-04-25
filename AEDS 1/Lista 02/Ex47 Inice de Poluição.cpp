#include <iostream>
using namespace std;

void poluicao (float valor){
    if (valor >= 0.5){
        cout <<"Crítica e declarada, todas as indústrias dos 3 grupos foram notificadas para parar suas atividades";
    } else if (valor >= 0.4){
        cout <<"As indústrias pertencentes tanto ao primeiro quanto ao segundo grupo receberam um aviso para interromper suas operações";
    } else if (valor >= 0.3){
        cout << "Um alerta para as indústrias do primeiro grupo foi enviada para suspenderem imediatamente suas atividades";
    } else {
        cout <<"Nenhuma notificacao precisou ser enviada";
    }
}

int main (){
    float valor = 0;
    cout << "Digite o indice de poluicao:";
    cin >> valor;

    poluicao(valor);
    return 0;
}