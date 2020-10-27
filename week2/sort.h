#include <iostream>
#include <time.h>
#include <vector>

// #include "print.h"
#include "time_log.h"

using namespace std;
int x;
void merge(int *v, int leftLimit, int middle, int rightLimit)
{
    int size1 = middle - leftLimit + 1;
    int size2 = rightLimit - middle;

    int v1[size1];
    int v2[size2];

    int i, j;
    for (i = 0; i < size1; i++)
    {
        v1[i] = v[(leftLimit + i)];
    }
    for (j = 0; j < size2; j++)
    {
        v2[j] = v[(middle + j + 1)];
    }

    i = 0;
    j = 0;
    int k = leftLimit;

    while (i < size1 && j < size2)
    {
        if (v1[i] <= v2[j])
        {
            v[k] = v1[i];
            i++;
        }
        else
        {
            v[k] = v2[j];
            j++;
        }
        k++;
    }
    while (i < size1)
    {
        v[k] = v1[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        v[k] = v2[j];
        j++;
        k++;
    }
}

// Executa o Merge Sort do vetor.
void mergeSort(int *v, int leftLimit, int rightLimit)
{
    if (leftLimit < rightLimit)
    {
        int middle = leftLimit + (rightLimit - leftLimit) / 2;
        mergeSort(v, leftLimit, middle);
        mergeSort(v, (middle + 1), rightLimit);

        merge(v, leftLimit, middle, rightLimit);
    }
}

void quickSort(int *v, int leftLimit, int rightLimit)
{

    int i, j, aux;

    int middle = (leftLimit + rightLimit) / 2;
    int pivot;
    pivot = v[middle];

    i = leftLimit;
    j = rightLimit;
    while (i <= j)
    {
        while (v[i] < pivot && i < rightLimit)
        {
            i++;
        }
        while (v[j] > pivot && j > leftLimit)
        {
            j--;
        }
        if (i <= j)
        {
            aux = (int)v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    if (leftLimit < j)
    {
        quickSort(v, leftLimit, j);
    }
    if (i < rightLimit)
    {
        quickSort(v, i, rightLimit);
    }
}
