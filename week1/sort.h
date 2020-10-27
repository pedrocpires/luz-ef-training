#include <iostream>
#include <time.h>
#include <vector>

#include "time_log.h"

using namespace std;

// Executa o bubbleSort do vetor.
void bubbleSort(int *v, int size)
{
    int timer;
    clock_t t_start, t_end;
    t_start = clock();

    int aux;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
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

    time_log(timer, size);
}

// Executa o insertionSort do vetor.
void insertionSort(int *v, int size)
{
    int timer;
    clock_t t_start, t_end;
    t_start = clock();

    int aux;

    for (int i = 1; i < size; i++)
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

    time_log(timer, size);
}

// Executa o selectionSort do vetor.
void selectionSort(int *v, int size)
{
    int timer;
    clock_t t_start, t_end;
    t_start = clock();

    for (int i = 0; i < size; i++)
    {
        int smaller = i;
        for (int j = i; j < size; j++)
        {
            if (v[j] < v[smaller])
            {
                smaller = j;
            }
        }
        int aux = v[i];
        v[i] = v[smaller];
        v[smaller] = aux;
    }

    t_end = clock();
    timer = difftime(t_end, t_start);

    time_log(timer, size);
}