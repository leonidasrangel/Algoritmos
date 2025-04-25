#include <iostream>
#include "Produto.h"
#include "ListaContigua.h"

using namespace std;

// Função que encontra o índice do produto com maior custo e o remove da lista
void removerProdutoDeMaiorCusto(ListaContigua &lista) {
    int indiceMaiorCusto = 0;
    double maiorCusto = lista.getLista()[0].getCusto();

    // Percorre a lista para encontrar o produto de maior custo
    for (int i = 1; i < lista.getQuant(); i++) {
        if (lista.getLista()[i].getCusto() > maiorCusto) {
            maiorCusto = lista.getLista()[i].getCusto();
            indiceMaiorCusto = i;
        }
    }
    
    cout << "Removendo o produto de maior custo: ";
    lista.getLista()[indiceMaiorCusto].imprimir();
    
    // Remove o produto da lista
    lista.remove(indiceMaiorCusto);
}

int main() {
    ListaContigua lista(10); // Cria uma lista com capacidade para 10 produtos

    // Insere 8 produtos personalizados
    Produto p1, p2, p3, p4, p5, p6, p7, p8;
    p1.setId(1); p1.setNome("Produto 1"); p1.setPreco(20.0); p1.setCusto(10.0); p1.setEstoque(50);
    p2.setId(2); p2.setNome("Produto 2"); p2.setPreco(15.0); p2.setCusto(5.0); p2.setEstoque(30);
    p3.setId(3); p3.setNome("Produto 3"); p3.setPreco(25.0); p3.setCusto(15.0); p3.setEstoque(40);
    p4.setId(4); p4.setNome("Produto 4"); p4.setPreco(18.0); p4.setCusto(8.0); p4.setEstoque(20);
    p5.setId(5); p5.setNome("Produto 5"); p5.setPreco(30.0); p5.setCusto(12.0); p5.setEstoque(60);
    p6.setId(6); p6.setNome("Produto 6"); p6.setPreco(22.0); p6.setCusto(11.0); p6.setEstoque(10);
    p7.setId(7); p7.setNome("Produto 7"); p7.setPreco(28.0); p7.setCusto(18.0); p7.setEstoque(70);
    p8.setId(8); p8.setNome("Produto 8"); p8.setPreco(26.0); p8.setCusto(13.0); p8.setEstoque(45);

    // Adiciona os produtos à lista
    lista.insert(p1);
    lista.insert(p2);
    lista.insert(p3);
    lista.insert(p4);
    lista.insert(p5);
    lista.insert(p6);
    lista.insert(p7);
    lista.insert(p8);

    // Exibe a lista antes da remoção
    cout << "Lista de produtos antes da remocao:\n";
    lista.imprimir();

    // Remove o produto de maior custo
    removerProdutoDeMaiorCusto(lista);

    // Exibe a lista após a remoção
    cout << "\nLista de produtos apos a remocao do produto de maior custo:\n";
    lista.imprimir();

    return 0;
}
