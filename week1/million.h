#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void million(int **v, int *size)
{
    *size = 10000000;
    // *size = 5000;

    allocVector(v, *size);
    for (int i = 0; i < *size; i++)
    {
        (*v)[i] = (rand() % 1000);
    }

    cout << "Vetor com 10 milhões de registros gerado.";
}