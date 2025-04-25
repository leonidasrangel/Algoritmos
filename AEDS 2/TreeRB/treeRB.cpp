#include <iostream>
using namespace std;

// Enumeração para representar as cores dos nós (RED = vermelho, BLACK = preto)
enum Color { RED, BLACK };

// Classe que representa um nó da Árvore Rubro-Negra
class Node {
public:
    int data;        // Valor armazenado no nó
    bool color;      // Cor do nó (RED ou BLACK)
    Node *left;      // Ponteiro para o filho esquerdo
    Node *right;     // Ponteiro para o filho direito
    Node *parent;    // Ponteiro para o nó pai

    // Construtor do nó
    Node(int data) {
        this->data = data;
        left = right = parent = nullptr; // Inicializa os ponteiros como nulos
        this->color = RED; // Novo nó é sempre vermelho por padrão
    }
};

// Classe que representa a Árvore Rubro-Negra
class RBTree {
private:
    Node *root; // Ponteiro para a raiz da árvore

protected:
    // Funções protegidas para rotações e correção de violações
    void rotateLeft(Node *&, Node *&);   // Rotação à esquerda
    void rotateRight(Node *&, Node *&);  // Rotação à direita
    void fixViolation(Node *&, Node *&); // Corrige violações após inserção

public:
    // Construtor da árvore
    RBTree() { root = nullptr; }

    // Métodos públicos
    void insert(const int &n); // Insere um novo valor na árvore
    void inorder();            // Travessia in-order (esquerda, raiz, direita)
    void levelOrder();         // Travessia em nível (por níveis da árvore)

private:
    // Funções auxiliares para travessias
    void inorderHelper(Node *root);    // Auxiliar para in-order
    void levelOrderHelper(Node *root); // Auxiliar para level-order
};

// Função auxiliar para realizar a travessia in-order
void RBTree::inorderHelper(Node *root) {
    if (root == nullptr)
        return;

    inorderHelper(root->left);   // Visita a subárvore esquerda
    cout << root->data << " ";   // Visita o nó atual
    inorderHelper(root->right);  // Visita a subárvore direita
}

// Função auxiliar para realizar a travessia em nível
void RBTree::levelOrderHelper(Node *root) {
    if (root == nullptr)
        return;

    // Visita os filhos do nó atual
    if (root->left != nullptr)
        cout << root->left->data << " ";
    if (root->right != nullptr)
        cout << root->right->data << " ";

    // Recursão para os próximos níveis
    levelOrderHelper(root->left);
    levelOrderHelper(root->right);
}

// Função para realizar uma rotação à esquerda
void RBTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right; // Guarda o filho direito do nó pt

    pt->right = pt_right->left; // O filho esquerdo de pt_right vira filho direito de pt

    if (pt->right != nullptr)
        pt->right->parent = pt; // Atualiza o pai do filho direito de pt

    pt_right->parent = pt->parent; // O pai de pt_right agora é o pai de pt

    if (pt->parent == nullptr)
        root = pt_right; // Se pt era a raiz, pt_right vira a nova raiz
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right; // Se pt era filho esquerdo, pt_right vira filho esquerdo
    else
        pt->parent->right = pt_right; // Se pt era filho direito, pt_right vira filho direito

    pt_right->left = pt; // pt vira filho esquerdo de pt_right
    pt->parent = pt_right; // O pai de pt agora é pt_right
}

// Função para realizar uma rotação à direita
void RBTree::rotateRight(Node *&root, Node *&pt) {
    Node *pt_left = pt->left; // Guarda o filho esquerdo do nó pt

    pt->left = pt_left->right; // O filho direito de pt_left vira filho esquerdo de pt

    if (pt->left != nullptr)
        pt->left->parent = pt; // Atualiza o pai do filho esquerdo de pt

    pt_left->parent = pt->parent; // O pai de pt_left agora é o pai de pt

    if (pt->parent == nullptr)
        root = pt_left; // Se pt era a raiz, pt_left vira a nova raiz
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left; // Se pt era filho esquerdo, pt_left vira filho esquerdo
    else
        pt->parent->right = pt_left; // Se pt era filho direito, pt_left vira filho direito

    pt_left->right = pt; // pt vira filho direito de pt_left
    pt->parent = pt_left; // O pai de pt agora é pt_left
}

// Função para corrigir violações das propriedades da Árvore Rubro-Negra
void RBTree::fixViolation(Node *&root, Node *&pt) {
    Node *parent_pt = nullptr;
    Node *grand_parent_pt = nullptr;

    // Enquanto houver violação (pai e avô são vermelhos)
    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED)) {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        // Caso A: O pai de pt é filho esquerdo do avô
        if (parent_pt == grand_parent_pt->left) {

            Node *uncle_pt = grand_parent_pt->right; // Tio de pt (filho direito do avô)

            // Caso 1: O tio é vermelho (apenas recoloração)
            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt; // Move o ponto de verificação para o avô
            } else {
                // Caso 2: pt é filho direito do pai (rotação à esquerda)
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                // Caso 3: pt é filho esquerdo do pai (rotação à direita e recoloração)
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }

        // Caso B: O pai de pt é filho direito do avô
        else {
            Node *uncle_pt = grand_parent_pt->left; // Tio de pt (filho esquerdo do avô)

            // Caso 1: O tio é vermelho (apenas recoloração)
            if ((uncle_pt != nullptr) && (uncle_pt->color == RED)) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt; // Move o ponto de verificação para o avô
            } else {
                // Caso 2: pt é filho esquerdo do pai (rotação à direita)
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                // Caso 3: pt é filho direito do pai (rotação à esquerda e recoloração)
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK; // A raiz sempre deve ser preta
}

// Função para inserir um novo valor na árvore
void RBTree::insert(const int &data) {
    Node *pt = new Node(data); // Cria um novo nó

    // Insere como em uma árvore binária comum
    if (root == nullptr) {
        root = pt;
        root->color = BLACK; // A raiz sempre é preta
        return;
    }

    Node *parent = nullptr;
    Node *current = root;

    // Encontra a posição correta para o novo nó
    while (current != nullptr) {
        parent = current;
        if (pt->data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    pt->parent = parent;

    // Define o novo nó como filho esquerdo ou direito do pai
    if (pt->data < parent->data)
        parent->left = pt;
    else
        parent->right = pt;

    // Corrige violações das propriedades da Árvore Rubro-Negra
    fixViolation(root, pt);
}

// Função para realizar a travessia in-order
void RBTree::inorder() {
    inorderHelper(root);
}

// Função para realizar a travessia em nível
void RBTree::levelOrder() {
    if (root == nullptr)
        return;

    cout << root->data << " "; // Visita a raiz
    levelOrderHelper(root);    // Visita os demais nós
}

// Função principal
int main() {
    RBTree tree;

    // Insere valores na árvore
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);

    // Exibe a travessia in-order
    cout << "Travessia In-Order da Árvore Criada:\n";
    tree.inorder();

    // Exibe a travessia em nível
    cout << "\n\nTravessia em Nível da Árvore Criada:\n";
    tree.levelOrder();

    return 0;
}