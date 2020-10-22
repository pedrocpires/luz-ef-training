#include <stdio.h>
#include <stdlib.h>

int *allocVector(int size)
{
    int *aux;

    aux = (int *)malloc(size * sizeof(int));

    return aux;
}