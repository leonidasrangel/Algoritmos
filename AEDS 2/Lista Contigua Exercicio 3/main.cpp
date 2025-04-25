#include <iostream>
#include "Produto.h"
#include "ListaContigua.h"

using namespace std;


// Função que encontra o produto com menor estoque e aumenta o estoque em 100 unidades
void aumentarEstoqueMenorProduto(ListaContigua &lista) {
    int indiceMenorEstoque = 0;
    int menorEstoque = lista.getLista()[0].getEstoque();

    // Percorre a lista para encontrar o produto com menor estoque
    for (int i = 1; i < lista.getQuant(); i++) {
        if (lista.getLista()[i].getEstoque() < menorEstoque) {
            menorEstoque = lista.getLista()[i].getEstoque();
            indiceMenorEstoque = i;
        }
    }

    // Aumenta o estoque do produto encontrado em 100 unidades
    lista.getLista()[indiceMenorEstoque].setEstoque(menorEstoque + 100);
    
    cout << "\nEstoque do produto com menor quantidade atualizado: ";
    lista.getLista()[indiceMenorEstoque].imprimir();
}

// Função principal
int main() {
    ListaContigua lista(10); // Cria uma lista com capacidade para 10 produtos

    // Insere 10 produtos pré-definidos
    Produto p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
    p1.setId(1); p1.setNome("Produto 1"); p1.setPreco(20.0); p1.setCusto(10.0); p1.setEstoque(50);
    p2.setId(2); p2.setNome("Produto 2"); p2.setPreco(15.0); p2.setCusto(5.0); p2.setEstoque(30);
    p3.setId(3); p3.setNome("Produto 3"); p3.setPreco(25.0); p3.setCusto(15.0); p3.setEstoque(40);
    p4.setId(4); p4.setNome("Produto 4"); p4.setPreco(18.0); p4.setCusto(8.0); p4.setEstoque(20);
    p5.setId(5); p5.setNome("Produto 5"); p5.setPreco(30.0); p5.setCusto(12.0); p5.setEstoque(60);
    p6.setId(6); p6.setNome("Produto 6"); p6.setPreco(22.0); p6.setCusto(11.0); p6.setEstoque(10);
    p7.setId(7); p7.setNome("Produto 7"); p7.setPreco(28.0); p7.setCusto(18.0); p7.setEstoque(70);
    p8.setId(8); p8.setNome("Produto 8"); p8.setPreco(26.0); p8.setCusto(13.0); p8.setEstoque(45);
    p9.setId(9); p9.setNome("Produto 9"); p9.setPreco(19.0); p9.setCusto(9.0); p9.setEstoque(25);
    p10.setId(10); p10.setNome("Produto 10"); p10.setPreco(27.0); p10.setCusto(14.0); p10.setEstoque(35);

    // Adiciona os produtos à lista
    lista.insert(p1);
    lista.insert(p2);
    lista.insert(p3);
    lista.insert(p4);
    lista.insert(p5);
    lista.insert(p6);
    lista.insert(p7);
    lista.insert(p8);
    lista.insert(p9);
    lista.insert(p10);

    // Exibe a lista de produtos antes de qualquer alteração
    cout << "Lista de produtos antes da atualização:\n";
    lista.imprimir();

    // Aumenta o estoque do produto com menor quantidade
    aumentarEstoqueMenorProduto(lista);

    // Insere um novo produto na 5ª posição
    Produto novoProduto;
    novoProduto.setId(11);
    novoProduto.setNome("Produto 11");
    novoProduto.setPreco(35.0);
    novoProduto.setCusto(18.0);
    novoProduto.setEstoque(50);

    lista.insert(4, novoProduto); // Insere na posição 4 (índice 4 é a 5ª posição)

    // Exibe a lista de produtos após as alterações
    cout << "\nLista de produtos após as alterações:\n";
    lista.imprimir();

    return 0;
}
