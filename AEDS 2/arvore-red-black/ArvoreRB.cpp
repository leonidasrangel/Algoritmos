#include "ArvoreRB.h"

Nodo::Nodo(int v) : valor(v), cor(RED), esquerda(nullptr), direita(nullptr), pai(nullptr) {}

ArvoreRB::ArvoreRB() : raiz(nullptr) {}

ArvoreRB::~ArvoreRB() {
    // Implementação para deletar todos os nós (evitar vazamento de memória)
}

void ArvoreRB::rotacaoEsquerda(Nodo*& nodo) {
    Nodo* y = nodo->direita;
    nodo->direita = y->esquerda;
    if (y->esquerda != nullptr)
        y->esquerda->pai = nodo;
    y->pai = nodo->pai;
    if (nodo->pai == nullptr)
        raiz = y;
    else if (nodo == nodo->pai->esquerda)
        nodo->pai->esquerda = y;
    else
        nodo->pai->direita = y;
    y->esquerda = nodo;
    nodo->pai = y;
}

void ArvoreRB::rotacaoDireita(Nodo*& nodo) {
    Nodo* y = nodo->esquerda;
    nodo->esquerda = y->direita;
    if (y->direita != nullptr)
        y->direita->pai = nodo;
    y->pai = nodo->pai;
    if (nodo->pai == nullptr)
        raiz = y;
    else if (nodo == nodo->pai->direita)
        nodo->pai->direita = y;
    else
        nodo->pai->esquerda = y;
    y->direita = nodo;
    nodo->pai = y;
}

void ArvoreRB::balancearInsercao(Nodo*& nodo) {
    while (nodo->pai && nodo->pai->cor == RED) {
        if (nodo->pai == nodo->pai->pai->esquerda) {
            Nodo* tio = nodo->pai->pai->direita;
            if (tio && tio->cor == RED) {
                nodo->pai->cor = BLACK;
                tio->cor = BLACK;
                nodo->pai->pai->cor = RED;
                nodo = nodo->pai->pai;
            } else {
                if (nodo == nodo->pai->direita) {
                    nodo = nodo->pai;
                    rotacaoEsquerda(nodo);
                }
                nodo->pai->cor = BLACK;
                nodo->pai->pai->cor = RED;
                rotacaoDireita(nodo->pai->pai);
            }
        } else {
            Nodo* tio = nodo->pai->pai->esquerda;
            if (tio && tio->cor == RED) {
                nodo->pai->cor = BLACK;
                tio->cor = BLACK;
                nodo->pai->pai->cor = RED;
                nodo = nodo->pai->pai;
            } else {
                if (nodo == nodo->pai->esquerda) {
                    nodo = nodo->pai;
                    rotacaoDireita(nodo);
                }
                nodo->pai->cor = BLACK;
                nodo->pai->pai->cor = RED;
                rotacaoEsquerda(nodo->pai->pai);
            }
        }
    }
    raiz->cor = BLACK;
}

void ArvoreRB::inserir(int valor) {
    Nodo* novo = new Nodo(valor);
    Nodo* y = nullptr;
    Nodo* x = raiz;

    while (x != nullptr) {
        y = x;
        if (novo->valor < x->valor)
            x = x->esquerda;
        else
            x = x->direita;
    }

    novo->pai = y;
    if (y == nullptr)
        raiz = novo;
    else if (novo->valor < y->valor)
        y->esquerda = novo;
    else
        y->direita = novo;

    balancearInsercao(novo);
}

Nodo* ArvoreRB::buscarNodo(int valor) {
    Nodo* atual = raiz;
    while (atual != nullptr) {
        if (valor == atual->valor)
            return atual;
        else if (valor < atual->valor)
            atual = atual->esquerda;
        else
            atual = atual->direita;
    }
    return nullptr;
}

Nodo* ArvoreRB::minimo(Nodo* nodo) {
    while (nodo->esquerda != nullptr)
        nodo = nodo->esquerda;
    return nodo;
}

void ArvoreRB::remover(int valor) {
    Nodo* z = buscarNodo(valor);
    if (z == nullptr)
        return;

    Nodo* y = z;
    Nodo* x;
    Cor corOriginal = y->cor;

    if (z->esquerda == nullptr) {
        x = z->direita;
        transplantar(z, z->direita);
    } else if (z->direita == nullptr) {
        x = z->esquerda;
        transplantar(z, z->esquerda);
    } else {
        y = minimo(z->direita);
        corOriginal = y->cor;
        x = y->direita;
        if (y->pai == z)
            x->pai = y;
        else {
            transplantar(y, y->direita);
            y->direita = z->direita;
            y->direita->pai = y;
        }
        transplantar(z, y);
        y->esquerda = z->esquerda;
        y->esquerda->pai = y;
        y->cor = z->cor;
    }

    delete z;

    if (corOriginal == BLACK)
        balancearRemocao(x);
}

void ArvoreRB::transplantar(Nodo* u, Nodo* v) {
    if (u->pai == nullptr)
        raiz = v;
    else if (u == u->pai->esquerda)
        u->pai->esquerda = v;
    else
        u->pai->direita = v;
    if (v != nullptr)
        v->pai = u->pai;
}

void ArvoreRB::balancearRemocao(Nodo* nodo) {
    // Implementação do balanceamento após remoção (caso necessário)
}

void ArvoreRB::exibirAux(Nodo* raiz, string indent, bool last) {
    if (raiz != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << (raiz->cor == RED ? "RED" : "BLACK") << "(" << raiz->valor << ")" << endl;
        exibirAux(raiz->esquerda, indent, false);
        exibirAux(raiz->direita, indent, true);
    }
}

void ArvoreRB::exibir() {
    exibirAux(raiz, "", true);
}
