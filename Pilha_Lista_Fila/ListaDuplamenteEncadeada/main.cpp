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
        Node *t;
        if(pos < this->n-pos)
        {
            int i = 0;
            t = this->head;
            while (i < pos)
            {
                t = t->next;
                i++;
            }
        }
            else
            {
                int i = this->n-1;
                t = this->tail;
                while (i > pos)
                {
                    t = t->prev;
                    i--;
                }
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
        if (this->isEmpty())
        {
            cout << "Erro: fila vazia.\n";
            return 0;
        }
        else
        {
            // cout << "ITEM: " << this->head->item << "\n";
            return this->head->item;
        }
    }

    //Retorna o item do final
    int getBack ()
    {
        if (this->isEmpty())
        {
            cout << "Erro: fila vazia.\n";
            return 0;
        }
        else
        {
            return this->tail->item;
        }
    }

    //Retorna o item de uma posição
    int get (int pos)
    {
        if (pos < 0 || pos > this->n)
        {
            cout << "Erro: indice invalido!!\n";
            return -1;
        }
        if (pos == 0)
        {
            return this->getFront();
        }
        else if (pos == n - 1)
        {
            return this->getBack();
        }
        else
        {
            Node *t = this->getNode(pos);
            return t->item;
        }

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
    void clear()
    {
        while (!this->isEmpty())
        {
            this->popFront();
        }
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
        cout << endl;
    }

    //Atribui um valor a elemento da lista
    void set (int item, int pos)
    {

    }

};




int main()
{
    int item;
    int pos;
    int op;

    List L;
    L.pushFront(10);
    L.pushFront(20);
    L.pushFront(30);
    L.pushFront(40);
    L.pushFront(50);
    L.pushFront(60);
    L.pushFront(70);
    L.pushFront(80);
    L.pushFront(90);
    L.pushFront(100);
    L.show();
    for(int i=0;i<L.size();i++)
    {

    cout << L.get(i) << "\n";
    }
}
