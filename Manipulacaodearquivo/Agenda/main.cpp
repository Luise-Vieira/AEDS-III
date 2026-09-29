#include <iostream>
#include <fstream>

using namespace std;

struct Contato {
    int codigo;
    char nome[50];
    char telefone[20];
};

class Agenda {
private:
    Contato contatos[100];
    int quantidade;

public:
    Agenda() {
        quantidade = 0;
    }

    void carregarDados(char *nomeArquivo)
    {
      ifstream fin;
        fin.open(nomeArquivo, ios:: binary); //passa o nome do arquivo e o jeito que vai ser salvo, nesse caso binario
        if(!fin)
        {
            cout << "Erro ao tentar criar o arquivo.\n";
            return;
        }

        //Mais facil /grava mais bytes
        fin.read((char*)this, sizeof(Agenda));// passa o endereço e o tamanho


        //Mais codigo / gera arquivos menores
        /*fin.write(&this->quantidade,sizeof(int));//quantidade n é ponteiro ent precisa passar o endereço
        for (int i=0; i< this->quantidade; i++)
        {
         fout.read((char*) &this->contatos[i],sizeof(Contato));
        }*/

          fin.close();
    }
    void salvarDados(char *nomeArquivo)
    {
        ofstream fout;
        fout.open(nomeArquivo, ios:: binary); //passa o nome do arquivo e o jeito que vai ser salvo, nesse caso binario
        if(!fout)
        {
            cout << "Erro ao tentar criar o arquivo.\n";
            return;
        }

        //Mais facil /grava mais bytes
        fout.write((char*)this, sizeof(Agenda));// passa o endereço e o tamanho


        //Mais codigo / gera arquivos menores
        /*fout.write(&this->quantidade,sizeof(int));//quantidade n é ponteiro ent precisa passar o endereço
        for (int i=0; i< this->quantidade; i++)
        {
         fout.write((char*) &this->contatos[i],sizeof(Contato));
        }*/

          fout.close();

        //A mesma estrategia para gravar tem que ser a mesma pra ler
    }

    void SalvarHTML (char *nomeArquivo) //descobrir como fazer uma tabela em html e imprimir os contatos, ent tem que fzr um for para salvar no html
    {
        ofstream fout;

        fout.open (nomeArquivo);

        if(!fout)
        {
            cout << "Erro ao criar um arquivo HTML";
            return;
        }

        fout << "<html>";

        fout << "<head>";

        fout << "<title>";
        fout << "Lista de Contatos";
        fout << "</title>";

        fout << "</head>";

        fout << "<body>";

        fout << "<h1> Lista de Contatos </h1>";

        fout << "</body>";

        fout << "</html>";

        fout.close();

    }

    void inserir() {
        if (quantidade >= 100) {
            cout << "Limite de 100 contatos atingido!\n";
            return;
        }

        cout << "Codigo: ";
        cin >> contatos[quantidade].codigo;

        cout << "Nome: ";
        //cin.ignore();
        cin >> contatos[quantidade].nome;

        cout << "Telefone: ";
        cin >> contatos[quantidade].telefone;

        quantidade++;

        cout << "\nContato inserido com sucesso!\n";
    }

    void alterar() {
        int codigo;
        int posicao = -1;

        cout << "Digite o codigo do contato: ";
        cin >> codigo;

        for (int i = 0; i < quantidade; i++) {
            if (contatos[i].codigo == codigo) {
                posicao = i;
                break;
            }
        }

        if (posicao == -1) {
            cout << "\nContato nao encontrado!\n";
            return;
        }

        cout << "\nNovo nome: ";
        cin >> contatos[posicao].nome;

        cout << "Novo telefone: ";
        cin >> contatos[posicao].telefone;

        cout << "\nContato alterado com sucesso!\n";
    }

    void excluir() {
        int codigo;
        int posicao = -1;

        cout << "Digite o codigo do contato: ";
        cin >> codigo;

        for (int i = 0; i < quantidade; i++) {
            if (contatos[i].codigo == codigo) {
                posicao = i;
                break;
            }
        }

        if (posicao == -1) {
            cout << "\nContato nao encontrado!\n";
            return;
        }

        for (int i = posicao; i < quantidade - 1; i++) {
            contatos[i] = contatos[i + 1];
        }

        quantidade--;

        cout << "\nContato excluido com sucesso!\n";
    }

    void mostrarTodos() {
        if (quantidade == 0) {
            cout << "Nenhum contato cadastrado!\n";
            return;
        }

        cout << "===== CONTATOS =====\n\n";

        for (int i = 0; i < quantidade; i++) {
            cout << "Codigo: " << contatos[i].codigo << endl;
            cout << "Nome: " << contatos[i].nome << endl;
            cout << "Telefone: " << contatos[i].telefone << endl;
            cout << "-------------------------\n";
        }
    }

    void loop () {
        int opcao;

        do {
            system("cls");

            cout << "=============================\n";
            cout << "       AGENDA DE CONTATOS\n";
            cout << "=============================\n";
            cout << "1 - Inserir contato\n";
            cout << "2 - Alterar contato\n";
            cout << "3 - Excluir contato\n";
            cout << "4 - Mostrar todos\n";
            cout << "5 - Mostrar todos(HTML)\n";
            cout << "0 - Sair\n";
            cout << "=============================\n";
            cout << "Digite uma opcao: ";
            cin >> opcao;

            system("cls");

            switch (opcao) {
                case 1:
                    inserir();
                    break;

                case 2:
                    alterar();
                    break;

                case 3:
                    excluir();
                    break;

                case 4:
                    mostrarTodos();
                    break;
                case 5:
                    SalvarHTML("contatos.html");
                    system("contatos.html");
                    break;

                case 0:
                    cout << "Programa encerrado.\n";
                    break;

                default:
                    cout << "Opcao invalida!\n";
            }

            if (opcao != 0) {
                system("pause");
            }

        } while (opcao != 0);
    }
};

int main() {

    //system("teste.html"); Isso aq abre no navegador
    //criar um arquivo de texto chamado contatos html e salvar os contatos dentro dele.

    Agenda agenda;

    agenda.carregarDados("dados.bin");
    system("pause");
    agenda.loop();
    agenda.salvarDados("dados.bin");
    return 0;
}

