#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int *million()
{

    int size = 10000000;
    int *v;
    v = allocVector(size);
    for (int i = 0; i < size; i++)
    {
        v[i] = rand() % 100;
    }

    return v;
}