#include <iostream>
#include <fstream>


using namespace std;

int main()
{

    /*string nome = "Maria";
    float salario= 2000.00;

    ofstream fout("dados.txt"); //escreve no arquivo
    //fstream fout("dados.txt", ios :: out); continua sendo um arquivo de escrita, assim caso desejado tem como usar pra escrita e para leitura

    if (!fout)
    {
        cout << "Erro ao criar o arquivo";
        return -1;
    }

    fout <<  nome << endl << salario; //gravaçao em arquivo texto é igual cout

    fout.close();

    ifstream fin("dados.txt.");

    if(!fin)
    {
        cout << "Erro ao abrir o arquivo; ";
        return 1;
    }

    string nome2;
    float salario2;

    fin >> nome2;
    fin >> salario2;

    cout << nome2 <<  " " << salario2;

    fin.close();*/

    //Binario

    int a=10;
    int b[6]={10,20,30,40,50};
    float c=99.3;
    float *d = new float;
    *d = 100; //o conteudo apontado por d recebe 100

   /* cout << sizeof(a) << endl << sizeof(b) << sizeof (c);

    cout << "\n\n";

    cout << &a << endl << b << endl << &c;
     //& endereço da variavel
     //Vetores ja sao ponteiros */

     //ofstream fout ("dados.dat", ios::binary); //cria o arquvio no construtir
        ofstream fout;
        fout.open("dados.bin", ios::binary);
        if(!fout)
        {
            cout << "Erro ao criar o arquivo. ";
            return 1;
        }
        //grava e le na mesma ordem

        //gravando os dados
        fout.write((char*)&a ,sizeof(a)); //primeiro parametro endereço, segundo o tamanho, tem que converter pra char devido a qm criou a função
        fout.write((char *)b ,sizeof(b));
        fout.write((char *) &c ,sizeof(c));
        fout.write((char *) d ,sizeof(float)); //*d ou float

        fout.close();

        ifstream fin;
        fin.open("dados.bin", ios::binary);

        if (!fin)
        {
            cout << "Erro ao abrir o arquivo";
            return 1;
        }

        int a2;
        int b2[6];
        float c2;
        float *d2 = new float;

        fin.read((char *) &a2, sizeof(a2));
        fin.read((char *) b2, sizeof(b2));
        fin.read((char *) &c2, sizeof(c2));
        fin.read((char *) d2, sizeof(float));//recebe dois paramentros, o ponteiro e quantidade de bytes

        cout << a2 << endl ;
        for(int i=0;i<6;i++)
        {
            cout << b2[i] << " ";
        }
        cout << endl << c2 << endl;
        cout << *d2;
        return 0;
}
