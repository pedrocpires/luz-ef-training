#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<float> million()
{
    vector<float> v(10000000, 0);
    for (int i = 0; i < 10000000; i++)
    {
        v[i] = rand() % 100;
    }

    return v;
}