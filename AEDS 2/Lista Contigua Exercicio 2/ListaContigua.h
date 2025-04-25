
#ifndef LISTAPRODUTO_H
#define	LISTAPRODUTO_H

#include "Produto.h"

class ListaContigua {
private:
    int tam, quant;
    Produto *lista;
    
    int contadorDeComparacoes;
    
    bool temEspaco(); 
    bool isEmpty ();
    bool indiceValido(int i);
    void shiftFront(int aPartir);
    void shiftEnd(int ate);
    void criaListaComProdutosAleatorios(int tam);

public:
    ListaContigua();
    ListaContigua(int tamanho);
    ListaContigua(const ListaContigua& outra);
    ListaContigua(const ListaContigua& outra, int novoTamanho);
    virtual ~ListaContigua();
            
    void insert();
    void insert(int posicao);
    void insert(Produto p);
    void remove();
    void remove(int posicao);
    
    void imprimir();
    void preencher();    
    int buscar(int idProduto);    
    Produto* buscar(double preco);
    int buscaBinaria(int codigoProcurado);
    
    //GETTERS E SETTERS
    void setLista(Produto* lista);
    Produto* getLista() const;
    void setQuant(int quant);
    int getQuant() const;
    void setTam(int tam);
    int getTam() const;
};

#endif	/* LISTAPRODUTO_H */

