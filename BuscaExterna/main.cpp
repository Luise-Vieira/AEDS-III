#include <iostream>
#include <fstream>
using namespace std;


// Grava um vetor de inteiros em um arquivo binario.
void gravaArquivo(int *A, int n, char *nomeArquivo)
{

    // Abre o arquivo para escrita.
    ofstream fout(nomeArquivo, ios::binary);

    if (!fout)
    {
        cout << "Erro ao abrir o arquivo para gravacao!" << endl;
        return;
    }

    // Grava os n elementos do vetor.
    fout.write((char *)A, n * sizeof(int));

    fout.close();
}


// Pesquisa sequencial externa.
//
// a: elemento procurado.
// nomeArquivo: nome do arquivo binario.
//
// Retorna a posicao do elemento ou -1 se nao encontrar.
int buscaSequencial(int a, char *nomeArquivo)
{

    // Abre o arquivo para leitura.
    ifstream fin(nomeArquivo, ios::binary);

    if (!fin)
    {
        cout << "Erro ao abrir o arquivo para leitura!" << endl;
        return -1;
    }

    int valor;
    int posicao = 0;

    // Le um inteiro por vez.
    while (fin.read((char *)&valor, sizeof(int)))
    {

        if (valor == a)
        {
            fin.close();
            return posicao;
        }

        posicao++;
    }

    fin.close();

    return -1;
}

int buscaBinaria(int a, char *nomeArquivo)
{
    ifstream fin;
    fin.open(nomeArquivo, ios::binary);
    if(!fin)
    {
        cout << "Erro ao abrir arquivo.\n";
        return -1;
    }

    fin.seekg(0, ios::end); //recebe deslocamento e posicao de referencia

    streamoff bytes = fin.tellg();
    //essas ultimas duas linhas são para obter a posicao
    int qtd = bytes / sizeof(int); //usando o tamanho para evitar que de erro caso um computador use quantidades de bytes por arquivo diferente do padrão

    int inicio = 0;
    int fim = qtd - 1; //menos um pq começa em zero

    while(inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        fin.seekg (meio * sizeof(int),ios::beg);  //colocando o ponteiro no meio,  beg é para andar as casas ate no meio.

        int valor ;
        fin.read((char*)&valor,sizeof(int));

        if (valor == a)
        {
            fin.close();
            return meio;
        }
        else if(valor > a)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;

        }
    }
    fin.close();
    return -1;

}


// Programa principal.
int main()
{

    // Vetor ordenado em ordem crescente.
    int A[] =
    {
        10, 20, 30, 40, 50,
        60, 70, 80, 90, 100
    };

    int n = 10;

    char nomeArquivo[] = "numeros.dat";

    // Grava o vetor no arquivo binario.
    gravaArquivo(A, n, nomeArquivo);

    int procurado = 40;

    // Realiza a pesquisa sequencial.
    // int p1 = buscaSequencial(procurado, nomeArquivo);
    //cout << p1;

    int p1 = buscaBinaria(procurado, nomeArquivo);
    cout << p1;

    return 0;
}
