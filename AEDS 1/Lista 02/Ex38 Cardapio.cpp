#include <iostream>
using namespace std;

void cardapio (int codigo, int quantidade){
    float valor = 0;
    switch (codigo){
        case 100:
            valor = (quantidade * 2.20);
            cout << "Vc esta pagando " << valor << " R$ neste pedido" <<endl;
            break;

        case 101:
            valor = (quantidade * 3.30);
            cout << "Vc esta pagando " << valor << " R$ neste pedido" <<endl;
            break;

        case 102:
            valor = (quantidade * 3.50);
            cout << "Vc esta pagando " << valor << " R$ neste pedido" <<endl;
            break;

        case 103:
            valor = (quantidade * 5.20);
            cout << "Vc esta pagando " << valor << " R$ neste pedido" <<endl;
            break;

        case 104:
            valor = (quantidade * 7.30);
            cout << "Vc esta pagando " << valor << " R$ neste pedido" <<endl;
            break;

        case 105:
            valor = (quantidade * 2.00);
            cout << "Vc esta pagando " << valor << " R$ neste pedido" <<endl;
            break;

        default:
            cout <<"Opcao Invalida" <<endl;
    }
}

int main (){
    int codigo = 0, quantidade = 0;

    cout << "|    Cardapio     | Codigo | Preco |" <<endl;
    cout << "| Cachorro quente |  100   |  2.20 |" <<endl;
    cout << "| Bauru Simples   |  101   |  3.30 |" <<endl;
    cout << "| Bauru Com ovo   |  102   |  3.50 |" <<endl;
    cout << "| Hamburguer      |  103   |  5.20 |" <<endl;
    cout << "| Cheeseburguer   |  104   |  7.30 |" <<endl;
    cout << "| Refrigerante    |  105   |  2.00 |" <<endl;

    cout << "Digite o codigo do produto que vc quer: ";
    cin >> codigo;
    cout << "Digite a quantidade: ";
    cin >> quantidade;

    cardapio(codigo,quantidade);
    return 0;    
}