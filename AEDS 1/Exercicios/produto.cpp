//Faça um programa que peça ao usuário para inserir os seguintes dados de um produto: nome, custo, preço, estoque, em seguida seu programa imprime cada uma das informações inseridas.
#include<iostream>
using namespace std;

int main(){

        string nome;
        float custo;
        double preco;
        int estoque;

        cout << "Insira o nome do produto" << endl;
        cin >> nome;
        cout << "Qual o preço de custo?" << endl;
        cin >> custo;
        cout << "Coloque o preço de venda:" <<endl; 
        cin >> preco;
        cout << "Qual a quantidade do estoque?" << endl;
        cin >> estoque;

        cout << "Os dados do produto são:" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Preço de custo: " << custo << endl;
        cout << "Preço de venda: " << preco << endl;
        cout << "Quantidade em estoque: " << estoque << endl;

    return 0;
}