#ifndef ARVORE_RB_H
#define ARVORE_RB_H
#include "Produto.h"
#include "Nodo.h"
#include <iostream>


class ArvoreRB {
private:
    Nodo* raiz;

    void rotacaoEsquerda(Nodo*& nodo);
    void rotacaoDireita(Nodo*& nodo);
    void balancearInsercao(Nodo*& nodo);
    void transplantar(Nodo* u, Nodo* v);
    void balancearRemocao(Nodo* nodo);
    Nodo* minimo(Nodo* nodo);
    Nodo* buscarNodo(int valor);
    
public:
    ArvoreRB();
    ~ArvoreRB();
    void inserir(int valor);
    void remover(int valor);
    void exibir();
    void exibirAux(Nodo* raiz, std::string indent, bool last);
};

#endif
