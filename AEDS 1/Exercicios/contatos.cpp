#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Classe para armazenar informações de um contato
class Contato {
private:
    int id;
    string nome;
    string telefone;

public:
    // Construtor
    Contato(int id = 0, const string& nome = "", const string& telefone = "")
        : id(id), nome(nome), telefone(telefone) {}

    // Métodos de acesso (getters)
    int getId() const { return id; }
    string getNome() const { return nome; }
    string getTelefone() const { return telefone; }

    // Métodos de modificação (setters)
    void setId(int novoId) { id = novoId; }
    void setNome(const string& novoNome) { nome = novoNome; }
    void setTelefone(const string& novoTelefone) { telefone = novoTelefone; }

    // Exibir as informações do contato
    void exibirContato() const {
        cout << id << " - " << nome << " - " << telefone << endl;
    }
};

// Classe para gerenciar os contatos
class GerenciadorContatos {
private:
    vector<Contato> contatos;

public:
    // Método para ler os contatos do arquivo
    void carregarContatos(const string& nomeArquivo) {
        ifstream arquivoEntrada(nomeArquivo);
        if (!arquivoEntrada.is_open()) {
            cout << "Erro ao abrir o arquivo!" << endl;
            return;
        }

        string linha;
        while (getline(arquivoEntrada, linha)) {
            stringstream ss(linha);
            int id;
            string nome, telefone;

            // Leitura do ID
            ss >> id;
            ss.ignore(3);  // Ignorar o " - "

            // Leitura do nome até o próximo " - "
            getline(ss, nome, '-');
            // Remover espaços em branco extras
            nome = nome.substr(0, nome.size() - 1);  // Remove o espaço no final

            // Leitura do telefone
            getline(ss >> ws, telefone);  // Lê o telefone até o final da linha

            // Adiciona o contato ao vetor
            contatos.push_back(Contato(id, nome, telefone));
        }
        arquivoEntrada.close();
    }

    // Método para exibir todos os contatos
    void exibirContatos() const {
        for (const auto& contato : contatos) {
            contato.exibirContato();
        }
    }

    // Método para atualizar o telefone de um contato pelo ID
    void atualizarTelefone(int id, const string& novoTelefone) {
        bool encontrado = false;
        for (auto& contato : contatos) {
            if (contato.getId() == id) {
                contato.setTelefone(novoTelefone);
                encontrado = true;
                break;
            }
        }

        if (encontrado) {
            cout << "Telefone atualizado com sucesso!" << endl;
        } else {
            cout << "Contato com ID " << id << " não encontrado." << endl;
        }
    }

    // Método para salvar os contatos atualizados no arquivo
    void salvarContatos(const string& nomeArquivo) const {
        ofstream arquivoSaida(nomeArquivo);
        if (!arquivoSaida.is_open()) {
            cout << "Erro ao abrir o arquivo para escrita!" << endl;
            return;
        }

        for (const auto& contato : contatos) {
            arquivoSaida << contato.getId() << " - " << contato.getNome() << " - " << contato.getTelefone() << endl;
        }
        arquivoSaida.close();
    }
};

int main() {
    GerenciadorContatos gerenciador;
    string nomeArquivo = "contatos.txt";

    // Carregar contatos do arquivo
    gerenciador.carregarContatos(nomeArquivo);

    // Exibir os contatos carregados
    cout << "Contatos atuais:" << endl;
    gerenciador.exibirContatos();

    // Solicitar ao usuário o ID do contato que deseja alterar
    int idBuscado;
    cout << "\nQual ID do contato deseja alterar: ";
    cin >> idBuscado;

    // Solicitar o novo número de telefone
    string novoTelefone;
    cout << "Informe o novo número para o contato de ID " << idBuscado << ": ";
    cin >> novoTelefone;

    // Atualizar o telefone no contato desejado
    gerenciador.atualizarTelefone(idBuscado, novoTelefone);

    // Salvar as alterações no arquivo
    gerenciador.salvarContatos(nomeArquivo);

    // Exibir os contatos atualizados
    cout << "\nContatos atualizados:" << endl;
    gerenciador.exibirContatos();

    return 0;
}
