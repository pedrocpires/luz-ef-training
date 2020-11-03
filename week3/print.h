#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

#include "linkedFunctions.h"

void printList(lists **firstList)
{
    if ((*firstList)->size == 0)
    {
        cout << "\nA lista está vazia!";
    }
    else
    {
        linked *node = (*firstList)->start;

        cout << "\n | ";
        while (node != NULL)
        {
            cout << node->n << " | ";
            node = node->next;
        }
        cout << "\n";
    }
}

int sizeList(lists **firstList)
{
    return (*firstList)->size;
}