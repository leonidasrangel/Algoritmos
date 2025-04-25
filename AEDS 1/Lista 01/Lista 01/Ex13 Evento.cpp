#include <iostream>
using namespace std;

void evento (int totalSegundos, int &horas, int &minutos, int &segundos){
    horas = totalSegundos / 3600;
    totalSegundos %= 3600;
    minutos = totalSegundos / 60;
    segundos = totalSegundos % 60;
}

int main (){
    int totalSegundos;
    int horas,minutos,segundos;
    cout << "Digite o tempo do evento em segundos: ";
    cin >> totalSegundos;

    evento (totalSegundos,horas,minutos,segundos);
    cout << "O tempo do evento em horas: " << horas << " Minutos:" << minutos << " Segundos:" << segundos;
    return 0;
}
