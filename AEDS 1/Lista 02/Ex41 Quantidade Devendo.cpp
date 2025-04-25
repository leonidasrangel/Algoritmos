#include <iostream>
using namespace std;

void devendo (int codigo, int quantidade){
    float valor = 0;
    switch (codigo){
        case 1001:
            valor = (quantidade * 5.32);
            cout << "Vc esta pagando " << valor << " R$ neste pedido" <<endl;
            break;

        case 1324:
            valor = (quantidade * 6.45);
            cout << "Vc esta pagando " << valor << " R$ neste pedido" <<endl;
            break;

        case 6548:
            valor = (quantidade * 2.37);
            cout << "Vc esta pagando " << valor << " R$ neste pedido" <<endl;
            break;

        case 1987:
            valor = (quantidade * 5.32);
            cout << "Vc esta pagando " << valor << " R$ neste pedido" <<endl;
            break;

        case 7623:
            valor = (quantidade * 6.45);
            cout << "Vc esta pagando " << valor << " R$ neste pedido" <<endl;
            break;

        default:
            cout <<"Opcao Invalida" <<endl;
    }
}

int main (){
    int codigo = 0, quantidade = 0;

    cout << "|    Produto      | Codigo  | Preco |" <<endl;
    cout << "|    Teclado      |  1001   |  5.32 |" <<endl;
    cout << "|    Mouse        |  1324   |  6.45 |" <<endl;
    cout << "|    Pendrive     |  6548   |  2.37 |" <<endl;
    cout << "|    Carregador   |  1987   |  5.32 |" <<endl;
    cout << "|    MousePad     |  7623   |  6.45 |" <<endl;

    cout << "Digite o codigo do produto que vc esta devendo: ";
    cin >> codigo;
    cout << "Digite a quantidade: ";
    cin >> quantidade;

    devendo(codigo,quantidade);
    return 0;    
}