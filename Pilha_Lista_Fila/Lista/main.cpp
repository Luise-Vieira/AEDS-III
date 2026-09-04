#include <iostream>

using namespace std;
struct Node
{
    int item;
    Node *next;
};

class List
{
privade:
    Node *head;
    Node *tail;
    int n;

public:
    //Construtor
    void List()
    {
        this->head= NULL;
        this->tail= NULL ;
        this->n=0;
    }
    //Destrutor
    ~List()
    {

    }
    //Inserir no inicio
    void pushFront (int item)
    {
        //cria um novo no
        Node *t =new Node();
        t->item =item;
        t->next= NULL;
        if (this->isEmpty)
        {
            //Se estiver vazia -> atribui na primeira posição
            this->head= t;
            this->tail=t;

        }
        else
        {
            t->next=this->head;//t liga o novo item inserido na frente a head
            this->head=t; //head aponta para o primeiro elemento novamente ao receber t
        }
        this->n++;
    }
    //Inserir no final
    void pushBack (int item)
    {
        if (this->isEmpty())
        {
            this->pushFront(item);//Se tiver vazia realiza a msm coisa que inserir na frente
        }
        else
        {
            Node *t =new Node ();
            t->item=item;
            t->next= NULL;
            this->tail->next=t;
            this->tail=t;
            this->n++;



        }

    }
    //Inserir em uma posição
    void pushAt (int item,int pos)
    {

    }
    //Remover do inicio
    int popFront()
    {

    }
    //Remover do Final
    int popBack()
    {

    }
    //Remover de uma posição especifica
    int pop (int pos)
    {

    }
    //Retorna o item do inicio
    int getFront()
    {

    }
    //Retorna o item do final
    int getBack()
    {

    }
    //Retorna o item de uma posição
    int get(int pos)
    {

    }
    //Tamanho da lista
    int size ()
    {
        return this->n;
    }
    //Verifica se está vazia
    bool isEmpty()
    {
        return this->n==0; //Jeito reduzido do if else
    }
    //Apaga todos os elementos da lista
    void clear ()
    {

    }
    //Mostra todos os elementos da lista
    void show()
    {

    }


};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
