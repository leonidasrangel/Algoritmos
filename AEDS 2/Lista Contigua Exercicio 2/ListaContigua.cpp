#include "ListaContigua.h"
#include<iostream>

using namespace std;

ListaContigua::ListaContigua() {
    quant = 0;
    cout << "Informe o tamanho desejado:";
    cin >> tam;
    lista = new Produto[tam];
    contadorDeComparacoes = 0;
}

ListaContigua::ListaContigua(int tamanho) {
    quant = 0;
    tam = tamanho;
    lista = new Produto[tam];
    contadorDeComparacoes = 0;
}

ListaContigua::ListaContigua(const ListaContigua& outra) {
    quant = outra.getQuant();
    tam = outra.getTam();
    lista = outra.getLista();
}

ListaContigua::ListaContigua(const ListaContigua& outra, int novoTamanho) {
    quant = outra.getQuant();
    tam = novoTamanho;
    lista = new Produto[tam];
    
    for(int i=0; i<=quant-1; i++){
        lista[i].copiar(outra.getLista()[i]);
    }    
}

ListaContigua::~ListaContigua() {
    //será chamado quando o objeto for destruido
}

/**
 * 
 * @param idProduto: identificador no produto
 * @return retorna a posição(index) do produto no vetor. Se nao encotrar
 * retorna -1
 */
int ListaContigua::buscar(int idProduto) {
    contadorDeComparacoes = 0;
    for (int i = 0; i <= tam - 1; i++) {
        if (lista[i].getId() == idProduto){            
            return i;
        }else
            contadorDeComparacoes++;
    }
    cerr << "Produto não encontrado"; 
    return -1;
}

/* Procura na lista de produtos todos os elementos que possuem o preco procurado.
A função retorna um vetor de produtos, pois pode encontrar mais de um elemento.
*/
Produto* ListaContigua::buscar(double preco) {
    Produto* resultado = new Produto[tam];
    int cont = 0;
    for (int i = 0; i <= tam - 1; i++) {
        if (lista[i].getPreco() == preco) {
            //resultado[i] = lista[i], como não pode, usamos o metodo copiar da classe PRODUTO
            resultado[cont].copiar(lista[i]);
            cont++;
        }
    }
    return resultado;
}

/*
 Lembrando que, pare este método funcionar é necessário que a lista esteja ordenada.
 */
int ListaContigua::buscaBinaria(int codigoProcurado) {
    contadorDeComparacoes = 0;
    int inicio = 0;
    int fim = tam - 1;
    int meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        contadorDeComparacoes++;
        
        if (lista[meio].getId() == codigoProcurado)
            return meio;
        else if (codigoProcurado < lista[meio].getId()) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1;
}

void ListaContigua::preencher() {
    for (int i = 0; i <= tam; i++) {
        insert();
    }
}

void ListaContigua::insert() {
    if (!temEspaco()){
        cout << "Operacao invalida. Lista cheia." << endl;
    }else{
        shiftEnd(0);
        lista[0].preencher();
        quant++;
    }
}

void ListaContigua::insert(int posicao) {
    if (!temEspaco()){
        cout << "Operacao invalida. Lista cheia." << endl;
    }else if(!indiceValido(posicao) || posicao > quant) {
        cout << "Operacao invalida para a posicao escolhida." << endl;
    }else{//tudo ok, pode inserir!
        shiftEnd(posicao);
        lista[posicao].preencher();
        quant++;
    }
}

void ListaContigua::insert(Produto p) {
    if (!temEspaco()){
        cout << "Operacao invalida. Lista cheia." << endl;
    }else{
        shiftEnd(0);
        lista[0].copiar(p);
        quant++;
    }
}

void ListaContigua::remove() {
    if(isEmpty()){
        cout << "Lista vazia" << endl;
    } else{//tudo ok
        shiftFront(0);
        quant--;
    }
}

void ListaContigua::remove(int posicao) {
    if(isEmpty()){
        cout << "Lista vazia" << endl;
    }else if(!indiceValido(posicao) || posicao >= quant){
        cout << "Operacao invalida para posicao escolhida.";
    }else{//tudo ok
        shiftFront(posicao);
        quant--;
    }
}

/**
 * Atenção pois so copiamos lista[i] = lista[i+1] até o penultimo, senao acessamos
 * memoria invalida
 * @param aPartir
 */
void ListaContigua::shiftFront(int aPartir) {
    if (indiceValido(aPartir)) {
        if (!isEmpty()) {
            for (int i = aPartir; i <= quant-2; i++) {                
                lista[i].copiar(lista[i + 1]);
            }
        }
    }
}

void ListaContigua::shiftEnd(int ate) {
    if (temEspaco() && !isEmpty()) {
        for (int i = quant; i > ate; i--) {            
            lista[i].copiar(lista[i - 1]);//lista[i] = lista[i-1];
        }
    }
}

void ListaContigua::criaListaComProdutosAleatorios(int tam) {
    quant = 0;
    this->tam = tam;
    lista = new Produto[tam];
    
    for(int i=tam-1; i>=0; i--){
        Produto p;
        p.setId(i);
        insert(p);
    }
}

void ListaContigua::imprimir() {
    cout << "\n Lista [ ";
    if (!isEmpty()) {
        for (int i = 0; i <= quant - 1; i++) {
            lista[i].imprimirReduzido();
        }
    }
    cout << " ]\n";
}

/**
 * Verifica se o index desejado não estrapola os limites do vetor
 * @param i
 * @return 
 */
bool ListaContigua::indiceValido(int i) {
    if (i >= 0 && i <= tam-1)
        return true;
    else
        return false;
}

bool ListaContigua::temEspaco() {
    if (quant < tam)
        return true;
    else
        return false;
}

bool ListaContigua::isEmpty() {
    if (quant == 0)
        return true;
    else
        return false;
}


/**
 *  GETTERS E SETTERS 
 */
void ListaContigua::setLista(Produto* lista) {
    this->lista = lista;
}

Produto* ListaContigua::getLista() const {
    return lista;
}

void ListaContigua::setQuant(int quant) {
    this->quant = quant;
}

int ListaContigua::getQuant() const {
    return quant;
}

void ListaContigua::setTam(int tam) {
    this->tam = tam;
}

int ListaContigua::getTam() const {
    return tam;
}