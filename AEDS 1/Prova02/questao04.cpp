/*(A) Faça uma sub-rotina que receba como parâmentro um número inteiro positivo e retorne 
o fatorial deste número. Lembre-se que n! = n*(n-1)*(n-2)*(...)* 3 * 2 * 1 

(B) Faça uma sub-rotina que receba como parâmetro um vetor de inteiros e seu tamanho e amazene
em cada posição i do vetor fatorial de (i+2). É obrigatório utilizar a sub-rotina da letra (a).

(C) Faça um programa principal (main) que crie um vetor de 15 posições e inicialize-o com a sub-rotina
da letra (B). Depois o programa deve ler uma sequência de valores inteiros, usando um laço, de forma que:
Se o valor digitado teve seu fatorial calculado durante a inicialização do vetor, seu programa deve
imprimir qual é a resposta do fatorial desse valor digitado, obrigatoriamente, imprimindo-a através de um
dos valores armazenados no vetor já inicializado. Proibido calcular novamente o fatorial.
Caso contrario, o programa deve ser encerrado. Isto é, um valor digitado que não teve fatorial pré calculado
encerrará a sequência de valores, terminando o laço, e indicará o término do programa.
*/

#include <iostream>
#include <vector>
using namespace std;

// Sub-rotina para calcular o fatorial de um número inteiro positivo
int fatorial(int n) {
    int resultado = 1;
    for(int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}
// Sub-rotina para preencher o vetor com fatoriais de (i+2)
void preencherFatoriais(vector<int>& vetor) {
    int tamanho = vetor.size();
    for(int i = 0; i < tamanho; i++) {
        vetor[i] = fatorial(i + 2);
    }
}
int main() {
    // Cria um vetor de 15 posições
    vector<int> vetor(15);

    // Inicializa o vetor com a sub-rotina da letra (B)
    preencherFatoriais(vetor);

    // Imprime os fatoriais para referência
    cout << "Vetor de fatoriais pre-calculados:" << endl;
    for(int i = 0; i < 15; i++) {
        cout << "fatorial(" << i + 2 << ") = " << vetor[i] << endl;
    }

    // Lê uma sequência de valores inteiros e imprime o fatorial correspondente
    while (true) {
        int valor;
        cout << "Digite um valor inteiro: ";
        cin >> valor;

        if (valor >= 2 && valor <= 16) {
            // Imprime o fatorial correspondente usando o vetor já inicializado
            cout << "fatorial(" << valor << ") = " << vetor[valor - 2] << endl;
        } else {
            // Encerra o programa se o valor não teve fatorial pré-calculado
            cout << "Valor fora do intervalo pre-calculado. Encerrando o programa." << endl;
            break;
        }
    }

    return 0;
}
