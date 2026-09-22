#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;

    fin.open("numeros.txt");

    if(!fin)
    {
        cout << "Erro ao abrir o arquivo";
        return 1;
    }
    for(int i=0; i< 10; i++)
    {
        int x;
        fin >> x; //pegando do arquivo e jogando na variavel
        cout << x << endl;
    }
    fin.close();
    return 0;

}
