#include <iostream>
#include <time.h>
#include <vector>

#include "time_log.h"

using namespace std;

// Executa o bubbleSort do vetor.
vector<float> bubbleSort(vector<float> v)
{
    float timer;
    clock_t t_start, t_end;
    t_start = clock();

    float aux;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    };
    t_end = clock();
    timer = difftime(t_end, t_start);

    time_log(timer, v.size());

    return v;
}

// Executa o insertionSort do vetor.
vector<float> insertionSort(vector<float> v)
{
    float timer;
    clock_t t_start, t_end;
    t_start = clock();

    float aux;

    for (int i = 1; i < v.size(); i++)
    {
        int j = i;
        while (v[j] < v[j - 1])
        {
            aux = v[j - 1];
            v[j - 1] = v[j];
            v[j] = aux;
            j--;
        }
    };

    t_end = clock();
    timer = difftime(t_end, t_start);

    time_log(timer, v.size());

    return v;
}

// Executa o selectionSort do vetor.
vector<float> selectionSort(vector<float> v)
{
    float timer;
    clock_t t_start, t_end;
    t_start = clock();

    for (int i = 0; i < v.size(); i++)
    {
        int smaller = i;
        for (int j = i; j < v.size(); j++)
        {
            if (v[j] < v[smaller])
            {
                smaller = j;
            }
        }
        float aux = v[i];
        v[i] = v[smaller];
        v[smaller] = aux;
    }

    t_end = clock();
    timer = difftime(t_end, t_start);

    time_log(timer, v.size());

    return v;
}
