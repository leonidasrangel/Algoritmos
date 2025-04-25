#include "ArvoreAVL.h"
#include<iostream>
#include<fstream>
#include<ostream>
using namespace std;

ArvoreAVL::ArvoreAVL() {
    quant = 0;
    root = NULL;
}

ArvoreAVL::ArvoreAVL(const ArvoreAVL& outra) {
    this->quant = outra.getQuant();
    this->root = outra.getRoot();
}

ArvoreAVL::~ArvoreAVL() {
    //será chamado quando o objeto for destruido
}

//Buscar
Nodo * ArvoreAVL::buscar(Nodo * subArvore, const Produto& p) {
    if (subArvore != NULL) {
        Produto item = subArvore->getItem();
        if (p.getId() < item.getId())
            return buscar(subArvore->getEsq(), p);
        else if (p.getId() > item.getId())
            return buscar(subArvore->getDir(), p);
        else {
            return subArvore; //cout << "--- Achou ! ---";
        }
    } else {
        cout << " Elemento não encontrado.";
        return NULL;
    }
}

//Local Entrada
Nodo* ArvoreAVL::localEntrada(Nodo* no, const Produto &p) {
    Produto item = no->getItem();

    if (p.getId() < item.getId()) {
        if (no->getEsq() != NULL)
            return localEntrada(no->getEsq(), p);
    } else {
        if (no->getDir() != NULL)
            return localEntrada(no->getDir(), p);
    }
    return no;
}

//Insert
void ArvoreAVL::insert(Produto &p) {
    Nodo *novo;
    novo = new Nodo(p);

    if (root == NULL) {
        root = new Nodo();
        root->setItem(p);
        quant++;
    } else {
        Nodo *pai = localEntrada(root, p);

        Produto itemPai = pai->getItem();
        if (p.getId() < itemPai.getId()) {
            pai->setEsq(novo);
            novo->setPai(pai);
            quant++;
        } else if (p.getId() > itemPai.getId()) {
            pai->setDir(novo);
            novo->setPai(pai);
            quant++;
        } else {
            cout << "Elemento ja existe!\n";
        }
    }
}

//Remove
void ArvoreAVL::remove(Produto &p) {
    Nodo* sair = buscar(root, p);

    if (sair != NULL) {
        int numeroFilhos = sair->getNumeroFilhos();
        if (numeroFilhos == 0) {
            this->removerZeroFilhos(sair);
        } else if (numeroFilhos == 1) {
            this->removerUmFilho(sair);
        } else {
            this->removerNFilhos(sair);
        }
        quant--;
    }
    Nodo* p2 = this->getP(sair);
    if (p2 != NULL) {
        cout << "Desbalanceou:";
        p2->getItem().imprimirLinear();
        cout << endl;
        executaBalanceamento(sair);
    }
}

//Remover Zero Filhos
void ArvoreAVL::removerZeroFilhos(Nodo *sair) {
    Nodo * pai = sair->getPai();
    if (pai == NULL) { //estamos removendo o root
        root = NULL;
    } else {
        Produto itemPai = pai->getItem();
        Produto itemSair = sair->getItem();

        if (itemSair.getId() < itemPai.getId())
            pai->setEsq(NULL);
        else
            pai->setDir(NULL);
    }
}

//Remover Um Filho
void ArvoreAVL::removerUmFilho(Nodo *sair) {
    Nodo * pai = sair->getPai();
    Nodo * filho = sair->getFilhoUnico();

    if (pai == NULL) { //o pai é o root e basta apontar pra o filho
        root = filho;
    } else {
        if (filho != NULL) {
            filho->setPai(pai);
            if (filho->getItem().getId() > pai->getItem().getId())
                pai->setDir(filho);
            else
                pai->setEsq(filho);
        }
    }
}

//Remover N Filhos
void ArvoreAVL::removerNFilhos(Nodo *sair) {
    Nodo * antecessor = this->getAntecessor(sair);

    Produto p = antecessor->getItem();
    this->remove(p);

    sair->setItem(antecessor->getItem());
}

/**
 * O Algoritmo desce SEMPRE para ESQUERDA procurando o 
 * MENOR elemento dentre os MAIORES que o NO
 * 
 * O algoritmo para quando um determinado NO descendente não tiver mais
 * filho a esquerda.
 * @param no
 * @return */

//Menor Descendente
Nodo* ArvoreAVL::menorDescendente(Nodo *no) {
    if (no != NULL) {
        if (no->getEsq() == NULL)
            return no;
        else
            return menorDescendente(no->getEsq());
    }
    return NULL;
}

//Get Sucessor
Nodo* ArvoreAVL::getSucessor(Nodo* no) {
    if (no != NULL) {
        return menorDescendente(no->getDir());
    } else {
        cout << "Esse nó não possui antecessor";
        return NULL;
    }
}

/**
 * O Algoritmo desce SEMPRE para Direita procurando o 
 * Maior elemento dentre os menores que o NO
 * 
 * O algoritmo para quando um determinado NO descendente não tiver mais
 * filho a direita.
 * @param no
 * @return */

//Maior Descendente
Nodo* ArvoreAVL::maiorDescendente(Nodo *no) {
    if (no != NULL) {
        if (no->getDir() == NULL)
            return no;
        else
            return maiorDescendente(no->getDir());
    }
    return NULL;
}

//Get Antecessor
Nodo* ArvoreAVL::getAntecessor(Nodo* no) {
    if (no != NULL) {
        return maiorDescendente(no->getEsq());
    } else {
        cout << "Esse nó não possui antecessor";
        return NULL;
    }
}

//Em Ordem
void ArvoreAVL::emOrdem(Nodo *no) {
    if (no != NULL) {
        emOrdem(no->getEsq());
        no->getItem().imprimirResumido();
        emOrdem(no->getDir());
    }
}

//Pre Ordem
void ArvoreAVL::preOrdem(Nodo *no) {
    if (no != NULL) {
        no->getItem().imprimirResumido();
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

//Pos Ordem
void ArvoreAVL::posOrdem(Nodo *no) {
    if (no != NULL) {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        no->getItem().imprimirResumido();
    }
}

/**
 * Vai verificar se tem algum no desbalanceado
 * Se tiver algum, verificaQual caso estamos e chama a rotação correta! */

//Balanceamento
void ArvoreAVL::executaBalanceamento(Nodo* entrou) {
    Nodo * p = getP(entrou);

    if (p != NULL) { //Tem alguem desbalanceado
        Nodo * q = getQ(p);
        q->imprimir();

        if (p->getFator() > 0 && q->getFator() >= 0) { //++, uma rotacao
           rotacaoUnica_DirDir(p, q);
        } else if (p->getFator() < 0 && q->getFator() <= 0) { //--, uma rotacao
            rotacaoUnica_EsqEsq(p, q);
        } else if (p->getFator() > 0 && q->getFator() < 0) { //+-, duas rotacoes
            Nodo * r = getQ(q);
            rotacaoDupla_DirEsq(p, q, r);
            //agora temos o r e podemos fazer as duas rotacoes
            // R->Q e R->P
        }
    }
}

//Rotação Unica Esquerda
void ArvoreAVL::rotacaoUnica_EsqEsq(Nodo *P, Nodo* Q) {
    Nodo* paiP = P->getPai();
    Nodo* A = Q->getDir();
    
    Q->setDir(P);
    P->setEsq(A);

    Q->setPai(paiP);
    if (Q->getItem().getId() > paiP->getItem().getId())
        paiP->setDir(Q);
    else
        paiP->setEsq(Q);
}

//Rotação Unica Direita
void ArvoreAVL::rotacaoUnica_DirDir(Nodo *P, Nodo* Q) {
    Nodo* paiP = P->getPai();
    Nodo* A = Q->getEsq();
    
    Q->setEsq(P);
    P->setDir(A);

    Q->setPai(paiP);
    if (Q->getItem().getId() > paiP->getItem().getId())
        paiP->setDir(Q);
    else
        paiP->setEsq(Q);
}

// Rotação Dupla Direita-Esquerda (Resolve desbalanceamento em P causado pela subárvore direita)
void ArvoreAVL::rotacaoDupla_DirEsq(Nodo *P, Nodo *Q, Nodo *R) {
    // Obtém o pai do nó P (será usado para ajustar a árvore após a rotação)
    Nodo *paiP = P->getPai();
    
    // Ajusta as conexões entre R e Q (primeira parte da rotação)
    R->setDir(Q);        // Define Q como o filho direito de R
    P->setDir(R);        // Define R como o filho direito de P
    Q->setPai(R);        // Define R como o pai de Q
    R->setPai(P);        // Define P como o pai de R
    
    // Limpa o filho esquerdo de Q para evitar ciclos na árvore
    Q->setEsq(NULL);

    // Ajusta as conexões entre R e P (segunda parte da rotação, rotação simples à esquerda)
    Nodo *subEsqR = R->getEsq(); // Salva o filho esquerdo de R (se existir) antes de alterar
    R->setEsq(P);                // Define P como o filho esquerdo de R
    P->setDir(subEsqR);          // Define o filho esquerdo de R como o filho direito de P

    // Se o filho esquerdo de R existia, atualiza seu pai para ser P
    if (subEsqR != NULL) {
        subEsqR->setPai(P);
    }

    // Atualiza o pai de R para ser o pai original de P
    R->setPai(paiP);

    // Ajusta as conexões do pai de P para apontar para R
    if (paiP != NULL) {            // Se P tinha um pai,
        if (P == paiP->getEsq()) { // verifica se P era o filho esquerdo
            paiP->setEsq(R);       // Define R como o novo filho esquerdo
        } else {                   // Caso contrário,
            paiP->setDir(R);       // Define R como o novo filho direito
        }
    }

    // Define R como o novo pai de P
    P->setPai(R);

    // Ajusta a raiz da árvore, caso P fosse a raiz original
    if (P == root) { // Se P era a raiz da árvore,
        root = R;    // define R como a nova raiz
    }
}
// Rotação Dupla Esquerda-Direita (Resolve desbalanceamento em P causado pela subárvore esquerda)
void ArvoreAVL::rotacaoDupla_EsqDir(Nodo *P, Nodo *Q, Nodo *R) {
    // Obtém o pai do nó P para ajustar a árvore após a rotação
    Nodo *paiP = P->getPai();

    // Ajusta as conexões entre R e Q (primeira parte da rotação)
    R->setEsq(Q);        // Define Q como o filho esquerdo de R
    P->setEsq(R);        // Define R como o filho esquerdo de P
    Q->setPai(R);        // Define R como o pai de Q
    R->setPai(P);        // Define P como o pai de R

    // Limpa o filho direito de Q para evitar ciclos na árvore
    Q->setDir(NULL);

    // Ajusta as conexões entre R e P (segunda parte da rotação, rotação simples à direita)
    Nodo *subDirR = R->getDir(); // Salva o filho direito de R (se existir) antes de alterar
    R->setDir(P);                // Define P como o filho direito de R
    P->setEsq(subDirR);          // Define o filho direito de R como o filho esquerdo de P

    // Se o filho direito de R existia, atualiza seu pai para ser P
    if (subDirR != NULL) {
        subDirR->setPai(P);
    }

    // Atualiza o pai de R para ser o pai original de P
    R->setPai(paiP);

    // Ajusta as conexões do pai de P para apontar para R
    if (paiP != NULL) {            // Se P tinha um pai,
        if (P == paiP->getEsq()) { // verifica se P era o filho esquerdo
            paiP->setEsq(R);       // Define R como o novo filho esquerdo
        } else {                   // Caso contrário,
            paiP->setDir(R);       // Define R como o novo filho direito
        }
    }

    // Define R como o novo pai de P
    P->setPai(R);

    // Ajusta a raiz da árvore, caso P fosse a raiz original
    if (P == root) { // Se P era a raiz da árvore,
        root = R;    // define R como a nova raiz
    }
}


/**
 * Sobe nos ancestrais e vai calculando o fatorDeBalanceamento() deles
 * quando encontrar alguem maior que 2, achou!
 * Como consequencia, ja tem o fatorDeBalanceamento dos ancestrais, assim
 * é possivel saber qual caso estamos ++,--,+- ou -+
 * @param entrou
 * @return */

//Get P
Nodo* ArvoreAVL::getP(Nodo *entrou) {
    Nodo * pai = entrou->getPai();
    while (pai != NULL) {
        int fator = getFatorBalanceamento(pai);
        if (abs(fator) >= 2) {
            return pai;
        }
        pai = pai->getPai();
    }
    return NULL;
}

//Nodo* ArvoreAVL::getQ(Nodo *p, Nodo*entrou) {
//    if (entrou->getItem().getId() < p->getItem().getId())
//        return p->getEsq();
//    else
//        return p->getDir();
//}

//Get Q
Nodo* ArvoreAVL::getQ(Nodo *p) {
    Nodo *q;
    if (p->getFator() > 0)
        q = p->getDir();
    else
        q = p->getEsq();
    
   //precisamos atualizar o fator de balanceamento do q
   getFatorBalanceamento(q);
   return q;
}

/**
 * Recebe um no como parametro e chama o metodo getAltura(SubArvoreEsquerda)
 *  e getAltura(SubArvoreDireita) e faz a diferenca.
 * @param no
 * @return */

//Fator Balanceamento
int ArvoreAVL::getFatorBalanceamento(Nodo *no) {
    int h_esq = 0;
    int h_dir = 0;
    Nodo* subEsq = no->getEsq();
    Nodo* subDir = no->getDir();

    if (subEsq != NULL)
        h_esq = getAltura(subEsq);

    if (subDir != NULL)
        h_dir = getAltura(subDir);

    int fator = h_dir - h_esq;
    no->setFator(fator);
    return fator;
}

//Get Altura
int ArvoreAVL::getAltura(Nodo *no) {
    if (no == NULL) {
        return 0;
    } else {
        int h_esq = getAltura(no->getEsq());
        int h_dir = getAltura(no->getDir());

        if (h_esq > h_dir)
            return h_esq + 1;
        else
            return h_dir + 1;
    }
}

//Pre Ordem Arquivo
void ArvoreAVL::preOrdemArquivo(Nodo *no) {
    if (no != NULL) {
        textoSalvo = textoSalvo + no->getItem().imprimirParaArquivo() + "\n";
        preOrdemArquivo(no->getEsq());
        preOrdemArquivo(no->getDir());
    }
}

//Load Produtos
void ArvoreAVL::loadProdutos() {
    string caminhoPasta = "teste.txt";
    ifstream arquivoLido;

    arquivoLido.open(caminhoPasta.c_str());
    int quant;
    arquivoLido >> quant;

    string nome;
    float id, custo, preco;
    int estoque;

    Produto p;
    for (int i = 0; i < quant; i++) {
        arquivoLido >> id;
        arquivoLido >> nome;
        arquivoLido >> custo;
        arquivoLido >> preco;
        arquivoLido >> estoque;
        p.setId(id);
        p.setNome(nome);
        p.setCusto(custo);
        p.setPreco(preco);
        p.setEstoque(estoque);

        insert(p);
    }

    arquivoLido.close();
}

//Produtos Salvos
void ArvoreAVL::saveProdutosArquivo() {
    string caminhoPasta = "teste.txt";
    ofstream arquivoSalvo;
    arquivoSalvo.open(caminhoPasta.c_str());

    preOrdemArquivo(root); //essa funcao monta o texto    
    arquivoSalvo << quant << endl << textoSalvo << endl;

    arquivoSalvo.close();
}

//Set
void ArvoreAVL::setQuant(int quant) {
    this->quant = quant;
}
void ArvoreAVL::setRoot(Nodo* root) {
    this->root = root;
}

//Get
int ArvoreAVL::getQuant() const {
    return quant;
}
Nodo* ArvoreAVL::getRoot() const {
    return root;
}