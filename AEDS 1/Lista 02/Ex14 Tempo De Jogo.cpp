#include <iostream>
using namespace std;

int calcularDuracao (int horaInicio, int horaFim) {
    if (horaFim >= horaInicio) {
        return horaFim - horaInicio;
    } else {
        return (24 - horaInicio) + horaFim;
    }
}

int main() {
    int horaInicio, horaFim;
    
    cout << "Digite a hora de início do jogo (0-23): ";
    cin >> horaInicio;
    
    if (horaInicio < 0 || horaInicio >= 24) {
        cout << "Hora de início inválida." << endl;
        return 1;
    }
    
    cout << "Digite a hora de fim do jogo (0-23): ";
    cin >> horaFim;
    
    if (horaFim < 0 || horaFim >= 24) {
        cout << "Hora de fim inválida." << endl;
        return 1;
    }
       
    int duracao = calcularDuracao(horaInicio, horaFim);
    cout << "A duração do jogo é: " << duracao << " horas" << endl;  
    return 0;
}
