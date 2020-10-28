#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void printVector(int *v, int size)
{
    int i;
    cout << " | ";

    for (i = 0; i < size; i++)
    {
        if (v[i] != 0)
        {
            cout << v[i] << " | ";
        }
        else
        {
            cout << "--"
                 << " | ";
        }
    };
    cout << "\n\n";
}