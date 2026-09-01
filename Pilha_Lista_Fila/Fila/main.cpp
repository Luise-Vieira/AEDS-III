#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node *next;
};

class Queue   //Fila
{

private:
    Node *head; //Ponteiro para o início
    Node *tail; //para o fim
    int n;      //Contador de elementos


public:
    Queue()  //Construtor
    {
        cout<< "Inicializando a fila\n";
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }

    ~Queue ()  //Destrutor
    {
        cout << "Destruindo a fila.\n";

    }

    void enqueue (int x)  //Enfileirar
    {
        Node *t = new Node(); //Cria uma nova caixinha
        t->x = x; //O x q foi passado como parametro entra dentro da caixinha do t
        t->next = NULL; // O proximo dessa nova caixinha aponta pra null

        if (this->n == 0)  //se vazia a head e a tail apontam para o unico no presente
        {
            this->head = t;
            this->tail = t;
        }
        else
        {
            this->tail->next = t; //caso n esteja vazia, o tail passa a apontar para proxima caixinha
            this->tail = t; // O t aponta para onde o t ta apontando.
        }
        this->n++;
    }

    int dequeue ()  //Desenfileirar retornando
    {
        if (this->isEmpty())
        {
            cout << "Erro: fila vazia.\n";
            return -1;
        }
        else if(this->n == 1)
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
            Node *t= this->head; //o t recebe o head para o head pular pra proxima e cknseguir apagar a caixinha q saiu
            this->head = this->head->next;
            delete t;
            this->n--;
            return x;

        }

    }

    bool isEmpty()   //Verifica se está vazia
    {
        if (this->n == 0 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size ()   //Tamanho
    {
        return this->n;

    }

    void clear ()   //Limpa a fila
    {

    }

    void show ()   //Mostrar
    {

    }

    int first ()   //Retorna o primeiro elemento
    {

    }
};

int main()
{
    //Queue *Q = new Queue(); //variavel dinamica= controlo o tempo que ela vive/ variavel automatica = sai da memoria quando o programa finaliza.
    Queue Q;


    return 0;
}
