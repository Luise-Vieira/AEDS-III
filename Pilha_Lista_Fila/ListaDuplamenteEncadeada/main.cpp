#include <iostream>

using namespace std;

struct Node
{
    int item;
    Node *prev;
    Node *next;
};

class List
{

private:
    Node *head;
    Node *tail;
    int n;

    //Função usada para obter um nó da lista
    //pelo seu índice (0 .. n-1).
    //É possivel melhorar essa implementação para deixar esse metodo mais eficiente, percorrendo a lista a partir do fim para o inicio
    //quando necessario.
    Node* getNode (int pos)
    {
        int i = 0;
        Node *t = this->head;
        while (i < pos)
        {
            t = t->next;
            i++;
        }
        return t;
    }


public:
    //Construtor
    List()
    {
        this->head=NULL;
        this->tail=NULL;
        this->n=0;
    }

    //Detrutor
    ~List()
    {
        this->clear();
    }

    //Inserir no início
    void pushFront (int item)
    {
        Node *nn = new Node();
        nn->item=item;
        nn->prev=NULL;
        nn->next=NULL;
        if(this->isEmpty())
        {
            this->head =nn;
            this->tail=nn;
        }
        else
        {
            this->head->prev=nn;
            nn->next=this->head;
            this->head=nn;
        }
        this->n++;

    }

    //Inserir no final
    void pushBack (int item)
    {


    }

    //Insrir em uma posição
    void pushAt (int item, int pos)
    {

    }

    //Remover do início
    int popFront ()
    {


    }


    //Remover do final
    int popBack ()
    {

    }

    //Remover de uma posição
    int pop ( int pos )
    {

    }

    //Retorna o item do início
    int getFront ()
    {

    }

    //Retorna o item do final
    int getBack ()
    {

    }

    //Retorna o item de uma posição
    int get (int pos)
    {

    }

    //Tamanho da lista
    int size ()
    {
        return this->n;
    }

    //Verifica se está vazia
    bool isEmpty ()
    {
        return this->n == 0;
    }

    //Apaga todos os elementos da lista
    void clear ()
    {

    }


    //Mostra todos os elementos da lista
    void show ()
    {
        cout << "\nList --> ";
        Node *t;
        t=this->head;
        while(t!=NULL)
        {
            cout << t->item << " ";
            t=t->next;
        }
        cout << "\nList <-- ";
        t=this->tail;
        while(t!=NULL)
        {
            cout << t->item << " ";
            t=t->prev;
        }
        cout << "\n n= " << this->n;
    }

    //Atribui um valor a elemento da lista
    void set (int item, int pos)
    {

    }

};




int main()
{
    List L;
    L.pushFront(10);
    L.pushFront(11);
    L.pushFront(12);
    L.show();
    return 0;
}
