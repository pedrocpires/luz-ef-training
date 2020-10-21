#include <iostream>
#include <vector>

using namespace std;

// Função para imprimir o vetor.
void printVector(vector<float> v)
{
    int i;
    cout << " | ";
    for (i = 0; i < v.size(); i++)
    {
        cout << v[i] << " | ";
    };
    cout << "\n\n";
}

// Função para imprimir um separador padrão.
void separator()
{
    printf("\n\n|==================================================|\n\n");
}