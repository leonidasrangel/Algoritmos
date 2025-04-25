#include "Nodo.h"
using namespace std;

Nodo::Nodo() {    
    this->pai = NULL;
    this->esq = NULL;
    this->dir = NULL;   
   // this->item = NULL;
    this->fator = 1;
}

Nodo::Nodo(Produto& p){
    this->pai = NULL;
    this->esq = NULL;
    this->item.copiar(p);
    this->dir = NULL;
    this->fator = 0;
}

Nodo::Nodo(const Nodo& outro) {
    this->pai = outro.getPai();
    this->item = outro.getItem();
    this->esq = outro.getEsq();
    this->dir = outro.getDir();
    this->fator = outro.getFator();           
}

Nodo::~Nodo() {
    
}

//Get Numero Filhos
int Nodo::getNumeroFilhos(){
    if(dir == NULL && esq == NULL)
        return 0;
    else if((dir == NULL && esq != NULL) ||(dir != NULL && esq == NULL))
        return 1;
    else
        return 2;                      
}

/**
 * Deve ser chamada quando sabemos que o no tem um filho apenas <br>
 * Quando tem mais de um filho ou nenhum, retorna NULL
 *
 * @return O unico filho */

//Get Filho Unico
Nodo* Nodo::getFilhoUnico(){
    if(this->getNumeroFilhos() == 1){
        if(this->esq != NULL)
            return this->esq;
        else
            return this->dir;
    }else{
        return NULL;
    }
}

//Imprimir
void Nodo::imprimir() const {
    cerr << "No(" << item.getId() << ", Esq->" << esq << ", Dir->" << dir << ")" << endl; 
}

//Set
void Nodo::setFator(int fator) {
    this->fator = fator;
}
void Nodo::setDir(Nodo* dir) {
    if(this!= NULL)
        this->dir = dir;
}
void Nodo::setItem(Produto item) {
    this->item = item;
}
void Nodo::setEsq(Nodo* esq) {
    this->esq = esq;
}
void Nodo::setPai(Nodo* pai) {
    this->pai = pai;
}

//Get
int Nodo::getFator() const {
    return fator;
}
Nodo* Nodo::getDir() const {
    return dir;
}
Produto Nodo::getItem() const {
    return item;
}
Nodo* Nodo::getEsq() const {
    return esq;
}
Nodo* Nodo::getPai() const {
    return pai;
}



