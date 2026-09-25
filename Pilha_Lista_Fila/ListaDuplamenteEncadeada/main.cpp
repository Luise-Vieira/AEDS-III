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
        if (this->isEmpty())
        {
            this->pushFront(item); // Se tiver vazia realiza a msm coisa que inserir na frente
        }
        else
        {
            Node *t = new Node(); // cria nova caixinha
            t->item = item;       // recebe o item na caixinha
            t->next = NULL;       // o next do t aponta pra null
            t->prev = this->tail;
            this->tail->next=t;
            this->tail=t;  
            this->n++;
        }

    }

    //Insrir em uma posição
    void pushAt (int item, int pos)
    {
        if (pos < 0 || pos > this->n)
        {
            cout << "Erro: indice invalido!!\n";
            return;
        }
        if (pos == 0)
        {
            this->pushFront(item);
        }
        else if (pos == this->n )
        {
            this->pushBack(item);
        }
        else // Neste caso existem pelo menos 2 elementos na lista e n estou inserindo nem no inicio nem no fim
        {
            Node *t=this->getNode(pos);
            Node *nn= new Node();
            nn->item=item;
            nn->prev=t->prev;
            nn->next=t;
            t->prev->next=nn;
            t->prev=nn;
            this->n++;
        }
    }

    //Remover do início
    int popFront ()
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia \n";
            return -1;
        }
        else
        {
            int item = this->head->item; // fez a copia do item para imprimir
            if (this->n == 1)
            {
                delete this->head;
                this->head = NULL;
                this->tail = NULL;
            }
            else
            {
                Node *t = this->head;
                this->head = this->head->next;
                this->head->prev=NULL;
                delete t;
            }
            this->n--;
            return item;
        }

    }


    //Remover do final
    int popBack ()
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia \n";
            return -1;
        }
        else if (this->n == 1)
        {
            return this->popFront();
        }
        else
        {
            Node *t = this->tail;
            int item = this->tail->item;
            this->tail = this->tail->prev;
            this->tail->next=NULL;
            delete t;
            this->n--;
            return item ;
        }
    }

    //Remover de uma posição
    int pop ( int pos )
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia \n";
            return -1;
        }
        else
        {
            // fez a copia do item para imprimir
            if (pos =- 0)
            {
                return this->popFront();
            }
            else if (pos == n - 1)
            {
                return this->popBack();
            }
            else
            {
                Node *t = this->getNode(pos);
                int item = t->item;
                t->prev->next = t->next;
                t->next->prev=t->prev;
                delete t;
                this->n--;
                return item;
            }
        }
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
        if (pos < 0 || pos >= this->n)
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
        if (pos < 0 || pos >= this->n)
        {
            cout << "Erro: indice invalido!!\n";
            return;
        }
    
        Node *t = this->getNode(pos);
        t->item = item;
    }

};




int main()
{
    List L;
    int item;
    int pos;
    int op;
    do
    {

        cout << "  ===== MENU =====\n ";
        cout << "1 - Inserir elemento no inicio\n";
        cout << "2 - Inserir elemento no final\n";
        cout << "3 - Inserir elemento em uma posicao\n";
        cout << "4 - Remover elemento do inicio\n";
        cout << "5 - Remover elemento do final\n";
        cout << "6 - Remover elemento de uma posicao\n";
        cout << "7 - Consultar elemento do inicio\n";
        cout << "8 - Consultar elemento do final\n";
        cout << "9 - Consultar elemento de uma posicao\n";
        cout << "10 - Obter tamanho da lista\n";
        cout << "11 - Verificar se a lista está vazia\n";
        cout << "12 - Mostrar lista\n";
        cout << "13 - Remover todos os elementos\n";
        cout << "0 - Sair\n";
        cout << "Digite a opcao que deseja: ";
        cin >> op;
        switch (op)
        {
        case 1: // inserir elemento no inicio
            cout << "Digite o elemento que deseja inserir:";
            cin >> item;
            L.pushFront(item);
            break;
        case 2: // Inserir elemento no final
            cout << "Digite o elemento que deseja inserir:";
            cin >> item;
            L.pushBack(item);
            break;
        case 3: // Inserir elemento em uma posicao
            cout << "Digite o elemento que deseja inserir:";
            cin >> item;
            cout << "Digite a posicao que deseja inserir:";
            cin >> pos;
            L.pushAt(item, pos);
            break;
        case 4: // Remover elemento do início
            cout << L.popFront();
            break;
        case 5: // Remover elemento do final
            cout << L.popBack();
            break;
        case 6:
            cout << "Digite a posicao que quer remover: \n";
            cin >> pos;
            cout << L.pop(pos);
            break;
        case 7:
            if (L.isEmpty() == false)
            {
                cout << "item: " << L.getFront() << "\n";
            }
            else
            {
                L.getFront();
            }
            break;
        case 8:
            if (L.isEmpty() == false)
            {
                cout << "item: " << L.getBack() << "\n";
            }
            else
            {
                L.getBack();
            }
            break;
        case 9:
            if (L.isEmpty() == false)
            {
                cout << "Digite a posicao que deseja visualizar: \n";
                cin >> pos;
                cout << "item: " << L.get(pos) << "\n";
            }
            else
            {
                L.getFront();
            }
            break;
        case 10:
            cout << "Tamanho da lista: " << L.size() << "\n";
            break;
        case 11:
            if (L.isEmpty() == true)
            {
                cout << "Lista esta vazia!\n";
            }
            else
            {
                cout << "A lista contem " << L.size() << " elementos\n";
            }
            break;
        case 12:
            L.show();
            break;
        case 13:
            L.clear();
            cout << "Lista esvaziada!\n";
            break;
        default:
            cout << "Opcao invalida!";
            break;
        }
        system("pause");
        system("cls");

    } while (op != 0);
}
