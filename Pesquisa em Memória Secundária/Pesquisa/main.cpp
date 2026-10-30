#include <iostream>
#include <fstream>
using namespace std;
void gravaArquivo (int *A, int n, char *nomeArquivo) //vetor, tamanho, nome do arquivo
{
    ofstream fout;
    fout.open(nomeArquivo,ios :: binary);
    if (!fout)
    {
        cout << "Erro ao abrir o arquivo. \n";
        return;
    }
    for (int i = 0; i< n;i++)
    {
        fout.write ( (char*)&A[i],sizeof(int) );
    }
    fout.close();
}

int buscaSequencialEx (int a,char *nomeArquivo)
{
    ifstream fin;
    fin.open(nomeArquivo, ios :: binary);
    if(!fin)
    {
        cout << "Erro ao tentar abrir o arquivo \n";
        return -1;
    }
    int x;
    int posicao = 0 ;
    while(fin.read((char *)&x,sizeof(int)))
    {
        if (a == x)
        {
            fin.close();
            return posicao;
        }
        posicao++;
    }
    fin.close();
    return -1;
}
int main()
{
    int A[] ={10,20,30,40,50,60,70,80,90,100};

    gravaArquivo(A,10,"numeros.bin");

    int a = 60;

    cout << buscaSequencialEx(a,"numeros.bin");
    return 0;
}
