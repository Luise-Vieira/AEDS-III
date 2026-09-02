#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node *next;
};

class Queue // Fila
{

private:
    Node *head; // Ponteiro para o início
    Node *tail; // para o fim
    int n;      // Contador de elementos

public:
    Queue() // Construtor
    {
        cout << "Inicializando a fila\n";
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }

    ~Queue() // Destrutor
    {
        cout << "Destruindo a fila.\n";
    }

    void enqueue(int x) // Enfileirar
    {
        Node *t = new Node(); // Cria uma nova caixinha
        t->x = x;             // O x q foi passado como parametro entra dentro da caixinha do t
        t->next = NULL;       // O proximo dessa nova caixinha aponta pra null

        if (this->n == 0) // se vazia a head e a tail apontam para o unico no presente
        {
            this->head = t;
            this->tail = t;
        }
        else
        {
            this->tail->next = t; // caso n esteja vazia, o tail passa a apontar para proxima caixinha
            this->tail = t;       // O t aponta para onde o t ta apontando.
        }
        this->n++;
    }

    int dequeue() // Desenfileirar retornando
    {
        if (this->isEmpty())
        {
            cout << "Erro: fila vazia.\n";
            return -1;
        }
        else if (this->n == 1)
        {
            int x = this->head->x;
            delete this->tail;
            this->head->NULL;
            this->tail->NULL;
            this->n--;
            return x;
        }
        else
        {
            int x = this->head->x;
            Node *t = this->head; // o t recebe o head para o head pular pra proxima e cknseguir apagar a caixinha q saiu
            this->head = this->head->next;
            delete t;
            this->n--;
            return x;
        }
    }

    bool isEmpty() // Verifica se está vazia
    {
        if (this->n == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size() // Tamanho
    {
        return this->n;
    }

    void clear() // Limpa a fila
    {
        while (n != 0)
        {
            Node *t = this->head;
            this->head = this->head->next;
            delete t;
            n--;
        }
    }

    void show() // Mostrar
    {
    }

    Node *first() // Retorna o primeiro elemento
    {
        if (this->isEmpty())
        {
            cout << "Erro: fila vazia.\n";
            return 0;
        }
        else
        {
            return this->head;
        }
    }
};

int main()
{
    // Queue *Q = new Queue(); //variavel dinamica= controlo o tempo que ela vive/ variavel automatica = sai da memoria quando o programa finaliza.

    int op;
    int item;
    Queue Q;
    do
    {
        cout << "==MENU==\n";
        cout << "0-Sair\n";
        cout << "1-Enfileirar\n";
        cout << "2-Desenfileirar\n";
        cout << "3-Consultar o elemento que está no início da fila\n";
        cout << "4-Tamanho da fila\n";
        cout << "5-Verificar se estar vazia\n";
        cout << "6-Imprimir fila\n";
        cout << "7-Limpar fila\n";
        cout << "Digite uma opcao: ";
        cin >> op;

        switch (op)
        {
        case 0:
            break;
        case 1:
            cout << "Digite o item: ";
            cin >> item;
            Q.enqueue(item);
            break;
        case 2:
            Q.dequeue();
            break;
        case 3:
            Q.first();
            break;
        case 4:
            Q.size();
        case 5:
            Q.isEmpty();
            break;
        case 6:
            Q.show();
            break;
        case 7:
            Q.clear();
            break;

        default:
            cout << "Opcao invalida\n";
            break;
        }}
        while (op != 0);
            
        Q.~Queue();
        return 0;
    }
