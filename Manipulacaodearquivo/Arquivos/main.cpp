#include <iostream>
#include <fstream>

//ifstream input leitura
//ofstram output escrita

using namespace std;

int main()
{
    //Criando um arquivo
    //ofstream arquivo("dados.txt");
    //verificar se houve erro
    //if (!arquivo)
    //{
      //  cout << "Erro ao tentar criar o arquivo. ";
      //  return 1;
    //}
   /* //Manipulacao do meu arquivo
    //O operador << funciona como o << do cout, mas direcionando a saida para o arquivo.
    arquivo << "Ola mundo!\n";
    arquivo << "\n\nEstou gravando informacoes no arquivo texto";
    int a =200;
    arquivo << "\n" << a;
    //fechando o arquivo
    arquivo.close();*/

    char nome[100];
    float nota;
    ofstream arquivo("NomeENota.txt");
    if (!arquivo)
    {
        cout << "Erro ao tentar criar o arquivo. ";
        return 1;
    }

    for(int i=0;i<10;i++)
    {
        cout << "Digite o nome do aluno" ;
        cin >> nome;
        cout << "Digite a nota do aluno";
        cin >> nota;
        arquivo << "\n Nome: "<< nome << " Nota: " << nota;
    }

    arquivo.close();


    return 0;
}
