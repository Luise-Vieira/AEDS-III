#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void criaArquivo (int *A,int n, char *nomeArquivo)
{
    ofstream fout;
    fout.open (nomeArquivo, ios::binary);
    if (!fout)
    {
        cout << "Erro ao criar o arquivo. \n";
        return;
    }

    for(int i = 0; i< n; i++)
    {
        fout.write ((char*)&A[i],sizeof(int));
    }
    fout.close();
}

int main()
{
    //int A[10]={5,2,8,40,65,89,78,2,10};
    //criaArquivo(A,10,"numeros.bin");

    ifstream fin;
    fin.open("numeros.bin", ios :: binary);

    if(!fin)
    {
        cout << "Erro ao abrir o arquivo. \n";
        return 0;
    }
    int valor;
    vector<int> bloco;
    //Enquanto ler,processa o dado
    while(fin.read((char*)&valor,sizeof(int)))
    {
        bloco.push_back(valor);
    }
    //Ordenando a lista
    sort (bloco.begin(),bloco.end());

    ofstream fout;
    fout.open ("run.bin", ios :: binary);
    if (!fout)
    {
        cout << "Erro ao criar o arquivo";
    }
    //Para cada elemento x do bloco
    for(int x : bloco)
    {
        fout.write (( char *)&x,sizeof(int));
        cout << x << " ";
    }

    return 0;
}
