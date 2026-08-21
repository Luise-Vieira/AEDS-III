#include <iostream>

using namespace std;

struct Node  //Novo tipo de dados
{
    int x; //dado manioulado
    Node *next; //Endereco do proximo
};

class Stack  //Novo tipo de dados
{
    //pss colocar funções e variaveis
private:
    int n;
    Node *top;
public:
    //Construtor: Inicializar um objeto.
    //Ele executa automaticamente.
    Stack () //Em c++ ele recebe o msm nome da classe
    {
        cout << "Criei um objeto novo\n";
        this -> n=0; //O this referencia as coisas da propria classe, pq tem como criar variavel local dentro do construtor
        this -> top = NULL;
    }  //Toda vez q vc criar um objeto ele execulta

    void push (int x)//Empilhar
    {
        Node *t = new Node; // Criar uma caixinha dinamica //O t é uma variavel dinamica q ta apontando para a variavel q foi criada
        t-> x =x; //Guardando o dado na caixinha //Se é ponteiro acessa as coisas de dentro com a setinha, quando nao é com ponto.
        t->next = this ->top; //Ligando com o topo
        this -> top = t; //O topo passa a ser o t, pq o top aponta para o t;
        this -> n++; //Aumenta o indice
    }

    int pop ()  //Desempilha e retorna
    {
        if (this-> isEmpty())
        {
            cout << "Erro: pilha vazia.\n";
            return 0;
        }
        Node *t=this->top; //Criou uma variavel temporaria pra onde o topo estava
        this-> top = this -> top->next; //Passou o topo pro item anterior
        int x = t-> x; //O x aq armazena o valor que o t tava apontando para retornar
        delete t; //Aqui apaga a caixinha onde o t estava apontando e deleta, nao pode fazer direto pq se n perde o caminho.
        this -> n--;
        return x;
    }

    int getTop () //Retorna o valor que ta no topo
    {
        if ( !this-> isEmpty())
        {
            return this -> top -> z;
        }
        else
        {
            cout << "Erro: pilha vazia.\n";
        }

    }

    bool isEmpty () //Retorna se esta vazia
    {
        if (this -> n ==0)
        {
            return true;
        }
        else
        {
            return false;
        }// Ou return this -> n == 0;
    }

    int size () //Retorna o tamanho
    {
        return this->n;
    }

    void clear ()
    {
    while (!this->isEmpty())
        this->pop();
    }
    //Void-> n retorna valor, int retorna algum resultado pro usuario.
};


int main()
{
    Stack s; //Meu objeto.
    cout << s.size();

    return 0;
}
