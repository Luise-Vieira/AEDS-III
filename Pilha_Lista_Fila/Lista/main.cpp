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
//Função usasa para obter um no da lista
//pelo seu indice (0.. n-1)
    Node* getNode (int pos)
    {
        int i=0;
        Node *t = this->head;
        while(i<pos)
        {
            t=t->next;
            i++;
        }
        return t;
    }

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
            Node *t =new Node ();//cria nova caixinha
            t->item=item; //recebe o item na caixinha
            t->next= NULL;// o next do t aponta pra null
            this->tail->next=t;// o next do tail passa a apontar para o ultimo que no caso foi a nova caixinha criada
            this->tail=t; //o tail passa a apontar para onde t aponta
            this->n++;



        }

    }
    //Inserir em uma posição
    void pushAt (int item,int pos)
    {
        if(pos <=0 || pos > this->n)
        {
            cout << "Erro: indice invalido!!\n";
            return;
        }
        if(pos == 0)
        {
            this->pushFront(item);
        } else if (pos == n-1)
        {
            this->pushBack(item);
        }
        else //Neste caso existem pelo menos 2 elementos na lista e n estou inserindo nem no inicio nem no fim
        {
            Node *nn= new Node(); //Cria um novo no para ligar entre duas caixas q estao no meio
            nn->item=item;
            //posicionar um temporario na posição anterior
            Node *t1= this->getNode(pos-1);
            Node *t2=t1->next;
            t1->next=nn;
            nn->next=t2;
            this->n++;
        }

    }
    //Remover do inicio
    int popFront()
    {
        if(this->isEmpty())
        {
            cout << "Erro: Lista vazia \n";
            return -1;
        }
        else
        {
            int item= this->head->item; //fez a copia do item para imprimir
            if(this->n==1)
            {
                delete this->head;
                this->head= NULL;
                this->tail= NULL;
            }
            else
            {
                Node *t = this->head;
                this->head = this->head->next;
                delete t;
            }
            this->n--;
            return item;
        }

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
