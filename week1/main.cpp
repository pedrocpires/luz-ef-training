#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <time.h>

#include "menu.h"
#include "sort.h"
#include "print.h"

using namespace std;

// Função principal, executa ao iniciar o programa.
int main()
{
    char option;

    while (true)
    {
        int size;
        int *vector;
        option = menuSort();
        if (option == '1')
        {
            cout << "\nVocê escolheu a opção Bubble Sort para ordernar.\n\n";
            menuVector(&vector, &size);
            bubbleSort(vector, size);
            printVector(vector, size);
            break;
        }
        else if (option == '2')
        {
            cout << "\nVocê escolheu a opção Insertion Sort para ordernar.\n\n";
            menuVector(&vector, &size);
            insertionSort(vector, size);
            printVector(vector, size);
            break;
        }
        else if (option == '3')
        {
            cout << "\nVocê escolheu a opção Selection Sort para ordernar.\n\n";
            menuVector(&vector, &size);
            selectionSort(vector, size);
            printVector(vector, size);
            break;
        }
        else if (option == '0')
        {
            cout << "\nBye!\n\n";
            exit(0);
        }
        else
        {
            cout << "\nOpção inválida. Por favor, tente novamente.\n\n";
        }
    }
    return 0;
}
