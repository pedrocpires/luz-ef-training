#include <iostream>
#include <vector>

using namespace std;

// Função para imprimir o vetor.
void printVector(int *v, int size)
{
    int i;
    cout << " | ";

    for (i = 0; i < size; i++)
    {
        cout << v[i] << " | ";
    };
    cout << "\n\n";
}