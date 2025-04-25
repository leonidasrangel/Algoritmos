#include <string.h>
#include <iostream>
#ifndef PRODUTO_H
#define	PRODUTO_H
using namespace std;

class Produto {
private:
    int id;
    string nome;
    double custo;
    double preco;   
    int estoque; 
    
public:   
    Produto();
    Produto(const Produto &outro);
    
    void imprimir() const;
    void imprimirLinear() const;
    void imprimirResumido() const;
    string imprimirParaArquivo() const;
    void preencher();
    void copiar(const Produto& outro);
    
    int EhMaiorQue(const Produto& outro);
    bool eIgual(const Produto& outro);
    
    //Set e Get
    void setEstoque(int estoque);
    int getEstoque() const;
    void setCusto(double custo);
    double getCusto() const;
    void setPreco(double preco);
    double getPreco() const;
    void setId(int id);
    int getId() const;
    void setNome(string nome);
    string getNome() const;
};

#endif	/* PRODUTO_H */

