#include <iostream>

using namespace std;
struct Node
{
    int item;
    Node *next;
};

class List
{
private:
    Node *head;
    Node *tail;
    int n;
    // Função usasa para obter um no da lista
    // pelo seu indice (0.. n-1)
    Node *getNode(int pos)
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
    // Construtor
    List()
    {
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }
    // Destrutor
    ~List()
    {
        this->clear();
    }
    // Inserir no inicio
    void pushFront(int item)
    {
        // cria um novo no
        Node *t = new Node();
        t->item = item;
        t->next = NULL;
        if (this->isEmpty())
        {
            // Se estiver vazia -> atribui na primeira posição
            this->head = t;
            this->tail = t;
        }
        else
        {
            t->next = this->head; // t liga o novo item inserido na frente a head
            this->head = t;       // head aponta para o primeiro elemento novamente ao receber t
        }
        this->n++;
    }
    // Inserir no final
    void pushBack(int item)
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
            this->tail->next = t; // o next do tail passa a apontar para o ultimo que no caso foi a nova caixinha criada
            this->tail = t;       // o tail passa a apontar para onde t aponta
            this->n++;
        }
    }
    // Inserir em uma posição
    void push(int item, int pos)
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
        else if (pos == n - 1)
        {
            this->pushBack(item);
        }
        else // Neste caso existem pelo menos 2 elementos na lista e n estou inserindo nem no inicio nem no fim
        {
            Node *nn = new Node(); // Cria um novo no para ligar entre duas caixas q estao no meio
            nn->item = item;
            // posicionar um temporario na posição anterior
            Node *t1 = this->getNode(pos - 1);
            Node *t2 = t1->next;
            t1->next = nn;
            nn->next = t2;
            this->n++;
        }
    }
    // Remover do inicio
    int popFront()
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
                delete t;
            }
            this->n--;
            return item;
        }
    }
    // Remover do Final
    int popBack()
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
            Node *t = this->getNode(this->n - 2);
            int item = this->tail->item;
            delete this->tail;
            t->next = NULL;
            this->tail = t;
            this->n--;
            return item;
        }
    }
    // Remover de uma posição especifica
    int pop(int pos)
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia \n";
            return -1;
        }
        else
        {
            // fez a copia do item para imprimir
            if (this->n == 1)
            {
                return this->popFront();
            }
            else if (pos == n - 1)
            {
                return this->popBack();
            }
            else
            {
                int item = this->head->item;
                Node *t1 = this->getNode(pos - 1);
                Node *t2 = t1->next;
                item = t2->item;
                t1->next = t2->next;
                delete t2;
                this->n--;
                return item;
            }
        }
    }
    // Retorna o item do inicio
    int getFront()
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

    // Retorna o item do final
    int getBack()
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
    // Retorna o item de uma posição
    int get(int pos)
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
    // Tamanho da lista
    int size()
    {
        return this->n;
    }
    // Verifica se está vazia
    bool isEmpty()
    {
        return this->n == 0; // Jeito reduzido do if else
    }
    // Apaga todos os elementos da lista
    void clear()
    {
        while (!this->isEmpty())
        {
            this->popFront();
        }
    }
    // Mostra todos os elementos da lista
    void show()
    {
        cout << "\nLista: ";
        for (Node *t = this->head; t != NULL; t = t->next)
        {
            cout << t->item << " ";
        }
        cout << "\n";
    }
};

;

int main()
{
    // Lista *L= new List(); //usando variavel dinamica e ai no final tem que dar um delete nela delete L;
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
            L.push(item, pos);
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
            cout << L.getFront();
            break;
        case 8:
            cout << L.getBack();
            break;
        case 9:
            cout << "Digite a posicao que deseja visualizar: \n";
            cin >> pos;
            cout << L.get(pos);
            break;
        case 10:
            cout << "Tamanho da lista: " << L.size();
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
            break;
        default:
            cout << "Opcao invalida!";
            break;
        }
        system("pause");
        system("cls");

    } while (op != 0);
}
