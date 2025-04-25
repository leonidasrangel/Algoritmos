#include <iostream>
#include "matriz.h" // Inclui a matriz já inicializada
using namespace std;

// Função para copiar matriz para vetor
void copiarMatrizParaVetor(int matriz[100][100], int vetor[], int linhas, int colunas) {
    int indice = 0;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            vetor[indice++] = matriz[i][j];
        }
    }
}

// Função para imprimir o maior e o menor valor por linha
void imprimirMaiorEMenorPorLinha(int matriz[100][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; ++i) {
        int maior = matriz[i][0];
        int menor = matriz[i][0];
        for (int j = 1; j < colunas; ++j) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
        cout << "Linha " << i << ": Maior = " << maior << ", Menor = " << menor << endl;
    }
}

// Função para imprimir o maior e o menor valor por coluna
void imprimirMaiorEMenorPorColuna(int matriz[100][100], int linhas, int colunas) {
    for (int j = 0; j < colunas; ++j) {
        int maior = matriz[0][j];
        int menor = matriz[0][j];
        for (int i = 1; i < linhas; ++i) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
        cout << "Coluna " << j << ": Maior = " << maior << ", Menor = " << menor << endl;
    }
}

// Função para encontrar o segundo maior valor nas diagonais
void encontrarSegundoMaiorDiagonal(int matriz[100][100], int dimensao) {
    int maior = matriz[0][0];
    int segundoMaior = matriz[0][0];

    // Verifica a diagonal principal
    for (int i = 0; i < dimensao; ++i) {
        int valor = matriz[i][i];
        if (valor > maior) {
            segundoMaior = maior;
            maior = valor;
        } else if (valor > segundoMaior && valor < maior) {
            segundoMaior = valor;
        }
    }

    // Verifica a diagonal secundária
    for (int i = 0; i < dimensao; ++i) {
        int valor = matriz[i][dimensao - 1 - i];
        if (valor > maior) {
            segundoMaior = maior;
            maior = valor;
        } else if (valor > segundoMaior && valor < maior) {
            segundoMaior = valor;
        }
    }

    if (segundoMaior == maior) {
        cout << "Não há um segundo maior valor encontrado." << endl;
    } else {
        cout << "O segundo maior valor nas diagonais é: " << segundoMaior << endl;
    }
}

// Função para inverter uma coluna da matriz
void inverterColuna(int matriz[100][100], int dimensao) {
    int coluna;
    
    // Solicita ao usuário o índice da coluna
    cout << "Digite o índice da coluna a ser invertida (0 a " << dimensao - 1 << "): ";
    cin >> coluna;

    // Verifica se o índice da coluna é válido
    if (coluna < 0 || coluna >= dimensao) {
        cout << "Índice de coluna inválido." << endl;
        return;
    }

    // Exibe a coluna antes da inversão
    cout << "Valores da coluna " << coluna << " antes da inversão:" << endl;
    for (int i = 0; i < dimensao; ++i) {
        cout << matriz[i][coluna] << " ";
    }
    cout << endl;

    // Inverte os valores da coluna especificada
    for (int i = 0; i < dimensao / 2; ++i) {
        int temp = matriz[i][coluna];
        matriz[i][coluna] = matriz[dimensao - 1 - i][coluna];
        matriz[dimensao - 1 - i][coluna] = temp;
    }

    // Exibe a coluna após a inversão
    cout << "Valores da coluna " << coluna << " após a inversão:" << endl;
    for (int i = 0; i < dimensao; ++i) {
        cout << matriz[i][coluna] << " ";
    }
    cout << endl;

    cout << "Coluna " << coluna << " invertida com sucesso." << endl;
}

// Função para preencher a matriz com o primeiro nome do usuário
void preencherMatrizComNome(int matriz[100][100], int linhas, int colunas, const string& nome) {
    // Vetor Z para armazenar os valores correspondentes às letras do nome
    int Z[100];
    int tamanhoZ = nome.size();
    
    // Preenche o vetor Z com os valores correspondentes e imprime na tela
    cout << "Valores correspondentes às letras do nome:" << endl;
    for (int k = 0; k < tamanhoZ; ++k) {
        char letra = nome[k];
        // Converte letras maiúsculas para minúsculas se necessário
        if (letra >= 'A' && letra <= 'Z') {
            letra = letra - 'A' + 'a';
        }
        Z[k] = letra - 'a' + 1;
        cout << nome[k] << " = " << Z[k] << endl; // Imprime o valor correspondente
    }
    
    // Define os índices i e j com base no primeiro e no último valor de Z
    int i = Z[0] - 1;  // Primeiro valor de Z
    int j = Z[tamanhoZ - 1] - 1;  // Último valor de Z
    
    // Verifica se os índices estão dentro dos limites da matriz
    if (i < 0 || i >= linhas || j < 0 || j >= colunas) {
        cout << "Índices (i, j) fora dos limites da matriz." << endl;
        return;
    }
    
    // Preenche a matriz com valores fixos (por exemplo, números sequenciais)
    int valor = 1;
    for (int x = 0; x < linhas; ++x) {
        for (int y = 0; y < colunas; ++y) {
            matriz[x][y] = valor++;
            if (valor > 100) valor = 1;  // Reinicia o valor após 100
        }
    }
    
    // Coloca a primeira letra na posição (i, j)
    matriz[i][j] = nome[0];
    
    // Preenche a mesma linha com as letras restantes, respeitando a condição de soma par
    int k = 1;  // Índice para o vetor Z, começando pela segunda letra do nome
    for (int col = j + 1; col < colunas && k < tamanhoZ; ++col) {
        if ((i + col) % 2 == 0) {  // Verifica se a soma dos índices é par
            matriz[i][col] = nome[k];
            ++k;
        }
    }
    
    cout << "Matriz preenchida com sucesso." << endl;
}

// Função para verificar quantas vezes um número aparece na matriz
void verificarNumeroNaMatriz(int matriz[100][100], int linhas, int colunas, int numero) {
    int contador = 0;
    
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (matriz[i][j] == numero) {
                contador++;
            }
        }
    }
    
    cout << "O número " << numero << " aparece " << contador << " vezes na matriz." << endl;
}

int main() {
    // A matriz já foi inicializada no arquivo "matriz.h"
    
    int vetor[10000];  // Vetor para armazenar os elementos da matriz
    copiarMatrizParaVetor(matriz, vetor, 100, 100);
    
    cout << "Imprimir maior e menor por linha:" << endl;
    imprimirMaiorEMenorPorLinha(matriz, 100, 100);
    
    cout << "Imprimir maior e menor por coluna:" << endl;
    imprimirMaiorEMenorPorColuna(matriz, 100, 100);
    
    cout << "Encontrar o segundo maior valor nas diagonais:" << endl;
    encontrarSegundoMaiorDiagonal(matriz, 100);
    
    cout << "Inverter uma coluna:" << endl;
    inverterColuna(matriz, 100);
    
    // Solicita ao usuário o primeiro nome
    string primeiroNome;
    cout << "Digite o seu primeiro nome: ";
    cin >> primeiroNome;
    
    // Preencher a matriz com o primeiro nome do usuário
    preencherMatrizComNome(matriz, 100, 100, primeiroNome);
    
    // Solicita ao usuário o último nome
    string ultimoNome;
    cout << "Digite o seu último nome: ";
    cin >> ultimoNome;
    
    // Criar o vetor C com os números correspondentes ao último nome digitado
    int C[100];
    int tamanhoC = ultimoNome.size();
    
    // Preencher o vetor C e imprimir os valores
    cout << "Valores correspondentes às letras do último nome:" << endl;
    int somatorio = 0;
    for (int k = 0; k < tamanhoC; ++k) {
        char letra = ultimoNome[k];
        // Converte letras maiúsculas para minúsculas se necessário
        if (letra >= 'A' && letra <= 'Z') {
            letra = letra - 'A' + 'a';
        }
        C[k] = letra - 'a' + 1;
        cout << ultimoNome[k] << " = " << C[k] << endl; // Imprime o valor correspondente
        somatorio += C[k];  // Calcula o somatório
    }
    
    // Verificar quantas vezes o somatório aparece na matriz
    verificarNumeroNaMatriz(matriz, 100, 100, somatorio);
    
    return 0;
}
