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
    // vector<float> v{10, 20, 50, 30, 40, 50, 60, 10, 20};
    // vector<float> v{10, 20, 30, 40, 50, 60, 70, 80, 90};
    // vector<float> v{90, 80, 70, 60, 50, 40, 30, 20, 10};

    char option;

    while (true)
    {
        option = menuSort();
        if (option == '1')
        {
            cout << "\nVocê escolheu a opção Bubble Sort para ordernar.\n\n";
            printVector(bubbleSort(menuVector()));
            break;
        }
        else if (option == '2')
        {
            cout << "\nVocê escolheu a opção Insertion Sort para ordernar.\n\n";
            printVector(insertionSort(menuVector()));
            break;
        }
        else if (option == '3')
        {
            cout << "\nVocê escolheu a opção Selection Sort para ordernar.\n\n";
            printVector(selectionSort(menuVector()));
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
