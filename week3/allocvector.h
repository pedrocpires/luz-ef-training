#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void allocVector(int **v, int size)
{
    (*v) = (int *)malloc(size * sizeof(int));

    if (!v)
    {
        cout << "Espaço insuficiente para alocar memória \n\n";
        exit(1);
    }
    else
    {
        cout << "Espaço alocado para vetor. \n\n";
    }
}