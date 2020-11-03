#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct linked
{
    int n;
    struct linked *next;
    struct linked *previous;
};

struct lists
{
    string name;
    struct linked *start;
    struct linked *end;
    int size;
};

void addBeginning(lists **firstList, int n)
{
    linked *newValue;
    newValue = (linked *)malloc(sizeof(linked));
    newValue->n = n;
    newValue->next = (*firstList)->start;
    newValue->previous = NULL;

    (*firstList)->start = newValue;

    if ((*firstList)->size == 0)
    {
        (*firstList)->end = newValue;
    }

    (*firstList)->size++;

    // *linkedPointer = newValue;
}

void addEnd(lists **firstList, int n)
{
    linked *newValue;
    newValue = (linked *)malloc(sizeof(linked));
    newValue->n = n;
    newValue->next = NULL;
    newValue->previous = (*firstList)->end;

    if ((*firstList)->size == 0)
    {
        (*firstList)->start = newValue;
        (*firstList)->end = newValue;
    }
    else
    {
        (*firstList)->end->next = newValue;
        (*firstList)->end = newValue;
    }

    (*firstList)->size++;
}

void removeBeginning(linked **linkedPointer, lists **firstList)
{

    if ((*firstList)->size == 0)
    {
        return;
    }
    else
    {
        linked *aux = (*firstList)->start;
        (*firstList)->start = ((*firstList)->start)->next;

        (*firstList)->size--;

        free(aux);
    }
}

void removeEnd(linked **linkedPointer, lists **firstList)
{
    if ((*firstList)->size == 0)
    {
        return;
    }
    else
    {
        (*firstList)->size--;

        (*firstList)->end = (*firstList)->end->previous;

        free((*firstList)->end->next);

        (*firstList)->end->next = NULL;
    }
}